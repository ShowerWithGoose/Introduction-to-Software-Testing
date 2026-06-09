package frontend;

import node.*;
import node.Character;
import node.Number;
import token.Token;
import token.TokenType;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import static error.Error.error;

import error.ErrorType;

public class Parser {
    private static final Parser instance = new Parser(); //只需要创建一个对象，采用单例模式

    public static Parser getInstance() {
        return instance;
    }

    private List<Token> tokens = new ArrayList<>();
    private int token_index = 0;

    private void initTokens() {
        tokens = Lexer.getInstance().getToken();
    }

    private boolean haveError = false;

    public void analyze() throws IOException { //语法分析入口
        initTokens();
        for (Token token : tokens)
            System.out.println(token.content);
        CompUnit compUnit = compUnit();
        if (!haveError) {
            compUnit.print();
        }
    }

    private Token expect(TokenType expectType, TokenType actualType) throws IOException { //期望匹配到分号、右小括号、右中括号，否则报错
        if (expectType == TokenType.SEMICN && actualType != TokenType.SEMICN) {
            haveError = true;
            error(tokens.get(token_index - 1).lineNumber, ErrorType.i);
            return new Token(TokenType.SEMICN,";",tokens.get(token_index-1).lineNumber);
        } else if (expectType == TokenType.RPARENT && actualType != TokenType.RPARENT) {
            haveError = true;
            error(tokens.get(token_index - 1).lineNumber, ErrorType.j);
            return new Token(TokenType.SEMICN,")",tokens.get(token_index-1).lineNumber);
        } else if (expectType == TokenType.RBRACK && actualType != TokenType.RBRACK) {
            haveError = true;
            error(tokens.get(token_index - 1).lineNumber, ErrorType.k);
            return new Token(TokenType.SEMICN,"]",tokens.get(token_index-1).lineNumber);
        }
        return tokens.get(token_index++);
    }

    // 编译单元 CompUnit → {Decl} {FuncDef} MainFuncDef 花括号表示【0到多个】
    private CompUnit compUnit() throws IOException {
        List<Decl> declList = new ArrayList<>();
        List<FuncDef> funcDefList = new ArrayList<>();
        MainFuncDef mainFuncDef = null;

        while (tokens.get(token_index + 1).type != TokenType.MAINTK && tokens.get(token_index + 2).type != TokenType.LPARENT) { //声明
            System.out.println("\n\n这是声明\n\n");
            declList.add(decl());
            System.out.println("\n\n声明部分结束！！！！\n\n");
        }
        while (tokens.get(token_index + 1).type != TokenType.MAINTK) { //函数
            System.out.println("\n\n这是函数\n\n");
            funcDefList.add(funcDef());
            System.out.println("\n\n函数部分结束！！！！\n\n");
        }
        if (tokens.get(token_index + 1).type == TokenType.MAINTK) { //主函数
            System.out.println("\n\n这是主函数\n\n");
            mainFuncDef = mainFuncDef();
            System.out.println("\n主函数结束\n");
        }

        return new CompUnit("<CompUnit>", declList, funcDefList, mainFuncDef);
    }

    // 声明 Decl → ConstDecl | VarDecl
    private Decl decl() throws IOException {
        ConstDecl constDecl = null;
        VarDecl varDecl = null;
        if (tokens.get(token_index).type == TokenType.CONSTTK) { //是常量声明
            constDecl = constDecl();
            System.out.println("以上是常量声明");
        } else { //是变量声明
            varDecl = varDecl();
            System.out.println("以上是变量声明");
        }
        return new Decl(constDecl, varDecl);
    }

    // 常量声明 ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';'
    private ConstDecl constDecl() throws IOException {
        Token constToken = null;
        BType bType = null;
        List<ConstDef> constDefList = new ArrayList<>();
        List<Token> commaTokenList = new ArrayList<>();
        Token semiToken = null;

        constToken = tokens.get(token_index++);
        bType = bType();
        constDefList.add(constDef());
        while (tokens.get(token_index).type == TokenType.COMMA) {
            commaTokenList.add(tokens.get(token_index++));
            constDefList.add(constDef());
        }
        semiToken = expect(TokenType.SEMICN, tokens.get(token_index).type);
        return new ConstDecl("<ConstDecl>", constToken, bType, constDefList, commaTokenList, semiToken);
    }

