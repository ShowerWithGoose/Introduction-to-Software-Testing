package frontend;

import frontend.AST.AST;
import frontend.AST.CompUnit;
import frontend.AST.Decl.*;
import frontend.AST.Exp.Character;
import frontend.AST.Exp.Number;
import frontend.AST.Exp.*;
import frontend.AST.Func.*;
import frontend.AST.Stmt.*;
import frontend.Error.ErrorItem;
import util.Logger;

import java.util.ArrayList;

public class Parser {
    private final TokenList tokens;
    private TryParser tryParser;

    public Parser(TokenList tokens) {
        this.tokens = tokens;
        tryParser = new TryParser(tokens);
    }

    public void parser() {
        ArrayList<CompUnit> compUnits = new ArrayList<>();
        while (tokens.hasNext()) {
            compUnits.add(parseCompUnit());
        }
        AST.ast.setCompUnits(compUnits);
        return;
    }

    // CompUnit → {Decl} {FuncDef} MainFuncDef
    public CompUnit parseCompUnit() {
        ArrayList<Decl> decls = new ArrayList<>();
        ArrayList<FuncDef> funcDefs = new ArrayList<>();
        MainFuncDef mainFuncDef = null;
        while (tokens.hasNext()) {
            if (tokens.get().isOf(TokenType.INTTK, TokenType.CHARTK, TokenType.CONSTTK)
                    && !tokens.ahead(2).isOf(TokenType.LPARENT)) {
                decls.add(parseDecl());
            } else if (tokens.ahead(1).isOf(TokenType.MAINTK)) {
                mainFuncDef = parseMainFuncDef();
            } else {
                funcDefs.add(parseFuncDef());
            }
        }
        return new CompUnit(decls, funcDefs, mainFuncDef);
    }

    // Decl → ConstDecl | VarDecl
    public Decl parseDecl() {
        if (tokens.get().isOf(TokenType.CONSTTK)) {
            return new Decl(parseConstDecl());
        } else {
            return new Decl(parseVarDecl());
        }
    }

    // ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';' // i
    public ConstDecl parseConstDecl() {
        tokens.consumeExpect(TokenType.CONSTTK);
        BType bType = parseBType();
        ArrayList<ConstDef> constDefs = new ArrayList<>();
        do {
            constDefs.add(parseConstDef());
        } while (tokens.consumeExpect(TokenType.COMMA) != null);
        Logger.logger.check(tokens.consumeExpect(TokenType.SEMICN), new ErrorItem(tokens.getBefore().getLineNum(), "i", "ConstDecl中缺少;"));
        return new ConstDecl(bType, constDefs);
    }

    // BType → 'int' | 'char'
    private BType parseBType() {
        return new BType(tokens.consumeExpect(TokenType.INTTK, TokenType.CHARTK));
    }

    // ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal // k
    private ConstDef parseConstDef() {
        Token ident = tokens.consumeExpect(TokenType.IDENFR);
        if (tokens.consumeExpect(TokenType.LBRACK) != null) {
            ConstExp constExp = parseConstExp();
            Logger.logger.check(tokens.consumeExpect(TokenType.RBRACK), new ErrorItem(tokens.getBefore().getLineNum(), "k", "ConstDef中缺少]"));
            tokens.consumeExpect(TokenType.ASSIGN);
            ConstInitVal constInitVal = parseConstInitVal();
            return new ConstDef(ident, constExp, constInitVal);
        } else {
            tokens.consumeExpect(TokenType.ASSIGN);
            ConstInitVal constInitVal = parseConstInitVal();
            return new ConstDef(ident, constInitVal);
        }
    }

    // ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
    private ConstInitVal parseConstInitVal() {
        if (tokens.get().isOf(TokenType.LBRACE)) {
            tokens.consume();
            ArrayList<ConstExp> constExps = new ArrayList<>();
            if (!tokens.get().isOf(TokenType.RBRACE)) {
                constExps.add(parseConstExp());
                while (tokens.consumeExpect(TokenType.COMMA) != null) {
                    constExps.add(parseConstExp());
                }
            }
            Logger.logger.check(tokens.consumeExpect(TokenType.RBRACE), new ErrorItem(tokens.getBefore().getLineNum(), "k", "ConstInitVal中缺少}"));
            return new ConstInitVal(constExps);
        } else if (tokens.get().isOf(TokenType.STRCON)) {
            return new ConstInitVal(tokens.consume());
        } else {
            return new ConstInitVal(parseConstExp());
        }
    }

