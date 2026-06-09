/********************************************************************************
 * @FileName     : Parser.java
 * @Author       :
 * @Description  : 语法分析器
 * @Notice       : None
 * @Time         : 2024-10-13 16:43
 * @Version      : 0.0
 ********************************************************************************/

package frontend;

import config.Config;
import debug.Debug;
import error.ErrorHandler;
import node.ASTNode;
import node.Character;
import node.CompUnit;
import error.Error;
import error.ErrorType;
import node.*;
import node.Number;
import type.LexType;

import java.util.ArrayList;
import java.util.List;

public class Parser {
    private final List<Token> tokenList; // 用于存储分析得到的词法单元
    private int tokenIndex; // 表示当前分析的token位置
    private ASTNode rootCompUnit;
    private boolean is_analyze_success;

    public Parser(List<Token> tokenList) {
        this.tokenList = tokenList;
        this.rootCompUnit = null;
        this.tokenIndex = 0;
        this.is_analyze_success = true;
    }

    public boolean analyze() {
        try {
            this.rootCompUnit = handleCompUnit();
            if (tokenIndex != tokenList.size()) is_analyze_success = false;
        } catch (Error error) {
            is_analyze_success = false;
            parserPanic();
            // todo 优化抛出异常的逻辑
            if (Config.is_printStackTrace) error.printStackTrace();
        }
        return is_analyze_success;
    }

    public CompUnit handleCompUnit() {
        // CompUnit -> {Decl} {FuncDef} MainFuncDef
        List<Decl> declList = new ArrayList<>();
        List<FuncDef> funcDefList = new ArrayList<>();
        MainFuncDef mainFuncDef = null;
        // {Decl}
        while (getSymType(1).notEquals(LexType.MAINTK) && getSymType(2).notEquals(LexType.LPARENT)) {
            declList.add(handleDecl());
        }
        // {FuncDef}
        while (getSymType(1).notEquals(LexType.MAINTK)) {
            funcDefList.add(handleFuncDef());
        }
        // MainFuncDef
        mainFuncDef = handleMainFuncDef();
        // todo 错误处理！！！
        return new CompUnit(declList, funcDefList, mainFuncDef);
    }

    private Decl handleDecl() {
        // Decl -> ConstDecl | VarDecl
        ConstDecl constDecl = null;
        VarDecl varDecl = null;
        // ConstDecl
        if (getSymType().equals(LexType.CONSTTK)) {
            constDecl = handleConstDecl();
        }
        // VarDecl
        else if (VarDecl.isVarDecl(getSymType())) {
            varDecl = handleVarDecl();
        }
        else {
            throw new Error(ErrorType.OTHER_ERROR, getLineNumber());
        }
        return new Decl(constDecl, varDecl);
    }

    private ConstDecl handleConstDecl() {
        // ConstDecl -> 'const' BType ConstDef { ',' ConstDef } ';'
        Token constTk = null;
        BType btype = null;
        List<ConstDef> constDefList = new ArrayList<>();
        List<Token> commaList = new ArrayList<>();
        Token semicnTk = null;

        // 'const'
        constTk = handleTerminal(LexType.CONSTTK);

        // BType
        btype = handleBType();

        // 首个ConstDef
        constDefList.add(handleConstDef());

        // { ',' ConstDef }
        while (getSymType().equals(LexType.COMMA)) {
            // ','
            commaList.add(handleTerminal(LexType.COMMA));
            // ConstDef
            constDefList.add(handleConstDef());
        }
        // ';'
        semicnTk = handleTerminal(LexType.SEMICN);

        return new ConstDecl(constTk, btype, constDefList, commaList, semicnTk);
    }

    private BType handleBType() {
        // BType -> 'int' | 'char'
        Token bTypeTk = null;
        if (BType.isBType(getSymType())) {
            bTypeTk = getNowToken();
            nextIndex();
        }
        else {
            throw new Error(ErrorType.OTHER_ERROR, getLineNumber());
        }
        return new BType(bTypeTk);
    }

