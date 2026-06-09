import lexer.LexType;
import logger.Logger;
import syntax.*;
import syntax.Character;
import syntax.Number;

import java.util.ArrayList;
import java.util.Arrays;

public class Parser {
    private final Lexer lexer;

    public Parser(Lexer lexer) {
        this.lexer = lexer;
    }

    public CompUnit parseCompUnit() {
        lexer.next();

        ArrayList<Decl> decls = new ArrayList<>();
        boolean hasDecl;
        do {
            hasDecl = false;
            if (lexer.getLexType() == LexType.CONSTTK) {
                decls.add(parseDecl());
                hasDecl = true;
            } else {
                lexer.nextNoPrint();
                lexer.nextNoPrint();
                if (lexer.getLexType() != LexType.LPARENT) {
                    lexer.prev();
                    lexer.prev();
                    decls.add(parseDecl());
                    hasDecl = true;
                } else {
                    lexer.prev();
                    lexer.prev();
                }
            }
        } while (hasDecl);

        ArrayList<FuncDef> funcDefs = new ArrayList<>();
        boolean hasFuncDef;
        do {
            hasFuncDef = false;
            lexer.nextNoPrint();
            if (lexer.getLexType() != LexType.MAINTK) {
                lexer.prev();
                funcDefs.add(parseFuncDef());
                hasFuncDef = true;
            } else {
                lexer.prev();
            }
        } while (hasFuncDef);

        MainFuncDef mainFuncDef = parseMainFuncDef();
        return new CompUnit(decls.toArray(new Decl[0]), funcDefs.toArray(new FuncDef[0]), mainFuncDef);
    }

    public Decl parseDecl() {
        if (Arrays.asList(ConstDecl.FIRST).contains(lexer.getLexType())) {
            // ConstDecl
            ConstDecl constDecl = parseConstDecl();
            return new Decl(constDecl);
        } else {
            // VarDecl
            VarDecl varDecl = parseVarDecl();
            return new Decl(varDecl);
        }
    }

    public ConstDecl parseConstDecl() {
        lexer.next(); // CONSTTK
        BType bType = parseBType();
        ArrayList<ConstDef> constDefs = new ArrayList<>();
        constDefs.add(parseConstDef());
        while (lexer.getLexType() == LexType.COMMA) {
            lexer.next();
            constDefs.add(parseConstDef());
        }
        if (lexer.getLexType() == LexType.SEMICN) {
            lexer.next(); // SEMICN
        } else {
            Logger.logBad(lexer.getPrevLineno() + " i\n");
        }
        return new ConstDecl(bType, constDefs.toArray(new ConstDef[0]));
    }

    public BType parseBType() {
        LexType lexType = lexer.getLexType();
        lexer.next();
        return new BType(lexType);
    }

    public ConstDef parseConstDef() {
        String name = lexer.getToken();
        lexer.next(); // IDENFR
        ConstExp constExp = null;
        if (lexer.getLexType() == LexType.LBRACK) {
            lexer.next(); // LBRACK
            constExp = parseConstExp();
            if (lexer.getLexType() == LexType.RBRACK) {
                lexer.next(); // RBRACK
            } else {
                Logger.logBad(lexer.getPrevLineno() + " k\n");
            }
        }
        lexer.next(); // ASSIGN
        ConstInitVal constInitVal = parseConstInitVal();
        return new ConstDef(name, constExp, constInitVal);
    }

    public ConstInitVal parseConstInitVal() {
        if (lexer.getLexType() == LexType.LBRACE) {
            // '{' [ ConstExp { ',' ConstExp } ] '}'
            lexer.next(); // LBRACE
            ArrayList<ConstExp> constExps = new ArrayList<>();
            if (lexer.getLexType() != LexType.RBRACE) {
                constExps.add(parseConstExp());
                while (lexer.getLexType() == LexType.COMMA) {
                    lexer.next(); // COMMA
                    constExps.add(parseConstExp());
                }
            }
            lexer.next(); // RBRACE
            return new ConstInitVal(constExps.toArray(new ConstExp[0]));
        } else if (lexer.getLexType() == LexType.STRCON) {
            // STRCON
            String string = lexer.getToken();
            lexer.next(); // STRCON
            return new ConstInitVal(string);
        } else {
            // Exp
            return new ConstInitVal(parseConstExp());
        }
    }

