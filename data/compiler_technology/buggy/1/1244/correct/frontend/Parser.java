package frontend;

import error.CompileError;
import syntaxTree.*;
import token.Token;
import token.TokenType;

import java.util.ArrayList;
import java.util.HashMap;

import static error.CompileErrorType.*;

public class Parser {
    private int curTokenIndex;
    private Token curToken;
    private CompUnit compUnit;
    private final HashMap<Integer, ArrayList<String>> nodes;

    private final ArrayList<Token> tokens;
    private final ArrayList<CompileError> compileErrors;

    private static final Parser parserInstance = new Parser();

    private Parser() {
        tokens = Lexer.getTokens();
        compileErrors = CompileError.getCompileErrors();
        nodes = new HashMap<>();
        curTokenIndex = 0;
    }

    public static Parser getInstance() {
        return parserInstance;
    }

    public CompUnit getCompUnit() {
        return compUnit;
    }

    public HashMap<Integer, ArrayList<String>> getNodes() {
        return nodes;
    }

    private void addNode(String node) {
        if (!nodes.containsKey(curTokenIndex)) {
            nodes.put(curTokenIndex, new ArrayList<>());
        }
        nodes.get(curTokenIndex).add(node);
    }

    private void removeNode(int index) {
        nodes.remove(index);
    }

    public void grammaticalAnalysis() {
        curToken = tokens.get(curTokenIndex);
        compUnit = parseCompUnit();
    }

    private CompUnit parseCompUnit() {
        ArrayList<Decl> decls = new ArrayList<>();
        ArrayList<FuncDef> funcDefs = new ArrayList<>();
        MainFuncDef mainFuncDef;

        while (true) {
            if (curToken.getType() == TokenType.CONSTTK) {
                decls.add(parseConstDecl());
            } else if (curToken.getType() == TokenType.INTTK) {
                if (tokens.get(curTokenIndex + 1).getType() == TokenType.MAINTK) {
                    mainFuncDef = parseMainFunc();
                    break;
                } else {
                    if (tokens.get(curTokenIndex + 2).getType() == TokenType.LPARENT) {
                        funcDefs.add(parseFuncDef());
                    } else {
                        decls.add(parseVarDecl());
                    }
                }
            } else if (curToken.getType() == TokenType.CHARTK) {
                if (tokens.get(curTokenIndex + 2).getType() == TokenType.LPARENT) {
                    funcDefs.add(parseFuncDef());
                } else {
                    decls.add(parseVarDecl());
                }
            } else if (curToken.getType() == TokenType.VOIDTK) {
                funcDefs.add(parseFuncDef());
            }
        }

        addNode("<CompUnit>");
        return new CompUnit(decls, funcDefs, mainFuncDef);
    }

    private ConstDecl parseConstDecl() {
        TokenType bType;
        ArrayList<ConstDef> constDefs = new ArrayList<>();

        curToken = tokens.get(++curTokenIndex);
        bType = curToken.getType();
        do {
            curToken = tokens.get(++curTokenIndex);
            constDefs.add(parseConstDef());
        } while (curToken.getType() == TokenType.COMMA);
        checkSemicn();

        addNode("<ConstDecl>");
        return new ConstDecl(bType, constDefs);
    }

    private ConstDef parseConstDef() {
        Token ident = curToken;
        ConstExp constExp = null;
        ConstInitVal constInitVal;

        curToken = tokens.get(++curTokenIndex);
        if (curToken.getType() == TokenType.LBRACK) {
            curToken = tokens.get(++curTokenIndex);
            constExp = parseConstExp();
            checkRBreak();
        }
        curToken = tokens.get(++curTokenIndex);
        constInitVal = parseConstInitVal();

        addNode("<ConstDef>");
        return new ConstDef(ident, constExp, constInitVal);
    }


    private ConstExp parseConstExp() {
        ConstExp constExp = parseAddExp();

        addNode("<ConstExp>");
        return constExp;
    }