    // VarDecl → BType VarDef { ',' VarDef } ';' // i
    private VarDecl parseVarDecl() {
        BType bType = parseBType();
        ArrayList<VarDef> varDefs = new ArrayList<>();
        do {
            varDefs.add(parseVarDef());
        } while (tokens.consumeExpect(TokenType.COMMA) != null);
        Logger.logger.check(tokens.consumeExpect(TokenType.SEMICN), new ErrorItem(tokens.getBefore().getLineNum(), "i", "VarDecl中缺少;"));
        return new VarDecl(bType, varDefs);
    }

    // VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal // k
    private VarDef parseVarDef() {
        Token ident = tokens.consumeExpect(TokenType.IDENFR);
        if (tokens.consumeExpect(TokenType.LBRACK) != null) {
            ConstExp constExp = parseConstExp();
            Logger.logger.check(tokens.consumeExpect(TokenType.RBRACK), new ErrorItem(tokens.getBefore().getLineNum(), "k", "VarDef中缺少]"));
            if (tokens.consumeExpect(TokenType.ASSIGN) != null) {
                InitVal initVal = parseInitVal();
                return new VarDef(ident, constExp, initVal);
            } else {
                return new VarDef(ident, constExp);
            }
        } else {
            if (tokens.consumeExpect(TokenType.ASSIGN) != null) {
                InitVal initVal = parseInitVal();
                return new VarDef(ident, initVal);
            } else {
                return new VarDef(ident);
            }
        }
    }

    // InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
    private InitVal parseInitVal() {
        if (tokens.get().isOf(TokenType.LBRACE)) {
            tokens.consume();
            ArrayList<Exp> exps = new ArrayList<>();
            if (!tokens.get().isOf(TokenType.RBRACE)) {
                exps.add(parseExp());
                while (tokens.consumeExpect(TokenType.COMMA) != null) {
                    exps.add(parseExp());
                }
            }
            Logger.logger.check(tokens.consumeExpect(TokenType.RBRACE), new ErrorItem(tokens.getBefore().getLineNum(), "k", "InitVal中缺少}"));
            return new InitVal(exps);
        } else if (tokens.get().isOf(TokenType.STRCON)) {
            return new InitVal(tokens.consume());
        } else {
            return new InitVal(parseExp());
        }
    }

    //FuncDef → FuncType Ident '(' [FuncFParams] ')' Block // j
    // Block 的First一定是 {
    private FuncDef parseFuncDef() {
        FuncType funcType = parseFuncType();
        Token ident = tokens.consumeExpect(TokenType.IDENFR);
        tokens.consumeExpect(TokenType.LPARENT);
        if (tokens.get().isOf(TokenType.RPARENT)) {
            tokens.consume();
            Block body = parseBlock();
            return new FuncDef(funcType, ident, body);
        } else {
            if (tokens.get().isOf(TokenType.LBRACE)) {
                Logger.logger.error(new ErrorItem(tokens.getBefore().getLineNum(), "j", "FuncDef中缺少)"));
                Block body = parseBlock();
                return new FuncDef(funcType, ident, body);
            } else {
                FuncFParams funcFParams = parseFuncFParams();
                Logger.logger.check(tokens.consumeExpect(TokenType.RPARENT), new ErrorItem(tokens.getBefore().getLineNum(), "j", "FuncDef中缺少)"));
                Block body = parseBlock();
                return new FuncDef(funcType, ident, funcFParams, body);
            }
        }

    }

    //MainFuncDef → 'int' 'main' '(' ')' Block // j
    private MainFuncDef parseMainFuncDef() {
        tokens.consumeExpect(TokenType.INTTK);
        tokens.consumeExpect(TokenType.MAINTK);
        tokens.consumeExpect(TokenType.LPARENT);
        Logger.logger.check(tokens.consumeExpect(TokenType.RPARENT), new ErrorItem(tokens.getBefore().getLineNum(), "j", "MainFuncDef中缺少)"));
        Block body = parseBlock();
        return new MainFuncDef(body);
    }