    public VarDecl parseVarDecl() {
        BType bType = parseBType();
        ArrayList<VarDef> varDefs = new ArrayList<>();
        varDefs.add(parseVarDef());
        while (lexer.getLexType() == LexType.COMMA) {
            lexer.next(); // COMMA
            varDefs.add(parseVarDef());
        }
        if (lexer.getLexType() == LexType.SEMICN) {
            lexer.next(); // SEMICN
        } else {
            Logger.logBad(lexer.getPrevLineno() + " i\n");
        }
        return new VarDecl(bType, varDefs.toArray(new VarDef[0]));
    }

    public VarDef parseVarDef() {
        String name = lexer.getToken();
        lexer.next();
        ConstExp constExp = null;
        if (lexer.getLexType() == LexType.LBRACK) {
            lexer.next(); // LBRACK
            constExp = parseConstExp();
            if (lexer.getLexType() == LexType.RBRACK) {
                lexer.next(); // RBRACK
            } else {
                Logger.logBad(lexer.getPrevLineno() + " k\n");
            }
        }
        InitVal initVal = null;
        if (lexer.getLexType() == LexType.ASSIGN) {
            lexer.next(); // ASSIGN
            initVal = parseInitVal();
        }
        return new VarDef(name, constExp, initVal);
    }

    public InitVal parseInitVal() {
        if (lexer.getLexType() == LexType.LBRACE) {
            // '{' [ Exp { ',' Exp } ] '}'
            lexer.next(); // LBRACE
            ArrayList<Exp> exps = new ArrayList<>();
            if (lexer.getLexType() != LexType.RBRACE) {
                exps.add(parseExp());
                while (lexer.getLexType() == LexType.COMMA) {
                    lexer.next(); // COMMA
                    exps.add(parseExp());
                }
            }
            lexer.next(); // RBRACE
            return new InitVal(exps.toArray(new Exp[0]));
        } else if (lexer.getLexType() == LexType.STRCON) {
            // STRCON
            String string = lexer.getToken();
            lexer.next(); // STRCON
            return new InitVal(string);
        } else {
            // Exp
            return new InitVal(parseExp());
        }
    }

    public FuncDef parseFuncDef() {
        FuncType funcType = parseFuncType();
        String string = lexer.getToken();
        lexer.next();
        lexer.next(); // LPARENT
        FuncFParams funcFParams = null;
        if (lexer.getLexType() == LexType.INTTK || lexer.getLexType() == LexType.CHARTK) {
             funcFParams = parseFuncFParams();
        }
        if (lexer.getLexType() == LexType.RPARENT) {
            lexer.next(); // RPARENT
        } else {
            Logger.logBad(lexer.getPrevLineno() + " j\n");
        }
        Block block = parseBlock();
        return new FuncDef(funcType, string, funcFParams, block);
    }

    public MainFuncDef parseMainFuncDef() {
        lexer.next(); // INTTK
        lexer.next(); // MAINTK
        lexer.next(); // LPARENT
        if (lexer.getLexType() == LexType.RPARENT) {
            lexer.next(); // RPARENT
        } else {
            Logger.logBad(lexer.getPrevLineno() + " j\n");
        }
        return new MainFuncDef(parseBlock());
    }

    public FuncType parseFuncType() {
        LexType lexType = lexer.getLexType();
        lexer.next();
        return new FuncType(lexType);
    }