    private AddExp parseAddExp() {
        MulExp right = parseMulExp();
        addNode("<AddExp>");
        TokenType operator;
        AddExp left = new AddExp(null, right, null);
        while (curToken.getType() == TokenType.PLUS || curToken.getType() == TokenType.MINU) {
            operator = curToken.getType();
            curToken = tokens.get(++curTokenIndex);
            right = parseMulExp();
            addNode("<AddExp>");
            left = new AddExp(left, right, operator);
        }
        return left;
    }

    private MulExp parseMulExp() {
        UnaryExp right = parseUnaryExp();
        addNode("<MulExp>");
        TokenType operator;
        MulExp left = new MulExp(null, right, null);
        while (curToken.getType() == TokenType.MULT || curToken.getType() == TokenType.DIV ||
                curToken.getType() == TokenType.MOD) {
            operator = curToken.getType();
            curToken = tokens.get(++curTokenIndex);
            right = parseUnaryExp();
            addNode("<MulExp>");
            left = new MulExp(left, right, operator);
        }
        return left;
    }

    private UnaryExp parseUnaryExp() {
        if (curToken.getType() == TokenType.PLUS || curToken.getType() == TokenType.MINU ||
                curToken.getType() == TokenType.NOT) {
            return parseUnaryOpResult();
        } else if (curToken.getType() == TokenType.LPARENT) {
            curToken = tokens.get(++curTokenIndex);
            Exp exp = parseExp();
            checkRParent();

            addNode("<PrimaryExp>");
            addNode("<UnaryExp>");
            return new PrimaryExp(exp, null, null, PrimaryExpType.Exp);
        } else if (curToken.getType() == TokenType.INTCON) {
            PrimaryExp primaryExp = new PrimaryExp(null, null, curToken, PrimaryExpType.Number);
            curToken = tokens.get(++curTokenIndex);

            addNode("<Number>");
            addNode("<PrimaryExp>");
            addNode("<UnaryExp>");
            return primaryExp;
        } else if (curToken.getType() == TokenType.CHRCON) {
            PrimaryExp primaryExp = new PrimaryExp(null, null, curToken, PrimaryExpType.Character);
            curToken = tokens.get(++curTokenIndex);

            addNode("<Character>");
            addNode("<PrimaryExp>");
            addNode("<UnaryExp>");
            return primaryExp;
        } else {
            if (tokens.get(curTokenIndex + 1).getType() == TokenType.LPARENT) {
                Token ident = curToken;
                ArrayList<FuncRParam> funcRParams = new ArrayList<>();
                ++curTokenIndex;
                curToken = tokens.get(++curTokenIndex);
                if (curToken.getType() == TokenType.LPARENT || curToken.getType() == TokenType.IDENFR ||
                        curToken.getType() == TokenType.INTCON || curToken.getType() == TokenType.CHRCON ||
                        curToken.getType() == TokenType.PLUS || curToken.getType() == TokenType.MINU ||
                        curToken.getType() == TokenType.NOT)
                    parseFuncRParams(funcRParams);
                checkRParent();

                addNode("<UnaryExp>");
                return new FuncResult(ident, funcRParams);
            } else {
                LVal lVal = parseLval();
                PrimaryExp primaryExp = new PrimaryExp(null, lVal, null, PrimaryExpType.LVal);

                addNode("<PrimaryExp>");
                addNode("<UnaryExp>");
                return primaryExp;
            }
        }
    }

    private UnaryOpResult parseUnaryOpResult() {
        TokenType operator = curToken.getType();
        curToken = tokens.get(++curTokenIndex);
        addNode("<UnaryOp>");
        UnaryExp unaryExp = parseUnaryExp();

        addNode("<UnaryExp>");
        return new UnaryOpResult(unaryExp, operator);
    }

    private Exp parseExp() {
        Exp exp = parseAddExp();

        addNode("<Exp>");
        return exp;
    }

