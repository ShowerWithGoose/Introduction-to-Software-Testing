package frontend.ParserModule;

import frontend.LexerModule.Lexer;
import frontend.LexerModule.LexerType;
import frontend.LexerModule.ParseLexer;
import frontend.ParserModule.BlockItem.*;
import frontend.ParserModule.exps.*;

import java.io.FileNotFoundException;
import java.util.ArrayList;

public class Parser {
    private final ArrayList<Lexer> lexerBuffer = new ArrayList<>();
    private final ParseLexer parseLexer;
    private Lexer gLexer;
    private Lexer lastLexer;
    private int gLexerIndex;

    public Parser() throws FileNotFoundException {
        parseLexer = new ParseLexer();
        getNextLexer();
        lastLexer = null;
    }

    public void getNextLexer() {
        lastLexer = gLexer;
        gLexerIndex++;
        if (gLexerIndex < lexerBuffer.size()) {
            gLexer = lexerBuffer.get(gLexerIndex);
        } else {
            gLexer = parseLexer.getNextLexer();
        }
    }

    public CompileUnit parseCompileUnit() {
        CompileUnit compileUnit = new CompileUnit();
        for (; ; ) {
            preGet();
            if (lexerBuffer.get(1).getType() == LexerType.MAINTK) {
                compileUnit.setMainBlock(parseMainBlock());
                break;
            } else if (lexerBuffer.get(2).getType() == LexerType.LPARENT) {
                compileUnit.addFuncDef(parseFuncDef());
            } else {
                compileUnit.addDecl(parseDecl());
            }
        }
        return compileUnit;
    }

    public MainBlock parseMainBlock() {
        getNextLexer(); //int->main
        getNextLexer(); //main->(
        getNextLexer();//(->)
        int error = checkSpecialType(LexerType.RPARENT);
        return new MainBlock(parseBlockItem(), error);
    }

    public FuncDef parseFuncDef() {
        Lexer funcType = gLexer;
        getNextLexer();
        Lexer ident = gLexer;
        getNextLexer();
        getNextLexer();
        ArrayList<FuncParam> paramList = new ArrayList<>();
        int err;
        for (;;) {
            if (gLexer.getType() == LexerType.INTTK || gLexer.getType() == LexerType.CHARTK) {
                Lexer paramType = gLexer;
                getNextLexer();
                Lexer paramIdent = gLexer;
                getNextLexer();
                if (gLexer.getType() == LexerType.LBRACK) {
                    getNextLexer();
                    paramList.add(new FuncParam(paramType, paramIdent, true, checkSpecialType(LexerType.RBRACK)));
                } else {
                    paramList.add(new FuncParam(paramType, paramIdent, false, -1));
                }
                if (gLexer.getType() == LexerType.COMMA) {
                    getNextLexer();
                }
            } else {
                err = checkSpecialType(LexerType.RPARENT);
                break;
            }
        }
        return new FuncDef(funcType, ident, paramList, ((Block) parseBlockItem()), err);
    }

    public UnaryExp parseUnaryExp() {
        ArrayList<Lexer> opList = new ArrayList<>();
        while (gLexer.getType() == LexerType.PLUS || gLexer.getType() == LexerType.MINU || gLexer.getType() == LexerType.NOT) {
            opList.add(gLexer);
            getNextLexer();
        }
        if (gLexer.getType() == LexerType.INTCON) {
            UnaryExp exp = new IntConst(gLexer, opList);
            getNextLexer();
            return exp;
        } else if (gLexer.getType() == LexerType.CHRCON) {
            UnaryExp exp = new CharConst(gLexer, opList);
            getNextLexer();
            return exp;
        } else if (gLexer.getType() == LexerType.LPARENT) {
            getNextLexer();
            AddExp exp = parseAddExp();
            return new BracketExp(exp, checkSpecialType(LexerType.RPARENT), opList);
        } else {
            Lexer ident = gLexer;
            getNextLexer();
            if (gLexer.getType() == LexerType.LPARENT) {
                getNextLexer();
                if (gLexer.getType() == LexerType.INTCON || gLexer.getType() == LexerType.CHRCON || gLexer.getType() == LexerType.PLUS
                        || gLexer.getType() == LexerType.MINU || gLexer.getType() == LexerType.IDENFR || gLexer.getType() == LexerType.LPARENT) {
                    ArrayList<AddExp> params = new ArrayList<>();
                    for (; ; ) {
                        params.add(parseAddExp());
                        if (gLexer.getType() != LexerType.COMMA) {
                            break;
                        } else {
                            getNextLexer();
                        }
                    }
                    return new FunctionRPrams(ident, params, checkSpecialType(LexerType.RPARENT), opList);
                } else {
                    return new FunctionRPrams(ident, new ArrayList<>(), checkSpecialType(LexerType.RPARENT), opList);
                }
            } else if (gLexer.getType() == LexerType.LBRACK) {
                getNextLexer();
                AddExp arrayExp = parseAddExp();
                return new Lvalue(ident, true, arrayExp, checkSpecialType(LexerType.RBRACK), opList);
            } else {
                return new Lvalue(ident, false, null, -1, opList);
            }
        }
        //分别对应整数/字符常量 括号表达式 函数调用 左值
    } //解析一元表达式