    public FuncFParams parseFuncFParams() {
        ArrayList<FuncFParam> funcFParams = new ArrayList<>();
        funcFParams.add(parseFuncFParam());
        while (lexer.getLexType() == LexType.COMMA) {
            lexer.next();
            funcFParams.add(parseFuncFParam());
        }
        return new FuncFParams(funcFParams.toArray(new FuncFParam[0]));
    }

    public FuncFParam parseFuncFParam() {
        BType bType = parseBType();
        String name = lexer.getToken();
        boolean array = false;
        lexer.next();
        if (lexer.getLexType() == LexType.LBRACK) {
            array = true;
            lexer.next(); // LBRACK
            if (lexer.getLexType() == LexType.RBRACK) {
                lexer.next(); // RBRACK
            } else {
                Logger.logBad(lexer.getPrevLineno() + " k\n");
            }
        }
        return new FuncFParam(bType, name, array);
    }

    public Block parseBlock() {
        ArrayList<BlockItem> blockItems = new ArrayList<>();
        lexer.next();
        while (lexer.getLexType() != LexType.RBRACE) {
            blockItems.add(parseBlockItem());
        }
        lexer.next();
        return new Block(blockItems.toArray(new BlockItem[0]));
    }

    public BlockItem parseBlockItem() {
        if (Arrays.asList(Decl.FIRST).contains(lexer.getLexType())) {
            // Decl
            return new BlockItem(parseDecl());
        } else {
            // Stmt
            return new BlockItem(parseStmt());
        }
    }