    private ConstDef handleConstDef() throws Error {
        //  ConstDef -> Ident [ '[' ConstExp ']' ] '=' ConstInitVal
        Ident indent = null;
        List<Token> leftBracketList = new ArrayList<>();
        List<ConstExp> constExpList = new ArrayList<>();
        List<Token> rightBracketList = new ArrayList<>();
        Token equalSym = null;
        ConstInitVal constInitVal = null;

        // Ident
        indent = handleIdent();

        // [ '[' ConstExp ']' ]
        while (getSymType().equals(LexType.LBRACK)) {
            // '['
            leftBracketList.add(handleTerminal(LexType.LBRACK));

            // ConstExp
            constExpList.add(handleConstExp());

            // ']'
            rightBracketList.add(handleTerminal(LexType.RBRACK));
        }

        // '='
        equalSym = handleTerminal(LexType.ASSIGN);

        // ConstInitVal
        constInitVal = handleConstInitVal();

        return new ConstDef(indent, leftBracketList, constExpList, rightBracketList, equalSym, constInitVal);
    }

    private ConstInitVal handleConstInitVal() throws Error {
        // todo 检查逻辑
        // ConstInitVal -> ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
        ConstExp constExpNode = null;
        Token leftBraceToken = null;
        List<ConstExp> constExpList = new ArrayList<>();
        List<Token> commas = new ArrayList<>();
        Token rightBraceToken = null;
        StringConst stringConst = null;

        // '{' [ ConstExp { ',' ConstExp } ] '}'
        if (getSymType() == LexType.LBRACE) {
            leftBraceToken = handleTerminal(LexType.LBRACE);
            if (ConstExp.isConstExp(getSymType())) {
                constExpList.add(handleConstExp());
                while (getSymType() == LexType.COMMA) {
                    commas.add(handleTerminal(LexType.COMMA));
                    constExpList.add(handleConstExp());
                }
            }
//            if (getSymType().notEquals(LexType.RBRACE)) {
//                constExpList.add(handleConstExp());
//                while (getSymType() == LexType.COMMA) {
//                    commas.add(handleTerminal(LexType.COMMA));
//                    constExpList.add(handleConstExp());
//                }
//            }
            rightBraceToken = handleTerminal(LexType.RBRACE);
        }
        // StringConst
        else if (getSymType() == LexType.STRCON) {
            stringConst = handleStringConst();
        }
        else {
            constExpNode = handleConstExp();
        }
        return new ConstInitVal(constExpNode, leftBraceToken, constExpList, commas, rightBraceToken, stringConst);
    }

    private VarDecl handleVarDecl() {
        // VarDecl -> BType VarDef { ',' VarDef } ';'
        BType bType = null;
        List<VarDef> varDefList = new ArrayList<>();
        List<Token> commaList = new ArrayList<>();
        Token semicnTk = null;
        // BType
        bType = handleBType();

        // 首个VarDef
        varDefList.add(handleVarDef());

        // { ',' VarDef }
        while (getSymType().equals(LexType.COMMA)) {
            // ','
            commaList.add(handleTerminal(LexType.COMMA));
            // VarDef
            varDefList.add(handleVarDef());
        }

        // ';'
        semicnTk = handleTerminal(LexType.SEMICN);

        return new VarDecl(bType, varDefList, commaList, semicnTk);
    }

    private VarDef handleVarDef() {
        // VarDef -> Ident { '[' ConstExp ']' } | Ident { '[' ConstExp ']' } '=' InitVal
        Ident ident = null;
        List<Token> leftBracketList = new ArrayList<>();
        List<ConstExp> constExpList = new ArrayList<>();
        List<Token> rightBracketList = new ArrayList<>();
        Token equalTk = null;
        InitVal initVal = null;

        // Ident
        ident = handleIdent();

        // { '[' ConstExp ']' } | Ident { '[' ConstExp ']' } '=' InitVal
        // { '[' ConstExp ']' }
        while (getSymType().equals(LexType.LBRACK)) {
            leftBracketList.add(handleTerminal(LexType.LBRACK));
            constExpList.add(handleConstExp());
            rightBracketList.add(handleTerminal(LexType.RBRACK));
        }
        // '=' InitVal
        if (getSymType().equals(LexType.ASSIGN)) {
            // '='
            equalTk = handleTerminal(LexType.ASSIGN);
            // InitVal
            initVal = handleInitVal();
        }
        return new VarDef(ident, leftBracketList, constExpList, rightBracketList, equalTk, initVal);
    }

