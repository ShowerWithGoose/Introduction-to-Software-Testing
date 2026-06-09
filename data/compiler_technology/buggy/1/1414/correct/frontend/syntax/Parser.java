package frontend.syntax;

import frontend.Config;
import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import utils.OutputTool;
import utils.Panic;

import java.util.LinkedList;
import java.util.List;

public class Parser {
    private final TokenList tokens;
    private final List<SyntaxTree.CompileUnit> compileUnits;

    public Parser(List<Token> tokens) {
        this.tokens = new TokenList(tokens);
        this.compileUnits = new LinkedList<>();
    }

    public List<SyntaxTree.CompileUnit> getCompileUnits() {
        return compileUnits;
    }

    public void parse() {
        while (tokens.hasNext()) {
            if (tokens.top(2).in(TokenType.LPARENT)) {
                compileUnits.add(parseFuncDecl());
            } else {
                compileUnits.add(parseDeclaration());
            }
        }
        OutputTool.writeToFile(Config.syntaxTreeWriter, "<CompUnit>\n");
    }

    private SyntaxTree.FuncDecl parseFuncDecl() {
        Token retType = tokens.pop();
        if (!tokens.top().getName().equals("main")) {
            OutputTool.writeToFile(Config.syntaxTreeWriter, "<FuncType>\n");
        }
        Token name = tokens.pop();
        tokens.tryNext(TokenType.LPARENT);
        List<SyntaxTree.FuncParamDecl> params = parseParamDecls();
        tokens.popAndCheck(TokenType.RPARENT); // j
        SyntaxTree.Block block = parseBlock();
        if (name.getName().equals("main")) {
            OutputTool.writeToFile(Config.syntaxTreeWriter, "<MainFuncDef>\n");
        } else {
            OutputTool.writeToFile(Config.syntaxTreeWriter, "<FuncDef>\n");
        }
        return new SyntaxTree.FuncDecl(name.getName(), params, retType.getType(), block);
    }

    private SyntaxTree.Declaration parseDeclaration() {
        // Decl → ConstDecl | VarDecl
        // ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';'
        // ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal
        // ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
        // VarDecl → BType VarDef { ',' VarDef } ';'
        // VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal
        // InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
        boolean isConst = tokens.tryNext(TokenType.CONSTTK);
        Token type = tokens.pop();
        LinkedList<SyntaxTree.VarDef> vars = new LinkedList<>();
        do {
            Token name = tokens.pop();
//            LinkedList<SyntaxTree.AddExpr> indexes = new LinkedList<>();
            SyntaxTree.AddExpr index = null;
            if (tokens.tryNext(TokenType.LBRACK)) {
                index = parseExpr();
                OutputTool.writeToFile(Config.syntaxTreeWriter, "<ConstExp>\n");
                tokens.popAndCheck(TokenType.RBRACK); // k
            }
            if (tokens.tryNext(TokenType.ASSIGN)) {
                vars.add(new SyntaxTree.VarDef(name.getName(), type.getType(), index, parseInitValue(isConst)));
            } else vars.add(new SyntaxTree.VarDef(name.getName(), type.getType(), index));
            if (isConst) {
                OutputTool.writeToFile(Config.syntaxTreeWriter, "<ConstDef>\n");
            } else {
                OutputTool.writeToFile(Config.syntaxTreeWriter, "<VarDef>\n");
            }
        } while (tokens.hasNext() && tokens.tryNext(TokenType.COMMA));
        tokens.popAndCheck(TokenType.SEMICN); // i
        if (isConst) {
            OutputTool.writeToFile(Config.syntaxTreeWriter, "<ConstDecl>\n");
        } else {
            OutputTool.writeToFile(Config.syntaxTreeWriter, "<VarDecl>\n");
        }
        return new SyntaxTree.VarDecl(isConst, type.getType(), vars);
    }

