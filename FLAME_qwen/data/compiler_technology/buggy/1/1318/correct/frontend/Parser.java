package frontend;

import utils.Logger;

import java.util.ArrayList;

public class Parser {

    private final TokenList tokens;

    public Parser(TokenList tokens) {
        this.tokens = tokens;
    }

    public Ast parser() {
        ArrayList<Ast.CompUnit> units = new ArrayList<>();
        while (tokens.hasNext()) {
            units.add(parseCompUnit());
        }
        return new Ast(units);
    }

    //CompUnit → {Decl} {FuncDef} MainFuncDef
    public Ast.CompUnit parseCompUnit() {
        ArrayList<Ast.Decl> decls = new ArrayList<>();
        ArrayList<Ast.FuncDef> funcDefs = new ArrayList<>();
        while (tokens.hasNext()
                && tokens.isType(TokenType.CONSTTK, TokenType.INTTK, TokenType.CHARTK)
                && tokens.ahead(2).getType() != TokenType.LPARENT) {
            decls.add(parseDecl());
        }
        while (tokens.hasNext()
                && tokens.isType(TokenType.VOIDTK, TokenType.INTTK, TokenType.CHARTK)) {
            funcDefs.add(parseFuncDef());
        }
        Ast.FuncDef mainFuncDef = funcDefs.remove(funcDefs.size() - 1);
        return new Ast.CompUnit(decls, funcDefs, mainFuncDef);
    }

    // Decl → [ 'const' ] BType Def { ',' Def } ';'
    private Ast.Decl parseDecl() {
        boolean constant = tokens.consume(TokenType.CONSTTK) != null;
        TokenType type = tokens.consume(TokenType.INTTK, TokenType.CHARTK).getType();
        ArrayList<Ast.Def> defs = new ArrayList<>();
        do {
            defs.add(parseDef(constant));
        } while (tokens.consume(TokenType.COMMA) != null);
        Logger.logger.check(tokens.consume(TokenType.SEMICN), tokens.getLast().getLine() + " " + "i");
        return new Ast.Decl(constant, type, defs);
    }

    // Def -> Ident {'[' ConstExp ']'} ['=' (Const)InitVal]
    private Ast.Def parseDef(boolean constant) {
        Token ident = tokens.consume(TokenType.IDENFR);
        if (ident == null) {
            System.out.print("error1");
        }
        Ast.ConstExp exp = null;
        if (tokens.consume(TokenType.LBRACK) != null) {
            exp = parseConstExp();
            Logger.logger.check(tokens.consume(TokenType.RBRACK), tokens.getLast().getLine() + " " + "k");
        }
        Ast.InitVal initVal;
        if (tokens.consume(TokenType.ASSIGN) != null) {
            initVal = parseInitVal(constant);
            return new Ast.Def(ident, exp, initVal, constant);
        } else if (constant) {
//            System.out.print("error2");
        }
        return new Ast.Def(ident, exp, constant);
    }

    // InitVal -> (Const)Exp | '{' [ (Const)Exp { ',' (Const)Exp } ] '}' | StringConst
    private Ast.InitVal parseInitVal(boolean constant) {
        if (tokens.consume(TokenType.LBRACE) != null) {
            ArrayList<Ast.Exp> exps = new ArrayList<>();
            do {
                if (tokens.get().getType() == TokenType.RBRACE) {
                    break;
                }
                exps.add(parseExp());
            } while (tokens.consume(TokenType.COMMA) != null);
            tokens.consume(TokenType.RBRACE);
            return new Ast.InitVal(exps, constant);
        } else if (tokens.get().getType() == TokenType.STRCON) {
            return new Ast.InitVal(tokens.consume(TokenType.STRCON), constant);
        } else {
            return new Ast.InitVal(parseExp(), constant);
        }
    }

    // Exp → AddExp
    private Ast.Exp parseExp() {
        return new Ast.Exp(parseAddExp());
    }

    // ConstExp → AddExp
    private Ast.ConstExp parseConstExp() {
        return new Ast.ConstExp(parseAddExp());
    }

    // AddExp → MulExp | AddExp ('+' | '−') MulExp
    private Ast.AddExp parseAddExp() {
        ArrayList<Ast.MulExp> mulExps = new ArrayList<>();
        ArrayList<TokenType> ops = new ArrayList<>();
        mulExps.add(parseMulExp());
        while (tokens.isType(TokenType.PLUS, TokenType.MINU)) {
            TokenType op = tokens.consume().getType();
            ops.add(op);
            mulExps.add(parseMulExp());
        }
        return new Ast.AddExp(mulExps, ops);
    }

    // MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
    private Ast.MulExp parseMulExp() {
        ArrayList<Ast.UnaryExp> unaryExps = new ArrayList<>();
        ArrayList<TokenType> ops = new ArrayList<>();
        unaryExps.add(parseUnaryExp());
        while (tokens.isType(TokenType.MULT, TokenType.DIV, TokenType.MOD)) {
            TokenType op = tokens.consume().getType();
            ops.add(op);
            unaryExps.add(parseUnaryExp());
        }
        return new Ast.MulExp(unaryExps, ops);
    }

    //UnaryExp → PrimaryExp | FuncCall | UnaryOp UnaryExp
    private Ast.UnaryExp parseUnaryExp() {
        if (tokens.isType(TokenType.IDENFR) && tokens.ahead(1).getType() == TokenType.LPARENT) {
            return new Ast.UnaryExp(parseFuncCall());
        } else if (tokens.isType(TokenType.PLUS, TokenType.MINU, TokenType.NOT)) {
            TokenType op = tokens.consume().getType();
            return new Ast.UnaryExp(op, parseUnaryExp());
        } else {
            return new Ast.UnaryExp(parsePrimaryExp());
        }
    }

    // PrimaryExp → '(' Exp ')' | LVal | Number | Character
    private Ast.PrimaryExp parsePrimaryExp() {
        if (tokens.consume(TokenType.LPARENT) != null) {
            Ast.Exp exp = parseExp();
            Logger.logger.check(tokens.consume(TokenType.RPARENT), tokens.getLast().getLine() + " " + "j");
            return new Ast.PrimaryExp(exp);
        } else if (tokens.isType(TokenType.IDENFR)) {
            return new Ast.PrimaryExp(parseLVal());
        } else if (tokens.isType(TokenType.INTCON)) {
            Ast.Number number = new Ast.Number(tokens.consume(TokenType.INTCON));
            return new Ast.PrimaryExp(number);
        } else if (tokens.isType(TokenType.CHRCON)) {
            Ast.Character character = new Ast.Character(tokens.consume(TokenType.CHRCON));
            return new Ast.PrimaryExp(character);
        } else {
            // warning: return 后没有;会到这
            return null;
        }
    }

    //LVal → Ident {'[' Exp ']'}
    private Ast.LVal parseLVal() {
        Token ident = tokens.consume(TokenType.IDENFR);
        ArrayList<Ast.Exp> exps = new ArrayList<>();
        while (tokens.consume(TokenType.LBRACK) != null) {
            exps.add(parseExp());
            Logger.logger.check(tokens.consume(TokenType.RBRACK), tokens.getLast().getLine() + " " + "k");
        }
        return new Ast.LVal(ident, exps);
    }

    // FuncCall → Ident '(' [FuncRParams] ')'
    private Ast.FuncCall parseFuncCall() {
        Token ident = tokens.consume(TokenType.IDENFR);
        tokens.consume(TokenType.LPARENT);
        ArrayList<Ast.Exp> params = new ArrayList<>();
        if (tokens.isType(TokenType.INTCON, TokenType.CHRCON, TokenType.IDENFR, TokenType.LPARENT, TokenType.PLUS, TokenType.MINU, TokenType.NOT)) {
            do {
                params.add(parseExp());
            } while (tokens.consume(TokenType.COMMA) != null);
        }
        Logger.logger.check(tokens.consume(TokenType.RPARENT), tokens.getLast().getLine() + " " + "j");
        return new Ast.FuncCall(ident, params);
    }

    //FuncDef → FuncType Ident '(' [FuncFParams] ')' Block
    private Ast.FuncDef parseFuncDef() {
        TokenType type = tokens.consume(TokenType.VOIDTK, TokenType.INTTK, TokenType.CHARTK).getType();
        Token ident = tokens.consume(TokenType.IDENFR, TokenType.MAINTK);
        tokens.consume(TokenType.LPARENT);
        ArrayList<Ast.FuncFParam> params = new ArrayList<>();
        // btype
        if (tokens.isType(TokenType.INTTK, TokenType.CHARTK)) {
            do {
                params.add(parseFuncFParam());
            } while (tokens.consume(TokenType.COMMA) != null);
        }
        Logger.logger.check(tokens.consume(TokenType.RPARENT), tokens.getLast().getLine() + " " + "j");
        Ast.Block block = parseBlock();
        return new Ast.FuncDef(type, ident, params, block);
    }

    // FuncFParam → BType Ident ['[' ']']
    public Ast.FuncFParam parseFuncFParam() {
        TokenType type = tokens.consume(TokenType.INTTK, TokenType.CHARTK).getType();
        Token ident = tokens.consume(TokenType.IDENFR);
        if (tokens.consume(TokenType.LBRACK) != null) {
            Logger.logger.check(tokens.consume(TokenType.RBRACK), tokens.getLast().getLine() + " " + "k");
            return new Ast.FuncFParam(type, ident, true);
        }
        return new Ast.FuncFParam(type, ident, false);
    }