    // 基本类型 BType → 'int' | 'char'
    private BType bType() {
        Token intToken = null;
        Token charToken = null;
        if (tokens.get(token_index).type == TokenType.INTTK)
            intToken = tokens.get(token_index++);
        else
            charToken = tokens.get(token_index++);
        return new BType(intToken, charToken);
    }

    // 常量定义 ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal
    private ConstDef constDef() throws IOException {
        Token identToken = null;
        Token lbrackToken = null;
        ConstExp constExp = null;
        Token rbrackToken = null;
        Token assignToken = null;
        ConstInitval constInitval = null;

        identToken = tokens.get(token_index++);
        if (tokens.get(token_index).type == TokenType.LBRACK) {
            lbrackToken = tokens.get(token_index++);
            constExp = constExp();
            rbrackToken = expect(TokenType.RBRACK, tokens.get(token_index).type);
        }
        assignToken = tokens.get(token_index++);
        constInitval = constInitval();
        return new ConstDef("<ConstDef>", identToken, lbrackToken, constExp, rbrackToken, assignToken, constInitval);
    }

    // 常量初值 ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
    private ConstInitval constInitval() throws IOException {
        List<ConstExp> constExpList = new ArrayList<>();
        Token lbraceToken = null;
        List<Token> commaTokenList = new ArrayList<>();
        Token rbraceToken = null;
        Token stringToken = null;

        if (tokens.get(token_index).type == TokenType.STRCON) { //是StringConst
            stringToken = tokens.get(token_index++);
        } else if (tokens.get(token_index).type == TokenType.LBRACE) { //是左花括号，'{' [ ConstExp { ',' ConstExp } ] '}'
            lbraceToken = tokens.get(token_index++);
            if (tokens.get(token_index).type != TokenType.RBRACE) { //中括号内存在
                constExpList.add(constExp());
                while (tokens.get(token_index).type == TokenType.COMMA) { //花括号内存在
                    commaTokenList.add(tokens.get(token_index++));
                    constExpList.add(constExp());
                }
            }
            rbraceToken = tokens.get(token_index++);
        } else {
            constExpList.add(constExp());
        }
        return new ConstInitval("<ConstInitVal>", lbraceToken, rbraceToken, constExpList, commaTokenList, stringToken);
    }

    // 变量声明 VarDecl → BType VarDef { ',' VarDef } ';'
    private VarDecl varDecl() throws IOException {
        BType bType = null;
        List<VarDef> varDefList = new ArrayList<>();
        List<Token> commaTokenList = new ArrayList<>();
        Token semiToken = null;

        bType = bType();
        varDefList.add(varDef());
        while (tokens.get(token_index).type == TokenType.COMMA) { //花括号内存在
            commaTokenList.add(tokens.get(token_index++));
            varDefList.add(varDef());
        }
        semiToken = expect(TokenType.SEMICN, tokens.get(token_index).type);
        return new VarDecl("<VarDecl>", bType, varDefList, commaTokenList, semiToken);
    }

    // 变量定义 VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal
    private VarDef varDef() throws IOException {
        Token identToken = null;
        Token lbrackToken = null;
        ConstExp constExp = null;
        Token rbrackToken = null;
        Token assignToken = null;
        InitVal initval = null;

        identToken = tokens.get(token_index++);
        if (tokens.get(token_index).type == TokenType.LBRACK) {
            lbrackToken = tokens.get(token_index++);
            constExp = constExp();
            rbrackToken = expect(TokenType.RBRACK, tokens.get(token_index).type);
        }
        if (tokens.get(token_index).type == TokenType.ASSIGN) {
            assignToken = tokens.get(token_index++);
            initval = initval();
        }
        return new VarDef("<VarDef>", identToken, lbrackToken, constExp, rbrackToken, assignToken, initval);
    }