    private List<SyntaxTree.FuncParamDecl> parseParamDecls() {
        List<SyntaxTree.FuncParamDecl> params = new LinkedList<>();
//        while (tokens.hasNext() && !tokens.top().in(TokenType.RPARENT)) ;
        do {
            if (!tokens.check(TokenType.INTTK, TokenType.CHARTK)) {
                break;
            }
            Token type = tokens.pop();
            Token name = tokens.pop();
            List<SyntaxTree.AddExpr> indexes = new LinkedList<>();
            if (tokens.tryNext(TokenType.LBRACK)) {
                indexes.add(null);
                tokens.popAndCheck(TokenType.RBRACK); // k
            }params.add(new SyntaxTree.FuncParamDecl(name.getName(), type.getType(), indexes));
            OutputTool.writeToFile(Config.syntaxTreeWriter, "<FuncFParam>\n");
        } while (tokens.hasNext() && tokens.tryNext(TokenType.COMMA));
//        tokens.popAndCheck(TokenType.RPARENT);
        if (!params.isEmpty()) {
            OutputTool.writeToFile(Config.syntaxTreeWriter, "<FuncFParams>\n");
        }
        return params;
    }

    private SyntaxTree.Block parseBlock() {
        List<SyntaxTree.BlockItem> items = new LinkedList<>();
        tokens.tryNext(TokenType.LBRACE);
        while (tokens.hasNext() && !tokens.check(TokenType.RBRACE)) {
            if (tokens.check(TokenType.CONSTTK, TokenType.INTTK, TokenType.CHARTK)) {
                items.add(parseDeclaration());
            } else {
                items.add(parseStatement());
            }
        }
        tokens.tryNext(TokenType.RBRACE);
        OutputTool.writeToFile(Config.syntaxTreeWriter, "<Block>\n");
        return new SyntaxTree.Block(items);
    }