    public Stmt parseStmt() {
        if (lexer.getLexType() == LexType.LPARENT
                || lexer.getLexType() == LexType.INTCON
                || lexer.getLexType() == LexType.CHRCON
                || lexer.getLexType() == LexType.PLUS
                || lexer.getLexType() == LexType.MINU
                || lexer.getLexType() == LexType.NOT
        ) {
            // Exp ';'
            Exp exp = parseExp();
            if (lexer.getLexType() == LexType.SEMICN) {
                lexer.next(); // SEMICN
            } else {
                Logger.logBad(lexer.getPrevLineno() + " i\n");
            }
            return new Stmt(exp);
        } else if (lexer.getLexType() == LexType.SEMICN) {
            // ';'
            lexer.next(); // SEMICN
            return new Stmt((Exp) null);
        } else if (lexer.getLexType() == LexType.LBRACE) {
            // Block
            return new Stmt(parseBlock());
        } else if (lexer.getLexType() == LexType.IFTK) {
            // 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
            lexer.next(); // IFTK
            lexer.next(); // LPARENT
            Cond cond = parseCond();
            if (lexer.getLexType() == LexType.RPARENT) {
                lexer.next(); // RPARENT
            } else {
                Logger.logBad(lexer.getPrevLineno() + " j\n");
            }
            Stmt stmt1 = parseStmt();
            Stmt stmt2 = null;
            if (lexer.getLexType() == LexType.ELSETK) {
                lexer.next(); // ELSETK
                stmt2 = parseStmt();
            }
            return new Stmt(cond, stmt1, stmt2);
        } else if (lexer.getLexType() == LexType.FORTK) {
            // 'for' '(' [ ForStmt ] ';' [ Cond ] ';' [ ForStmt ] ')' Stmt
            lexer.next(); // FORTK
            lexer.next(); // LPARENT
            ForStmt forStmt1 = null;
            if (lexer.getLexType() != LexType.SEMICN) {
                forStmt1 = parseForStmt();
            }
            lexer.next(); // SEMICN
            Cond cond = null;
            if (lexer.getLexType() != LexType.SEMICN) {
                cond = parseCond();
            }
            lexer.next(); // SEMICN
            ForStmt forStmt2 = null;
            if (lexer.getLexType() != LexType.RPARENT) {
                forStmt2 = parseForStmt();
            }
            lexer.next(); // RPARENT
            Stmt stmt = parseStmt();
            return new Stmt(forStmt1, cond, forStmt2, stmt);
        } else if (lexer.getLexType() == LexType.BREAKTK) {
            // 'break' ';'
            lexer.next(); // BREAKTK
            if (lexer.getLexType() == LexType.SEMICN) {
                lexer.next(); // SEMICN
            } else {
                Logger.logBad(lexer.getPrevLineno() + " i\n");
            }
            return new Stmt();
        } else if (lexer.getLexType() == LexType.CONTINUETK) {
            // 'continue' ';'
            lexer.next(); // CONTINUETK
            if (lexer.getLexType() == LexType.SEMICN) {
                lexer.next(); // SEMICN
            } else {
                Logger.logBad(lexer.getPrevLineno() + " i\n");
            }
            return new Stmt(0);
        } else if (lexer.getLexType() == LexType.RETURNTK) {
            // 'return' [ Exp ] ';'
            lexer.next(); // RETURNTK
            Exp exp = null;
            if (Arrays.asList(Exp.FIRST).contains(lexer.getLexType())) {
                exp = parseExp();
            }
            if (lexer.getLexType() == LexType.SEMICN) {
                lexer.next(); // SEMICN
            } else {
                Logger.logBad(lexer.getPrevLineno() + " i\n");
            }
            return new Stmt(exp, 0);
        } else if (lexer.getLexType() == LexType.PRINTFTK) {
            // 'printf' '(' StringConst { ',' Exp } ')' ';'
            lexer.next(); // PRINTFTK
            lexer.next(); // LPARENT
            String string = lexer.getToken();
            lexer.next(); // STRCON
            ArrayList<Exp> exps = new ArrayList<>();
            while (lexer.getLexType() == LexType.COMMA) {
                lexer.next(); // COMMA
                exps.add(parseExp());
            }
            if (lexer.getLexType() == LexType.RPARENT) {
                lexer.next(); // RPARENT
            } else {
                Logger.logBad(lexer.getPrevLineno() + " j\n");
            }
            if (lexer.getLexType() == LexType.SEMICN) {
                lexer.next(); // SEMICN
            } else {
                Logger.logBad(lexer.getPrevLineno() + " i\n");
            }
            return new Stmt(string, exps.toArray(new Exp[0]));
        } else {
            // 可能的四种情况：
            //     LVal '=' Exp ';'
            //     Exp ';'
            //     LVal '=' 'getint' '(' ')' ';'
            //     LVal '=' 'getchar' '(' ')' ';'
            // 先解析一个 Exp
            Exp expOrLVal = parseExp();
            if (lexer.getLexType() == LexType.ASSIGN) {
                LVal lVal = expOrLVal.getAddExp().getMulExp().getUnaryExp().getPrimaryExp().getlVal();
                while (!Logger.getLastGood().equals("<LVal>\n")) {
                    Logger.removeLastGood();
                }

                lexer.next(); // ASSIGN
                if (lexer.getLexType() == LexType.GETINTTK) {
                    // LVal '=' 'getint' '(' ')' ';'
                    lexer.next(); // GETINTTK
                    lexer.next(); // LPARENT
                    if (lexer.getLexType() == LexType.RPARENT) {
                        lexer.next(); // RPARENT
                    } else {
                        Logger.logBad(lexer.getPrevLineno() + " j\n");
                    }
                    if (lexer.getLexType() == LexType.SEMICN) {
                        lexer.next(); // SEMICN
                    } else {
                        Logger.logBad(lexer.getPrevLineno() + " i\n");
                    }
                    return new Stmt(lVal);
                } else if (lexer.getLexType() == LexType.GETCHARTK) {
                    // LVal '=' 'getchar' '(' ')' ';'
                    lexer.next(); // GETCHARTK
                    lexer.next(); // LPARENT
                    if (lexer.getLexType() == LexType.RPARENT) {
                        lexer.next(); // RPARENT
                    } else {
                        Logger.logBad(lexer.getPrevLineno() + " j\n");
                    }
                    if (lexer.getLexType() == LexType.SEMICN) {
                        lexer.next(); // SEMICN
                    } else {
                        Logger.logBad(lexer.getPrevLineno() + " i\n");
                    }
                    return new Stmt(lVal, 0);
                } else {
                    // LVal '=' Exp ';'
                    Exp exp = parseExp();
                    if (lexer.getLexType() == LexType.SEMICN) {
                        lexer.next(); // SEMICN
                    } else {
                        Logger.logBad(lexer.getPrevLineno() + " i\n");
                    }
                    return new Stmt(lVal, exp);
                }
            } else {
                // Exp ';'
                if (lexer.getLexType() == LexType.SEMICN) {
                    lexer.next(); // SEMICN
                } else {
                    Logger.logBad(lexer.getPrevLineno() + " i\n");
                }
                return new Stmt(expOrLVal);
            }
        }
    }