    private InitVal handleInitVal() {
        // todo
        // InitVal ->  Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
        Exp expNode = null;
        Token leftBraceToken = null;
        List<Exp> expList = new ArrayList<>();
        List<Token> commas = new ArrayList<>();
        Token rightBraceToken = null;
        StringConst stringConst = null;

        // '{' [ Exp { ',' Exp } ] '}'
        if (getSymType().equals(LexType.LBRACE)) {
            // '{'
            leftBraceToken = handleTerminal(LexType.LBRACE);

            // [ Exp { ',' Exp } ]
            if (Exp.isExp(getSymType())) {
                expList.add(handleExp());
                // todo 优化逻辑
                while (getSymType().notEquals(LexType.RBRACE)) {
                    commas.add(handleTerminal(LexType.COMMA));
                    expList.add(handleExp());
                }
            }
//            if (getSymType().notEquals(LexType.RBRACE)) {
//                expList.add(handleExp());
//                while (getSymType().notEquals(LexType.RBRACE)) {
//                    commas.add(handleTerminal(LexType.COMMA));
//                    expList.add(handleExp());
//                }
//            }
            rightBraceToken = handleTerminal(LexType.RBRACE);
        }
        else if (getSymType().equals(LexType.STRCON)) {
            stringConst = handleStringConst();
        }
        else {
            expNode = handleExp();
        }
        return new InitVal(expNode, leftBraceToken, expList, commas, rightBraceToken, stringConst);
    }

    private FuncDef handleFuncDef() {
        // FuncDef -> FuncType Ident '(' [FuncFParams] ')' Block
        FuncType funcTypeNode = null;
        Ident ident = null;
        Token leftParent = null;
        FuncFParams funcParams = null;
        Token rightParent = null;
        Block block = null;


        // FuncType
        funcTypeNode = handleFuncType();

        // Ident
        ident = handleIdent();

        // '('
        leftParent = handleTerminal(LexType.LPARENT);

        // [FuncFParams]
        if (BType.isBType(getSymType())) {
            funcParams = handleFuncFParams();
        }

        // ')'
        rightParent = handleTerminal(LexType.RPARENT);

        // Block
        block = handleBlock();

        return new FuncDef(funcTypeNode, ident, leftParent, funcParams, rightParent, block);
    }

    private MainFuncDef handleMainFuncDef() throws Error {
        // MainFuncDef -> 'int' 'main' '(' ')' Block
        Token intTk = null;
        Token mainTk = null;
        Token leftParentTk = null;
        Token rightParentTk = null;
        Block block = null;

        // 'int'
        intTk = handleTerminal(LexType.INTTK);

        // 'main'
        mainTk = handleTerminal(LexType.MAINTK);

        // '('
        leftParentTk = handleTerminal(LexType.LPARENT);

        // ')'
        rightParentTk = handleTerminal(LexType.RPARENT);

        // Block
        block = handleBlock();

        return new MainFuncDef(intTk, mainTk, leftParentTk, rightParentTk, block);
    }

    private FuncType handleFuncType() {
        // FuncType -> 'void' | 'int' | 'char'
        LexType nowType = getSymType();
        Token nowToken = null;
        if (nowType == LexType.VOIDTK || nowType == LexType.INTTK || nowType == LexType.CHARTK) {
            nowToken = getNowToken();
            nextIndex();
        }
        else {
            throw new Error(ErrorType.OTHER_ERROR, getLineNumber());
        }
        return new FuncType(nowToken);
    }

    private FuncFParams handleFuncFParams() {
        // FuncFParams -> FuncFParam { ',' FuncFParam }
        List<FuncFParam> funcFParamList = new ArrayList<>();
        List<Token> commaList = new ArrayList<>();

        // 首个FuncFParam
        funcFParamList.add(handleFuncFParam());

        // { ',' FuncFParam }
        while (getSymType().equals(LexType.COMMA)) {
            // ','
            commaList.add(handleTerminal(LexType.COMMA));
            // FuncFParam
            funcFParamList.add(handleFuncFParam());
        }
        return new FuncFParams(funcFParamList, commaList);
    }

    private FuncFParam handleFuncFParam() {
        // // FuncFParam -> BType Ident [ '[' ']' ]
        BType bTypeNode = null;
        Ident ident = null;
        List<Token> leftBrackets = new ArrayList<>();
        List<Token> rightBrackets = new ArrayList<>();

        // BType
        bTypeNode = handleBType();

        // Ident
        ident = handleIdent();

        // [ '[' ']' ]
        if (getSymType().equals(LexType.LBRACK)) {
            // '['
            leftBrackets.add(handleTerminal(LexType.LBRACK));
            // ']'
            rightBrackets.add(handleTerminal(LexType.RBRACK));
        }
        return new FuncFParam(bTypeNode, ident, leftBrackets, rightBrackets);
    }