    private void parseFuncRParams(ArrayList<FuncRParam> funcRParams) {
        Exp exp;
        while (true) {
            exp = parseExp();
            funcRParams.add(new FuncRParam(exp));
            if (curToken.getType() != TokenType.COMMA)
                break;
            curToken = tokens.get(++curTokenIndex);
        }

        addNode("<FuncRParams>");
    }

    private LVal parseLval() {
        Token ident = curToken;
        Exp exp = null;
        curToken = tokens.get(++curTokenIndex);
        if (curToken.getType() == TokenType.LBRACK) {
            curToken = tokens.get(++curTokenIndex);
            if (curToken.getType() == TokenType.LPARENT || curToken.getType() == TokenType.IDENFR ||
                    curToken.getType() == TokenType.INTCON || curToken.getType() == TokenType.CHRCON ||
                    curToken.getType() == TokenType.PLUS || curToken.getType() == TokenType.MINU ||
                    curToken.getType() == TokenType.NOT)
                exp = parseExp();
            checkRBreak();
        }

        addNode("<LVal>");
        return new LVal(ident, exp);
    }

    private ConstInitVal parseConstInitVal() {
        ArrayList<ConstExp> exps = new ArrayList<>();
        Token stringConst = null;
        InitValType initValType;
        if (curToken.getType() == TokenType.LBRACE) {
            initValType = InitValType.MULTIEXP;
            if (tokens.get(curTokenIndex + 1).getType() != TokenType.RBRACE) {
                do {
                    curToken = tokens.get(++curTokenIndex);
                    exps.add(parseConstExp());
                } while (curToken.getType() == TokenType.COMMA);
            } else {
                ++curTokenIndex;
            }
            curToken = tokens.get(++curTokenIndex);
        } else if (curToken.getType() == TokenType.STRCON) {
            initValType = InitValType.STRINGCONST;
            stringConst = curToken;
            curToken = tokens.get(++curTokenIndex);
        } else {
            initValType = InitValType.SINGLEEXP;
            exps.add(parseConstExp());
        }

        addNode("<ConstInitVal>");
        return new ConstInitVal(exps, stringConst, initValType);
    }

    private VarDecl parseVarDecl() {
        TokenType bType = curToken.getType();
        ArrayList<VarDef> varDefs = new ArrayList<>();

        do {
            curToken = tokens.get(++curTokenIndex);
            varDefs.add(parseVarDef());
        } while (curToken.getType() == TokenType.COMMA);
        checkSemicn();

        addNode("<VarDecl>");
        return new VarDecl(bType, varDefs);
    }


    private VarDef parseVarDef() {
        Token ident = curToken;
        ConstExp constExp = null;
        InitVal initVal = null;

        curToken = tokens.get(++curTokenIndex);
        if (curToken.getType() == TokenType.LBRACK) {
            curToken = tokens.get(++curTokenIndex);
            if (curToken.getType() == TokenType.LPARENT || curToken.getType() == TokenType.IDENFR ||
                    curToken.getType() == TokenType.INTCON || curToken.getType() == TokenType.CHRCON ||
                    curToken.getType() == TokenType.PLUS || curToken.getType() == TokenType.MINU ||
                    curToken.getType() == TokenType.NOT)
                constExp = parseConstExp();
            checkRBreak();
        }
        if (curToken.getType() == TokenType.ASSIGN) {
            curToken = tokens.get(++curTokenIndex);
            initVal = parseInitVal();
        }


        addNode("<VarDef>");
        return new VarDef(ident, constExp, initVal);
    }