    // 变量初值 InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
    private InitVal initval() throws IOException {
        List<Exp> expList = new ArrayList<>();
        Token lbraceToken = null;
        List<Token> commaTokenList = new ArrayList<>();
        Token rbraceToken = null;
        Token stringToken = null;

        if (tokens.get(token_index).type == TokenType.STRCON) { //是StringConst
            stringToken = tokens.get(token_index++);
        } else if (tokens.get(token_index).type == TokenType.LBRACE) { // 是'{' [ Exp { ',' Exp } ] '}'
            lbraceToken = tokens.get(token_index++);
            if (tokens.get(token_index).type != TokenType.RBRACE) {
                expList.add(exp());
                while (tokens.get(token_index).type == TokenType.COMMA) {
                    commaTokenList.add(tokens.get(token_index++));
                    expList.add(exp());
                }
            }
            rbraceToken = tokens.get(token_index++);
        } else {
            expList.add(exp());
        }
        return new InitVal("<InitVal>", lbraceToken, expList, commaTokenList, rbraceToken, stringToken);
    }

    // 函数定义 FuncDef → FuncType Ident '(' [FuncFParams] ')' Block
    private FuncDef funcDef() throws IOException {
        FuncType funcType = null;
        Token identToken = null;
        Token lparentToken = null;
        FuncFParams funcFParams = null;
        Token rparentToken = null;
        Block block = null;

        funcType = funcType();
        identToken = tokens.get(token_index++);
        lparentToken = tokens.get(token_index++);
        if (tokens.get(token_index + 1).type == TokenType.IDENFR) //存在形参
            funcFParams = funcFParams();
        rparentToken = expect(TokenType.RPARENT, tokens.get(token_index).type);
        block = block();

        System.out.println("\n调用block完毕！！！！\n");
        return new FuncDef("<FuncDef>", funcType, identToken, lparentToken, funcFParams, rparentToken, block);
    }

    // 主函数定义 MainFuncDef → 'int' 'main' '(' ')' Block
    private MainFuncDef mainFuncDef() throws IOException {
        Token identToken = tokens.get(token_index++);
        Token mainToken = tokens.get(token_index++);
        Token lparentToken = tokens.get(token_index++);
        Token rparentToken = expect(TokenType.RPARENT, tokens.get(token_index).type);
        Block block = block();
        return new MainFuncDef("<MainFuncDef>", identToken, mainToken, lparentToken, rparentToken, block);
    }

    // 函数类型 FuncType → 'void' | 'int' | 'char'
    private FuncType funcType() {
        Token voidToken = null;
        Token intToken = null;
        Token charToken = null;

        if (tokens.get(token_index).type == TokenType.VOIDTK)
            voidToken = tokens.get(token_index++);
        else if (tokens.get(token_index).type == TokenType.INTTK)
            intToken = tokens.get(token_index++);
        else
            charToken = tokens.get(token_index++);

        return new FuncType("<FuncType>", voidToken, intToken, charToken);
    }

    // 函数形参表 FuncFParams → FuncFParam { ',' FuncFParam }
    private FuncFParams funcFParams() throws IOException {
        List<FuncFParam> funcFParamList = new ArrayList<>();
        List<Token> commaTokenList = new ArrayList<>();

        funcFParamList.add(funcFParam());
        while (tokens.get(token_index).type == TokenType.COMMA) {
            commaTokenList.add(tokens.get(token_index++));
            funcFParamList.add(funcFParam());
        }
        return new FuncFParams("<FuncFParams>", funcFParamList, commaTokenList);
    }

    // 函数形参 FuncFParam → BType Ident ['[' ']']
    private FuncFParam funcFParam() throws IOException {
        BType bType = null;
        Token identToken = null;
        Token lbrackToken = null;
        Token rbrackToken = null;

        bType = bType();
        identToken = tokens.get(token_index++);
        if (tokens.get(token_index).type == TokenType.LBRACK) {
            lbrackToken = tokens.get(token_index++);
            rbrackToken = expect(TokenType.RBRACK, tokens.get(token_index).type);
        }
        return new FuncFParam("<FuncFParam>", bType, identToken, lbrackToken, rbrackToken);
    }