    // FuncType → 'void' | 'int' | 'char'
    private FuncType parseFuncType() {
        return new FuncType(tokens.consumeExpect(TokenType.VOIDTK, TokenType.INTTK, TokenType.CHARTK));
    }

    // FuncFParams → FuncFParam { ',' FuncFParam }
    private FuncFParams parseFuncFParams() {
        ArrayList<FuncFParam> funcFParams = new ArrayList<>();
        do {
            funcFParams.add(parseFuncFParam());
        } while (tokens.consumeExpect(TokenType.COMMA) != null);
        return new FuncFParams(funcFParams);
    }

    // FuncFParam → BType Ident ['[' ']'] // k
    private FuncFParam parseFuncFParam() {
        BType bType = parseBType();
        Token ident = tokens.consumeExpect(TokenType.IDENFR);
        if (tokens.consumeExpect(TokenType.LBRACK) != null) {
            Logger.logger.check(tokens.consumeExpect(TokenType.RBRACK), new ErrorItem(tokens.getBefore().getLineNum(), "k", "FuncFParam中缺少]"));
            return new FuncFParam(bType, ident, true);
        } else {
            return new FuncFParam(bType, ident, false);
        }
    }

    // Block → '{' { BlockItem } '}'
    private Block parseBlock() {
        tokens.consumeExpect(TokenType.LBRACE);
        ArrayList<BlockItem> blockItems = new ArrayList<>();
        while (!tokens.get().isOf(TokenType.RBRACE)) {
            blockItems.add(parseBlockItem());
        }
        tokens.consumeExpect(TokenType.RBRACE);
        return new Block(blockItems);
    }

    // BlockItem → Decl | Stmt
    private BlockItem parseBlockItem() {
        if (tokens.get().isOf(TokenType.INTTK, TokenType.CHARTK, TokenType.CONSTTK)) {
            return new BlockItem(parseDecl());
        } else {
            return new BlockItem(parseStmt());
        }
    }