    private InitVal parseInitVal() {
        ArrayList<Exp> exps = new ArrayList<>();
        Token stringConst = null;
        InitValType initValType;

        if (curToken.getType() == TokenType.LBRACE) {
            initValType = InitValType.MULTIEXP;
            if (tokens.get(curTokenIndex + 1).getType() != TokenType.RBRACE) {
                do {
                    curToken = tokens.get(++curTokenIndex);
                    exps.add(parseExp());
                } while (curToken.getType() == TokenType.COMMA);
            } else {
                ++curTokenIndex;
            }
            curToken = tokens.get(++curTokenIndex);
        } else if (curToken.getType() == TokenType.STRCON) {
            initValType = InitValType.STRINGCONST;
            stringConst = curToken;
            curToken = tokens.get(++curTokenIndex);
        } else {
            initValType = InitValType.SINGLEEXP;
            exps.add(parseExp());
        }

        addNode("<InitVal>");
        return new InitVal(exps, stringConst, initValType);
    }

    private FuncDef parseFuncDef() {
        TokenType funcType = curToken.getType();
        curToken = tokens.get(++curTokenIndex);
        addNode("<FuncType>");
        Token ident = curToken;
        ArrayList<FuncFParam> funcFParams = new ArrayList<>();
        ArrayList<BlockItem> blockItems = new ArrayList<>();
        ++curTokenIndex;
        curToken = tokens.get(++curTokenIndex);
        if (curToken.getType() == TokenType.INTTK || curToken.getType() == TokenType.CHARTK)
            parseFuncFParams(funcFParams);
        checkRParent();
        parseBlock(blockItems);

        addNode("<FuncDef>");
        return new FuncDef(funcType, ident, funcFParams, blockItems);
    }

    private void parseFuncFParams(ArrayList<FuncFParam> funcFParams) {
        TokenType bType;
        Token ident;
        boolean isArray;
        while (true) {
            bType = curToken.getType();
            curToken = tokens.get(++curTokenIndex);
            ident = curToken;
            curToken = tokens.get(++curTokenIndex);
            if (curToken.getType() == TokenType.LBRACK) {
                isArray = true;
                curToken = tokens.get(++curTokenIndex);
                checkRBreak();
            } else {
                isArray = false;
            }
            addNode("<FuncFParam>");
            funcFParams.add(new FuncFParam(bType, ident, isArray));
            if (curToken.getType() != TokenType.COMMA)
                break;
            curToken = tokens.get(++curTokenIndex);
        }

        addNode("<FuncFParams>");
    }

    private void parseBlock(ArrayList<BlockItem> blockItems) {
        curToken = tokens.get(++curTokenIndex);
        do {
            if (curToken.getType() == TokenType.CONSTTK) {
                ConstDecl constDecl = parseConstDecl();
                blockItems.add(constDecl);
            } else if (curToken.getType() == TokenType.INTTK || curToken.getType() == TokenType.CHARTK) {
                VarDecl varDecl = parseVarDecl();
                blockItems.add(varDecl);
            } else if (curToken.getType() != TokenType.RBRACE) {
                blockItems.add(parseStmt());
            }
        } while (curToken.getType() != TokenType.RBRACE);

        ++curTokenIndex;
        addNode("<Block>");
        if (curTokenIndex < tokens.size() - 1)
            curToken = tokens.get(curTokenIndex);
    }