    private Block handleBlock() {
        // Block -> '{' { BlockItem } '}'
        Token leftBraceTk = null;
        List<BlockItem> blockItemList = new ArrayList<>();
        Token rightBraceTk = null;

        // '{'
        leftBraceTk = handleTerminal(LexType.LBRACE);

        // { BlockItem }
        // todo 优化判断条件
        while (getSymType().notEquals(LexType.RBRACE)) {
            blockItemList.add(handleBlockItem());
        }

        // '}'
        rightBraceTk = handleTerminal(LexType.RBRACE);
        return new Block(leftBraceTk, blockItemList, rightBraceTk);
    }

    private BlockItem handleBlockItem() {
        // BlockItem -> Decl | Stmt
        Decl decl = null;
        Stmt stmt = null;
        // Decl
        if (getSymType().equals(LexType.CONSTTK) || getSymType().equals(LexType.INTTK) || getSymType().equals(LexType.CHARTK)) {
            decl = handleDecl();
        }
        // Stmt
        else {
            stmt = handleStmt();
        }
        return new BlockItem(decl, stmt);
    }

    private Stmt handleStmt() {
        // Stmt -> LVal '=' Exp ';'
        //	| [Exp] ';'
        //	| Block
        //	| 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
        //	| 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
        //	| 'break' ';' | 'continue' ';'
        //	| 'return' [Exp] ';'
        //	| LVal '=' 'getint' '(' ')' ';'
        //  | LVal '=' 'getchar''('')'';'
        //	| 'printf' '(' FormatString { ',' Exp } ')' ';'
        if (getSymType() == LexType.LBRACE) {
            // Block
            Block blockNode = handleBlock();
            return new Stmt(Stmt.StmtType.Block, blockNode);
        }
        else if (getSymType() == LexType.PRINTFTK) {
            // 'printf' '(' FormatString { ',' Exp } ')' ';'
            Token printfToken = handleTerminal(LexType.PRINTFTK);
            Token leftParentToken = handleTerminal(LexType.LPARENT);
            // todo 考虑其类别判断
            // FormatString
            Token formatString = handleTerminal(LexType.STRCON);
            List<Token> commas = new ArrayList<>();
            List<Exp> expNodes = new ArrayList<>();
            // { ',' Exp }
            while (getSymType() == LexType.COMMA) {
                commas.add(handleTerminal(LexType.COMMA));
                expNodes.add(handleExp());
            }
            Token rightParentToken = handleTerminal(LexType.RPARENT);
            Token semicnToken = handleTerminal(LexType.SEMICN);
            return new Stmt(Stmt.StmtType.print, printfToken, leftParentToken, formatString, commas, expNodes, rightParentToken, semicnToken);
        }
        else if (getSymType() == LexType.IFTK) {
            // 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
            Token ifToken = handleTerminal(LexType.IFTK);
            Token leftParentToken = handleTerminal(LexType.LPARENT);
            Cond condNode = handleCond();
            Token rightParentToken = handleTerminal(LexType.RPARENT);
            List<Stmt> stmtNodes = new ArrayList<>();
            stmtNodes.add(handleStmt());
            Token elseToken = null;
            //  [ 'else' Stmt ]
            if (getSymType() == LexType.ELSETK) {
                elseToken = handleTerminal(LexType.ELSETK);
                stmtNodes.add(handleStmt());
            }
            return new Stmt(Stmt.StmtType.ifBranch, ifToken, leftParentToken, condNode, rightParentToken, stmtNodes, elseToken);
        }
        else if (getSymType() == LexType.FORTK) {
            // 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
            List<Token> semicnList = new ArrayList<>();
            // 'for'
            Token forToken = handleTerminal(LexType.FORTK);
            // '('
            Token leftParentToken = handleTerminal(LexType.LPARENT);
            // [ForStmt]
            ForStmt forStmt1 = null;
            if (ForStmt.isForStmt(getSymType())) {
                forStmt1 = hanldeForStmt();
            }
//            if (getSymType().notEquals(LexType.SEMICN)) {
//                forStmt1 = hanldeForStmt();
//            }
            // ';'
            semicnList.add(handleTerminal(LexType.SEMICN));
            // [Cond]
            // todo 优化逻辑
            Cond cond = null;
            if (getSymType().notEquals(LexType.SEMICN)) {
                cond = handleCond();
            }
            // ';'
            semicnList.add(handleTerminal(LexType.SEMICN));
            // [ForStmt]
            ForStmt forStmt2 = null;
            if (ForStmt.isForStmt(getSymType())) {
                forStmt2 = hanldeForStmt();
            }
//            if (getSymType().notEquals(LexType.RPARENT)) {
//                forStmt2 = hanldeForStmt();
//            }
            // ')'
            Token rightParentToken = handleTerminal(LexType.RPARENT);
            // Stmt
            List<Stmt> stmts = new ArrayList<>();
            stmts.add(handleStmt());
            return new Stmt(Stmt.StmtType.forBranch, forToken, leftParentToken, forStmt1, cond, forStmt2, rightParentToken, stmts, semicnList);
        }
        else if (getSymType() == LexType.BREAKTK) {
            // 'break' ';'
            Token breakToken = handleTerminal(LexType.BREAKTK);
            Token semicnToken = handleTerminal(LexType.SEMICN);
            return new Stmt(Stmt.StmtType.breakStmt, breakToken, semicnToken);
        }
        else if (getSymType() == LexType.CONTINUETK) {
            // 'continue' ';'
            Token continueToken = handleTerminal(LexType.CONTINUETK);
            Token semicnToken = handleTerminal(LexType.SEMICN);
            return new Stmt(Stmt.StmtType.continueStmt, continueToken, semicnToken);
        }
        else if (getSymType() == LexType.RETURNTK) {
            // 'return' [Exp] ';'
            Token returnToken = handleTerminal(LexType.RETURNTK);
            Exp expNode = null;
            // todo 解决 Exp.isExp(getSymType()) 错误
            if (Exp.isExp(getSymType())) {
                expNode = handleExp();
            }
            Token semicnToken = handleTerminal(LexType.SEMICN);
            return new Stmt(Stmt.StmtType.returnStmt, returnToken, expNode, semicnToken);
        }
        else {
            // todo 优化判断逻辑
            boolean is_lval = false;
            int record_index = tokenIndex; // 记录当前token指针
            LVal lValNode = null;

            // 要确保是LVal，需要排除 UnaryExp -> PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp 中的第二种情况
            if (LVal.isLVal(getSymType()) && getSymType(1).notEquals(LexType.LPARENT)) {
                lValNode = handleLVal();
                // 判断是哪一种情况
                if (getSymType().equals(LexType.ASSIGN)) {
                    is_lval = true;
                }
            }

            if (is_lval) {
                // LVal '=' Exp ';'
                // LVal '=' 'getint' '(' ')' ';'
                // LVal '=' 'getchar' '(' ')' ';'
                Token assignToken = handleTerminal(LexType.ASSIGN);
                if (getSymType() == LexType.GETINTTK) {
                    Token getintToken = handleTerminal(LexType.GETINTTK);
                    Token leftParentToken = handleTerminal(LexType.LPARENT);
                    Token rightParentToken = handleTerminal(LexType.RPARENT);
                    Token semicnToken = handleTerminal(LexType.SEMICN);
                    return new Stmt(Stmt.StmtType.inputInt, lValNode, assignToken, getintToken, leftParentToken, rightParentToken, semicnToken);
                }
                else if (getSymType() == LexType.GETCHARTK) {
                    Token getintToken = handleTerminal(LexType.GETCHARTK);
                    Token leftParentToken = handleTerminal(LexType.LPARENT);
                    Token rightParentToken = handleTerminal(LexType.RPARENT);
                    Token semicnToken = handleTerminal(LexType.SEMICN);
                    return new Stmt(Stmt.StmtType.intputChar, lValNode, assignToken, getintToken, leftParentToken, rightParentToken, semicnToken);
                }
                else {
                    Exp expNode = handleExp();
                    Token semicnToken = handleTerminal(LexType.SEMICN);
                    return new Stmt(Stmt.StmtType.Assign, lValNode, assignToken, expNode, semicnToken);
                }
            }
            else {
                tokenIndex = record_index; // 回退token指针
                if (Exp.isExp(getSymType()) || getSymType().equals(LexType.SEMICN)) {
                    // [Exp] ';'
                    Exp expNode = null;
                    // todo 优化 Exp.isExp(getSymType())
                    if (Exp.isExp(getSymType())) {
                        expNode = handleExp();
                    }
                    Token semicnToken = handleTerminal(LexType.SEMICN);
                    return new Stmt(Stmt.StmtType.Exp, expNode, semicnToken);
                }
                else {
                    throw new Error(ErrorType.OTHER_ERROR, getLineNumber());
                }
            }
        }
    }

