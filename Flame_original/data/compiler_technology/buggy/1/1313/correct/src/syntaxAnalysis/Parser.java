package src.syntaxAnalysis;

import src.errorHandle.Error;
import src.errorHandle.ErrorList;
import src.errorHandle.ErrorType;
import src.lexicAnalysis.Token;
import src.lexicAnalysis.TokenList;
import src.lexicAnalysis.TokenType;
import src.syntaxTree.STRoot;
import src.syntaxTree.enums.*;
import src.syntaxTree.treeNodes.*;
import src.syntaxTree.treeNodes.Character;
import src.syntaxTree.treeNodes.Number;

/**
 * 语法分析器，语法分析核心部分
 */
public class Parser {
    private TokenList tokenList; // 输入的单词列表
    private ErrorList errorList; // 输出的错误列表
    private SyntaxList syntaxList; // 输出的语法列表
    private STRoot stRoot; // 语法树根节点
    private int curPos; // tokenList的当前位置指针

    public Parser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.errorList = new ErrorList();
        this.syntaxList = new SyntaxList();
        this.stRoot = new STRoot();
        this.curPos = -1;
    }

    public STRoot getStRoot() {
        return stRoot;
    }

    public ErrorList getErrorList() {
        return errorList;
    }

    public SyntaxList getSyntaxList() {
        return syntaxList;
    }

    /*--------------------工具方法---------------------*/
    private Token nextToken(int i) { // 获取往后第i个token
        return curPos + i < tokenList.getTokens().size() ? tokenList.getTokens().get(curPos + i) : null;
    }

    private Token goNextToken(String s) { // 判断接下来的一个token是否符合s的要求，符合则指针后移并返回下一个token
        if (curPos + 1 >= tokenList.getTokens().size()) {
            return null;
        }
        Token token = tokenList.getTokens().get(curPos + 1);
        if (s.equals(token.getContent())
                || (s.equals("ident") && isNext(1, TokenType.IDENFR))
                || (s.equals("intConst") && isNext(1, TokenType.INTCON))
                || (s.equals("stringConst") && isNext(1, TokenType.STRCON))
                || (s.equals("charConst") && isNext(1, TokenType.CHRCON))) {
            syntaxList.add(token.getTokenType() + " " + token.getContent());
            curPos += 1;
            return tokenList.getTokens().get(curPos);
        }
        return null;
    }

    private boolean isNext(int i, TokenType tokenType) { // 判断往后第i个token的类型是否符合期望
        if (nextToken(i) != null) {
            return nextToken(i).getTokenType() == tokenType;
        }
        return false;
    }

    private Token handleErrorIJK(ErrorType errorType) { // ijk错误处理，并返回一个包装了缺失单词的token对象
        Token token = tokenList.getTokens().get(curPos);
        Error error = new Error(errorType, token.getTokenRow(), token.getTokenCol());
        errorList.add(error);

        Token retToken = null;
        if (errorType == ErrorType.i) {
            retToken = new Token(TokenType.SEMICN, token.getTokenRow(), token.getTokenCol(), ";");
        } else if (errorType == ErrorType.j) {
            retToken = new Token(TokenType.RPARENT, token.getTokenRow(), token.getTokenCol(), ")");
        } else if (errorType == ErrorType.k) {
            retToken = new Token(TokenType.RBRACK, token.getTokenRow(), token.getTokenCol(), "]");
        }
        return retToken;
    }

    private int isNextNotLVal(int i) { // 用于判断 Stmt → LVal '=' ... ，是则返回移动到 '=' 的i值，否则返回0
        if (isNext(i, TokenType.LBRACK)) {
            i++;
            while (!isNext(i, TokenType.ASSIGN) && !isNext(i, TokenType.SEMICN)
                    && curPos + i < tokenList.getTokens().size()) {
                if (isNext(i, TokenType.IDENFR) || isNext(i, TokenType.INTCON) || isNext(i, TokenType.CHRCON)) {
                    if (isNext(i + 1, TokenType.IDENFR)
                            || isNext(i + 1, TokenType.INTCON)
                            || isNext(i + 1, TokenType.CHRCON)
                            || isNext(i + 1, TokenType.INTTK)
                            || isNext(i + 1, TokenType.CHARTK)
                            || isNext(i + 1, TokenType.CONSTTK)
                            || isNext(i + 1, TokenType.LBRACE)
                            || isNext(i + 1, TokenType.IFTK)
                            || isNext(i + 1, TokenType.FORTK)
                            || isNext(i + 1, TokenType.BREAKTK)
                            || isNext(i + 1, TokenType.CONTINUETK)
                            || isNext(i + 1, TokenType.RETURNTK)
                            || isNext(i + 1, TokenType.PRINTFTK)) {
                        return 0;
                    }
                }
                i++;
            }
            if (isNext(i, TokenType.SEMICN)) {
                return 0;
            }
        }
        return i;
    }

    private int isNextLValAssignGetintOrGetchar() { // getint 返回1，getchar 返回2，否则返回0
        int i = 1;
        if (isNext(i, TokenType.IDENFR)) {
            i++;
            i = isNextNotLVal(i);
            if (i == 0) {
                return 0;
            }
            if (isNext(i, TokenType.ASSIGN)) {
                if (isNext(i + 1, TokenType.GETINTTK)) {
                    return 1;
                } else if (isNext(i + 1, TokenType.GETCHARTK)) {
                    return 2;
                }
            }
        }
        return 0;
    }

    private boolean isNextValAssignExp() {
        int i = 1;
        if (isNext(i, TokenType.IDENFR)) {
            i++;
            i = isNextNotLVal(i);
            if (i == 0) {
                return false;
            }
            if (isNext(i, TokenType.ASSIGN)) {
                return true;
            }
        }
        return false;
    }

    private boolean isNextExpOrLVal() { // 判断下一个语句是否为 Exp 或 LVal
        return (isNext(1, TokenType.PLUS)
                || isNext(1, TokenType.MINU)
                || isNext(1, TokenType.NOT)
                || isNext(1, TokenType.LPARENT)
                || isNext(1, TokenType.IDENFR)
                || isNext(1, TokenType.INTCON)
                || isNext(1, TokenType.CHRCON));
    }

    /*--------------------分析部分---------------------*/
    public void analyze() { // 主要方法
        stRoot.compUnit = analyzeCompUnit();
    } // 主要方法

    // 编译单元 CompUnit → {Decl} {FuncDef} MainFuncDef
    private CompUnit analyzeCompUnit() {
        CompUnit compUnit = new CompUnit();
        while (isNext(1, TokenType.CONSTTK)
                || ((isNext(1, TokenType.INTTK) || isNext(1, TokenType.CHARTK))
                && isNext(2, TokenType.IDENFR)
                && !isNext(3, TokenType.LPARENT))) { // {Decl}
            compUnit.decls.add(analyzeDecl());
        }
        while (isNext(1, TokenType.VOIDTK)
                || ((isNext(1, TokenType.INTTK) || isNext(1, TokenType.CHARTK))
                && isNext(2, TokenType.IDENFR)
                && isNext(3, TokenType.LPARENT))) { // {FuncDef}
            compUnit.funcDefs.add(analyzeFuncDef());
        }
        if (isNext(1, TokenType.INTTK)) {
            compUnit.mainFuncDef = analyzeMainFuncDef();
        }
        syntaxList.add("<" + SyntaxType.CompUnit + ">");
        return compUnit;
    }

    // 声明 Decl → ConstDecl | VarDecl
    private Decl analyzeDecl() {
        Decl decl = new Decl();
        if (isNext(1, TokenType.CONSTTK)) {
            decl.declType = DeclType.CONST_DECL;
            decl.constDecl = analyzeConstDecl();
        } else {
            decl.declType = DeclType.VAR_DECL;
            decl.varDecl = analyzeVarDecl();
        }
        // <Decl> 无需输出
        return decl;
    }

    // 常量声明 ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';' // i
    private ConstDecl analyzeConstDecl() {
        ConstDecl constDecl = new ConstDecl();
        constDecl.tokenConst = goNextToken("const");
        constDecl.bType = analyzeBType();
        constDecl.constDef = analyzeConstDef();
        while (isNext(1, TokenType.COMMA)) {
            constDecl.commaList.add(goNextToken(","));
            constDecl.constDefs.add(analyzeConstDef());
        }

        if (isNext(1, TokenType.SEMICN)) {
            constDecl.semicolon = goNextToken(";");
        } else { // 错误处理
            constDecl.semicolon = handleErrorIJK(ErrorType.i);
        }
        syntaxList.add("<" + SyntaxType.ConstDecl + ">");
        return constDecl;
    }

    // 基本类型 BType → 'int' | 'char'
    private BType analyzeBType() {
        BType bType = new BType();
        if (isNext(1, TokenType.INTTK)) {
            bType.token = goNextToken("int");
        } else {
            bType.token = goNextToken("char");
        }
        // <BType> 无需输出
        return bType;
    }

    // 常量定义 ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal // k
    private ConstDef analyzeConstDef() {
        ConstDef constDef = new ConstDef();
        constDef.ident = isNext(1, TokenType.IDENFR) ? goNextToken("ident") : null;
        if (isNext(1, TokenType.LBRACK)) {
            constDef.lBrack = goNextToken("[");
            constDef.constExp = analyzeConstExp();
            if (isNext(1, TokenType.RBRACK)) {
                constDef.rBrack = goNextToken("]");
            } else { // 错误处理
                constDef.rBrack = handleErrorIJK(ErrorType.k);
            }
        }
        constDef.assign = goNextToken("=");
        constDef.constInitVal = analyzeConstInitVal();
        syntaxList.add("<" + SyntaxType.ConstDef + ">");
        return constDef;
    }

    // 常量初值 ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
    private ConstInitVal analyzeConstInitVal() {
        ConstInitVal constInitVal = new ConstInitVal();
        if (isNext(1, TokenType.STRCON)) {
            constInitVal.constInitValType = ConstInitValType.STRING_CONST;
            constInitVal.stringConst = goNextToken("stringConst");
        } else if (isNext(1, TokenType.LBRACE)) {
            constInitVal.constInitValType = ConstInitValType.BRACED_CONST_EXP;
            constInitVal.lBrace = goNextToken("{");
            if (!isNext(1, TokenType.RBRACE)) {
                constInitVal.constExp = analyzeConstExp();
                while (isNext(1, TokenType.COMMA)) {
                    constInitVal.commaList.add(goNextToken(","));
                    constInitVal.constExps.add(analyzeConstExp());
                }
            }
            constInitVal.rBrace = goNextToken("}");
        } else {
            constInitVal.constInitValType = ConstInitValType.CONST_EXP;
            constInitVal.constExp = analyzeConstExp();
        }

        syntaxList.add("<" + SyntaxType.ConstInitVal + ">");
        return constInitVal;
    }

    // 变量声明 VarDecl → BType VarDef { ',' VarDef } ';' // i
    private VarDecl analyzeVarDecl() {
        VarDecl varDecl = new VarDecl();
        varDecl.bType = analyzeBType();
        varDecl.varDef = analyzeVarDef();
        while (isNext(1, TokenType.COMMA)) {
            varDecl.commaList.add(goNextToken(","));
            varDecl.varDefs.add(analyzeVarDef());
        }
        if (isNext(1, TokenType.SEMICN)) {
            varDecl.semicolon = goNextToken(";");
        } else {
            varDecl.semicolon = handleErrorIJK(ErrorType.i);
        }

        syntaxList.add("<" + SyntaxType.VarDecl + ">");
        return varDecl;
    }

    // 变量定义 VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal // k
    private VarDef analyzeVarDef() {
        VarDef varDef = new VarDef();
        varDef.ident = isNext(1, TokenType.IDENFR) ? goNextToken("ident") : null;
        if (isNext(1, TokenType.LBRACK)) {
            varDef.lBrack = goNextToken("[");
            varDef.constExp = analyzeConstExp();
            if (isNext(1, TokenType.RBRACK)) {
                varDef.rBrack = goNextToken("]");
            } else { // 错误处理
                varDef.rBrack = handleErrorIJK(ErrorType.k);
            }
        }
        if (isNext(1, TokenType.ASSIGN)) {
            varDef.assign = goNextToken("=");
            varDef.initval = analyzeInitVal();
        }

        syntaxList.add("<" + SyntaxType.VarDef + ">");
        return varDef;
    }

    // 变量初值 InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
    private InitVal analyzeInitVal() {
        InitVal initVal = new InitVal();
        if (isNext(1, TokenType.STRCON)) {
            initVal.initValType = InitValType.STRING_CONST;
            initVal.stringConst = goNextToken("stringConst");
        } else if (isNext(1, TokenType.LBRACE)) {
            initVal.initValType = InitValType.BRACED_EXP;
            initVal.lBrace = goNextToken("{");
            if (!isNext(1, TokenType.RBRACE)) {
                initVal.exp = analyzeExp();
                while (isNext(1, TokenType.COMMA)) {
                    initVal.commaList.add(goNextToken(","));
                    initVal.exps.add(analyzeExp());
                }
            }
            initVal.rBrace = goNextToken("}");
        } else {
            initVal.initValType = InitValType.EXP;
            initVal.exp = analyzeExp();
        }

        syntaxList.add("<" + SyntaxType.InitVal + ">");
        return initVal;
    }

    // 函数定义 FuncDef → FuncType Ident '(' [FuncFParams] ')' Block // j
    private FuncDef analyzeFuncDef() {
        FuncDef funcDef = new FuncDef();
        funcDef.funcType = analyzeFuncType();
        funcDef.ident = isNext(1, TokenType.IDENFR) ? goNextToken("ident") : null;
        funcDef.lParent = goNextToken("(");
        if (!isNext(1, TokenType.RPARENT) && !isNext(1, TokenType.LBRACE)) { // 考虑j型错误
            funcDef.funcFParams = analyzeFuncFParams();
        }
        if (isNext(1, TokenType.RPARENT)) {
            funcDef.rParent = goNextToken(")");
        } else { // 错误处理
            funcDef.rParent = handleErrorIJK(ErrorType.j);
        }
        funcDef.block = analyzeBlock();
        syntaxList.add("<" + SyntaxType.FuncDef + ">");
        return funcDef;
    }

    // 主函数定义 MainFuncDef → 'int' 'main' '(' ')' Block // j
    private MainFuncDef analyzeMainFuncDef() {
        MainFuncDef mainFuncDef = new MainFuncDef();
        mainFuncDef.tokenInt = goNextToken("int");
        mainFuncDef.tokenMain = goNextToken("main");
        mainFuncDef.lParent = goNextToken("(");
        if (isNext(1, TokenType.RPARENT)) {
            mainFuncDef.rParent = goNextToken(")");
        } else { // 错误处理
            mainFuncDef.rParent = handleErrorIJK(ErrorType.j);
        }
        mainFuncDef.block = analyzeBlock();
        syntaxList.add("<" + SyntaxType.MainFuncDef + ">");
        return mainFuncDef;
    }

    // 函数类型 FuncType → 'void' | 'int' | 'char'
    private FuncType analyzeFuncType() {
        FuncType funcType = new FuncType();
        if (isNext(1, TokenType.VOIDTK)) {
            funcType.token = goNextToken("void");
        } else if (isNext(1, TokenType.INTTK)) {
            funcType.token = goNextToken("int");
        } else if (isNext(1, TokenType.CHARTK)) {
            funcType.token = goNextToken("char");
        }
        syntaxList.add("<" + SyntaxType.FuncType + ">");
        return funcType;
    }

    // 函数形参表 FuncFParams → FuncFParam { ',' FuncFParam }
    private FuncFParams analyzeFuncFParams() {
        FuncFParams funcFParams = new FuncFParams();
        funcFParams.funcFParam = analyzeFuncFParam();
        while (isNext(1, TokenType.COMMA)) {
            funcFParams.commaList.add(goNextToken(","));
            funcFParams.funcFParams.add(analyzeFuncFParam());
        }
        syntaxList.add("<" + SyntaxType.FuncFParams + ">");
        return funcFParams;
    }

    // 函数形参 FuncFParam → BType Ident ['[' ']'] // k
    private FuncFParam analyzeFuncFParam() {
        FuncFParam funcFParam = new FuncFParam();
        funcFParam.bType = analyzeBType();
        funcFParam.ident = isNext(1, TokenType.IDENFR) ? goNextToken("ident") : null;
        if (isNext(1, TokenType.LBRACK)) {
            funcFParam.lBrack = goNextToken("[");
            if (isNext(1, TokenType.RBRACK)) {
                funcFParam.rBrack = goNextToken("]");
            } else { // 错误处理
                funcFParam.rBrack = handleErrorIJK(ErrorType.k);
            }
        }
        syntaxList.add("<" + SyntaxType.FuncFParam + ">");
        return funcFParam;
    }

    // 语句块 Block → '{' { BlockItem } '}'
    private Block analyzeBlock() {
        Block block = new Block();
        block.lBrace = goNextToken("{");
        while (isNext(1, TokenType.CONSTTK)
                || isNext(1, TokenType.INTTK)
                || isNext(1, TokenType.CHARTK)
                || isNext(1, TokenType.SEMICN)
                || isNext(1, TokenType.LBRACE)
                || isNext(1, TokenType.IFTK)
                || isNext(1, TokenType.FORTK)
                || isNext(1, TokenType.BREAKTK)
                || isNext(1, TokenType.CONTINUETK)
                || isNext(1, TokenType.RETURNTK)
                || isNext(1, TokenType.PRINTFTK)
                || isNextExpOrLVal()) {
            block.blockItems.add(analyzeBlockItem());
        }
        block.rBrace = goNextToken("}");
        syntaxList.add("<" + SyntaxType.Block + ">");
        return block;
    }

    // 语句块项 BlockItem → Decl | Stmt
    private BlockItem analyzeBlockItem() {
        BlockItem blockItem = new BlockItem();
        if (isNext(1, TokenType.INTTK)
                || isNext(1, TokenType.CHARTK)
                || isNext(1, TokenType.CONSTTK)) {
            blockItem.blockItemType = BlockItemType.DECL;
            blockItem.decl = analyzeDecl();
        } else {
            blockItem.blockItemType = BlockItemType.STMT;
            blockItem.stmt = analyzeStmt();
        }
        // <BlockItem> 无需输出
        return blockItem;
    }

    // 语句 Stmt → LVal '=' Exp ';' // i
    // | [Exp] ';' // i
    // | Block
    // | 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // j
    // | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
    // | 'break' ';' | 'continue' ';' // i
    // | 'return' [Exp] ';' // i
    // | LVal '=' 'getint''('')'';' // i j
    // | LVal '=' 'getchar''('')'';' // i j
    // | 'printf''('StringConst {','Exp}')'';' // i j
    private Stmt analyzeStmt() {
        Stmt stmt = new Stmt();

        if (isNext(1, TokenType.LBRACE)) {
            stmt.stmtType = StmtType.BLOCK;
            stmt.block = analyzeBlock();
        } else if (isNext(1, TokenType.IFTK)) {
            stmt.stmtType = StmtType.IF;
            StmtIf stmtIf = new StmtIf();
            stmtIf.tokenIf = goNextToken("if");
            stmtIf.lParent = goNextToken("(");
            stmtIf.cond = analyzeCond();
            if (isNext(1, TokenType.RPARENT)) {
                stmtIf.rParent = goNextToken(")");
            } else {
                stmtIf.rParent = handleErrorIJK(ErrorType.j);
            }
            stmtIf.stmt = analyzeStmt();
            if (isNext(1, TokenType.ELSETK)) {
                stmtIf.tokenElse = goNextToken("else");
                stmtIf.elseStmt = analyzeStmt();
            }
            stmt.stmtIf = stmtIf;
        } else if (isNext(1, TokenType.FORTK)) {
            stmt.stmtType = StmtType.FOR;
            StmtFor stmtFor = new StmtFor();
            stmtFor.tokenFor = goNextToken("for");
            stmtFor.lParent = goNextToken("(");
            if (!isNext(1, TokenType.SEMICN)) {
                stmtFor.forStmt1 = analyzeForStmt();
            }
            stmtFor.semicolon1 = goNextToken(";");
            if (!isNext(1, TokenType.SEMICN)) {
                stmtFor.cond = analyzeCond();
            }
            stmtFor.semicolon2 = goNextToken(";");
            if (!isNext(1, TokenType.RPARENT)) {
                stmtFor.forStmt2 = analyzeForStmt();
            }
            stmtFor.rParent = goNextToken(")");
            stmtFor.stmt = analyzeStmt();
            stmt.stmtFor = stmtFor;
        } else if (isNext(1, TokenType.BREAKTK)) {
            stmt.stmtType = StmtType.BREAK;
            StmtBreak stmtBreak = new StmtBreak();
            stmtBreak.tokenBreak = goNextToken("break");
            if (isNext(1, TokenType.SEMICN)) {
                stmtBreak.semicolon = goNextToken(";");
            } else {
                stmtBreak.semicolon = handleErrorIJK(ErrorType.i);
            }
            stmt.stmtBreak = stmtBreak;
        } else if (isNext(1, TokenType.CONTINUETK)) {
            stmt.stmtType = StmtType.CONTINUE;
            StmtContinue stmtContinue = new StmtContinue();
            stmtContinue.tokenContinue = goNextToken("continue");
            if (isNext(1, TokenType.SEMICN)) {
                stmtContinue.semicolon = goNextToken(";");
            } else {
                stmtContinue.semicolon = handleErrorIJK(ErrorType.i);
            }
            stmt.stmtContinue = stmtContinue;
        } else if (isNext(1, TokenType.RETURNTK)) {
            stmt.stmtType = StmtType.RETURN;
            StmtReturn stmtReturn = new StmtReturn();
            stmtReturn.tokenReturn = goNextToken("return");
            if (isNextExpOrLVal()) {
                stmtReturn.exp = analyzeExp();
            }
            if (isNext(1, TokenType.SEMICN)) {
                stmtReturn.semicolon = goNextToken(";");
            } else {
                stmtReturn.semicolon = handleErrorIJK(ErrorType.i);
            }
            stmt.stmtReturn = stmtReturn;
        } else if (isNext(1, TokenType.PRINTFTK)) {
            stmt.stmtType = StmtType.PRINTF;
            StmtPrintf stmtPrintf = new StmtPrintf();
            stmtPrintf.printf = goNextToken("printf");
            stmtPrintf.lParent = goNextToken("(");
            stmtPrintf.stringConst = goNextToken("stringConst");
            while (isNext(1, TokenType.COMMA)) {
                stmtPrintf.commaList.add(goNextToken(","));
                stmtPrintf.exps.add(analyzeExp());
            }
            if (isNext(1, TokenType.RPARENT)) {
                stmtPrintf.rParent = goNextToken(")");
            } else {
                stmtPrintf.rParent = handleErrorIJK(ErrorType.j);
            }
            if (isNext(1, TokenType.SEMICN)) {
                stmtPrintf.semicolon = goNextToken(";");
            } else {
                stmtPrintf.semicolon = handleErrorIJK(ErrorType.i);
            }
            stmt.stmtPrintf = stmtPrintf;
        } else if (isNextLValAssignGetintOrGetchar() == 1) { // getint
            stmt.stmtType = StmtType.LVAL_GETINT;
            StmtLValGetint stmtLValGetint = new StmtLValGetint();
            stmtLValGetint.lVal = analyzeLVal();
            stmtLValGetint.assign = goNextToken("=");
            stmtLValGetint.getint = goNextToken("getint");
            stmtLValGetint.lParent = goNextToken("(");
            if (isNext(1, TokenType.RPARENT)) {
                stmtLValGetint.rParent = goNextToken(")");
            } else {
                stmtLValGetint.rParent = handleErrorIJK(ErrorType.j);
            }
            if (isNext(1, TokenType.SEMICN)) {
                stmtLValGetint.semicolon = goNextToken(";");
            } else {
                stmtLValGetint.semicolon = handleErrorIJK(ErrorType.i);
            }
            stmt.stmtLValGetint = stmtLValGetint;
        } else if (isNextLValAssignGetintOrGetchar() == 2) { // getchar
            stmt.stmtType = StmtType.LVAL_GETCHAR;
            StmtLValGetchar stmtLValGetchar = new StmtLValGetchar();
            stmtLValGetchar.lVal = analyzeLVal();
            stmtLValGetchar.assign = goNextToken("=");
            stmtLValGetchar.getchar = goNextToken("getchar");
            stmtLValGetchar.lParent = goNextToken("(");
            if (isNext(1, TokenType.RPARENT)) {
                stmtLValGetchar.rParent = goNextToken(")");
            } else {
                stmtLValGetchar.rParent = handleErrorIJK(ErrorType.j);
            }
            if (isNext(1, TokenType.SEMICN)) {
                stmtLValGetchar.semicolon = goNextToken(";");
            } else {
                stmtLValGetchar.semicolon = handleErrorIJK(ErrorType.i);
            }
            stmt.stmtLValGetchar = stmtLValGetchar;
        } else if (isNextValAssignExp()) {
            stmt.stmtType = StmtType.LVAL_EXP;
            StmtLValAssign stmtLValAssign = new StmtLValAssign();
            stmtLValAssign.lVal = analyzeLVal();
            stmtLValAssign.assign = goNextToken("=");
            stmtLValAssign.exp = analyzeExp();
            if (isNext(1, TokenType.SEMICN)) {
                stmtLValAssign.semicolon = goNextToken(";");
            } else {
                stmtLValAssign.semicolon = handleErrorIJK(ErrorType.i);
            }
            stmt.stmtLValAssign = stmtLValAssign;
        } else if (isNextExpOrLVal()) {
            stmt.stmtType = StmtType.EXP;
            stmt.exp = analyzeExp();
            if (isNext(1, TokenType.SEMICN)) {
                stmt.semicolon = goNextToken(";");
            } else {
                stmt.semicolon = handleErrorIJK(ErrorType.i);
            }
        } else {
            stmt.stmtType = StmtType.SEMICN;
            if (isNext(1, TokenType.SEMICN)) {
                stmt.semicolon = goNextToken(";");
            } else {
                stmt.semicolon = handleErrorIJK(ErrorType.i);
            }
        }

        syntaxList.add("<" + SyntaxType.Stmt + ">");
        return stmt;
    }

    // 语句 ForStmt → LVal '=' Exp
    private ForStmt analyzeForStmt() { // added
        ForStmt forStmt = new ForStmt();
        forStmt.lVal = analyzeLVal();
        forStmt.assign = goNextToken("=");
        forStmt.exp = analyzeExp();
        syntaxList.add("<" + SyntaxType.ForStmt + ">");
        return forStmt;
    }

    // 表达式 Exp → AddExp
    private Exp analyzeExp() {
        Exp exp = new Exp();
        exp.addExp = analyzeAddExp();
        syntaxList.add("<" + SyntaxType.Exp + ">");
        return exp;
    }

    // 条件表达式 Cond → LOrExp
    private Cond analyzeCond() {
        Cond cond = new Cond();
        cond.lOrExp = analyzeLOrExp();
        syntaxList.add("<" + SyntaxType.Cond + ">");
        return cond;
    }

    // 左值表达式 LVal → Ident ['[' Exp ']'] // k
    private LVal analyzeLVal() {
        LVal lVal = new LVal();
        lVal.ident = isNext(1, TokenType.IDENFR) ? goNextToken("ident") : null;
        if (isNext(1, TokenType.LBRACK)) {
            lVal.lBrack = goNextToken("[");
            lVal.exp = analyzeExp();
            if (isNext(1, TokenType.RBRACK)) {
                lVal.rBrack = goNextToken("]");
            } else {
                lVal.rBrack = handleErrorIJK(ErrorType.k);
            }
        }
        syntaxList.add("<" + SyntaxType.LVal + ">");
        return lVal;
    }

    // 基本表达式 PrimaryExp → '(' Exp ')' | LVal | Number | Character// j
    private PrimaryExp analyzePrimaryExp() {
        PrimaryExp primaryExp = new PrimaryExp();
        if (isNext(1, TokenType.LPARENT)) {
            primaryExp.primaryExpType = PrimaryExpType.EXP;
            primaryExp.lParent = goNextToken("(");
            primaryExp.exp = analyzeExp();
            if (isNext(1, TokenType.RPARENT)) {
                primaryExp.rParent = goNextToken(")");
            } else { // 错误处理
                primaryExp.rParent = handleErrorIJK(ErrorType.j);
            }
        } else if (isNext(1, TokenType.IDENFR)) {
            primaryExp.primaryExpType = PrimaryExpType.LVAL;
            primaryExp.lVal = analyzeLVal();
        } else if (isNext(1, TokenType.INTCON)) {
            primaryExp.primaryExpType = PrimaryExpType.NUMBER;
            primaryExp.number = analyzeNumber();
        } else if (isNext(1, TokenType.CHRCON)) {
            primaryExp.primaryExpType = PrimaryExpType.CHARACTER;
            primaryExp.character = analyzeCharacter();
        }
        syntaxList.add("<" + SyntaxType.PrimaryExp + ">");
        return primaryExp;
    }

    // 数值 Number → IntConst
    private Number analyzeNumber() {
        Number number = new Number();
        number.intConst = goNextToken("intConst");
        syntaxList.add("<" + SyntaxType.Number + ">");
        return number;
    }

    // 字符 Character → CharConst
    private Character analyzeCharacter() { // added
        Character character = new Character();
        character.charConst = goNextToken("charConst");
        syntaxList.add("<" + SyntaxType.Character + ">");
        return character;
    }

    // 一元表达式 UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp // j
    private UnaryExp analyzeUnaryExp() {
        UnaryExp unaryExp = new UnaryExp();
        if (isNext(1, TokenType.LPARENT)
                || (isNext(1, TokenType.IDENFR) && !isNext(2, TokenType.LPARENT))
                || isNext(1, TokenType.INTCON)
                || isNext(1, TokenType.CHRCON)) {
            unaryExp.unaryExpType = UnaryExpType.PRIMARY_EXP;
            unaryExp.primaryExp = analyzePrimaryExp();
        } else if (isNext(1, TokenType.IDENFR) && isNext(2, TokenType.LPARENT)) {
            unaryExp.unaryExpType = UnaryExpType.IDENT;
            unaryExp.ident = isNext(1, TokenType.IDENFR) ? goNextToken("ident") : null;
            unaryExp.lParent = goNextToken("(");
            if (isNextExpOrLVal()) {
                unaryExp.funcRParams = analyzeFuncRParams();
            }
            if (isNext(1, TokenType.RPARENT)) {
                unaryExp.rParent = goNextToken(")");
            } else { // 错误处理
                unaryExp.rParent = handleErrorIJK(ErrorType.j);
            }
        } else if (isNext(1, TokenType.PLUS)
                || isNext(1, TokenType.MINU)
                || isNext(1, TokenType.NOT)) {
            unaryExp.unaryExpType = UnaryExpType.UNARY_OP;
            unaryExp.unaryOp = analyzeUnaryOp();
            unaryExp.unaryExp = analyzeUnaryExp();
        }
        syntaxList.add("<" + SyntaxType.UnaryExp + ">");
        return unaryExp;
    }

    // 单目运算符 UnaryOp → '+' | '−' | '!' 注：'!'仅出现在条件表达式中
    private UnaryOp analyzeUnaryOp() {
        UnaryOp unaryOp = new UnaryOp();
        if (isNext(1, TokenType.PLUS)) {
            unaryOp.token = goNextToken("+");
        } else if (isNext(1, TokenType.MINU)) {
            unaryOp.token = goNextToken("-");
        } else if (isNext(1, TokenType.NOT)) {
            unaryOp.token = goNextToken("!");
        }
        syntaxList.add("<" + SyntaxType.UnaryOp + ">");
        return unaryOp;
    }

    // 函数实参表 FuncRParams → Exp { ',' Exp }
    private FuncRParams analyzeFuncRParams() {
        FuncRParams funcRParams = new FuncRParams();
        funcRParams.exp = analyzeExp();
        while (isNext(1, TokenType.COMMA)) {
            funcRParams.commaList.add(goNextToken(","));
            funcRParams.exps.add(analyzeExp());
        }
        syntaxList.add("<" + SyntaxType.FuncRParams + ">");
        return funcRParams;
    }

    // 乘除模表达式 MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
    private MulExp analyzeMulExp() {
        MulExp mulExp = new MulExp();
        mulExp.unaryExp = analyzeUnaryExp();
        syntaxList.add("<" + SyntaxType.MulExp + ">");

        while (isNext(1, TokenType.MULT)
                || isNext(1, TokenType.DIV)
                || isNext(1, TokenType.MOD)) {
            MulExp preMulExp = new MulExp();
            preMulExp.mulExp = mulExp;

            if (isNext(1, TokenType.MULT)) {
                preMulExp.token = goNextToken("*");
            } else if (isNext(1, TokenType.DIV)) {
                preMulExp.token = goNextToken("/");
            } else if (isNext(1, TokenType.MOD)) {
                preMulExp.token = goNextToken("%");
            }

            preMulExp.unaryExp = analyzeUnaryExp();
            syntaxList.add("<" + SyntaxType.MulExp + ">");
            mulExp = preMulExp;
        }
        return mulExp;
    }

    // 加减表达式 AddExp → MulExp | AddExp ('+' | '−') MulExp
    private AddExp analyzeAddExp() {
        AddExp addExp = new AddExp();
        addExp.mulExp = analyzeMulExp();
        syntaxList.add("<" + SyntaxType.AddExp + ">");

        while (isNext(1, TokenType.PLUS) || isNext(1, TokenType.MINU)) {
            AddExp preAddExp = new AddExp();
            preAddExp.addExp = addExp;

            if (isNext(1, TokenType.PLUS)) {
                preAddExp.token = goNextToken("+");
            } else if (isNext(1, TokenType.MINU)) {
                preAddExp.token = goNextToken("-");
            }
            preAddExp.mulExp = analyzeMulExp();
            syntaxList.add("<" + SyntaxType.AddExp + ">");
            addExp = preAddExp;
        }
        return addExp;
    }

    // 关系表达式 RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
    private RelExp analyzeRelExp() {
        RelExp relExp = new RelExp();
        relExp.addExp = analyzeAddExp();
        syntaxList.add("<" + SyntaxType.RelExp + ">");

        while (isNext(1, TokenType.LSS) || isNext(1, TokenType.GRE)
                || isNext(1, TokenType.LEQ) || isNext(1, TokenType.GEQ)) {
            RelExp preRelExp = new RelExp();
            preRelExp.relExp = relExp;

            if (isNext(1, TokenType.LSS)) {
                preRelExp.token = goNextToken("<");
            } else if (isNext(1, TokenType.GRE)) {
                preRelExp.token = goNextToken(">");
            } else if (isNext(1, TokenType.LEQ)) {
                preRelExp.token = goNextToken("<=");
            } else if (isNext(1, TokenType.GEQ)) {
                preRelExp.token = goNextToken(">=");
            }
            preRelExp.addExp = analyzeAddExp();
            syntaxList.add("<" + SyntaxType.RelExp + ">");
            relExp = preRelExp;
        }
        return relExp;
    }

    // 相等性表达式 EqExp → RelExp | EqExp ('==' | '!=') RelExp
    private EqExp analyzeEqExp() {
        EqExp eqExp = new EqExp();
        eqExp.relExp = analyzeRelExp();
        syntaxList.add("<" + SyntaxType.EqExp + ">");

        while (isNext(1, TokenType.EQL) || isNext(1, TokenType.NEQ)) {
            EqExp preEqExp = new EqExp();
            preEqExp.eqExp = eqExp;

            if (isNext(1, TokenType.EQL)) {
                preEqExp.token = goNextToken("==");
            } else if (isNext(1, TokenType.NEQ)) {
                preEqExp.token = goNextToken("!=");
            }
            preEqExp.relExp = analyzeRelExp();
            syntaxList.add("<" + SyntaxType.EqExp + ">");
            eqExp = preEqExp;
        }
        return eqExp;
    }

    // 逻辑与表达式 LAndExp → EqExp | LAndExp '&&' EqExp
    private LAndExp analyzeLAndExp() {
        LAndExp lAndExp = new LAndExp();
        lAndExp.eqExp = analyzeEqExp();
        syntaxList.add("<" + SyntaxType.LAndExp + ">");

        while (isNext(1, TokenType.AND)) {
            LAndExp preLAndExp = new LAndExp();
            preLAndExp.lAndExp = lAndExp;

            if (isNext(1, TokenType.AND)) {
                preLAndExp.tokenAnd = goNextToken("&&");
            }
            preLAndExp.eqExp = analyzeEqExp();
            syntaxList.add("<" + SyntaxType.LAndExp + ">");
            lAndExp = preLAndExp;
        }
        return lAndExp;
    }

    // 逻辑或表达式 LOrExp → LAndExp | LOrExp '||' LAndExp
    private LOrExp analyzeLOrExp() {
        LOrExp lOrExp = new LOrExp();
        lOrExp.lAndExp = analyzeLAndExp();
        syntaxList.add("<" + SyntaxType.LOrExp + ">");

        while (isNext(1, TokenType.OR)) {
            LOrExp preLOrExp = new LOrExp();
            preLOrExp.lOrExp = lOrExp;

            if (isNext(1, TokenType.OR)) {
                preLOrExp.tokenOr = goNextToken("||");
            }
            preLOrExp.lAndExp = analyzeLAndExp();
            syntaxList.add("<" + SyntaxType.LOrExp + ">");
            lOrExp = preLOrExp;
        }
        return lOrExp;
    }

    // 常量表达式 ConstExp → AddExp 注：使用的 Ident 必须是常量
    private ConstExp analyzeConstExp() {
        ConstExp constExp = new ConstExp();
        constExp.addExp = analyzeAddExp();
        syntaxList.add("<" + SyntaxType.ConstExp + ">");
        return constExp;
    }
}