    public ForStmt parseForStmt() {
        LVal lVal = parseLVal();
        lexer.next(); // ASSIGN
        Exp exp = parseExp();
        return new ForStmt(lVal, exp);
    }

    public Exp parseExp() {
        return new Exp(parseAddExp());
    }

    public Cond parseCond() {
        return new Cond(parseLOrExp());
    }

    public LVal parseLVal() {
        String name = lexer.getToken();
        Exp exp = null;
        lexer.next();
        if (lexer.getLexType() == LexType.LBRACK) {
            lexer.next(); // LBRACK
            exp = parseExp();
            if (lexer.getLexType() == LexType.RBRACK) {
                lexer.next(); // RBRACK
            } else {
                Logger.logBad(lexer.getPrevLineno() + " k\n");
            }
        }
        return new LVal(name, exp);
    }

    public PrimaryExp parsePrimaryExp() {
        if (lexer.getLexType() == LexType.LPARENT) {
            // ( Exp )
            lexer.next(); // LPARENT
            Exp exp = parseExp();
            if (lexer.getLexType() == LexType.RPARENT) {
                lexer.next(); // RPARENT
            } else {
                Logger.logBad(lexer.getPrevLineno() + " j\n");
            }
            return new PrimaryExp(exp);
        } else if (Arrays.asList(LVal.FIRST).contains(lexer.getLexType())) {
            // LVal
            return new PrimaryExp(parseLVal());
        } else if (Arrays.asList(Number.FIRST).contains(lexer.getLexType())) {
            // Number
            return new PrimaryExp(parseNumber());
        } else if (Arrays.asList(Character.FIRST).contains(lexer.getLexType())) {
            // Character
            return new PrimaryExp(parseCharacter());
        } else {
            throw new RuntimeException();
        }
    }

    public Number parseNumber() {
        String token = lexer.getToken();
        lexer.next();
        return new Number(Integer.parseInt(token));
    }

    public Character parseCharacter() {
        String token = lexer.getToken();
        lexer.next();
        return new Character(token.charAt(1));
    }

    public UnaryExp parseUnaryExp() {
        if (Arrays.asList(UnaryOp.FIRST).contains(lexer.getLexType())) {
            // UnaryOp UnaryExp
            UnaryOp unaryOp = parseUnaryOp();
            UnaryExp unaryExp = parseUnaryExp();
            return new UnaryExp(unaryOp, unaryExp);
        } else if (lexer.getLexType() != LexType.IDENFR) {
            // PrimaryExp
            PrimaryExp primaryExp = parsePrimaryExp();
            return new UnaryExp(primaryExp);
        } else {
            // PrimaryExp | Ident '(' [FuncRParams] ')'
            String name = lexer.getToken();
            lexer.nextNoPrint();
            if (lexer.getLexType() == LexType.LPARENT) {
                lexer.prev();
                lexer.next();
                lexer.next(); // LPARENT
                // TODO 真的是这样吗？
                // Ident '(' [FuncRParams] ')'
                FuncRParams funcRParams = null;
                if (Arrays.asList(FuncRParams.FIRST).contains(lexer.getLexType())) {
                    funcRParams = parseFuncRParams();
                }
                if (lexer.getLexType() == LexType.RPARENT) {
                    lexer.next(); // RPARENT
                } else {
                    Logger.logBad(lexer.getPrevLineno() + " j\n");
                }
                return new UnaryExp(name, funcRParams);
            } else {
                // PrimaryExp
                lexer.prev();
                PrimaryExp primaryExp = parsePrimaryExp();
                return new UnaryExp(primaryExp);
            }
        }
    }