    public ForStmt hanldeForStmt() {
        // ForStmt -> LVal '=' Exp
        // LVal
        LVal lval = handleLVal();
        // '='
        Token assign = handleTerminal(LexType.ASSIGN);
        // Exp
        Exp exp = handleExp();
        return new ForStmt(lval, assign, exp);
    }

    private Exp handleExp() {
        // Exp -> AddExp
        return new Exp(handleAddExp());
    }

    private Cond handleCond() {
        // Cond -> LOrExp
        return new Cond(handleLOrExp());
    }

    private LVal handleLVal() {
        // LVal -> Ident {'[' Exp ']'}
        Ident ident = null;
        List<Token> leftBrackets = new ArrayList<>();
        List<Exp> expNodes = new ArrayList<>();
        List<Token> rightBrackets = new ArrayList<>();

        // Ident
        ident = handleIdent();

        // {'[' Exp ']'}
        while (getSymType() == LexType.LBRACK) {
            // '['
            leftBrackets.add(handleTerminal(LexType.LBRACK));
            // Exp
            expNodes.add(handleExp());
            // ']'
            rightBrackets.add(handleTerminal(LexType.RBRACK));
        }
        return new LVal(ident, leftBrackets, expNodes, rightBrackets);
    }

    private PrimaryExp handlePrimaryExp() {
        // PrimaryExp -> '(' Exp ')' | LVal | Numberr | Character
        Token leftParentToken = null;
        Exp exp = null;
        Token rightParentToken = null;
        LVal lVal = null;
        Number number = null;
        Character character = null;

        // '(' Exp ')'
        if (getSymType() == LexType.LPARENT) {
            leftParentToken = handleTerminal(LexType.LPARENT);
            exp = handleExp();
            rightParentToken = handleTerminal(LexType.RPARENT);
        }
        // Numberr
        else if (getSymType() == LexType.INTCON) {
            number = handleNumber();
        }
        // Character
        else if (getSymType() == LexType.CHRCON) {
            character = handleCharacter();
        }
        else { // todo 错误处理
            lVal = handleLVal();
        }
        return new PrimaryExp(leftParentToken, exp, rightParentToken, lVal, number, character);
    }