    // 语句块 Block → '{' { BlockItem } '}'
    private Block block() throws IOException {
        Token lbrackToken = null;
        List<BlockItem> blockItemList = new ArrayList<>();
        Token rbrackToken = null;

        lbrackToken = tokens.get(token_index++);
        while (tokens.get(token_index).type != TokenType.RBRACE) {
            blockItemList.add(blockItem());
        }

        System.out.println("当前处在block函数内，当前token是" + tokens.get(token_index).content);

        if (token_index == tokens.size() - 1) { //注意，文件的末尾一定是block的花括号，不要越界了
            rbrackToken = tokens.get(token_index);
        } else {
            rbrackToken = tokens.get(token_index++);
        }

        return new Block("<Block>", lbrackToken, rbrackToken, blockItemList);
    }

    // 语句块项 BlockItem → Decl | Stmt
    private BlockItem blockItem() throws IOException {
        Decl decl = null;
        Stmt stmt = null;
        if (tokens.get(token_index).type == TokenType.CONSTTK || tokens.get(token_index).type == TokenType.INTTK || tokens.get(token_index).type == TokenType.CHARTK) {
            decl = decl();
            System.out.println("以上是声明");
        } else {
            stmt = stmt();
            System.out.println("以上是语句");
            System.out.println("当前处在blockItem函数内，当前token是" + tokens.get(token_index).content);
        }
        return new BlockItem(decl, stmt);
    }

    /*语句 Stmt → LVal '=' Exp ';'
        | [Exp] ';'
        | Block
        | 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
        | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
        | 'break' ';' | 'continue' ';'
        | 'return' [Exp] ';'
        | LVal '=' 'getint''('')'';'
        | LVal '=' 'getchar''('')'';'
        | 'printf''('StringConst {','Exp}')'';'  */
    private Stmt stmt() throws IOException {
        LVal lVal = null;
        Token assignToken = null, lparentToken = null, rparentToken = null;
        Token semiToken1 = null, semiToken2 = null;
        Block block = null;
        Token ifToken = null, elseToken = null, forToken = null;
        Cond cond = null;
        Stmt stmt1 = null, stmt2 = null;
        ForStmt forStmt1 = null, forStmt2 = null;
        Token breakToken = null, continueToken = null, returnToken = null, printfToken = null;
        Token getIntToken = null, getCharToken = null, stringToken = null;
        List<Token> commaTokenList = new ArrayList<>();
        List<Exp> expList = new ArrayList<>();


        if (tokens.get(token_index).type == TokenType.LBRACE) { // Block
            block = block();
        } else if (tokens.get(token_index).type == TokenType.RETURNTK) { // 'return' [Exp] ';'
            System.out.println("存在return语句");
            returnToken = tokens.get(token_index++);
            if (tokens.get(token_index).type != TokenType.SEMICN) { // 存在Exp
                expList.add(exp());
            }
            System.out.println("当前token是" + tokens.get(token_index).content);
            semiToken1 = expect(TokenType.SEMICN, tokens.get(token_index).type);
            System.out.println("当前token是" + tokens.get(token_index).content);
        } else if (tokens.get(token_index).type == TokenType.BREAKTK) { // 'break' ';'
            breakToken = tokens.get(token_index++);
            semiToken1 = expect(TokenType.SEMICN, tokens.get(token_index).type);
        } else if (tokens.get(token_index).type == TokenType.CONTINUETK) { // 'continue' ';'
            continueToken = tokens.get(token_index++);
            semiToken1 = expect(TokenType.SEMICN, tokens.get(token_index).type);
        } else if (tokens.get(token_index).type == TokenType.FORTK) { // 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
            forToken = tokens.get(token_index++);
            lparentToken = tokens.get(token_index++);
            if (tokens.get(token_index).type != TokenType.SEMICN) { //存在ForStmt
                forStmt1 = forStmt();
            }
            semiToken1 = tokens.get(token_index++);
            if (tokens.get(token_index).type != TokenType.SEMICN) { //存在Cond
                cond = cond();
            }
            semiToken2 = tokens.get(token_index++);
            if (tokens.get(token_index).type != TokenType.RPARENT) { //存在第二个ForStmt
                forStmt2 = forStmt();
            }
            rparentToken = tokens.get(token_index++);
            stmt1 = stmt();
        } else if (tokens.get(token_index).type == TokenType.PRINTFTK) { // 'printf' '(' StringConst {','Exp} ')' ';'
            System.out.println("存在printf语句");
            printfToken = tokens.get(token_index++);
            lparentToken = tokens.get(token_index++);
            stringToken = tokens.get(token_index++);
            while (tokens.get(token_index).type == TokenType.COMMA) {
                commaTokenList.add(tokens.get(token_index++));
                expList.add(exp());
            }
            rparentToken = expect(TokenType.RPARENT, tokens.get(token_index).type);
            semiToken1 = expect(TokenType.SEMICN, tokens.get(token_index).type);
        } else if (tokens.get(token_index).type == TokenType.IFTK) { // 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
            ifToken = tokens.get(token_index++);
            lparentToken = tokens.get(token_index++);
            cond = cond();
            rparentToken = expect(TokenType.RPARENT, tokens.get(token_index).type);
            stmt1 = stmt();
            if (tokens.get(token_index).type == TokenType.ELSETK) {
                elseToken = tokens.get(token_index++);
                stmt2 = stmt();
            }
        } else {
            int assign = token_index;
            for (int i = token_index; i < tokens.size() && tokens.get(i).lineNumber == tokens.get(token_index).lineNumber; i++) {
                if (tokens.get(i).type == TokenType.ASSIGN) //做一下预读，如果存在等号的话，位置记录在assign里
                    assign = i;
            }
            if (assign > token_index) { // 存在等号
                if (tokens.get(assign + 1).type == TokenType.GETINTTK) { // LVal '=' 'getint''('')'';'
                    lVal = lVal();
                    assignToken = tokens.get(token_index++);
                    getIntToken = tokens.get(token_index++);
                    lparentToken = tokens.get(token_index++);
                    rparentToken = expect(TokenType.RPARENT, tokens.get(token_index).type);
                    semiToken1 = expect(TokenType.SEMICN, tokens.get(token_index).type);
                } else if (tokens.get(assign + 1).type == TokenType.GETCHARTK) { // LVal '=' 'getchar''('')'';'
                    lVal = lVal();
                    assignToken = tokens.get(token_index++);
                    getCharToken = tokens.get(token_index++);
                    lparentToken = tokens.get(token_index++);
                    rparentToken = expect(TokenType.RPARENT, tokens.get(token_index).type);
                    semiToken1 = expect(TokenType.SEMICN, tokens.get(token_index).type);
                } else { // LVal '=' Exp ';'
                    lVal = lVal();
                    assignToken = tokens.get(token_index++);
                    expList.add(exp());
                    semiToken1 = expect(TokenType.SEMICN, tokens.get(token_index).type);
                }
            } else {
                if (tokens.get(token_index).type != TokenType.SEMICN) { //存在Exp
                    expList.add(exp());
                }
                semiToken1 = expect(TokenType.SEMICN, tokens.get(token_index).type);
            }
        }

        return new Stmt("<Stmt>", lVal, assignToken, lparentToken, rparentToken, semiToken1, semiToken2,
                block, ifToken, elseToken, forToken, cond, stmt1, stmt2, forStmt1, forStmt2, breakToken, continueToken,
                returnToken, printfToken, getIntToken, getCharToken, stringToken, commaTokenList, expList);
    }