    public MulExp parseMulExp() {
        MulExp res = new MulExp(parseUnaryExp());
        while (gLexer.getType() == LexerType.MULT || gLexer.getType() == LexerType.DIV || gLexer.getType() == LexerType.MOD) {
            Lexer tem = gLexer;
            getNextLexer();
            res.addUnaryExp(parseUnaryExp(), tem);
            if (gLexer == null) {
                break;
            }
        }
        return res;
    }

    public AddExp parseAddExp() {
        AddExp res = new AddExp(parseMulExp());
        while (gLexer.getType() == LexerType.PLUS || gLexer.getType() == LexerType.MINU) {
            Lexer tem = gLexer;
            getNextLexer();
            res.addMulExp(parseMulExp(), tem);
            if (gLexer == null) {
                break;
            }
        }
        return res;
    }

    public RelExp parseRelExp() {
        RelExp res = new RelExp(parseAddExp());
        while (gLexer.getType() == LexerType.LSS || gLexer.getType() == LexerType.LEQ || gLexer.getType() == LexerType.GRE || gLexer.getType() == LexerType.GEQ) {
            Lexer tem = gLexer;
            getNextLexer();
            res.addAddExp(parseAddExp(), tem);
            if (gLexer == null) {
                break;
            }
        }
        return res;
    }

    public EqExp parseEqExp() {
        EqExp res = new EqExp(parseRelExp());
        while (gLexer.getType() == LexerType.EQL || gLexer.getType() == LexerType.NEQ) {
            Lexer tem = gLexer;
            getNextLexer();
            res.addRelExp(parseRelExp(), tem);
            if (gLexer == null) {
                break;
            }
        }
        return res;
    }

    public LAndExp parseLAndExp() {
        LAndExp res = new LAndExp(parseEqExp());
        while (gLexer.getType() == LexerType.AND) {
            Lexer tem = gLexer;
            getNextLexer();
            res.addEqExp(parseEqExp(), tem);
            if (gLexer == null) {
                break;
            }
        }
        return res;
    }

    public LOrExp parseLOrExp() {
        LOrExp res = new LOrExp(parseLAndExp());
        while (gLexer.getType() == LexerType.OR) {
            Lexer tem = gLexer;
            getNextLexer();
            res.addLAndExp(parseLAndExp(), tem);
            if (gLexer == null) {
                break;
            }
        }
        return res;
    }

    public VarDef parseVarDef() {
        Lexer ident = gLexer;
        int errorLocate = -1;
        boolean isArray = false;
        AddExp arrayExp = null;
        getNextLexer();
        if (gLexer.getType() == LexerType.LBRACK) {
            getNextLexer();
            arrayExp = parseAddExp();
            isArray = true;
            errorLocate = checkSpecialType(LexerType.RBRACK);
        }
        //此时glexer指向‘=’或;
        if (gLexer.getType() != LexerType.ASSIGN) {
            return new VarDef(ident, isArray, arrayExp, errorLocate, false, null, false, new ArrayList<>());
        }
        getNextLexer();
        if (gLexer.getType() != LexerType.LBRACE) {
            if (gLexer.getType() == LexerType.STRCON) {
                VarDef newDef = new VarDef(ident, isArray, arrayExp, errorLocate, true, gLexer, false, new ArrayList<>());
                getNextLexer();
                return newDef;
            } else {
                ArrayList<AddExp> values = new ArrayList<>();
                values.add(parseAddExp());
                return new VarDef(ident, isArray, arrayExp, errorLocate, true, null, false, values);
            }
        } else {
            getNextLexer();
            if (gLexer.getType() == LexerType.RBRACE) {
                VarDef newDef = new VarDef(ident, isArray, arrayExp, errorLocate, true, null, true, new ArrayList<>());
                getNextLexer();
                return newDef;
            } else {
                ArrayList<AddExp> values = new ArrayList<>();
                values.add(parseAddExp());
                while (gLexer.getType() == LexerType.COMMA) {
                    getNextLexer();
                    values.add(parseAddExp());
                }
                VarDef newDef = new VarDef(ident, isArray, arrayExp, errorLocate, true, null, true, values);
                getNextLexer();
                return newDef;
            }
        }
    }

    public Decl parseDecl() {
        boolean constFlag = false;
        if (gLexer.getType() == LexerType.CONSTTK) {
            constFlag = true;
            getNextLexer();
        }
        Lexer bType = gLexer;
        getNextLexer();
        Decl decl = new Decl(constFlag, bType, parseVarDef());
        while (gLexer.getType() == LexerType.COMMA) {
            getNextLexer();
            decl.addVarDef(parseVarDef());
        }
        decl.setErrorLocate(checkSpecialType(LexerType.SEMICN));
        return decl;
    }