    private Number handleNumber() {
        // Number -> IntConst
        IntConst intConst = handleIntConst();
        return new Number(intConst);
    }

    private UnaryExp handleUnaryExp() {
        // UnaryExp -> PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
        //  Ident '(' [FuncRParams] ')'
        if (getSymType() == LexType.IDENFR && getSymType(1) == LexType.LPARENT) {
            Ident ident = handleIdent();
            Token leftParentToken = handleTerminal(LexType.LPARENT);
            FuncRParams funcRParamsNode = null;
            if (FuncRParams.isFuncRParams(getSymType())) {
                funcRParamsNode = handleFuncRParams();
            }
            Token rightParentToken = handleTerminal(LexType.RPARENT);

            return new UnaryExp(ident, leftParentToken, funcRParamsNode, rightParentToken);
        }
        // UnaryOp UnaryExp
        else if (UnaryOp.isUnaryOp(getSymType())) {
            UnaryOp unaryOpNode = handleUnaryOp();
            UnaryExp unaryExpNode = handleUnaryExp();
            return new UnaryExp(unaryOpNode, unaryExpNode);
        }
        // PrimaryExp
        else {
            PrimaryExp primaryExpNode = handlePrimaryExp();
            return new UnaryExp(primaryExpNode);
        }
    }


    private UnaryOp handleUnaryOp() {
        // UnaryOp -> '+' | '−' | '!'
        Token token;
        if (UnaryOp.isUnaryOp(getSymType())) {
            token = getNowToken();
            nextIndex();
        }
        else {
            throw new Error(ErrorType.OTHER_ERROR, getLineNumber());
        }
        return new UnaryOp(token);
    }

    private FuncRParams handleFuncRParams() {
        // FuncRParams -> Exp { ',' Exp }
        List<Exp> expNodes = new ArrayList<>();
        List<Token> commas = new ArrayList<>();
        expNodes.add(handleExp());
        while (getSymType() == LexType.COMMA) {
            commas.add(handleTerminal(LexType.COMMA));
            expNodes.add(handleExp());
        }
        return new FuncRParams(expNodes, commas);
    }