    // Stmt → LVal '=' Exp ';' // i
    //      | [Exp] ';' // i
    //      | Block
    //      | 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // j
    //      | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
    //      | 'break' ';' | 'continue' ';' // i
    //      | 'return' [Exp] ';' // i
    //      | LVal '=' 'getint''('')'';' // i j
    //      | LVal '=' 'getchar''('')'';' // i j
    //      | 'printf''('StringConst {','Exp}')'';' // i j
    private Stmt parseStmt() {
        Token token = tokens.get();
        switch (token.getType()) {
            case LBRACE:
                return parseBlockStmt();
            case IFTK:
                tokens.consume();
                tokens.consumeExpect(TokenType.LPARENT);
                Cond ifCond = parseCond();
                Logger.logger.check(tokens.consumeExpect(TokenType.RPARENT), new ErrorItem(tokens.getBefore().getLineNum(), "j", "IfStmt中缺少)"));
                Stmt stmt1 = parseStmt();
                if (tokens.consumeExpect(TokenType.ELSETK) != null) {
                    Stmt stmt2 = parseStmt();
                    return new IfStmt(ifCond, stmt1, stmt2);
                } else {
                    return new IfStmt(ifCond, stmt1);
                }
            case FORTK:
                tokens.consume();
                tokens.consumeExpect(TokenType.LPARENT);
                ForStmt forStmt1 = null;
                Cond forCond = null;
                ForStmt forStmt2 = null;
                if (tokens.get().isOf(TokenType.SEMICN)) {
                    tokens.consume();
                } else {
                    forStmt1 = parseForStmt();
                    tokens.consumeExpect(TokenType.SEMICN);
                }
                if (tokens.get().isOf(TokenType.SEMICN)) {
                    tokens.consume();
                } else {
                    forCond = parseCond();
                    tokens.consumeExpect(TokenType.SEMICN);
                }
                if (tokens.get().isOf(TokenType.RPARENT)) {
                    tokens.consume();
                } else {
                    forStmt2 = parseForStmt();
                    tokens.consumeExpect(TokenType.RPARENT);
                }
                Stmt stmt = parseStmt();
                return new For(forStmt1, forCond, forStmt2, stmt);
            case BREAKTK:
                tokens.consume();
                Logger.logger.check(tokens.consumeExpect(TokenType.SEMICN), new ErrorItem(tokens.getBefore().getLineNum(), "i", "BreakStmt中缺少;"));
                return new BreakStmt();
            case CONTINUETK:
                tokens.consume();
                Logger.logger.check(tokens.consumeExpect(TokenType.SEMICN), new ErrorItem(tokens.getBefore().getLineNum(), "i", "ContinueStmt中缺少;"));
                return new ContinueStmt();
            case PRINTFTK:  //'printf''('StringConst {','Exp}')'';' // i j
                tokens.consume();
                tokens.consumeExpect(TokenType.LPARENT);
                Token stringConst = tokens.consumeExpect(TokenType.STRCON);
                ArrayList<Exp> exps = new ArrayList<>();
                while (tokens.get().isOf(TokenType.COMMA)) {
                    tokens.consume();
                    exps.add(parseExp());
                }
                Logger.logger.check(tokens.consumeExpect(TokenType.RPARENT), new ErrorItem(tokens.getBefore().getLineNum(), "j", "PrintStmt中缺少)"));
                Logger.logger.check(tokens.consumeExpect(TokenType.SEMICN), new ErrorItem(tokens.getBefore().getLineNum(), "i", "PrintStmt中缺少;"));
                return new PrintStmt(stringConst, exps);
            case RETURNTK:
                tokens.consume();
                if (tokens.get().isOf(TokenType.SEMICN)) {
                    tokens.consume();
                    return new ReturnStmt();
                } else {
                    int index = tokens.getIndex();
                    Exp exp = tryParser.tryParseExp();
                    if (exp == null) {
                        tokens.setIndex(index);
                        Logger.logger.error(new ErrorItem(tokens.getBefore().getLineNum(), "i", "ReturnStmt中缺少;"));
                        return new ReturnStmt();
                    } else {
                        if (tokens.get().isOf(TokenType.ASSIGN)) {
                            tokens.setIndex(index);
                            Logger.logger.error(new ErrorItem(tokens.getBefore().getLineNum(), "i", "ReturnStmt中缺少分号"));
                            return new ReturnStmt();
                        } else {
                            tokens.setIndex(index);
                            exp = parseExp();
                            Logger.logger.check(tokens.consumeExpect(TokenType.SEMICN), new ErrorItem(tokens.getBefore().getLineNum(), "i", "ReturnStmt中缺少;"));
                            return new ReturnStmt(exp);
                        }
                    }
                }
            default:
                int index = tokens.getIndex();
                Exp exp = tryParser.tryParseExp();
                if (tokens.get().isOf(TokenType.ASSIGN)) {
                    tokens.setIndex(index);
                    LVal lVal = parseLVal();
                    tokens.consumeExpect(TokenType.ASSIGN);
                    if (tokens.get().isOf(TokenType.GETINTTK, TokenType.GETCHARTK)) {
                        Token get = tokens.consume();
                        tokens.consumeExpect(TokenType.LPARENT);
                        Logger.logger.check(tokens.consumeExpect(TokenType.RPARENT), new ErrorItem(tokens.getBefore().getLineNum(), "j", "Stmt中缺少)"));
                        Logger.logger.check(tokens.consumeExpect(TokenType.SEMICN), new ErrorItem(tokens.getBefore().getLineNum(), "i", "Stmt中缺少;"));
                        return new GetStmt(lVal, get);
                    }
                    exp = parseExp();
                    Logger.logger.check(tokens.consumeExpect(TokenType.SEMICN), new ErrorItem(tokens.getBefore().getLineNum(), "i", "Stmt中缺少;"));
                    return new AssignStmt(lVal, exp);
                } else if (exp != null) {
                    tokens.setIndex(index);
                    exp = parseExp();
                    Logger.logger.check(tokens.consumeExpect(TokenType.SEMICN), new ErrorItem(tokens.getBefore().getLineNum(), "i", "Stmt中缺少;"));
                    return new ExpStmt(exp);
                } else {
                    Logger.logger.check(tokens.consumeExpect(TokenType.SEMICN), new ErrorItem(tokens.getBefore().getLineNum(), "i", "Stmt中缺少;"));
                    return new ExpStmt();
                }
        }
    }