    private Stmt parseStmt() {
        if (curToken.getType() == TokenType.IDENFR) {
            if (tokens.get(curTokenIndex + 1).getType() == TokenType.LPARENT) {
                return parseExpStmt();
            }
            int backtrack = curTokenIndex, curErrorSize = compileErrors.size();
            LVal lVal = parseLval();
            if (curToken.getType() != TokenType.ASSIGN) {
                for (int i = curTokenIndex; i > backtrack; i--)
                    removeNode(i);
                if (compileErrors.size() > curErrorSize) {
                    compileErrors.subList(curErrorSize, compileErrors.size()).clear();
                }
                curTokenIndex = backtrack;
                curToken = tokens.get(curTokenIndex);
                return parseExpStmt();
            }
            curToken = tokens.get(++curTokenIndex);
            if (curToken.getType() == TokenType.GETINTTK || curToken.getType() == TokenType.GETCHARTK) {
                TokenType bType = curToken.getType();
                ++curTokenIndex;
                curToken = tokens.get(++curTokenIndex);
                checkRParent();
                checkSemicn();
                addNode("<Stmt>");
                return new GetStmt(lVal, bType);
            } else {
                Exp exp = parseExp();
                checkSemicn();
                addNode("<Stmt>");
                return new AssignStmt(lVal, exp);
            }
        } else if (curToken.getType() == TokenType.LBRACE) {
            ArrayList<BlockItem> subBlockItems = new ArrayList<>();
            parseBlock(subBlockItems);
            addNode("<Stmt>");
            return new BlockStmt(subBlockItems);
        } else if (curToken.getType() == TokenType.IFTK) {
            return parseIfStmt();
        } else if (curToken.getType() == TokenType.FORTK) {
            return parseForLoopStmt();
        } else if (curToken.getType() == TokenType.BREAKTK || curToken.getType() == TokenType.CONTINUETK) {
            curToken = tokens.get(++curTokenIndex);
            checkSemicn();
            addNode("<Stmt>");
            return new ControlStmt(curToken.getType());
        } else if (curToken.getType() == TokenType.RETURNTK) {
            return parseReturnStmt();
        } else if (curToken.getType() == TokenType.PRINTFTK) {
            return parsePrintfStmt();
        } else {
            if (curToken.getType() == TokenType.SEMICN) {
                curToken = tokens.get(++curTokenIndex);
                addNode("<Stmt>");
                return new ExpStmt(null);
            }
            return parseExpStmt();
        }
    }

    private ExpStmt parseExpStmt() {
        Exp exp = parseExp();
        checkSemicn();

        addNode("<Stmt>");
        return new ExpStmt(exp);
    }

    private IfStmt parseIfStmt() {
        ++curTokenIndex;
        curToken = tokens.get(++curTokenIndex);
        Cond cond = parseCond();
        checkRParent();
        Stmt stmt = parseStmt();
        Stmt elseStmt = null;
        if (curToken.getType() == TokenType.ELSETK) {
            curToken = tokens.get(++curTokenIndex);
            elseStmt = parseStmt();
        }

        addNode("<Stmt>");
        return new IfStmt(cond, stmt, elseStmt);
    }

    private Cond parseCond() {
        LOrExp lOrExp = parseLOrExp();

        addNode("<Cond>");
        return new Cond(lOrExp);
    }

    private LOrExp parseLOrExp() {
        LAndExp right = parseLAndExp();
        addNode("<LOrExp>");
        LOrExp left = new LOrExp(null, right);
        while (curToken.getType() == TokenType.OR) {
            curToken = tokens.get(++curTokenIndex);
            right = parseLAndExp();
            addNode("<LOrExp>");
            left = new LOrExp(left, right);
        }
        return left;
    }

    private LAndExp parseLAndExp() {
        EqExp right = parseEqExp();
        addNode("<LAndExp>");
        LAndExp left = new LAndExp(null, right);
        while (curToken.getType() == TokenType.AND) {
            curToken = tokens.get(++curTokenIndex);
            right = parseEqExp();
            addNode("<LAndExp>");
            left = new LAndExp(left, right);
        }
        return left;
    }

    private EqExp parseEqExp() {
        RelExp right = parseRelExp();
        addNode("<EqExp>");
        TokenType operator;
        EqExp left = new EqExp(null, right, null);
        while (curToken.getType() == TokenType.EQL || curToken.getType() == TokenType.NEQ) {
            operator = curToken.getType();
            curToken = tokens.get(++curTokenIndex);
            right = parseRelExp();
            addNode("<EqExp>");
            left = new EqExp(left, right, operator);
        }
        return left;
    }