    // Block → '{' { BlockItem } '}'
    private Ast.Block parseBlock() {
        tokens.consume(TokenType.LBRACE);
        ArrayList<Ast.BlockItem> items = new ArrayList<>();
        while (!tokens.isType(TokenType.RBRACE)) {
            items.add(parseBlockItem());
        }
        tokens.consume(TokenType.RBRACE);
        return new Ast.Block(items);
    }

    //  BlockItem → Decl | Stmt
    private Ast.BlockItem parseBlockItem() {
        TokenType tokenType = tokens.get().getType();
        if (tokenType.equals(TokenType.CHARTK) || tokenType.equals(TokenType.INTTK) || tokenType.equals(TokenType.CONSTTK)) {
            return new Ast.BlockItem(parseDecl());
        } else {
            return new Ast.BlockItem(parseStmt());
        }
    }

    // Stmt → AssignStmt | ExpStmt | Block | IfStmt | ForStmt | BreakStmt | ReturnStmt | GetStmt | PrintStmt
    private Ast.Stmt parseStmt() {
        TokenType stmtType = tokens.get().getType();
        Ast.Cond cond;
        switch (stmtType) {
            case IDENFR:
            case LPARENT:
            case MAINTK:
            case INTCON:
            case STRCON:
            case PLUS:
            case MINU:
            case NOT:
            case GETCHARTK:
            case GETINTTK:
            case CHRCON:
                Ast.Exp exp = parseExp();
                // AssignStmt → LVal '=' Exp ';'
                if (tokens.get().getType() == TokenType.ASSIGN) {
                    Ast.LVal lval = exp.getLVal();
                    tokens.consume(TokenType.ASSIGN);
                    // GetStmt | PrintStmt → LVal '=' 'getint''('')'';' | LVal '=' 'getchar''('')'';'
                    if (tokens.isType(TokenType.GETINTTK, TokenType.GETCHARTK)) {
                        TokenType type = tokens.consume().getType();
                        tokens.consume(TokenType.LPARENT);
                        Logger.logger.check(tokens.consume(TokenType.RPARENT), tokens.getLast().getLine() + " " + "j");
                        Logger.logger.check(tokens.consume(TokenType.SEMICN), tokens.getLast().getLine() + " " + "i");
                        return new Ast.GetStmt(lval, type);
                    }
                    tokens.consume(TokenType.ASSIGN);
                    Ast.Exp e = parseExp();
                    Logger.logger.check(tokens.consume(TokenType.SEMICN), tokens.getLast().getLine() + " " + "i");
                    return new Ast.AssignStmt(lval, e, false);
                } else {
                    // ExpStmt → Exp ';'
                    Logger.logger.check(tokens.consume(TokenType.SEMICN), tokens.getLast().getLine() + " " + "i");
                    return new Ast.ExpStmt(exp);
                }
            case LBRACE:
                // Block → '{' { BlockItem } '}'
                return new Ast.BlockStmt(parseBlock());
            case IFTK:
                // IfStmt → 'if' '(' Cond ')' Stmt ['else' Stmt]
                tokens.consume(TokenType.IFTK);
                tokens.consume(TokenType.LPARENT);
                cond = parseCond();
                Logger.logger.check(tokens.consume(TokenType.RPARENT), tokens.getLast().getLine() + " " + "j");
                Ast.Stmt thenStmt = parseStmt();
                Ast.Stmt elseStmt = null;
                if (tokens.consume(TokenType.ELSETK) != null) {
                    elseStmt = parseStmt();
                }
                return new Ast.IfStmt(cond, thenStmt, elseStmt);
            case FORTK:
                // ForStmt -> 'for' '(' [AssignStmt] ';' [Cond] ';' [AssignStmt] ')' Stmt
                tokens.consume(TokenType.FORTK);
                tokens.consume(TokenType.LPARENT);
                Ast.AssignStmt init = null;
                if (!tokens.isType(TokenType.SEMICN)) {
                    init = parseAssignStmt(true);
                }
                tokens.consume(TokenType.SEMICN);
                Ast.Cond c = null;
                if (!tokens.isType(TokenType.SEMICN)) {
                    c = parseCond();
                }
                tokens.consume(TokenType.SEMICN);
                Ast.AssignStmt update = null;
                if (tokens.isType(TokenType.IDENFR)) {
                    update = parseAssignStmt(true);
                }
                Logger.logger.check(tokens.consume(TokenType.RPARENT), tokens.getLast().getLine() + " " + "j");
                Ast.Stmt body = parseStmt();
                return new Ast.ForStmt(init, c, update, body);
            case BREAKTK:
                // BreakStmt → 'break' ';'
                tokens.consume(TokenType.BREAKTK);
                Logger.logger.check(tokens.consume(TokenType.SEMICN), tokens.getLast().getLine() + " " + "i");
                return new Ast.BreakStmt();
            case CONTINUETK:
                // ContinueStmt → 'continue' ';'
                tokens.consume(TokenType.CONTINUETK);
                Logger.logger.check(tokens.consume(TokenType.SEMICN), tokens.getLast().getLine() + " " + "i");
                return new Ast.ContinueStmt();
            case RETURNTK:
                // ReturnStmt → 'return' [Exp] ';'
                tokens.consume(TokenType.RETURNTK);
                Ast.Exp value = null;
                if (!tokens.isType(TokenType.SEMICN)) {
                    value = parseExp();
                }
                Logger.logger.check(tokens.consume(TokenType.SEMICN), tokens.getLast().getLine() + " " + "i");
                return new Ast.ReturnStmt(value);
            case PRINTFTK:
                // 'printf''('StringConst {','Exp}')'';'
                tokens.consume(TokenType.PRINTFTK);
                tokens.consume(TokenType.LPARENT);
                Token format = tokens.consume(TokenType.STRCON);
                ArrayList<Ast.Exp> exps = new ArrayList<>();
                while (tokens.consume(TokenType.COMMA) != null) {
                    exps.add(parseExp());
                }
                Logger.logger.check(tokens.consume(TokenType.RPARENT), tokens.getLast().getLine() + " " + "j");
                Logger.logger.check(tokens.consume(TokenType.SEMICN), tokens.getLast().getLine() + " " + "i");
                return new Ast.PrintStmt(format, exps);
            case SEMICN:
                // NoStmt → ';'
                tokens.consume();
                return new Ast.ExpStmt(null);
            default:
                System.out.print("errorStmt");
                return null;
        }
    }