    public BlockItem parseBlockItem() {
        switch (gLexer.getType()) {
            case INTTK:
            case CHARTK:
            case CONSTTK:
                return parseDecl();
            case LBRACE:
                getNextLexer();
                Block block = new Block();
                while (gLexer.getType() != LexerType.RBRACE) {
                    block.addBlockItem(parseBlockItem());
                }
                getNextLexer();
                return block;
            case FORTK:
                return parseForBlock();
            case IFTK:
                return parseIfBlock();
            case CONTINUETK:
            case BREAKTK:
                Lexer tem = gLexer;
                getNextLexer();
                return new SpecialStmt(tem, null, checkSpecialType(LexerType.SEMICN));
            case RETURNTK:
                Lexer tem1 = gLexer;
                getNextLexer();
                if (gLexer.getType() == LexerType.SEMICN) {
                    getNextLexer();
                    return new SpecialStmt(tem1, null, -1);
                } else if (gLexer.getType() == LexerType.INTCON || gLexer.getType() == LexerType.CHRCON || gLexer.getType() == LexerType.PLUS
                        || gLexer.getType() == LexerType.MINU || gLexer.getType() == LexerType.IDENFR || gLexer.getType() == LexerType.LPARENT) {
                    AddExp exp = parseAddExp();
                    return new SpecialStmt(tem1, exp, checkSpecialType(LexerType.SEMICN));
                } else {
                    return new SpecialStmt(tem1, null, lastLexer.getLineNumber());
                }
            case PRINTFTK:
                return parsePrintBlock();
            default:
                return parseAssignStmtAndSingleExp();
        }
    }

    public ForBlock parseForBlock() {
        getNextLexer();
        getNextLexer();
        ForStmt forStmt1 = null, forStmt2 = null;
        LOrExp cond = null;
        if (gLexer.getType() != LexerType.SEMICN) {
            forStmt1 = parseForStmt();
        }
        getNextLexer();
        if (gLexer.getType() != LexerType.SEMICN) {
            cond = parseLOrExp();
        }
        getNextLexer();
        if (gLexer.getType() != LexerType.RPARENT) {
            forStmt2 = parseForStmt();
        }
        int err = checkSpecialType(LexerType.RPARENT);
        return new ForBlock(forStmt1, cond, forStmt2, parseBlockItem(), err);
    }

    public ForStmt parseForStmt() {
        AddExp exp = parseAddExp();
        getNextLexer();
        AddExp rvalue = parseAddExp();
        return new ForStmt(exp.toLvalue(), rvalue);
    }


    public IfBlock parseIfBlock() {
        getNextLexer();
        getNextLexer();
        LOrExp cond = parseLOrExp();
        int error = checkSpecialType(LexerType.RPARENT);
        BlockItem ifBlock = parseBlockItem();
        if (gLexer.getType() == LexerType.ELSETK) {
            getNextLexer();
            BlockItem elseBlock = parseBlockItem();
            return new IfBlock(cond, ifBlock, elseBlock, error);
        }
        return new IfBlock(cond, ifBlock, null, error);
    }

    public BlockItem parseAssignStmtAndSingleExp() {
        if (gLexer.getType() == LexerType.SEMICN) {
            getNextLexer();
            return new SingleExp(null, -1);
        }
        AddExp exp = parseAddExp();
        if (gLexer.getType() == LexerType.SEMICN) {
            getNextLexer();
            return new SingleExp(exp, -1);
        } else if (gLexer.getType() == LexerType.ASSIGN) {
            getNextLexer();
            if (gLexer.getType() == LexerType.GETCHARTK || gLexer.getType() == LexerType.GETINTTK) {
                Lexer funcType = gLexer;
                getNextLexer(); //gLexer左括号
                getNextLexer();
                int e1 = checkSpecialType(LexerType.RPARENT);
                int e2 = checkSpecialType(LexerType.SEMICN);
                return new AssignByFunc(exp.toLvalue(), funcType, e1, e2);
            } else {
                AddExp rvalue = parseAddExp();
                return new AssignByExp(exp.toLvalue(), rvalue, checkSpecialType(LexerType.SEMICN));
            }
        } else {
            return new SingleExp(exp, lastLexer.getLineNumber());
        }
    }

    public PrintBlock parsePrintBlock() {
        int printLine = gLexer.getLineNumber();
        getNextLexer();
        getNextLexer();
        Lexer strCon = gLexer;
        getNextLexer();
        ArrayList<AddExp> exps = new ArrayList<>();
        while (gLexer.getType() == LexerType.COMMA) {
            getNextLexer();
            exps.add(parseAddExp());
        }
        int e1 = checkSpecialType(LexerType.RPARENT);
        int e2 = checkSpecialType(LexerType.SEMICN);
        return new PrintBlock(strCon, exps, e1, e2,printLine);
    }

    public int checkSpecialType(LexerType type) {
        if (gLexer.getType() == type) {
            getNextLexer();
            return -1;
        } else {
            return lastLexer.getLineNumber();
        }
    }

    public void preGet() {
        lexerBuffer.clear();
        lexerBuffer.add(gLexer);
        for (int i = 0; i < 2; i += 1) {
            lexerBuffer.add(parseLexer.getNextLexer());
        }
        gLexerIndex = 0;
    } //预取Lexer进入buffer 用于识别模块

}