    private RelExp parseRelExp() {
        AddExp right = parseAddExp();
        addNode("<RelExp>");
        TokenType operator;
        RelExp left = new RelExp(null, right, null);
        while (curToken.getType() == TokenType.LSS || curToken.getType() == TokenType.LEQ ||
                curToken.getType() == TokenType.GRE || curToken.getType() == TokenType.GEQ) {
            operator = curToken.getType();
            curToken = tokens.get(++curTokenIndex);
            right = parseAddExp();
            addNode("<RelExp>");
            left = new RelExp(left, right, operator);
        }
        return left;
    }

    private ForLoopStmt parseForLoopStmt() {
        ForStmt initStmt = null, iterStmt = null;
        Cond cond = null;
        ++curTokenIndex;
        curToken = tokens.get(++curTokenIndex);
        if (curToken.getType() != TokenType.SEMICN)
            initStmt = parseForStmt();
        curToken = tokens.get(++curTokenIndex);
        if (curToken.getType() != TokenType.SEMICN)
            cond = parseCond();
        curToken = tokens.get(++curTokenIndex);
        if (curToken.getType() != TokenType.RPARENT)
            iterStmt = parseForStmt();
        curToken = tokens.get(++curTokenIndex);
        Stmt stmt = parseStmt();

        addNode("<Stmt>");
        return new ForLoopStmt(initStmt, cond, iterStmt, stmt);
    }

    private ForStmt parseForStmt() {
        LVal lVal = parseLval();
        curToken = tokens.get(++curTokenIndex);
        Exp exp = parseExp();

        addNode("<ForStmt>");
        return new ForStmt(lVal, exp);
    }

    private ReturnStmt parseReturnStmt() {
        Exp exp = null;
        curToken = tokens.get(++curTokenIndex);
        if (curToken.getType() == TokenType.LPARENT || curToken.getType() == TokenType.IDENFR ||
                curToken.getType() == TokenType.INTCON || curToken.getType() == TokenType.CHRCON ||
                curToken.getType() == TokenType.PLUS || curToken.getType() == TokenType.MINU ||
                curToken.getType() == TokenType.NOT) {
            exp = parseExp();
        }
        checkSemicn();

        addNode("<Stmt>");
        return new ReturnStmt(exp);
    }

    private PrintfStmt parsePrintfStmt() {
        ++curTokenIndex;
        curToken = tokens.get(++curTokenIndex);
        Token stringConst = curToken;
        ArrayList<Exp> exps = new ArrayList<>();
        curToken = tokens.get(++curTokenIndex);
        while (curToken.getType() == TokenType.COMMA) {
            curToken = tokens.get(++curTokenIndex);
            exps.add(parseExp());
        }
        checkRParent();
        checkSemicn();

        addNode("<Stmt>");
        return new PrintfStmt(stringConst, exps);
    }

    private MainFuncDef parseMainFunc() {
        ArrayList<BlockItem> blockItems = new ArrayList<>();
        curTokenIndex += 2;
        curToken = tokens.get(++curTokenIndex);
        checkRParent();
        parseBlock(blockItems);

        addNode("<MainFuncDef>");
        return new MainFuncDef(blockItems);
    }

    private void checkSemicn() {
        if (curToken.getType() != TokenType.SEMICN)
            compileErrors.add(new CompileError(i, tokens.get(curTokenIndex - 1).getLineno()));
        else
            curToken = tokens.get(++curTokenIndex);
    }

    private void checkRParent() {
        if (curToken.getType() != TokenType.RPARENT)
            compileErrors.add(new CompileError(j, tokens.get(curTokenIndex - 1).getLineno()));
        else
            curToken = tokens.get(++curTokenIndex);
    }

    private void checkRBreak() {
        if (curToken.getType() != TokenType.RBRACK)
            compileErrors.add(new CompileError(k, tokens.get(curTokenIndex - 1).getLineno()));
        else
            curToken = tokens.get(++curTokenIndex);
    }
}