    public SyntaxTree.Statement parseStatement() {
        /*
        Stmt → LVal '=' Exp ';' // 每种类型的语句都要覆盖
            | [Exp] ';' //有无Exp两种情况
            | Block
            | 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // 1.有else 2.无else
            | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt // 1. 无缺省，1种情况 2.
            | 'break' ';' | 'continue' ';'
            | 'return' [Exp] ';' // 1.有Exp 2.无Exp
            | LVal '=' 'getint''('')'';'
            | LVal '=' 'getchar''('')'';'
            | 'printf''('StringConst {','Exp}')'';'
         */
        SyntaxTree.Statement ret = null;
        if (tokens.check(TokenType.LBRACE)) {
            ret = parseBlock();
        } else if (tokens.tryNext(TokenType.IFTK)) {
            // if-else
            tokens.tryNext(TokenType.LPARENT);
            SyntaxTree.LOrExpr orExpr = parseCondition();
            OutputTool.writeToFile(Config.syntaxTreeWriter, "<Cond>\n");
            tokens.popAndCheck(TokenType.RPARENT); // j
            SyntaxTree.Statement thenStmt = parseStatement();
            if (tokens.tryNext(TokenType.ELSETK)) {
                ret = new SyntaxTree.BranchStmt(orExpr, thenStmt, parseStatement());
            } else ret = new SyntaxTree.BranchStmt(orExpr, thenStmt, null);
        } else if (tokens.tryNext(TokenType.FORTK)) {
            // for
            // 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
            tokens.tryNext(TokenType.LPARENT);
            SyntaxTree.ForExpr init = null;
            if (!tokens.check(TokenType.SEMICN)) {
                init = parseForExpr();
            }
            tokens.tryNext(TokenType.SEMICN);
            SyntaxTree.LOrExpr condition = null;
            if (!tokens.check(TokenType.SEMICN)) {
                condition = parseCondition();
                OutputTool.writeToFile(Config.syntaxTreeWriter, "<Cond>\n");
            }
            tokens.tryNext(TokenType.SEMICN);
            SyntaxTree.ForExpr move = null;
            if (!tokens.check(TokenType.SEMICN)) {
                move = parseForExpr();
            }
            tokens.tryNext(TokenType.RPARENT);
            SyntaxTree.Statement thenStmt = parseStatement();
            ret = new SyntaxTree.ForStmt(thenStmt, init, move, condition);
        } else if (tokens.tryNext(TokenType.RETURNTK)) {
            // return
            if (tokens.tryNext(TokenType.SEMICN)) {
                ret = new SyntaxTree.ReturnStmt(null);
            } else {
                boolean flag = false;
                try {
                    ret = new SyntaxTree.ReturnStmt(parseExpr());
                } catch (Exception e) {
                    flag = true;
                }
                if (!flag) {
                    OutputTool.writeToFile(Config.syntaxTreeWriter, "<Exp>\n");
                }
                tokens.popAndCheck(TokenType.SEMICN); // i
            }
        } else if (tokens.check(TokenType.BREAKTK, TokenType.CONTINUETK)) {
            // break | continue
            TokenType type = tokens.pop().getType();
            tokens.popAndCheck(TokenType.SEMICN); // i
            ret = new SyntaxTree.CtrlStmt(type);
        } else if (tokens.tryNext(TokenType.PRINTFTK)) {
            // printf
            tokens.tryNext(TokenType.LPARENT);
            String strConst = tokens.pop().getString();
            List<SyntaxTree.AddExpr> indexes = new LinkedList<>();
            while (tokens.tryNext(TokenType.COMMA)) {
                indexes.add(parseExpr());
                OutputTool.writeToFile(Config.syntaxTreeWriter, "<Exp>\n");
            }
            tokens.popAndCheck(TokenType.RPARENT); // j
            tokens.popAndCheck(TokenType.SEMICN); // i
            ret = new SyntaxTree.PrintStmt(strConst, indexes);
        } else {
            // expr | LVal =
            if (tryGetLVal()) {
                SyntaxTree.LValue lValue = parseLValue();
                tokens.tryNext(TokenType.ASSIGN);
                if (tokens.check(TokenType.GETINTTK, TokenType.GETCHARTK)) {
                    SyntaxTree.GetInStream get = new SyntaxTree.GetInStream(tokens.pop().getType());
                    tokens.tryNext(TokenType.LPARENT);
                    tokens.popAndCheck(TokenType.RPARENT); // j
                    tokens.popAndCheck(TokenType.SEMICN); // i
                    ret = new SyntaxTree.AssignStmt(lValue, get);
                } else {
                    SyntaxTree.AddExpr expr = parseExpr();
                    OutputTool.writeToFile(Config.syntaxTreeWriter, "<Exp>\n");
                    tokens.popAndCheck(TokenType.SEMICN); // i
                    ret = new SyntaxTree.AssignStmt(lValue, expr);
                }
            } else if (tokens.tryNext(TokenType.SEMICN)) {
                ret = new SyntaxTree.ExprStmt(null);
            } else {
                SyntaxTree.AddExpr expr = parseExpr();
                OutputTool.writeToFile(Config.syntaxTreeWriter, "<Exp>\n");
                tokens.popAndCheck(TokenType.SEMICN); // i
                ret = new SyntaxTree.ExprStmt(expr);
            }
        }
        OutputTool.writeToFile(Config.syntaxTreeWriter, "<Stmt>\n");
        return ret;
    }

    private SyntaxTree.ForExpr parseForExpr() {
        if (tokens.check(TokenType.SEMICN, TokenType.RPARENT)) {
            return new SyntaxTree.ForExpr(null, null);
        }
        SyntaxTree.LValue lValue = parseLValue();
        tokens.tryNext(TokenType.ASSIGN);
        SyntaxTree.AddExpr expr = parseExpr();
        OutputTool.writeToFile(Config.syntaxTreeWriter, "<Exp>\n");
        OutputTool.writeToFile(Config.syntaxTreeWriter, "<ForStmt>\n");
        return new SyntaxTree.ForExpr(lValue, expr);
    }