    private BlockStmt parseBlockStmt() {
        return new BlockStmt(parseBlock());
    }

    // ForStmt → LVal '=' Exp
    private ForStmt parseForStmt() {
        LVal lVal = parseLVal();
        tokens.consumeExpect(TokenType.ASSIGN);
        Exp exp = parseExp();
        return new ForStmt(lVal, exp);
    }

    // Exp → AddExp
    private Exp parseExp() {
        return new Exp(parseAddExp());
    }

    //  Cond → LOrExp
    private Cond parseCond() {
        return new Cond(parseLOrExp());
    }

    // LVal → Ident ['[' Exp ']'] // k
    private LVal parseLVal() {
        Token ident = tokens.consumeExpect(TokenType.IDENFR);
        if (tokens.consumeExpect(TokenType.LBRACK) != null) {
            Exp exp = parseExp();
            Logger.logger.check(tokens.consumeExpect(TokenType.RBRACK), new ErrorItem(tokens.getBefore().getLineNum(), "k", "LVal中缺少]"));
            return new LVal(ident, exp);
        } else {
            return new LVal(ident);
        }
    }

    // PrimaryExp → '(' Exp ')' | LVal | Number | Character// j
    private PrimaryExp parsePrimaryExp() {
        if (tokens.consumeExpect(TokenType.LPARENT) != null) {
            Exp exp = parseExp();
            Logger.logger.check(tokens.consumeExpect(TokenType.RPARENT), new ErrorItem(tokens.getBefore().getLineNum(), "j", "PrimaryExp中缺少)"));
            return new PrimaryExp(exp);
        } else if (tokens.get().isOf(TokenType.IDENFR)) {
            return new PrimaryExp(parseLVal());
        } else if (tokens.get().isOf(TokenType.INTCON)) {
            return new PrimaryExp(parseNumber());
        } else {
            return new PrimaryExp(parseCharacter());
        }
    }

    // Number → IntConst
    private Number parseNumber() {
        return new Number(tokens.consumeExpect(TokenType.INTCON));
    }

    // Character → CharConst
    private Character parseCharacter() {
        return new Character(tokens.consumeExpect(TokenType.CHRCON));
    }

    // UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp // j
    private UnaryExp parseUnaryExp() {
        if (tokens.get().isOf(TokenType.IDENFR)) {
            if (tokens.ahead(1).isOf(TokenType.LPARENT)) {
                Token ident = tokens.consumeExpect(TokenType.IDENFR);
                tokens.consumeExpect(TokenType.LPARENT);

                if (tokens.get().isOf(TokenType.RPARENT)) {
                    tokens.consume();
                    return new UnaryExp(ident);
                } else {
                    int index = tokens.getIndex();
                    Exp exp = tryParser.tryParseExp();
                    if (exp == null) {
                        Logger.logger.error(new ErrorItem(tokens.getBefore().getLineNum(), "j", "UnaryExp中缺少)"));
                        return new UnaryExp(ident);
                    } else {
                        if (tokens.get().isOf(TokenType.ASSIGN)) {
                            tokens.setIndex(index);
                            Logger.logger.error(new ErrorItem(tokens.getBefore().getLineNum(), "j", "UnaryExp中缺少)"));
                            return new UnaryExp(ident);
                        } else {
                            tokens.setIndex(index);
                            FuncRParams funcRParams = parseFuncRParams();
                            Logger.logger.check(tokens.consumeExpect(TokenType.RPARENT), new ErrorItem(tokens.getBefore().getLineNum(), "j", "UnaryExp中缺少)"));
                            return new UnaryExp(ident, funcRParams);
                        }
                    }
                }
            } else {
                return new UnaryExp(parsePrimaryExp());
            }
        } else if (tokens.get().isOf(TokenType.LPARENT, TokenType.INTCON, TokenType.CHRCON)) {
            return new UnaryExp(parsePrimaryExp());
        } else {
            UnaryOp unaryOp = parseUnaryOp();
            UnaryExp unaryExp = parseUnaryExp();
            return new UnaryExp(unaryOp, unaryExp);
        }
    }