    private MulExp handleMulExp() {
        // MulExp -> UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
        List<UnaryExp> unaryExpArrayList = new ArrayList<>();
        List<Token> opList = new ArrayList<>();
        unaryExpArrayList.add(handleUnaryExp());
        while (getSymType() == LexType.MULT || getSymType() == LexType.DIV || getSymType() == LexType.MOD) {
            if (getSymType() == LexType.MULT) {
                opList.add(handleTerminal(LexType.MULT));
            }
            else if (getSymType() == LexType.DIV) {
                opList.add(handleTerminal(LexType.DIV));
            }
            else if (getSymType() == LexType.MOD) {
                opList.add(handleTerminal(LexType.MOD));
            }
            // todo 错误处理
            unaryExpArrayList.add(handleUnaryExp());
        }
        return new MulExp(opList, unaryExpArrayList);
    }

    private AddExp handleAddExp() throws Error {
        // todo 圆括号表示什么？
        // AddExp -> MulExp | AddExp ('+' | '−') MulExp
        // AddExp -> MulExp { ('+' | '−') MulExp }
        List<Token> opList = new ArrayList<>();
        List<MulExp> mulExpList = new ArrayList<>();
        // MulExp
        mulExpList.add(handleMulExp());
        while (getSymType().equals(LexType.PLUS) || getSymType().equals(LexType.MINU)) {
            if (getSymType().equals(LexType.PLUS)) {
                opList.add(handleTerminal(LexType.PLUS));
            }
            else if (getSymType().equals(LexType.MINU)) {
                opList.add(handleTerminal(LexType.MINU));
            }
            mulExpList.add(handleMulExp());
        }
        return new AddExp(opList, mulExpList);
    }

    private RelExp handleRelExp() {
        // RelExp -> AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
        List<AddExp> addExpList = new ArrayList<>();
        List<Token> opList = new ArrayList<>();
        addExpList.add(handleAddExp());
        while (getSymType() == LexType.LSS || getSymType() == LexType.GRE || getSymType() == LexType.LEQ || getSymType() == LexType.GEQ) {
            if (getSymType() == LexType.LSS) {
                opList.add(handleTerminal(LexType.LSS));
            }
            else if (getSymType() == LexType.GRE) {
                opList.add(handleTerminal(LexType.GRE));
            }
            else if (getSymType() == LexType.LEQ) {
                opList.add(handleTerminal(LexType.LEQ));
            }
            else if (getSymType() == LexType.GEQ) {
                opList.add(handleTerminal(LexType.GEQ));
            }
            addExpList.add(handleAddExp());
        }
        return new RelExp(addExpList, opList);
    }

    private EqExp handleEqExp() {
        // EqExp -> RelExp | EqExp ('==' | '!=') RelExp
        List<RelExp> relExpList = new ArrayList<>();
        List<Token> opList = new ArrayList<>();
        relExpList.add(handleRelExp());
        while (getSymType() == LexType.EQL || getSymType() == LexType.NEQ) {
            if (getSymType() == LexType.EQL) {
                opList.add(handleTerminal(LexType.EQL));
            }
            else if (getSymType() == LexType.NEQ) {
                opList.add(handleTerminal(LexType.NEQ));
            }
            relExpList.add(handleRelExp());
        }
        return new EqExp(relExpList, opList);
    }

    private LAndExp handleLAndExp() {
        // LAndExp -> EqExp | LAndExp '&&' EqExp
        List<EqExp> eqExpList = new ArrayList<>();
        List<Token> opList = new ArrayList<>();
        eqExpList.add(handleEqExp());
        while (getSymType().equals(LexType.AND)) {
            opList.add(handleTerminal(LexType.AND));
            eqExpList.add(handleEqExp());
        }
        return new LAndExp(eqExpList, opList);
    }


    private LOrExp handleLOrExp() {
        // LOrExp -> LAndExp | LOrExp '||' LAndExp
        List<LAndExp> lAndExpList = new ArrayList<>();
        List<Token> opList = new ArrayList<>();
        lAndExpList.add(handleLAndExp());

        while (getSymType().equals(LexType.OR)) {
            opList.add(handleTerminal(LexType.OR));
            lAndExpList.add(handleLAndExp());
        }
        return new LOrExp(lAndExpList, opList);
    }


    private ConstExp handleConstExp() throws Error {
        // ConstExp -> AddExp  注：使用的 Ident 必须是常量
        AddExp addExp = handleAddExp();
        return new ConstExp(addExp);
    }


    public void nextIndex() throws Error {
        if (!this.checkTokenIndexRange(tokenIndex)) {
            throw new Error(ErrorType.OVER_RANGE, -1);
        }
        this.tokenIndex++;
    }

    // tokenIndex范围是否合法
    private boolean checkTokenIndexRange(int ind) {
        return ind < tokenList.size() && ind >= 0;
    }