    private SyntaxTree.AddExpr parseExpr() {
        // AddExp → MulExp | AddExp ('+' | '−') MulExp
        if (!tokens.check(TokenType.IDENFR, TokenType.PLUS, TokenType.MINU, TokenType.NOT, TokenType.LPARENT, TokenType.INTCON, TokenType.CHRCON)) {
            Panic.panic("expected parseExpr but got: " + tokens.top().getType());
        }
        SyntaxTree.MulExpr leading = parseMulExpr();
        List<SyntaxTree.ExprWithLeading<SyntaxTree.MulExpr>> follows = new LinkedList<>();
        while (tokens.check(TokenType.MINU, TokenType.PLUS)) {
            OutputTool.writeToFile(Config.syntaxTreeWriter, "<AddExp>\n");
            follows.add(new SyntaxTree.ExprWithLeading<>(tokens.pop().getType(), parseMulExpr()));
        }
        OutputTool.writeToFile(Config.syntaxTreeWriter, "<AddExp>\n");
        return new SyntaxTree.AddExpr(leading, follows);
    }

    private SyntaxTree.MulExpr parseMulExpr() {
        // MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
        SyntaxTree.UnaryExpr leading = parseUnaryExpr();
        List<SyntaxTree.ExprWithLeading<SyntaxTree.UnaryExpr>> follows = new LinkedList<>();
        while (tokens.check(TokenType.MULT, TokenType.DIV, TokenType.MOD)) {
            OutputTool.writeToFile(Config.syntaxTreeWriter, "<MulExp>\n");
            follows.add(new SyntaxTree.ExprWithLeading<>(tokens.pop().getType(), parseUnaryExpr()));
        }
        OutputTool.writeToFile(Config.syntaxTreeWriter, "<MulExp>\n");
        return new SyntaxTree.MulExpr(leading, follows);
    }

    private SyntaxTree.UnaryExpr parseUnaryExpr() {
        // UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
        List<TokenType> operators = new LinkedList<>();
        if (tokens.check(TokenType.PLUS, TokenType.MINU, TokenType.NOT)) {
            operators.add(tokens.pop().getType());
            OutputTool.writeToFile(Config.syntaxTreeWriter, "<UnaryOp>\n");
            SyntaxTree.UnaryExpr ret = parseUnaryExpr();
            OutputTool.writeToFile(Config.syntaxTreeWriter, "<UnaryExp>\n");
            return ret;
        } else if (tokens.check(TokenType.IDENFR) && tokens.top(1).in(TokenType.LPARENT)) {
            Token funcName = tokens.pop();
            tokens.tryNext(TokenType.LPARENT);
            List<SyntaxTree.AddExpr> args = new LinkedList<>();
//            while (!tokens.check(TokenType.RPARENT)) {
            do {
                try {
                    args.add(parseExpr());
                } catch (Exception e) {
                    break;
                }
                OutputTool.writeToFile(Config.syntaxTreeWriter, "<Exp>\n");
            } while(tokens.tryNext(TokenType.COMMA));
            if (!args.isEmpty()) {
                OutputTool.writeToFile(Config.syntaxTreeWriter, "<FuncRParams>\n");
            }
            tokens.popAndCheck(TokenType.RPARENT); // j
//            tokens.popAndCheck(TokenType.SEMICN);
            OutputTool.writeToFile(Config.syntaxTreeWriter, "<UnaryExp>\n");
            return new SyntaxTree.UnaryExpr(operators, new SyntaxTree.FuncCall(funcName.getName(), args));
        } else {
            SyntaxTree.UnaryExpr ret = new SyntaxTree.UnaryExpr(operators, parsePrimaryExpr());
            OutputTool.writeToFile(Config.syntaxTreeWriter, "<UnaryExp>\n");
            return ret;
        }
    }