    // 语句 ForStmt → LVal '=' Exp
    private ForStmt forStmt() throws IOException {
        LVal lVal = lVal();
        Token assignToken = tokens.get(token_index++);
        Exp exp = exp();
        return new ForStmt("<ForStmt>", lVal, assignToken, exp);
    }

    // 表达式 Exp → AddExp
    private Exp exp() throws IOException {
        AddExp addExp = addExp();
        System.out.println("以上是addExp");
        return new Exp("<Exp>", addExp);
    }

    // 条件表达式 Cond → LOrExp
    private Cond cond() throws IOException {
        LOrExp lOrExp = lOrExp();
        return new Cond("<Cond>", lOrExp);
    }

    // 左值表达式 LVal → Ident ['[' Exp ']']
    private LVal lVal() throws IOException {
        Token identToken = null;
        Token lbrackToken = null;
        Exp exp = null;
        Token rbrackToken = null;

        identToken = tokens.get(token_index++);
        if (tokens.get(token_index).type == TokenType.LBRACK) {
            lbrackToken = tokens.get(token_index++);
            exp = exp();
            System.out.println("以上是exp");
            rbrackToken = expect(TokenType.RBRACK, tokens.get(token_index).type);
        }

        return new LVal("<LVal>", identToken, lbrackToken, exp, rbrackToken);
    }