    // UnaryOp → '+' | '−' | '!' 注：'!'仅出现在条件表达式中
    private UnaryOp parseUnaryOp() {
        return new UnaryOp(tokens.consumeExpect(TokenType.PLUS, TokenType.MINU, TokenType.NOT));
    }

    // FuncRParams → Exp { ',' Exp }
    private FuncRParams parseFuncRParams() {
        ArrayList<Exp> exps = new ArrayList<>();
        do {
            exps.add(parseExp());
        } while (tokens.consumeExpect(TokenType.COMMA) != null);
        return new FuncRParams(exps);
    }

    // MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
    private MulExp parseMulExp() {
        ArrayList<UnaryExp> unaryExps = new ArrayList<>();
        ArrayList<Token> ops = new ArrayList<>();
        unaryExps.add(parseUnaryExp());
        while (tokens.get().isOf(TokenType.MULT, TokenType.DIV, TokenType.MOD)) {
            ops.add(tokens.consume());
            unaryExps.add(parseUnaryExp());
        }
        return new MulExp(unaryExps, ops);
    }

    // AddExp → MulExp | AddExp ('+' | '−') MulExp
    private AddExp parseAddExp() {
        ArrayList<MulExp> mulExps = new ArrayList<>();
        ArrayList<Token> ops = new ArrayList<>();
        mulExps.add(parseMulExp());
        while (tokens.get().isOf(TokenType.PLUS, TokenType.MINU)) {
            ops.add(tokens.consume());
            mulExps.add(parseMulExp());
        }
        return new AddExp(mulExps, ops);
    }

    // RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
    private RelExp parseRelExp() {
        ArrayList<AddExp> addExps = new ArrayList<>();
        ArrayList<Token> ops = new ArrayList<>();
        addExps.add(parseAddExp());
        while (tokens.get().isOf(TokenType.LSS, TokenType.GRE, TokenType.LEQ, TokenType.GEQ)) {
            ops.add(tokens.consume());
            addExps.add(parseAddExp());
        }
        return new RelExp(addExps, ops);
    }

    // EqExp → RelExp | EqExp ('==' | '!=') RelExp
    private EqExp parseEqExp() {
        ArrayList<RelExp> relExps = new ArrayList<>();
        ArrayList<Token> ops = new ArrayList<>();
        relExps.add(parseRelExp());
        while (tokens.get().isOf(TokenType.EQL, TokenType.NEQ)) {
            ops.add(tokens.consume());
            relExps.add(parseRelExp());
        }
        return new EqExp(relExps, ops);
    }

    // LAndExp → EqExp | LAndExp '&&' EqExp
    private LAndExp parseLAndExp() {
        ArrayList<EqExp> eqExps = new ArrayList<>();
        ArrayList<Token> ops = new ArrayList<>();
        eqExps.add(parseEqExp());
        while (tokens.get().isOf(TokenType.AND)) {
            ops.add(tokens.consume());
            eqExps.add(parseEqExp());
        }
        return new LAndExp(eqExps, ops);
    }

    // LOrExp → LAndExp | LOrExp '||' LAndExp
    private LOrExp parseLOrExp() {
        ArrayList<LAndExp> lAndExps = new ArrayList<>();
        ArrayList<Token> ops = new ArrayList<>();
        lAndExps.add(parseLAndExp());
        while (tokens.get().isOf(TokenType.OR)) {
            ops.add(tokens.consume());
            lAndExps.add(parseLAndExp());
        }
        return new LOrExp(lAndExps, ops);
    }

    // ConstExp → AddExp 注：使用的 Ident 必须是常量
    private ConstExp parseConstExp() {
        return new ConstExp(parseAddExp());
    }
}