    // AssignStmt → LVal '=' Exp
    private Ast.AssignStmt parseAssignStmt(boolean isFor) {
        Ast.LVal lval = parseLVal();
        tokens.consume(TokenType.ASSIGN);
        Ast.Exp exp = parseExp();
        return new Ast.AssignStmt(lval, exp, isFor);
    }

    public Ast.Cond parseCond() {
        return new Ast.Cond(parseLOrExp());
    }

    // LAndExp | LOrExp '||' LAndExp
    public Ast.LOrExp parseLOrExp() {
        ArrayList<Ast.LAndExp> lAndExps = new ArrayList<>();
        ArrayList<TokenType> ops = new ArrayList<>();
        lAndExps.add(parseLAndExp());
        while (tokens.isType(TokenType.OR)) {
            ops.add(tokens.consume().getType());
            lAndExps.add(parseLAndExp());
        }
        return new Ast.LOrExp(lAndExps, ops);
    }

    //  LAndExp → EqExp | LAndExp '&&' EqExp
    public Ast.LAndExp parseLAndExp() {
        ArrayList<Ast.EqExp> eqExps = new ArrayList<>();
        ArrayList<TokenType> ops = new ArrayList<>();
        eqExps.add(parseEqExp());
        while (tokens.isType(TokenType.AND)) {
            ops.add(tokens.consume().getType());
            eqExps.add(parseEqExp());
        }
        return new Ast.LAndExp(eqExps, ops);
    }

    //EqExp → RelExp | EqExp ('==' | '!=') RelExp
    public Ast.EqExp parseEqExp() {
        ArrayList<Ast.RelExp> relExps = new ArrayList<>();
        ArrayList<TokenType> ops = new ArrayList<>();
        relExps.add(parseRelExp());
        while (tokens.isType(TokenType.EQL, TokenType.NEQ)) {
            ops.add(tokens.consume().getType());
            relExps.add(parseRelExp());
        }
        return new Ast.EqExp(relExps, ops);
    }

    // RelExp → AddExp | RelExp ('<' | '<=' | '>' | '>=') AddExp
    public Ast.RelExp parseRelExp() {
        ArrayList<Ast.AddExp> addExps = new ArrayList<>();
        ArrayList<TokenType> ops = new ArrayList<>();
        addExps.add(parseAddExp());
        while (tokens.isType(TokenType.LSS, TokenType.LEQ, TokenType.GRE, TokenType.GEQ)) {
            ops.add(tokens.consume().getType());
            addExps.add(parseAddExp());
        }
        return new Ast.RelExp(addExps, ops);
    }

}