    // 基本表达式 PrimaryExp → '(' Exp ')' | LVal | Number | Character
    private PrimaryExp primaryExp() throws IOException {
        Token lparentToken = null;
        Exp exp = null;
        Token rparentToken = null;
        LVal lVal = null;
        Number number = null;
        Character character = null;

        if (tokens.get(token_index).type == TokenType.LPARENT) {
            lparentToken = tokens.get(token_index++);
            exp = exp();
            rparentToken = expect(TokenType.RPARENT, tokens.get(token_index).type);
        } else if (tokens.get(token_index).type == TokenType.IDENFR) {

            lVal = lVal();
        } else if (tokens.get(token_index).type == TokenType.INTCON) {
            number = number();
        } else {
            character = character();
        }

        return new PrimaryExp("<PrimaryExp>", lparentToken, exp, rparentToken, lVal, number, character);
    }

    // 数值 Number → IntConst
    private Number number() {
        System.out.println("当前token是" + tokens.get(token_index).content);
        System.out.println("上一个token是" + tokens.get(token_index - 1).content);
        System.out.println("上两个token是" + tokens.get(token_index - 2).content);
        Token intConstToken = tokens.get(token_index++);
        System.out.println("\n当前token是" + tokens.get(token_index).content);
        return new Number("<Number>", intConstToken);
    }

    // 字符 Character → CharConst
    private Character character() {
        Token charConstToken = tokens.get(token_index++);
        return new Character("<Character>", charConstToken);
    }

    // 一元表达式 UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
    private UnaryExp unaryExp() throws IOException {
        PrimaryExp primaryExp = null;
        Token identToken = null;
        Token lparentToken = null;
        FuncRParams funcRParams = null;
        Token rparentToken = null;
        UnaryOp unaryOp = null;
        UnaryExp unaryExp = null;

        System.out.println("\n在unaryExp中，当前token是" + tokens.get(token_index));
        if (tokens.get(token_index).type == TokenType.IDENFR && tokens.get(token_index + 1).type == TokenType.LPARENT) { // Ident '(' [FuncRParams] ')'
            identToken = tokens.get(token_index++);
            lparentToken = tokens.get(token_index++);
            if (tokens.get(token_index).type != TokenType.RPARENT) //存在FuncRParams
                funcRParams = funcRParams();
            rparentToken = tokens.get(token_index++);
        } else if (tokens.get(token_index).type == TokenType.PLUS || tokens.get(token_index).type == TokenType.MINU ||
                tokens.get(token_index).type == TokenType.NOT) { // UnaryOp UnaryExp
            unaryOp = unaryOp();
            unaryExp = unaryExp();
        } else { // PrimaryExp
            primaryExp = primaryExp();
        }

        return new UnaryExp("<UnaryExp>", primaryExp, identToken, lparentToken, funcRParams, rparentToken, unaryOp, unaryExp);
    }

    // 单目运算符 UnaryOp → '+' | '−' | '!'
    private UnaryOp unaryOp() {
        Token plusToken = null;
        Token minusToken = null;
        Token notToken = null;
        if (tokens.get(token_index).type == TokenType.PLUS)
            plusToken = tokens.get(token_index++);
        else if (tokens.get(token_index).type == TokenType.MINU)
            minusToken = tokens.get(token_index++);
        else
            notToken = tokens.get(token_index++);
        return new UnaryOp("<UnaryOp>", plusToken, minusToken, notToken);
    }

    // 函数实参表 FuncRParams → Exp { ',' Exp }
    private FuncRParams funcRParams() throws IOException {
        List<Exp> expList = new ArrayList<>();
        List<Token> commaTokenList = new ArrayList<>();

        expList.add(exp());
        while (tokens.get(token_index).type == TokenType.COMMA) {
            commaTokenList.add(tokens.get(token_index++));
            expList.add(exp());
        }
        return new FuncRParams("<FuncRParams>", expList, commaTokenList);
    }