    // 获取当前token的类型
    public LexType getSymType() {
        return tokenList.get(tokenIndex).getTokenType();
    }

    // 获取偏移后token的类型（偏移量offset）
    public LexType getSymType(int offset) {
        if (!this.checkTokenIndexRange(tokenIndex + offset)) {
            throw new Error(ErrorType.OVER_RANGE, -1);
        }
        return tokenList.get(tokenIndex + offset).getTokenType();
    }

    // debug模式下，打印当前token
    public void printSymDebug() {
        if (Debug.is_debugging && Debug.use_parser_info_print) System.out.println(getNowToken().toString());
    }

    // debug模式下，打印信息
    public void printInfoDebug(String info) {
        if (Debug.is_debugging && Debug.use_parser_info_print) System.out.println(info);
    }

    // 获取当前token
    public Token getNowToken() throws Error {
        if (!this.checkTokenIndexRange(tokenIndex)) {
            throw new Error(ErrorType.OVER_RANGE, -1);
        }
        return tokenList.get(tokenIndex);
    }


    // 处理终结符
    private Token handleTerminal(LexType lexType) {
        if (getSymType().equals(lexType)) {
            Token token = getNowToken();
            nextIndex();
            return token;
        }
        is_analyze_success = false;
        if (lexType.equals(LexType.SEMICN)) {
            ErrorHandler.recordError(ErrorType.SEMICN_MISSING, getLineNumber(-1));
        }
        else if (lexType.equals(LexType.RPARENT)) {
            ErrorHandler.recordError(ErrorType.RPARENT_MISSING, getLineNumber(-1));
        }
        else if (lexType.equals(LexType.RBRACK)) {
            ErrorHandler.recordError(ErrorType.RBRACK_MISSING, getLineNumber(-1));
        }
        else {
            throw new Error(ErrorType.OTHER_ERROR, getLineNumber());
        }
        return null;
    }

    private Ident handleIdent() {
        if (!Ident.isIdent(getSymType()))
            throw new Error(ErrorType.OTHER_ERROR, getLineNumber());
        Token token = getNowToken();
        nextIndex();
        return new Ident(token);
    }

    private IntConst handleIntConst() {
        if (!IntConst.isIntConst(getSymType()))
            throw new Error(ErrorType.OTHER_ERROR, getLineNumber());
        Token token = getNowToken();
        nextIndex();
        return new IntConst(token);
    }

    private StringConst handleStringConst() {
        if (!StringConst.isStringConst(getSymType())) throw new Error(ErrorType.OTHER_ERROR, getLineNumber());
        Token token = getNowToken();
        nextIndex();
        return new StringConst(token);
    }

    private Character handleCharacter() {
        // Character -> CharConst
        if (getSymType().notEquals(LexType.CHRCON))
            throw new Error(ErrorType.OTHER_ERROR, getLineNumber());
        CharConst charConst = handleCharConst();
        return new Character(charConst);
    }

    private CharConst handleCharConst() {
        // CharConst -> '\''ASCII'\''
        if (getSymType().notEquals(LexType.CHRCON))
            throw new Error(ErrorType.OTHER_ERROR, getLineNumber());
        Token token = getNowToken();
        nextIndex();
        return new CharConst(token);
    }

    // 获取当前行数
    public int getLineNumber() {
        return getNowToken().getLineNumber();
    }

    // 获取偏移后的行数
    public int getLineNumber(int offset) {
        if (checkTokenIndexRange(tokenIndex + offset))
            return tokenList.get(tokenIndex + offset).getLineNumber();
        else
            throw new Error(ErrorType.OVER_RANGE, getLineNumber());
    }


    public void parserPanic() {
        // 在debug模式下显示错误信息（错误行位置+当前token）
//        System.out.println("Error: " + error.errorType);
        String errorMsgLast = "last token: " + tokenList.get(tokenIndex - 1).toString() + "  at line: " + getLineNumber(-1);
        String errorMsgNow = "now token: " + getNowToken().toString() + "  at line: " + getLineNumber();
        String errorMsgNext = "next token: " + tokenList.get(tokenIndex + 1).toString() + "  at line: " + getLineNumber(1);
        Debug.panic("Error during parser analysis at line " + getLineNumber() + "\n" + errorMsgLast + "\n" + errorMsgNow + "\n" + errorMsgNext);
    }

    // 打印分析结果
    public void printParseAns() {
        if (is_analyze_success) rootCompUnit.printInfo();
    }

}