    public UnaryOp parseUnaryOp() {
        LexType lexType = lexer.getLexType();
        lexer.next();
        return new UnaryOp(lexType);
    }

    public FuncRParams parseFuncRParams() {
        ArrayList<Exp> exps = new ArrayList<>();
        exps.add(parseExp());
        while (lexer.getLexType() == LexType.COMMA) {
            lexer.next(); // COMMA
            exps.add(parseExp());
        }
        return new FuncRParams(exps.toArray(new Exp[0]));
    }

    public MulExp parseMulExp() {
        MulExp mulExp = new MulExp(parseUnaryExp());
        LexType lexType = null;
        UnaryExp unaryExp = null;
        while (lexer.getLexType() == LexType.MULT || lexer.getLexType() == LexType.DIV || lexer.getLexType() == LexType.MOD) {
            lexType = lexer.getLexType();
            lexer.next();
            unaryExp = parseUnaryExp();
            mulExp = new MulExp(mulExp, lexType, unaryExp);
        }
        return mulExp;
    }

    public AddExp parseAddExp() {
        AddExp addExp = new AddExp(parseMulExp());
        LexType lexType = null;
        MulExp mulExp = null;
        while (lexer.getLexType() == LexType.PLUS || lexer.getLexType() == LexType.MINU) {
            lexType = lexer.getLexType();
            lexer.next();
            mulExp = parseMulExp();
            addExp = new AddExp(addExp, lexType, mulExp);
        }
        return addExp;
    }

    public RelExp parseRelExp() {
        RelExp relExp = new RelExp(parseAddExp());
        LexType lexType = null;
        AddExp addExp = null;
        while (lexer.getLexType() == LexType.LSS || lexer.getLexType() == LexType.GRE || lexer.getLexType() == LexType.LEQ || lexer.getLexType() == LexType.GEQ) {
            lexType = lexer.getLexType();
            lexer.next();
            addExp = parseAddExp();
            relExp = new RelExp(relExp, lexType, addExp);
        }
        return relExp;
    }

    public EqExp parseEqExp() {
        EqExp eqExp = new EqExp(parseRelExp());
        LexType lexType = null;
        RelExp relExp = null;
        while (lexer.getLexType() == LexType.EQL || lexer.getLexType() == LexType.NEQ) {
            lexType = lexer.getLexType();
            lexer.next();
            relExp = parseRelExp();
            eqExp = new EqExp(eqExp, lexType, relExp);
        }
        return eqExp;
    }

    public LAndExp parseLAndExp() {
        LAndExp lAndExp = new LAndExp(parseEqExp());
        EqExp eqExp = null;
        while (lexer.getLexType() == LexType.AND) {
            lexer.next(); // AND
            eqExp = parseEqExp();
            lAndExp = new LAndExp(lAndExp, eqExp);
        }
        return lAndExp;
    }

    public LOrExp parseLOrExp() {
        LOrExp lOrExp = new LOrExp(parseLAndExp());
        LAndExp lAndExp = null;
        while (lexer.getLexType() == LexType.OR) {
            lexer.next(); // OR
            lAndExp = parseLAndExp();
            lOrExp = new LOrExp(lOrExp, lAndExp);
        }
        return lOrExp;
    }

    public ConstExp parseConstExp() {
        return new ConstExp(parseAddExp());
    }
}