    private SyntaxTree.PrimaryExpr parsePrimaryExpr() {
        // PrimaryExp → '(' Exp ')' | LVal | Number | Character
        SyntaxTree.PrimaryExpr ret = null;
        if (tokens.tryNext(TokenType.LPARENT)) {
            SyntaxTree.AddExpr expr = parseExpr();
            OutputTool.writeToFile(Config.syntaxTreeWriter, "<Exp>\n");
            tokens.popAndCheck(TokenType.RPARENT); // j
            ret = new SyntaxTree.PrimaryExpr(expr);
        } else if (tokens.check(TokenType.INTCON)) {
            ret = new SyntaxTree.PrimaryExpr(new SyntaxTree.IntNum(tokens.pop().getIntValue()));
            OutputTool.writeToFile(Config.syntaxTreeWriter, "<Number>\n");
        } else if (tokens.check(TokenType.CHRCON)) {
            ret = new SyntaxTree.PrimaryExpr(new SyntaxTree.CharNum(tokens.pop().getCharValue()));
            OutputTool.writeToFile(Config.syntaxTreeWriter, "<Character>\n");
        } else {
            ret = new SyntaxTree.PrimaryExpr(parseLValue());
        }
        OutputTool.writeToFile(Config.syntaxTreeWriter, "<PrimaryExp>\n");
        return ret;
    }

    private SyntaxTree.InitValue parseInitValue(boolean isConst) {
        // InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
        //  ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
        if (tokens.tryNext(TokenType.LBRACE)) {
            List<SyntaxTree.InitValue> values = new LinkedList<>();
            while (!tokens.check(TokenType.RBRACE)) {
                values.add(new SyntaxTree.InitValue(parseExpr()));
                if (isConst) {
                    OutputTool.writeToFile(Config.syntaxTreeWriter, "<ConstExp>\n");
                } else {
                    OutputTool.writeToFile(Config.syntaxTreeWriter, "<Exp>\n");
                }
                tokens.tryNext(TokenType.COMMA);
            }
            tokens.tryNext(TokenType.RBRACE);
            if (isConst) {
                OutputTool.writeToFile(Config.syntaxTreeWriter, "<ConstInitVal>\n");
            } else {
                OutputTool.writeToFile(Config.syntaxTreeWriter, "<InitVal>\n");
            }
            return new SyntaxTree.InitValue(values);
        } else if (tokens.check(TokenType.STRCON)) {
            SyntaxTree.InitValue ret = new SyntaxTree.InitValue(tokens.pop().getString());
            if (isConst) {
                OutputTool.writeToFile(Config.syntaxTreeWriter, "<ConstInitVal>\n");
            } else {
                OutputTool.writeToFile(Config.syntaxTreeWriter, "<InitVal>\n");
            }
            return ret;
        } else {
            SyntaxTree.InitValue ret = new SyntaxTree.InitValue(parseExpr());
            if (isConst) {
                OutputTool.writeToFile(Config.syntaxTreeWriter, "<ConstExp>\n");
                OutputTool.writeToFile(Config.syntaxTreeWriter, "<ConstInitVal>\n");
            } else {
                OutputTool.writeToFile(Config.syntaxTreeWriter, "<Exp>\n");
                OutputTool.writeToFile(Config.syntaxTreeWriter, "<InitVal>\n");
            }
            return ret;
        }
    }

    private SyntaxTree.LValue parseLValue() {
        // LVal → Ident ['[' Exp ']']
        SyntaxTree.LValue ret = null;
        if (!tokens.check(TokenType.IDENFR)) {
            Panic.panic("Expected : IDENFR but got: " + tokens.top().getType());
        }
        Token name = tokens.pop();
        if (tokens.tryNext(TokenType.LBRACK)) {
            SyntaxTree.AddExpr index = parseExpr();
            OutputTool.writeToFile(Config.syntaxTreeWriter, "<Exp>\n");
            tokens.popAndCheck(TokenType.RBRACK); // k
            ret = new SyntaxTree.LValue(name.getName(), index);
        } else {
            ret = new SyntaxTree.LValue(name.getName(), null);
        }
        OutputTool.writeToFile(Config.syntaxTreeWriter, "<LVal>\n");
        return ret;
    }