    /* 乘除模表达式 MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
    左递归文法，改写成 MulExp → UnaryExp { ('*' | '/' | '%') UnaryExp } */
    private MulExp mulExp() throws IOException {
        List<UnaryExp> unaryExpList = new ArrayList<>();
        List<Token> tokenList = new ArrayList<>(); //存放乘号、除号、模

        System.out.println("存在mulExp");
        unaryExpList.add(unaryExp());
        while (tokens.get(token_index).type == TokenType.MULT || tokens.get(token_index).type == TokenType.DIV || tokens.get(token_index).type == TokenType.MOD) {
            tokenList.add(tokens.get(token_index++));
            unaryExpList.add(unaryExp());
        }
        return new MulExp("<MulExp>", unaryExpList, tokenList);
    }

    /* 加减表达式 AddExp → MulExp | AddExp ('+' | '−') MulExp
    左递归文法，改写成 AddExp → MulExp { ('+' | '−') MulExp } */
    private AddExp addExp() throws IOException {
        List<MulExp> mulExpList = new ArrayList<>();
        List<Token> tokenList = new ArrayList<>();

        System.out.println("存在addExp");
        mulExpList.add(mulExp());
        while (tokens.get(token_index).type == TokenType.PLUS || tokens.get(token_index).type == TokenType.MINU) {
            tokenList.add(tokens.get(token_index++));
            mulExpList.add(mulExp());
        }
        return new AddExp("<AddExp>", mulExpList, tokenList);
    }

    /* 关系表达式 RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
    左递归，改写成RelExp → AddExp { ('<' | '>' | '<=' | '>=') AddExp } */
    private RelExp relExp() throws IOException {
        List<AddExp> addExpList = new ArrayList<>();
        List<Token> tokenList = new ArrayList<>();

        addExpList.add(addExp());
        while (tokens.get(token_index).type == TokenType.LSS || tokens.get(token_index).type == TokenType.LEQ ||
                tokens.get(token_index).type == TokenType.GRE || tokens.get(token_index).type == TokenType.GEQ) {
            tokenList.add(tokens.get(token_index++));
            addExpList.add(addExp());
        }
        return new RelExp("<RelExp>", addExpList, tokenList);
    }

    /* 相等性表达式 EqExp → RelExp | EqExp ('==' | '!=') RelExp
    左递归，改写成 EqExp → RelExp { ('==' | '!=') RelExp } */
    private EqExp eqExp() throws IOException {
        List<RelExp> relExpList = new ArrayList<>();
        List<Token> tokenList = new ArrayList<>();

        relExpList.add(relExp());
        while (tokens.get(token_index).type == TokenType.EQL || tokens.get(token_index).type == TokenType.NEQ) {
            tokenList.add(tokens.get(token_index++));
            relExpList.add(relExp());
        }
        return new EqExp("<EqExp>", tokenList, relExpList);
    }

    /* 逻辑与表达式 LAndExp → EqExp | LAndExp '&&' EqExp
    左递归。改写成 LAndExp → EqExp { '&&' EqExp } */
    private LAndExp lAndExp() throws IOException {
        List<EqExp> eqExpList = new ArrayList<>();
        List<Token> andTokenList = new ArrayList<>();

        eqExpList.add(eqExp());
        while (tokens.get(token_index).type == TokenType.AND) {
            andTokenList.add(tokens.get(token_index++));
            eqExpList.add(eqExp());
        }
        return new LAndExp("<LAndExp>", andTokenList, eqExpList);
    }

    /* 逻辑或表达式 LOrExp → LAndExp | LOrExp '||' LAndExp
   左递归，改写成 LOrExp → LAndExp { '||' LAndExp } */
    private LOrExp lOrExp() throws IOException {
        List<LAndExp> lAndExpList = new ArrayList<>();
        List<Token> orTokenList = new ArrayList<>();

        lAndExpList.add(lAndExp());
        while (tokens.get(token_index).type == TokenType.OR) {
            orTokenList.add(tokens.get(token_index++));
            lAndExpList.add(lAndExp());
        }
        return new LOrExp("<LOrExp>", orTokenList, lAndExpList);
    }

    // 常量表达式 ConstExp → AddExp
    private ConstExp constExp() throws IOException {
        AddExp addExp = addExp();
        return new ConstExp("<ConstExp>", addExp);
    }


}
