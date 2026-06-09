package frontend;

import error.Error;
import error.ErrorHandler;
import error.ErrorType;
import frontend.node.*;
import frontend.token.*;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Parser {
    private static Parser parser = new Parser();

    public static Parser getInstance() {
        return parser;
    }

    private ArrayList<Token> tokens = new ArrayList<>();
    private int index = 0;
    private Token curToken;
    private CompUnitNode compUnitNode;

    /**
     * @param tokens 词法分析得到的Token序列
     * @Description 将词法分析得到的Token序列传递给语法分析程序
     * @date 2024/10/10 13:06
     * @version 1.0
     */
    public void setTokens(ArrayList<Token> tokens) {
        this.tokens = tokens;
        curToken = tokens.get(index);
    }

    // 建立NodeType到语法成分名称的一一映射，用于打印语法成分名称，便于统一修改
    public static Map<NodeType, String> nodeType = new HashMap<NodeType, String>() {{
        put(NodeType.CompUnit, "<CompUnit>\n");
        put(NodeType.Decl, "<Decl>\n");
        put(NodeType.ConstDecl, "<ConstDecl>\n");
        put(NodeType.BType, "<BType>\n");
        put(NodeType.ConstDef, "<ConstDef>\n");
        put(NodeType.ConstInitVal, "<ConstInitVal>\n");
        put(NodeType.VarDecl, "<VarDecl>\n");
        put(NodeType.VarDef, "<VarDef>\n");
        put(NodeType.InitVal, "<InitVal>\n");
        put(NodeType.FuncDef, "<FuncDef>\n");
        put(NodeType.MainFuncDef, "<MainFuncDef>\n");
        put(NodeType.FuncType, "<FuncType>\n");
        put(NodeType.FuncFParams, "<FuncFParams>\n");
        put(NodeType.FuncFParam, "<FuncFParam>\n");
        put(NodeType.Block, "<Block>\n");
        put(NodeType.BlockItem, "<BlockItem>\n");
        put(NodeType.Stmt, "<Stmt>\n");
        put(NodeType.ForStmt, "<ForStmt>\n");
        put(NodeType.Exp, "<Exp>\n");
        put(NodeType.Cond, "<Cond>\n");
        put(NodeType.LVal, "<LVal>\n");
        put(NodeType.PrimaryExp, "<PrimaryExp>\n");
        put(NodeType.Number, "<Number>\n");
        put(NodeType.Character, "<Character>\n");
        put(NodeType.UnaryExp, "<UnaryExp>\n");
        put(NodeType.UnaryOp, "<UnaryOp>\n");
        put(NodeType.FuncRParams, "<FuncRParams>\n");
        put(NodeType.MulExp, "<MulExp>\n");
        put(NodeType.AddExp, "<AddExp>\n");
        put(NodeType.RelExp, "<RelExp>\n");
        put(NodeType.EqExp, "<EqExp>\n");
        put(NodeType.LAndExp, "<LAndExp>\n");
        put(NodeType.LOrExp, "<LOrExp>\n");
        put(NodeType.ConstExp, "<ConstExp>\n");
    }};

    /**
     * @Description 主程序中调用的语法分析程序，compUnitNode为最大分析单元
     * @date 2024/10/10 13:07
     * @version 1.0
     */
    public void parsing() {
        this.compUnitNode = compUnit();
    }

    public void printParserRes(){
        this.compUnitNode.print();
    }

    /**
     * @param tokenType 目标token类型
     * @return frontend.token.Token 匹配得到的token
     * 注意如果是i/j/k类错误，则需要返回应匹配到的值，因为程序还要继续
     * @Description 匹配目标token类型，如果匹配成功则返回当前token，否则处理异常
     * @date 2024/10/10 13:08
     * @version 1.0
     */
    private Token match(TokenType tokenType) {
        // 正确匹配
        if (curToken.getType() == tokenType) {
            Token tmpCurToken = curToken;
            if (index + 1 < tokens.size()) {
                index++;
                curToken = tokens.get(index);
            }
            return tmpCurToken;
        } else if (tokenType == TokenType.SEMICN) { // 缺少分号
            ErrorHandler.getInstance().addError(new Error(tokens.get(index - 1).getLineNumber(), ErrorType.i));
            return new Token(TokenType.SEMICN, tokens.get(index - 1).getLineNumber(), ";");
        } else if (tokenType == TokenType.RPARENT) { // 缺少右小括号
            ErrorHandler.getInstance().addError(new Error(tokens.get(index - 1).getLineNumber(), ErrorType.j));
            return new Token(TokenType.RPARENT, tokens.get(index - 1).getLineNumber(), ")");
        } else if (tokenType == TokenType.RBRACK) { // 缺少右中括号
            ErrorHandler.getInstance().addError(new Error(tokens.get(index - 1).getLineNumber(), ErrorType.k));
            return new Token(TokenType.RBRACK, tokens.get(index - 1).getLineNumber(), "]");
        } else {    // 其他错误情况
            throw new RuntimeException("ParserError in line " + curToken.getLineNumber() + ": " + curToken.getContent() + " is not " + tokenType);
        }
    }

    boolean isUnaryOp() {
        return (curToken.getType() == TokenType.PLUS || curToken.getType() == TokenType.MINU || curToken.getType() == TokenType.NOT);
    }

    boolean isExp() {
        return (curToken.getType() == TokenType.IDENFR || curToken.getType() == TokenType.LPARENT || curToken.getType() == TokenType.INTCON || curToken.getType() == TokenType.CHARTK || isUnaryOp());
    }

    /*
     * 每种语法成分的分析方法
     */
    private CompUnitNode compUnit() {
        // 编译单元 CompUnit -> {Decl} {FuncDef} MainFuncDef
        ArrayList<DeclNode> declNodes = new ArrayList<>();
        ArrayList<FuncDefNode> funcDefNodes = new ArrayList<>();
        MainFuncDefNode mainFuncDefNode;
        // 首先匹配 Decl 成分
        // 很难直接通过预读判断是 Decl,所以使用排除法，只要不是 FuncDef、 MainFuncDef就交由 Decl程序分析
        while (tokens.get(index + 1).getType() != TokenType.MAINTK && tokens.get(index + 2).getType() != TokenType.LPARENT) {
            DeclNode declNode = decl();
            declNodes.add(declNode);
        }
        // 再匹配 FuncDef 成分
        // 同样，很难直接通过预读判断是 FuncDef,所以使用排除法，只要不是MainFuncDef就交由 FuncDef 程序分析
        while (tokens.get(index + 1).getType() != TokenType.MAINTK) {
            FuncDefNode funcDefNode = funcDef();
            funcDefNodes.add(funcDefNode);
        }
        mainFuncDefNode = mainFuncDef();
        return new CompUnitNode(declNodes, funcDefNodes, mainFuncDefNode);
    }

    private DeclNode decl() {
        // 声明 Decl -> ConstDecl | VarDecl
        ConstDeclNode constDeclNode = null;
        VarDeclNode varDeclNode = null;
        if (curToken.getType() == TokenType.CONSTTK) {
            constDeclNode = constDecl();
        } else {
            varDeclNode = varDecl();
        }
        return new DeclNode(constDeclNode, varDeclNode);
    }

    private ConstDeclNode constDecl() {
        // 常量声明 ConstDecl -> 'const' BType ConstDef { ',' ConstDef } ';'
        Token constToken = match(TokenType.CONSTTK);
        BTypeNode bTypeNode = bType();
        ArrayList<ConstDefNode> constDefNodes = new ArrayList<>();
        Token commaToken = null;
        Token semicnToken;
        constDefNodes.add(constDef());
        while (curToken.getType() == TokenType.COMMA) {
            commaToken = match(TokenType.COMMA);
            constDefNodes.add(constDef());
        }
        semicnToken = match(TokenType.SEMICN);
        return new ConstDeclNode(constToken, bTypeNode, constDefNodes, commaToken, semicnToken);
    }

    private BTypeNode bType() {
        // 基本类型 BType → 'int' | 'char'
        if (curToken.getType() == TokenType.INTTK) {
            Token intToken = match(TokenType.INTTK);
            return new BTypeNode(intToken);
        } else {
            Token charToken = match(TokenType.CHARTK);
            return new BTypeNode(charToken);
        }
    }

    private ConstDefNode constDef() {
        // 常量定义 ConstDef -> Ident [ '[' ConstExp ']' ] '=' ConstInitVal
        Token ident = match(TokenType.IDENFR);
        Token lbrackToken = null;
        ConstExpNode constExpNode = null;
        Token rbrackToken = null;
        if (curToken.getType() == TokenType.LBRACK) {
            lbrackToken = match(TokenType.LBRACK);
            constExpNode = constExp();
            rbrackToken = match(TokenType.RBRACK);
        }
        Token equalToken = match(TokenType.ASSIGN);
        ConstInitValNode constInitValNode = constInitVal();
        return new ConstDefNode(ident, lbrackToken, constExpNode, rbrackToken, equalToken, constInitValNode);
    }

    private ConstInitValNode constInitVal() {
        // 常量初值 ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
        ConstExpNode constExpNode = null;
        Token lbraceToken = null;
        ArrayList<ConstExpNode> constExpNodes = new ArrayList<>();
        Token commaToken = null;
        Token rbraceToken = null;
        Token stringConstToken = null;
        if (curToken.getType() == TokenType.LBRACE) {
            lbraceToken = match(TokenType.LBRACE);
            if (curToken.getType() != TokenType.RBRACE) {
                constExpNodes.add(constExp());
                while (curToken.getType() != TokenType.RBRACE) {
                    commaToken = match(TokenType.COMMA);
                    constExpNodes.add(constExp());
                }
            }
            rbraceToken = match(TokenType.RBRACE);
        } else if (curToken.getType() == TokenType.STRCON) {
            stringConstToken = match(TokenType.STRCON);
        } else {
            constExpNode = constExp();
        }
        return new ConstInitValNode(constExpNode, lbraceToken, constExpNodes, commaToken, rbraceToken, stringConstToken);
    }

    private VarDeclNode varDecl() {
        // 变量声明 VarDecl -> BType VarDef { ',' VarDef } ';'
        BTypeNode bTypeNode = bType();
        ArrayList<VarDefNode> varDefNodes = new ArrayList<>();
        Token commaToken = null;
        Token semicnToken;
        varDefNodes.add(varDef());
        while (curToken.getType() == TokenType.COMMA) {
            commaToken = match(TokenType.COMMA);
            varDefNodes.add(varDef());
        }
        semicnToken = match(TokenType.SEMICN);
        return new VarDeclNode(bTypeNode, varDefNodes, commaToken, semicnToken);
    }

    private VarDefNode varDef() {
        // 变量初值 VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '= InitVal
        Token ident = match(TokenType.IDENFR);
        Token lbrackToken = null;
        ConstExpNode constExpNode = null;
        Token rBrackToken = null;
        Token equalToken = null;
        InitValNode initValNode = null;
        if (curToken.getType() == TokenType.LBRACK) {
            lbrackToken = match(TokenType.LBRACK);
            constExpNode = constExp();
            rBrackToken = match(TokenType.RBRACK);
        }
        if (curToken.getType() == TokenType.ASSIGN) {
            equalToken = match(TokenType.ASSIGN);
            initValNode = initVal();
        }
        return new VarDefNode(ident, lbrackToken, constExpNode, rBrackToken, equalToken, initValNode);
    }

    private InitValNode initVal() {
        // 变量初值 InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
        ExpNode expNode = null;
        Token lbraceToken = null;
        ArrayList<ExpNode> expNodes = new ArrayList<>();
        Token commaToken = null;
        Token rbraceToken = null;
        Token stringConstToken = null;
        if (curToken.getType() == TokenType.LBRACE) {
            lbraceToken = match(TokenType.LBRACE);
            if (curToken.getType() != TokenType.RBRACE) {
                expNodes.add(exp());
                while (curToken.getType() != TokenType.RBRACE) {
                    commaToken = match(TokenType.COMMA);
                    expNodes.add(exp());
                }
            }
            rbraceToken = match(TokenType.RBRACE);
        } else if (curToken.getType() == TokenType.STRCON) {
            stringConstToken = match(TokenType.STRCON);
        } else {
            expNode = exp();
        }
        return new InitValNode(expNode, lbraceToken, expNodes, commaToken, rbraceToken, stringConstToken);
    }

    private FuncDefNode funcDef() {
        // 函数定义 FuncDef → FuncType Ident '(' [FuncFParams] ')' Block
        FuncTypeNode funcTypeNode = funcType();
        Token ident = match(TokenType.IDENFR);
        Token lparentToken = match(TokenType.LPARENT);
        FuncFParamsNode funcfParamsNode = null;
        if (curToken.getType() != TokenType.RPARENT) {
            funcfParamsNode = funcFParams();
        }
        Token rparentToken = match(TokenType.RPARENT);
        BlockNode blockNode = block();
        return new FuncDefNode(funcTypeNode, ident, lparentToken, funcfParamsNode, rparentToken, blockNode);
    }

    private MainFuncDefNode mainFuncDef() {
        // 主函数定义 MainFuncDef → 'int' 'main' '(' ')' Block
        Token intToken = match(TokenType.INTTK);
        Token mainToken = match(TokenType.MAINTK);
        Token lparentToken = match(TokenType.LPARENT);
        Token rparentToken = match(TokenType.RPARENT);
        BlockNode blockNode = block();
        return new MainFuncDefNode(intToken, mainToken, lparentToken, rparentToken, blockNode);
    }

    private FuncTypeNode funcType() {
        // 函数类型 FuncType → 'void' | 'int' | 'char'
        if (curToken.getType() == TokenType.VOIDTK) {
            Token voidToken = match(TokenType.VOIDTK);
            return new FuncTypeNode(voidToken);
        } else if (curToken.getType() == TokenType.INTTK) {
            Token intToken = match(TokenType.INTTK);
            return new FuncTypeNode(intToken);
        } else {
            Token charToken = match(TokenType.CHARTK);
            return new FuncTypeNode(charToken);
        }
    }

    private FuncFParamsNode funcFParams() {
        // 函数形参表 FuncFParams → FuncFParam { ',' FuncFParam }
        ArrayList<FuncFParamNode> funcFParamNodes = new ArrayList<>();
        Token commaToken = null;
        funcFParamNodes.add(funcFParam());
        while (curToken.getType() == TokenType.COMMA) {
            commaToken = match(TokenType.COMMA);
            funcFParamNodes.add(funcFParam());
        }
        return new FuncFParamsNode(funcFParamNodes, commaToken);
    }

    private FuncFParamNode funcFParam() {
        // 函数形参 FuncFParam → BType Ident ['[' ']']
        BTypeNode bTypeNode = bType();
        Token ident = match(TokenType.IDENFR);
        Token lbrackToken = null;
        Token rbrackToken = null;
        if (curToken.getType() == TokenType.LBRACK) {
            lbrackToken = match(TokenType.LBRACK);
            rbrackToken = match(TokenType.RBRACK);
        }
        return new FuncFParamNode(bTypeNode, ident, lbrackToken, rbrackToken);
    }

    private BlockNode block() {
        // 语句块 Block -> '{' { BlockItem } '}'
        Token lbraceToken = match(TokenType.LBRACE);
        ArrayList<BlockItemNode> blockItemNodes = new ArrayList<>();
        while (curToken.getType() != TokenType.RBRACE) {
            blockItemNodes.add(blockItem());
        }
        Token rbraceToken = match(TokenType.RBRACE);
        return new BlockNode(lbraceToken, blockItemNodes, rbraceToken);
    }

    private BlockItemNode blockItem() {
        // 语句块项 BlockItem → Decl | Stmt
        DeclNode declNode = null;
        StmtNode stmtNode = null;
        if (curToken.getType() == TokenType.CONSTTK || curToken.getType() == TokenType.INTTK || curToken.getType() == TokenType.CHARTK) {
            declNode = decl();
        } else {
            stmtNode = stmt();
        }
        return new BlockItemNode(declNode, stmtNode);
    }

    private StmtNode stmt() {
        // 语句 Stmt -> LVal '=' Exp ';'
        //	| [Exp] ';'
        //	| Block
        //	| 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
        //	| 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
        //	| 'break' ';' | 'continue' ';'
        //	| 'return' [Exp] ';'
        //	| LVal '=' 'getint' '(' ')' ';'
        //  | LVal '=' 'getchar''('')'';'
        //	| 'printf' '(' StringConst { ',' Exp } ')' ';'
        if (curToken.getType() == TokenType.LBRACE) {   // Block
            BlockNode blockNode = block();
            return new StmtNode(StmtType.Block, blockNode);
        } else if (curToken.getType() == TokenType.IFTK) {  // 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
            Token ifToken = match(TokenType.IFTK);
            Token lparentToken = match(TokenType.LPARENT);
            CondNode condNode = cond();
            Token rparentToken = match(TokenType.RPARENT);
            ArrayList<StmtNode> stmtNodes = new ArrayList<>();
            stmtNodes.add(stmt());
            Token elseToken = null;
            if (curToken.getType() == TokenType.ELSETK) {
                elseToken = match(TokenType.ELSETK);
                stmtNodes.add(stmt());
            }
            return new StmtNode(StmtType.If, ifToken, lparentToken, condNode, rparentToken, stmtNodes, elseToken);
        } else if (curToken.getType() == TokenType.FORTK) {   // 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
            Token forToken = match(TokenType.FORTK);
            Token lparentToken = match(TokenType.LPARENT);
            ForStmtNode forStmtToken1 = null;
            CondNode condNode = null;
            ForStmtNode forStmtToken2 = null;
            if (curToken.getType() != TokenType.SEMICN) {
                forStmtToken1 = forStmt();
            }
            Token semicnToken = match(TokenType.SEMICN);
            if (curToken.getType() != TokenType.SEMICN) {
                condNode = cond();
            }
            semicnToken = match(TokenType.SEMICN);
            if (curToken.getType() != TokenType.RPARENT) {
                forStmtToken2 = forStmt();
            }
            Token rparentToken = match(TokenType.RPARENT);
            StmtNode stmtNode = stmt();
            return new StmtNode(StmtType.For, forToken, lparentToken, forStmtToken1, semicnToken, condNode, forStmtToken2, rparentToken, stmtNode);
        } else if (curToken.getType() == TokenType.BREAKTK) {   // 'break' ';'
            Token breakToken = match(TokenType.BREAKTK);
            Token semicnToken = match(TokenType.SEMICN);
            return new StmtNode(StmtType.Break, breakToken, semicnToken);
        } else if (curToken.getType() == TokenType.CONTINUETK) {    // 'continue' ';'
            Token continueToken = match(TokenType.CONTINUETK);
            Token semicnToken = match(TokenType.SEMICN);
            return new StmtNode(StmtType.Continue, continueToken, semicnToken);
        } else if (curToken.getType() == TokenType.RETURNTK) {  // 'return' [Exp] ';'
            Token returnToken = match(TokenType.RETURNTK);
            ExpNode expNode = null;
            // 这里把一长串条件的判断封装在了一个方法里，太长了，后面还要用，封装更简洁点
            if (isExp()) {
                expNode = exp();
            }
            Token semicnToken = match(TokenType.SEMICN);
            return new StmtNode(StmtType.Return, returnToken, expNode, semicnToken);
        } else if (curToken.getType() == TokenType.PRINTFTK) {  // 'printf' '(' stringConst { ',' Exp } ')' ';'
            Token printfToken = match(TokenType.PRINTFTK);
            Token lparentToken = match(TokenType.LPARENT);
            Token stringConstToken = match(TokenType.STRCON);
            ArrayList<ExpNode> expNodes = new ArrayList<>();
            Token commaToken = null;
            while (curToken.getType() == TokenType.COMMA) {
                commaToken = match(TokenType.COMMA);
                expNodes.add(exp());
            }
            Token rparentToken = match(TokenType.RPARENT);
            Token semicnToken = match(TokenType.SEMICN);
            return new StmtNode(StmtType.Printf, printfToken, lparentToken, stringConstToken, commaToken, expNodes, rparentToken, semicnToken);
        } else {    // FIRST集复杂的几个，根据是否有 =号判断是否为 Exp (因为 Exp中不包含=)
            boolean assignExist = false;
            for (int i = index; i < tokens.size() && tokens.get(i).getLineNumber() == curToken.getLineNumber(); i++) {
                if (tokens.get(i).getType() == TokenType.ASSIGN) {
                    assignExist = true;
                    break;
                }
            }
            if (assignExist) {  // LVal '=' Exp ';' | LVal '=' 'getint' '(' ')' ';' | LVal '=' 'getchar' '(' ')' ';'
                LValNode lValNode = lVal();
                Token assignToken = match(TokenType.ASSIGN);
                Token lparentToken = null;
                Token rparentToken = null;
                Token semicnToken = null;
                if (curToken.getType() == TokenType.GETINTTK) {
                    Token getintToken = match(TokenType.GETINTTK);
                    lparentToken = match(TokenType.LPARENT);
                    rparentToken = match(TokenType.RPARENT);
                    semicnToken = match(TokenType.SEMICN);
                    return new StmtNode(StmtType.LValAssignGetint, lValNode, assignToken, getintToken, lparentToken, rparentToken, semicnToken);
                } else if (curToken.getType() == TokenType.GETCHARTK) {
                    Token getcharToken = match(TokenType.GETCHARTK);
                    lparentToken = match(TokenType.LPARENT);
                    rparentToken = match(TokenType.RPARENT);
                    semicnToken = match(TokenType.SEMICN);
                    return new StmtNode(StmtType.LValAssignGetchar, lValNode, assignToken, getcharToken, lparentToken, rparentToken, semicnToken);
                } else {
                    ExpNode expNode = exp();
                    semicnToken = match(TokenType.SEMICN);
                    return new StmtNode(StmtType.LValAssignExp, lValNode, assignToken, expNode, semicnToken);
                }
            } else {
                // [Exp] ';'
                ExpNode expNode = null;
                if (isExp()) {
                    expNode = exp();
                }
                Token semicnToken = match(TokenType.SEMICN);
                return new StmtNode(StmtType.Exp, expNode, semicnToken);
            }
        }
    }

    private ForStmtNode forStmt() {
        // 语句 ForStmt → LVal '=' Exp
        LValNode lValNode = lVal();
        Token assignToken = match(TokenType.ASSIGN);
        ExpNode initExpNode = exp();
        return new ForStmtNode(lValNode, assignToken, initExpNode);
    }

    private ExpNode exp() {
        // 表达式 Exp → AddExp
        return new ExpNode(addExp());
    }

    private CondNode cond() {
        // Cond -> LOrExp
        return new CondNode(lOrExp());
    }

    private LValNode lVal() {
        // 左值表达式 LVal -> Ident ['[' Exp ']']
        Token ident = match(TokenType.IDENFR);
        Token lbrackToken = null;
        ExpNode expNode = null;
        Token rbrackToken = null;
        if (curToken.getType() == TokenType.LBRACK) {
            lbrackToken = match(TokenType.LBRACK);
            expNode = exp();
            rbrackToken = match(TokenType.RBRACK);
        }
        return new LValNode(ident, lbrackToken, expNode, rbrackToken);
    }

    private PrimaryExpNode primaryExp() {
        // 基本表达式 PrimaryExp → '(' Exp ')' | LVal | Number | Character
        if (curToken.getType() == TokenType.LPARENT) {
            Token lparentToken = match(TokenType.LPARENT);
            ExpNode expNode = exp();
            Token rparentToken = match(TokenType.RPARENT);
            return new PrimaryExpNode(lparentToken, expNode, rparentToken);
        } else if (curToken.getType() == TokenType.INTCON) {
            NumberNode numberNode = number();
            return new PrimaryExpNode(numberNode);
        } else if (curToken.getType() == TokenType.CHRCON) {
            CharacterNode characterNode = character();
            return new PrimaryExpNode(characterNode);
        } else {
            LValNode lValNode = lVal();
            return new PrimaryExpNode(lValNode);
        }
    }

    private NumberNode number() {
        // 数值 Number -> IntConst
        return new NumberNode(match(TokenType.INTCON));
    }

    private CharacterNode character() {
        // 字符 Character → CharConst
        return new CharacterNode(match(TokenType.CHRCON));
    }

    private UnaryExpNode unaryExp() {
        // 一元表达式 UnaryExp -> PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
        if (curToken.getType() == TokenType.IDENFR && tokens.get(index + 1).getType() == TokenType.LPARENT) {   // Ident '(' [FuncRParams] ')'
            Token ident = match(TokenType.IDENFR);
            Token lparentToken = match(TokenType.LPARENT);
            FuncRParamsNode funcRParamsNode = null;
            if (isExp()) {
                funcRParamsNode = funcRParams();
            }
            Token rparentToken = match(TokenType.RPARENT);
            return new UnaryExpNode(ident, lparentToken, funcRParamsNode, rparentToken);
        } else if (isUnaryOp()) {   // UnaryOp UnaryExp
            UnaryOpNode unaryOpNode = unaryOp();
            UnaryExpNode unaryExpNode = unaryExp();
            return new UnaryExpNode(unaryOpNode, unaryExpNode);
        } else {    // PrimaryExp
            PrimaryExpNode primaryExpNode = primaryExp();
            return new UnaryExpNode(primaryExpNode);
        }
    }

    private UnaryOpNode unaryOp() {
        // 单目运算符 UnaryOp -> '+' | '−' | '!'
        Token token;
        if (curToken.getType() == TokenType.PLUS) {
            token = match(TokenType.PLUS);
        } else if (curToken.getType() == TokenType.MINU) {
            token = match(TokenType.MINU);
        } else {
            token = match(TokenType.NOT);
        }
        return new UnaryOpNode(token);
    }

    private FuncRParamsNode funcRParams() {
        // 函数实参表 FuncRParams -> Exp { ',' Exp }
        ArrayList<ExpNode> expNodes = new ArrayList<>();
        Token commaToken = null;
        expNodes.add(exp());
        while (curToken.getType() == TokenType.COMMA) {
            commaToken = match(TokenType.COMMA);
            expNodes.add(exp());
        }
        return new FuncRParamsNode(expNodes, commaToken);
    }

    private MulExpNode mulExp() {
        // 乘除模表达式 MulExp → UnaryExp[ ('*' | '/' | '%') MulExp]
        UnaryExpNode unaryExpNode = unaryExp();
        Token operator = null;
        MulExpNode mulExpNode = null;
        if (curToken.getType() == TokenType.MULT) {
            operator = match(TokenType.MULT);
            mulExpNode = mulExp();
        } else if (curToken.getType() == TokenType.DIV) {
            operator = match(TokenType.DIV);
            mulExpNode = mulExp();
        } else if (curToken.getType() == TokenType.MOD) {
            operator = match(TokenType.MOD);
            mulExpNode = mulExp();
        }
        return new MulExpNode(unaryExpNode, operator, mulExpNode);
    }

    private AddExpNode addExp() {
        // 加减表达式 AddExp → MulExp[ ('+' | '−') AddExp]
        MulExpNode mulExpNode = mulExp();
        Token operator = null;
        AddExpNode addExpNode = null;
        if (curToken.getType() == TokenType.PLUS) {
            operator = match(TokenType.PLUS);
            addExpNode = addExp();
        } else if (curToken.getType() == TokenType.MINU) {
            operator = match(TokenType.MINU);
            addExpNode = addExp();
        }
        return new AddExpNode(mulExpNode, operator, addExpNode);
    }

    private RelExpNode relExp() {
        // 关系表达式 RelExp → AddExp[ ('<' | '>' | '<=' | '>=') RelExp]
        AddExpNode addExpNode = addExp();
        Token operator = null;
        RelExpNode relExpNode = null;
        if (curToken.getType() == TokenType.LSS) {
            operator = match(TokenType.LSS);
            relExpNode = relExp();
        } else if (curToken.getType() == TokenType.GRE) {
            operator = match(TokenType.GRE);
            relExpNode = relExp();
        } else if (curToken.getType() == TokenType.LEQ) {
            operator = match(TokenType.LEQ);
            relExpNode = relExp();
        } else if (curToken.getType() == TokenType.GEQ) {
            operator = match(TokenType.GEQ);
            relExpNode = relExp();
        }
        return new RelExpNode(addExpNode, operator, relExpNode);
    }

    private EqExpNode eqExp() {
        // 相等性表达式 EqExp → RelExp[ ('==' | '!=') EqExp]
        RelExpNode relExpNode = relExp();
        Token operator = null;
        EqExpNode eqExpNode = null;
        if (curToken.getType() == TokenType.EQL) {
            operator = match(TokenType.EQL);
            eqExpNode = eqExp();
        } else if (curToken.getType() == TokenType.NEQ) {
            operator = match(TokenType.NEQ);
            eqExpNode = eqExp();
        }
        return new EqExpNode(relExpNode, operator, eqExpNode);
    }

    private LAndExpNode lAndExp() {
        // 逻辑与表达式 LAndExp → EqExp[ '&&' LAndExp]
        EqExpNode eqExpNode = eqExp();
        Token operator = null;
        LAndExpNode lAndExpNode = null;
        if (curToken.getType() == TokenType.AND) {
            operator = match(TokenType.AND);
            lAndExpNode = lAndExp();
        }
        return new LAndExpNode(eqExpNode, operator, lAndExpNode);
    }

    private LOrExpNode lOrExp() {
        // 逻辑或表达式 LOrExp -> LAndExp | LOrExp '||' LAndExp
        LAndExpNode lAndExpNode = lAndExp();
        Token operator = null;
        LOrExpNode lOrExpNode = null;
        if (curToken.getType() == TokenType.OR) {
            operator = match(TokenType.OR);
            lOrExpNode = lOrExp();
        }
        return new LOrExpNode(lAndExpNode, operator, lOrExpNode);
    }

    private ConstExpNode constExp() {
        // 常量表达式 ConstExp -> AddExp
        return new ConstExpNode(addExp());
    }
}