    private boolean tryGetLVal() {
        // LVal → Ident ['[' Exp ']']
        if (!tokens.check(TokenType.IDENFR)) {
            return false;
        }
        Config.emitSyntaxTree = false;
        Config.emitError = false;
        int cur = tokens.getCur();
        Token name = tokens.pop();
        if (tokens.tryNext(TokenType.LBRACK)) {
            parseExpr();
            tokens.tryNext(TokenType.RBRACK);
        }
        boolean ret = false;
        if (tokens.check(TokenType.ASSIGN)) {
            ret = true;
        }
        tokens.setCur(cur);
        Config.emitSyntaxTree = true;
        Config.emitError = true;
        return ret;
    }
    private SyntaxTree.LOrExpr parseCondition() {
        //  LOrExp → LAndExp | LOrExp '||' LAndExp
        SyntaxTree.LAndExpr leading = parseLAndExpr();
        List<SyntaxTree.ExprWithLeading<SyntaxTree.LAndExpr>> follows = new LinkedList<>();
        while (tokens.check(TokenType.OR)) {
            OutputTool.writeToFile(Config.syntaxTreeWriter, "<LOrExp>\n");
            follows.add(new SyntaxTree.ExprWithLeading<>(tokens.pop().getType(), parseLAndExpr()));
        }
        OutputTool.writeToFile(Config.syntaxTreeWriter, "<LOrExp>\n");
        return new SyntaxTree.LOrExpr(leading, follows);
    }

    private SyntaxTree.LAndExpr parseLAndExpr() {
        //  LAndExp → EqExp | LAndExp '&&' EqExp
        SyntaxTree.EqExpr leading = parseEqExpr();
        List<SyntaxTree.ExprWithLeading<SyntaxTree.EqExpr>> follows = new LinkedList<>();
        while (tokens.check(TokenType.AND)) {
            OutputTool.writeToFile(Config.syntaxTreeWriter, "<LAndExp>\n");
            follows.add(new SyntaxTree.ExprWithLeading<>(tokens.pop().getType(), parseEqExpr()));
        }
        OutputTool.writeToFile(Config.syntaxTreeWriter, "<LAndExp>\n");
        return new SyntaxTree.LAndExpr(leading, follows);
    }

    private SyntaxTree.EqExpr parseEqExpr() {
        // EqExp → RelExp | EqExp ('==' | '!=') RelExp
        SyntaxTree.RelExpr leading = parseRelExpr();
        List<SyntaxTree.ExprWithLeading<SyntaxTree.RelExpr>> follows = new LinkedList<>();
        while (tokens.check(TokenType.EQL, TokenType.NEQ)) {
            OutputTool.writeToFile(Config.syntaxTreeWriter, "<EqExp>\n");
            follows.add(new SyntaxTree.ExprWithLeading<>(tokens.pop().getType(), parseRelExpr()));
        }
        OutputTool.writeToFile(Config.syntaxTreeWriter, "<EqExp>\n");
        return new SyntaxTree.EqExpr(leading, follows);
    }

    private SyntaxTree.RelExpr parseRelExpr() {
        // RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
        SyntaxTree.AddExpr leading = parseExpr();
        List<SyntaxTree.ExprWithLeading<SyntaxTree.AddExpr>> follows = new LinkedList<>();
        while (tokens.check(TokenType.LEQ, TokenType.GEQ, TokenType.GRE, TokenType.LSS)) {
            OutputTool.writeToFile(Config.syntaxTreeWriter, "<RelExp>\n");
            follows.add(new SyntaxTree.ExprWithLeading<>(tokens.pop().getType(), parseExpr()));
        }
        OutputTool.writeToFile(Config.syntaxTreeWriter, "<RelExp>\n");
        return new SyntaxTree.RelExpr(leading, follows);
    }
}
