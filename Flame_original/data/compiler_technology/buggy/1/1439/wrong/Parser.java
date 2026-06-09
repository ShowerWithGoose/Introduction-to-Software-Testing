import java.io.*;
import java.util.*;

public class Parser {
    private List<Token> tokens;
    private int curPos;
    private int doingIsStmtLval;
    private List<String> errors;
    private Node root;
    private Set<String> definedIdentifiers; // 当前作用域定义的标识符

    public Parser(List<Token> tokens) {
        this.tokens = tokens;
        this.curPos = 0;
        this.doingIsStmtLval = 0;
        this.errors = new ArrayList<>();
        this.root = null;
        this.definedIdentifiers = new HashSet<>();
    }

    private Token currentToken() {
        if (curPos < tokens.size()) {
            return tokens.get(curPos);
        }
        return null; // 返回空表示没有更多 tokens
    }

    private void advance() {
        if (curPos < tokens.size()) {
            curPos++;
        }
    }

    private void reportError(String errorCode) {
        if (currentToken() != null) {
            errors.add(lookAhead(-1).line + " " + errorCode); // 记录当前行号和错误码
        }
    }

    public void parse() {
        root = parseCompUnit();
        outputResults();
    }

    private Node parseCompUnit() {
        Node compUnitNode = new Node("<CompUnit>");
        while(isDeclStart(currentToken())){
            compUnitNode.addChild(parseDecl());
        }
        while(isFuncDefStart(currentToken())){
            compUnitNode.addChild(parseFuncDef());
        }
        compUnitNode.addChild(parseMainFuncDef());
        return compUnitNode;
    }

    private boolean isDeclStart(Token token) {
        return token.type == TokenType.CONSTTK || ((token.type == TokenType.INTTK || token.type == TokenType.CHARTK)
                && lookAhead(1).type == TokenType.IDENFR
                && lookAhead(2).type != TokenType.LPARENT);
    }

    private boolean isFuncDefStart(Token token) {
        return (token.type == TokenType.VOIDTK || token.type == TokenType.INTTK || token.type == TokenType.CHARTK)
                && lookAhead(1).type == TokenType.IDENFR
                && lookAhead(2).type == TokenType.LPARENT;
    }

    private Token lookAhead(int n) {
        if (curPos + n < tokens.size()) {
            return tokens.get(curPos + n);
        }
        return null;
    }

    private Node parseDecl() {
        if (currentToken().type == TokenType.CONSTTK) {
            return parseConstDecl();
        } else if (isBType(currentToken())) {
            return parseVarDecl();
        }
        return null;
    }

    private boolean isBType(Token token) {
        return token.type == TokenType.INTTK || token.type == TokenType.CHARTK;
    }

    private Node parseBType() {
        Node bTypeNode;
        if (currentToken().type == TokenType.INTTK) {
            bTypeNode = new Node("INTTK", currentToken().value);
        } else if (currentToken().type == TokenType.CHARTK) {
            bTypeNode = new Node("CHARTK", currentToken().value);
        } else {
            advance();
            return null; // 返回 null 表示解析失败
        }
        advance(); // 消耗类型标识符
        return bTypeNode;
    }

    private Node parseConstDecl() {
        Node constDeclNode = new Node("<ConstDecl>");
        constDeclNode.addChild(new Node("CONSTTK",currentToken().value));
        advance(); // const
        constDeclNode.addChild(parseBType());
        constDeclNode.addChild(parseConstDef());
        while (currentToken().type == TokenType.COMMA) {
            Node comma = new Node("COMMA", currentToken().value);
            advance();
            constDeclNode.addChild(comma);
            constDeclNode.addChild(parseConstDef());
        }
        if(currentToken().type == TokenType.SEMICN){
            Node semicn = new Node("SEMICN", currentToken().value);
            constDeclNode.addChild(semicn);
            advance();
        }else{
            reportError("i"); // 缺少;
        }
        return constDeclNode;
    }

    private Node parseConstDef() {
        Node constDefNode = new Node("<ConstDef>");

        // 处理标识符
        if (currentToken().type == TokenType.IDENFR) {
            constDefNode.addChild(new Node("IDENFR", currentToken().value));
            advance();
        }

        // 处理数组定义的情况
        if (currentToken().type == TokenType.LBRACK) {
            constDefNode.addChild(new Node("LBRACK", currentToken().value));
            advance(); // 消耗 '['
            constDefNode.addChild(parseConstExp()); // 解析数组大小
            if (currentToken().type == TokenType.RBRACK) {
                constDefNode.addChild(new Node("RBRACK", currentToken().value));
                advance(); // 消耗 ']'
            } else {
                reportError("k"); // 缺少 ']'
            }
        }

        // 处理 '='
        if (currentToken().type == TokenType.ASSIGN) {
            constDefNode.addChild(new Node("ASSIGN", currentToken().value));
            advance();
        }

        // 处理常量初值
        constDefNode.addChild(parseConstInitVal());

        return constDefNode;
    }

    private Node parseConstInitVal() {
        Node constInitValNode = new Node("<ConstInitVal>");

        if (currentToken().type == TokenType.LBRACE) {
            constInitValNode.addChild(new Node("LBRACE", currentToken().value));
            advance(); // 消耗 '{'

            // 处理可能存在的多项常量表达式
            if (isExpStart(currentToken())) {
                constInitValNode.addChild(parseConstExp());
                while (currentToken().type == TokenType.COMMA) {
                    constInitValNode.addChild(new Node("COMMA", currentToken().value));
                    advance(); // 消耗 ','
                    constInitValNode.addChild(parseConstExp());
                }
            }

            if (currentToken().type == TokenType.RBRACE) {
                constInitValNode.addChild(new Node("RBRACE", currentToken().value));
                advance(); // 消耗 '}'
            } else {
                reportError("k"); // 缺少 '}'
            }
        } else if (isExpStart(currentToken())) {
            constInitValNode.addChild(parseConstExp());
        } else if (currentToken().type == TokenType.STRCON) {
            constInitValNode.addChild(new Node("STRCON", currentToken().value));
            advance(); // 消耗字符串常量
        }
        return constInitValNode;
    }

    private Node parseConstExp() {
        Node constExpNode = new Node("<ConstExp>");
        constExpNode.addChild(parseAddExp());
        return constExpNode;
    }

    private Node parseAddExp() {
        Node addExpNode = new Node("<AddExp>");
        // 首先解析第一个 MulExp
        addExpNode.addChild(parseMulExp());

        // 处理后续的 '+' 或 '-' 运算符及其后的 MulExp
        while (currentToken() != null &&
                (currentToken().type == TokenType.PLUS ||
                        currentToken().type == TokenType.MINU)) {
            Node tmp = new Node("<AddExp>");
            Node opNode = new Node(currentToken().type.name(), currentToken().value);
            advance(); // 消耗运算符
            tmp.addChild(addExpNode); // 将当前的 AddExp 作为左子节点
            tmp.addChild(opNode);
            tmp.addChild(parseMulExp()); // 解析右侧的 MulExp
            addExpNode = tmp; // 更新 addExpNode 为新的根节点
        }

        return addExpNode;
    }

    private Node parseMulExp() {
        Node mulExpNode = new Node("<MulExp>");
        // 首先解析第一个 UnaryExp
        mulExpNode.addChild(parseUnaryExp());

        // 处理后续的 '*', '/', '%' 运算符及其后的 UnaryExp
        while (currentToken() != null &&
                (currentToken().type == TokenType.MULT ||
                        currentToken().type == TokenType.DIV ||
                        currentToken().type == TokenType.MOD)) {
            Node tmp = new Node("<MulExp>");
            Node opNode = new Node(currentToken().type.name(), currentToken().value);
            advance(); // 消耗运算符
            tmp.addChild(mulExpNode); // 将当前的 MulExp 作为左子节点
            tmp.addChild(opNode);
            tmp.addChild(parseUnaryExp()); // 解析右侧的 UnaryExp
            mulExpNode = tmp; // 更新 mulExpNode 为新的根节点
        }

        return mulExpNode;
    }

    private Node parseUnaryOp() {
        Node unaryOpNode = new Node("<UnaryOp>");

        // 检查并处理 '+'、'−' 和 '!' 运算符
        if (currentToken().type == TokenType.PLUS) {
            unaryOpNode.addChild(new Node("PLUS", currentToken().value));
            advance(); // 消耗 '+'
        } else if (currentToken().type == TokenType.MINU) {
            unaryOpNode.addChild(new Node("MINU", currentToken().value));
            advance(); // 消耗 '−'
        } else if (currentToken().type == TokenType.NOT) {
            unaryOpNode.addChild(new Node("NOT", currentToken().value));
            advance(); // 消耗 '!'
        }
        return unaryOpNode; // 返回单目运算符节点
    }


    private Node parseUnaryExp() {
        Node unaryExpNode = new Node("<UnaryExp>");

        // 检查是否为单目运算符
        if (currentToken().type == TokenType.PLUS ||
                currentToken().type == TokenType.MINU ||
                currentToken().type == TokenType.NOT) {
            // 处理单目运算符
            unaryExpNode.addChild(parseUnaryOp()); // 解析单目运算符
            unaryExpNode.addChild(parseUnaryExp());
        } else if (currentToken().type == TokenType.IDENFR && lookAhead(1).type == TokenType.LPARENT) {
            // 处理函数调用
            Node idenNode = new Node("IDENFR", currentToken().value);
            unaryExpNode.addChild(idenNode);
            advance(); // 消耗标识符

            // 检查是否是函数调用
            if (currentToken().type == TokenType.LPARENT) {
                unaryExpNode.addChild(new Node("LPARENT", currentToken().value));
                advance(); // 消耗 '('

                // 检查是否有实参
                if (currentToken().type == TokenType.RPARENT) {
                    unaryExpNode.addChild(new Node("RPARENT", currentToken().value));
                    advance(); // 消耗 ')'
                } else {
                    // 解析函数参数
                    unaryExpNode.addChild(parseFuncRParams()); // 解析函数实参表
                    if (currentToken().type == TokenType.RPARENT) {
                        unaryExpNode.addChild(new Node("RPARENT", currentToken().value));
                        advance(); // 消耗 ')'
                    } else  if(doingIsStmtLval == 0){
                        reportError("j"); // 缺少 ')'
                    }
                }
            }
        } else {
            // 如果当前 token 不是上述情况，则解析基本表达式
            unaryExpNode.addChild(parsePrimaryExp()); // 解析基本表达式
        }

        return unaryExpNode; // 返回一元表达式节点
    }

    private Node parseFuncRParams() {
        Node funcRParamsNode = new Node("<FuncRParams>");

        // 解析第一个表达式
        funcRParamsNode.addChild(parseExp());

        // 处理逗号分隔的其他参数
        while (currentToken().type == TokenType.COMMA) {
            funcRParamsNode.addChild(new Node("COMMA", currentToken().value));
            advance(); // 消耗逗号
            funcRParamsNode.addChild(parseExp()); // 解析下一个表达式
        }

        return funcRParamsNode;
    }

    private Node parsePrimaryExp() {
        Node primaryExpNode = new Node("<PrimaryExp>");

        if (currentToken().type == TokenType.LPARENT) {
            primaryExpNode.addChild(new Node("LPARENT", currentToken().value));
            advance(); // 消耗 '('
            primaryExpNode.addChild(parseExp()); // 递归解析表达式
            if (currentToken().type == TokenType.RPARENT) {
                primaryExpNode.addChild(new Node("RPARENT", currentToken().value));
                advance(); // 消耗 ')'
            } else {
                reportError("j"); // 缺少 ')'
            }
        } else if (currentToken().type == TokenType.IDENFR) {
            primaryExpNode.addChild(parseLVal()); // 解析左值
        } else if (currentToken().type == TokenType.INTCON) {
            primaryExpNode.addChild(parseNumber()); // 解析数值
        } else if (currentToken().type == TokenType.CHRCON) {
            primaryExpNode.addChild(parseCharacter()); // 解析字符
        }
        return primaryExpNode; // 返回基本表达式节点
    }


    private Node parseNumber() {
        Node numberNode = new Node("<Number>"); // 创建数值节点

        if (currentToken().type == TokenType.INTCON) {
            // 创建 INTCON 节点并添加到数值节点
            numberNode.addChild(new Node("INTCON", currentToken().value));
            advance(); // 消耗整数字符
        }
        return numberNode; // 返回数值节点
    }

    private Node parseCharacter() {
        Node charNode = new Node("<Character>"); // 创建字符节点

        if (currentToken().type == TokenType.CHRCON) {
            // 创建 CHRCON 节点并添加到字符节点
            charNode.addChild(new Node("CHRCON", currentToken().value));
            advance(); // 消耗字符常量
        }
        return charNode; // 返回字符节点
    }



    private Node parseLVal() {
        Node lValNode = new Node("<LVal>");

        if (currentToken().type == TokenType.IDENFR) {
            lValNode.addChild(new Node("IDENFR", currentToken().value));
            advance(); // 消耗标识符

            // 如果是数组访问，则处理中括号部分（在这里假设没有数组）
            if (currentToken().type == TokenType.LBRACK) {
                lValNode.addChild(new Node("LBRACK", currentToken().value));
                advance(); // 消耗 '['
                lValNode.addChild(parseExp()); // 解析数组下标
                if (currentToken().type == TokenType.RBRACK) {
                    lValNode.addChild(new Node("RBRACK", currentToken().value));
                    advance(); // 消耗 ']'
                } else if(doingIsStmtLval == 0){
                    reportError("k"); // 缺少 ']'
                }
            }
        }

        return lValNode;
    }


    private Node parseVarDecl() {
        Node varDeclNode = new Node("<VarDecl>");
        varDeclNode.addChild(parseBType());
        varDeclNode.addChild(parseVarDef());
        while (currentToken().type != TokenType.SEMICN) {
            if(currentToken().type == TokenType.COMMA){
                Node comma = new Node("COMMA", currentToken().value);
                varDeclNode.addChild(comma);
                advance();
            }
            varDeclNode.addChild(parseVarDef());
        }
        if(currentToken().type == TokenType.SEMICN){
            Node semicn = new Node("SEMICN", currentToken().value);
            varDeclNode.addChild(semicn);
            advance();
        }
        return varDeclNode;
    }

    private Node parseVarDef() {
        Node varDefNode = new Node("<VarDef>");

        // 检查并解析标识符
        if (currentToken().type == TokenType.IDENFR) {
            varDefNode.addChild(new Node("IDENFR", currentToken().value));
            advance(); // 消耗标识符

            // 检查是否有数组下标 '['
            if (currentToken().type == TokenType.LBRACK) {
                varDefNode.addChild(new Node("LBRACK", currentToken().value));
                advance(); // 消耗 '['
                varDefNode.addChild(parseConstExp()); // 解析常量表达式
                if (currentToken().type == TokenType.RBRACK) {
                    varDefNode.addChild(new Node("RBRACK", currentToken().value));
                    advance(); // 消耗 ']'
                } else {
                    reportError("k"); // 缺少 ']'
                }
            }

            // 检查是否有赋值 '='
            if (currentToken().type == TokenType.ASSIGN) {
                varDefNode.addChild(new Node("ASSIGN", currentToken().value));
                advance(); // 消耗 '='
                varDefNode.addChild(parseInitVal()); // 解析初始化值
            }
        }

        return varDefNode;
    }

    private Node parseInitVal() {
        Node initValNode = new Node("<InitVal>");

        // 情况 1: 直接解析一个表达式
        if (isExpStart(currentToken())) {
            initValNode.addChild(parseExp());
        }
        // 情况 2: 处理大括号包裹的初始化值
        else if (currentToken().type == TokenType.LBRACE) {
            initValNode.addChild(new Node("LBRACE", currentToken().value));
            advance(); // 消耗 '{'

            // 解析第一个可选的表达式
            if (isExpStart(currentToken())) {
                initValNode.addChild(parseExp());

                // 处理逗号分隔的其他表达式
                while (currentToken().type == TokenType.COMMA) {
                    initValNode.addChild(new Node("COMMA", currentToken().value));
                    advance(); // 消耗 ','
                    if (isExpStart(currentToken())) {
                        initValNode.addChild(parseExp());
                    }
                }
            }

            // 确保有右大括号 '}'
            if (currentToken().type == TokenType.RBRACE) {
                initValNode.addChild(new Node("RBRACE", currentToken().value));
                advance(); // 消耗 '}'
            }
        }
        // 情况 3: 字符串常量
        else if (currentToken().type == TokenType.STRCON) {
            initValNode.addChild(new Node("STRCON", currentToken().value));
            advance(); // 消耗字符串常量
        }

        return initValNode;
    }

    // 判断当前 token 是否是表达式的起始
    private boolean isExpStart(Token token) {
        return (token.type == TokenType.LPARENT) ||
                (token.type == TokenType.PLUS) ||
                (token.type == TokenType.MINU) ||
                (token.type == TokenType.NOT) ||
                (token.type == TokenType.IDENFR) ||
                (token.type == TokenType.INTCON) ||
                (token.type == TokenType.CHRCON);
    }

    private Node parseFuncDef() {
        Node funcDefNode = new Node("<FuncDef>");

        // 解析函数类型
        funcDefNode.addChild(parseFuncType());

        // 确保有标识符
        if (currentToken().type == TokenType.IDENFR) {
            funcDefNode.addChild(new Node("IDENFR", currentToken().value));
            advance(); // 消耗函数名
        }

        // 确保有左括号 '('
        if (currentToken().type == TokenType.LPARENT) {
            funcDefNode.addChild(new Node("LPARENT", currentToken().value));
            advance(); // 消耗 '('
        }
        // 解析可选的函数形参表 [FuncFParams]
        if (currentToken().type != TokenType.RPARENT && currentToken().type != TokenType.RBRACE) {
            funcDefNode.addChild(parseFuncFParams());
        }
        // 确保有右括号 ')'
        if (currentToken().type == TokenType.RPARENT) {
            funcDefNode.addChild(new Node("RPARENT", currentToken().value));
            advance(); // 消耗 ')'
        } else {
            reportError("j"); // 缺少 ')'
        }

        // 解析函数体 Block
        funcDefNode.addChild(parseBlock());

        if (needsReturnCheck(funcDefNode)) {
            reportError("g"); // 有返回值的函数缺少 return 语句
        }

        return funcDefNode;
    }

    private boolean needsReturnCheck(Node funcDefNode) {
        // 获取函数的返回类型（通过第一个子节点）
        Node funcTypeNode = funcDefNode.children.get(0);
        String funcType = funcTypeNode.value;

        // 检查函数类型是否为 int 或 char（即需要返回值的类型）
        if ("int".equals(funcType) || "char".equals(funcType)) {
            // 获取函数体（Block）节点
            Node blockNode = funcDefNode.children.get(funcDefNode.children.size() - 1);

            // 检查 block 中是否包含 return 语句
            return !containsReturnWithExp(blockNode);
        }

        // 如果是 void 类型，或者不需要 return 检查的情况，返回 false
        return false;
    }

    // 检查 Block 节点是否包含带返回值的 return 语句
    private boolean containsReturnWithExp(Node blockNode) {
        for (Node child : blockNode.children) {
            // 递归检查语句块中的子节点
            if ("<Stmt>".equals(child.type)) {
                // 如果遇到 return 语句，检查是否带有 Exp
                if (child.type.equals(TokenType.RETURNTK)) {
                    // 如果 return 语句的第一个子节点是 Exp，则表示有返回值
                    if (child.children.size() > 1) {
                        return true;
                    }
                }
            } else if ("<Block>".equals(child.type)) {
                // 递归检查嵌套的 block 节点
                if (containsReturnWithExp(child)) {
                    return true;
                }
            }
        }
        return false;
    }


    private Node parseFuncType() {
        Node funcTypeNode = new Node("<FuncType>");
        if (currentToken().type == TokenType.INTTK) {
            funcTypeNode.addChild(new Node("INTTK", currentToken().value));
            advance(); // 消耗 'int'
        } else if (currentToken().type == TokenType.CHARTK) {
            funcTypeNode.addChild(new Node("CHARTK", currentToken().value));
            advance(); // 消耗 'char'
        } else if (currentToken().type == TokenType.VOIDTK) {
            funcTypeNode.addChild(new Node("VOIDTK", currentToken().value));
            advance(); // 消耗 'void'
        }
        return funcTypeNode;
    }


    private Node parseMainFuncDef() {
        Node mainFuncDefNode = new Node("<MainFuncDef>");

        // 检查并解析 'int'
        if (currentToken().type == TokenType.INTTK) {
            mainFuncDefNode.addChild(new Node("INTTK", currentToken().value));
            advance(); // 消耗 'int'
        }
        // 检查并解析 'main'
        if (currentToken().type == TokenType.MAINTK) {
            mainFuncDefNode.addChild(new Node("MAINTK", currentToken().value));
            advance(); // 消耗 'main'
        }
        // 检查并解析左括号 '('
        if (currentToken().type == TokenType.LPARENT) {
            mainFuncDefNode.addChild(new Node("LPARENT", currentToken().value));
            advance(); // 消耗 '('
        }
        // 检查并解析右括号 ')'
        if (currentToken().type == TokenType.RPARENT) {
            mainFuncDefNode.addChild(new Node("RPARENT", currentToken().value));
            advance(); // 消耗 ')'
        } else {
            reportError("j"); // 缺少 ')'
        }
        if(currentToken().type == TokenType.LBRACE){
            // 解析函数体 Block
            mainFuncDefNode.addChild(parseBlock());
        }
        return mainFuncDefNode;
    }

    private Node parseFuncFParams() {
        Node funcFParamsNode = new Node("<FuncFParams>");

        // 解析第一个形参
        funcFParamsNode.addChild(parseFuncFParam());

        // 处理多个形参
        while (currentToken().type == TokenType.COMMA) {
            funcFParamsNode.addChild(new Node("COMMA", currentToken().value));
            advance(); // 消耗逗号
            funcFParamsNode.addChild(parseFuncFParam()); // 解析下一个形参
        }

        return funcFParamsNode;
    }

    private Node parseFuncFParam() {
        Node funcFParamNode = new Node("<FuncFParam>");

        // 解析基本类型
        funcFParamNode.addChild(parseBType());

        // 确保有标识符
        if (currentToken().type == TokenType.IDENFR) {
            funcFParamNode.addChild(new Node("IDENFR", currentToken().value));
            advance(); // 消耗标识符
        }

        // 检查是否有数组定义
        if (currentToken().type == TokenType.LBRACK) {
            funcFParamNode.addChild(new Node("LBRACK", currentToken().value));
            advance(); // Consume '['
            if (currentToken().type == TokenType.RBRACK) {
                funcFParamNode.addChild(new Node("RBRACK", currentToken().value));
                advance(); // Consume ']'
            } else {
                reportError("k"); // 缺少右中括号 ']'
            }
        }
        return funcFParamNode;
    }


    private Node parseBlock() {
        Node blockNode = new Node("<Block>");

        // 检查并解析左大括号 '{'
        if (currentToken().type == TokenType.LBRACE) {
            blockNode.addChild(new Node("LBRACE", currentToken().value));
            advance(); // 消耗 '{'
        }

        // 解析多个块项 BlockItem
        while (currentToken() != null && currentToken().type != TokenType.RBRACE) {
            blockNode.addChild(parseBlockItem());
        }

        // 检查并解析右大括号 '}'
        if (currentToken() != null && currentToken().type == TokenType.RBRACE) {
            blockNode.addChild(new Node("RBRACE", currentToken().value));
            advance(); // 消耗 '}'
        }

        return blockNode;
    }


    private Node parseBlockItem() {
        if (isDeclStart(currentToken())) {
            return parseDecl(); // 解析声明
        } else {
            return parseStmt(); // 解析语句
        }
    }


    private Node parseStmt() {
        Node stmtNode = new Node("<Stmt>");

        // 情况 3: Block
        if (currentToken().type == TokenType.LBRACE) {
            stmtNode.addChild(parseBlock()); // 解析块
            return stmtNode;
        }
        // 情况 4: 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
        else if (currentToken().type == TokenType.IFTK) {
            stmtNode.addChild(new Node("IFTK", currentToken().value));
            advance(); // 消耗 'if'

            if (currentToken().type == TokenType.LPARENT) {
                stmtNode.addChild(new Node("LPARENT", currentToken().value));
                advance(); // 消耗 '('
                stmtNode.addChild(parseCond()); // 解析条件
                if (currentToken().type == TokenType.RPARENT) {
                    stmtNode.addChild(new Node("RPARENT", currentToken().value));
                    advance(); // 消耗 ')'
                } else {
                    reportError("j"); // 缺少 ')'
                }
            }
            stmtNode.addChild(parseStmt()); // 解析 if 的语句
            if (currentToken() != null && currentToken().type == TokenType.ELSETK) {
                stmtNode.addChild(new Node("ELSETK", currentToken().value));
                advance(); // 消耗 'else'
                stmtNode.addChild(parseStmt()); // 解析 else 的语句
            }
            return stmtNode;
        }
        // 情况 5: 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
        else if (currentToken().type == TokenType.FORTK) {
            stmtNode.addChild(new Node("FORTK", currentToken().value));
            advance(); // 消耗 'for'

            if (currentToken().type == TokenType.LPARENT) {
                stmtNode.addChild(new Node("LPARENT", currentToken().value));
                advance(); // 消耗 '('
                // 解析 ForStmt，需处理缺省情况
                if (currentToken().type != TokenType.SEMICN) {
                    stmtNode.addChild(parseForStmt()); // 解析 for 语句
                }
                if (currentToken().type == TokenType.SEMICN) {
                    stmtNode.addChild(new Node("SEMICN", currentToken().value));
                    advance(); // 消耗 ';'
                }
                if (currentToken().type != TokenType.SEMICN) {
                    stmtNode.addChild(parseCond()); // 解析条件
                }
                if (currentToken().type == TokenType.SEMICN) {
                    stmtNode.addChild(new Node("SEMICN", currentToken().value));
                    advance(); // 消耗 ';'
                }
                if (currentToken().type != TokenType.RPARENT) {
                    stmtNode.addChild(parseForStmt()); // 解析后操作
                }
                if (currentToken().type == TokenType.RPARENT) {
                    stmtNode.addChild(new Node("RPARENT", currentToken().value));
                    advance(); // 消耗 ')'
                }
            }
            stmtNode.addChild(parseStmt()); // 解析 for 的语句
            return stmtNode;
        }
        // 情况 6: 'break' ';'
        else if (currentToken().type == TokenType.BREAKTK) {
            stmtNode.addChild(new Node("BREAKTK", currentToken().value));
            advance(); // 消耗 'break'
            if (currentToken().type == TokenType.SEMICN) {
                stmtNode.addChild(new Node("SEMICN", currentToken().value));
                advance(); // 消耗 ';'
            } else {
                reportError("i"); // 缺少 ';'
            }
            return stmtNode;
        }

        // 情况 7: 'continue' ';'
        else if (currentToken().type == TokenType.CONTINUETK) {
            stmtNode.addChild(new Node("CONTINUETK", currentToken().value));
            advance(); // 消耗 'continue'
            if (currentToken().type == TokenType.SEMICN) {
                stmtNode.addChild(new Node("SEMICN", currentToken().value));
                advance(); // 消耗 ';'
            } else {
                reportError("i"); // 缺少 ';'
            }
            return stmtNode;
        }
        // 情况 8: 'return' [Exp] ';'
        else if (currentToken().type == TokenType.RETURNTK) {
            stmtNode.addChild(new Node("RETURNTK", currentToken().value));
            advance(); // 消耗 'return'
            // 可选解析 Exp
            if (isExpStart(currentToken())) {
                stmtNode.addChild(parseExp()); // 解析返回值
            }
            if (currentToken().type == TokenType.SEMICN) {
                stmtNode.addChild(new Node("SEMICN", currentToken().value));
                advance(); // 消耗 ';'
            } else {
                reportError("i"); // 缺少 ';'
            }
            return stmtNode;
        }

        // 情况 11: printf '(' StringConst { ',' Exp } ')' ';'
        else if (currentToken().type == TokenType.PRINTFTK) {
            stmtNode.addChild(new Node("PRINTFTK", currentToken().value));
            advance(); // 消耗 'printf'

            if (currentToken().type == TokenType.LPARENT) {
                stmtNode.addChild(new Node("LPARENT", currentToken().value));
                advance(); // 消耗 '('

                // 处理字符串常量
                if (currentToken().type == TokenType.STRCON) {
                    stmtNode.addChild(new Node("STRCON", currentToken().value));
                    advance(); // 消耗字符串常量
                }

                // 处理后续可能的逗号和表达式
                while (currentToken() != null && currentToken().type == TokenType.COMMA) {
                    stmtNode.addChild(new Node("COMMA", currentToken().value));
                    advance(); // 消耗 ','
                    if (isExpStart(currentToken())) {
                        stmtNode.addChild(parseExp()); // 解析表达式
                    }
                }

                if (currentToken().type == TokenType.RPARENT) {
                    stmtNode.addChild(new Node("RPARENT", currentToken().value));
                    advance(); // 消耗 ')'
                } else {
                    reportError("j"); // 缺少 ')'
                }
            }

            if (currentToken().type == TokenType.SEMICN) {
                stmtNode.addChild(new Node("SEMICN", currentToken().value));
                advance(); // 消耗 ';'
            } else {
                reportError("i"); // 缺少 ';'
            }
            return stmtNode;
        }
        // 情况 9: LVal
        else if (isStmtLval(currentToken())) {
            stmtNode.addChild(parseLVal()); // 解析左值
            if (currentToken().type == TokenType.ASSIGN) {
                stmtNode.addChild(new Node("ASSIGN", currentToken().value));
                advance(); // 消耗 '='
            }
            if (currentToken().type == TokenType.GETINTTK) {
                stmtNode.addChild(new Node("GETINTTK", currentToken().value));
                advance(); // 消耗 'getint'
                if (currentToken().type == TokenType.LPARENT) {
                    stmtNode.addChild(new Node("LPARENT", currentToken().value));
                    advance(); // 消耗 '('
                    if (currentToken().type == TokenType.RPARENT) {
                        stmtNode.addChild(new Node("RPARENT", currentToken().value));
                        advance(); // 消耗 ')'
                    } else {
                        reportError("j"); // 缺少 ')'
                    }
                }
            }
            else if (currentToken().type == TokenType.GETCHARTK) {
                stmtNode.addChild(new Node("GETCHARTK", currentToken().value));
                advance(); // 消耗 'getchar'
                if (currentToken().type == TokenType.LPARENT) {
                    stmtNode.addChild(new Node("LPARENT", currentToken().value));
                    advance(); // 消耗 '('
                    if (currentToken().type == TokenType.RPARENT) {
                        stmtNode.addChild(new Node("RPARENT", currentToken().value));
                        advance(); // 消耗 ')'
                    } else {
                        reportError("j"); // 缺少 ')'
                    }
                }
            }
            else{
                stmtNode.addChild(parseExp()); // 解析右侧表达式
            }
            if (currentToken().type == TokenType.SEMICN) {
                stmtNode.addChild(new Node("SEMICN", currentToken().value));
                advance(); // 消耗 ';'
            } else {
                reportError("i"); // 缺少 ';'
            }
            return stmtNode;
        }
        // 情况 2: [Exp] ';'
        // 如果当前 token 是 ';' 或者是一个表达式开头的 token，那么解析为 [Exp] ';'
        else if (isExpStart(currentToken())) {
            // 可选解析 Exp
            stmtNode.addChild(parseExp()); // 解析表达式
            if (currentToken().type == TokenType.SEMICN) {
                stmtNode.addChild(new Node("SEMICN", currentToken().value));
                advance(); // 消耗 ';'
            } else {
                reportError("i"); // 缺少 ';'

            }
            return stmtNode;
        }
        else if(currentToken().type == TokenType.SEMICN){
            stmtNode.addChild(new Node("SEMICN", currentToken().value));
            advance(); // 消耗 ';'
            return stmtNode;
        }
        else{
            reportError("i"); // 缺少;
            advance(); // 消耗当前 token，避免死循环
        }
        return stmtNode;
    }

    private boolean isStmtLval(Token token) {
        if (lookAhead(1).type == TokenType.ASSIGN || lookAhead(1).type == TokenType.LBRACK) {
            // 保存当前状态
            int tempCurPos = curPos;
            doingIsStmtLval = 1;
            parseLVal(); // 解析左值
            doingIsStmtLval = 0;
            // 检查当前 token 是否为 ASSIGN
            if (currentToken().type == TokenType.ASSIGN) {
                // 恢复之前的状态
                curPos = tempCurPos;
                return true;
            }

            // 恢复之前的状态
            curPos = tempCurPos;
        }
        return false;
    }

    private Node parseForStmt() {
        Node forStmtNode = new Node("<ForStmt>");

        if (currentToken().type == TokenType.IDENFR) {
            forStmtNode.addChild(parseLVal()); // 解析左值 LVal

            if (currentToken().type == TokenType.ASSIGN) {
                forStmtNode.addChild(new Node("ASSIGN", currentToken().value));
                advance(); // 消耗 '='
                forStmtNode.addChild(parseExp()); // 解析表达式 Exp
            }
        }

        return forStmtNode;
    }

    private Node parseExp() {
        Node expNode = new Node("<Exp>");
        expNode.addChild(parseAddExp()); // 解析加法表达式 AddExp
        return expNode;
    }

    private Node parseCond() {
        Node condNode = new Node("<Cond>");
        condNode.addChild(parseLOrExp()); // 解析逻辑或表达式 LOrExp
        return condNode;
    }

    private Node parseLOrExp() {
        Node lOrExpNode = new Node("<LOrExp>");
        // 首先解析第一个 LAndExp
        lOrExpNode.addChild(parseLAndExp());

        // 处理后续的 '||' 运算符及其后的 LAndExp
        while (currentToken() != null && currentToken().type == TokenType.OR) {
            Node tmp = new Node("<LOrExp>");
            Node opNode = new Node("OR", currentToken().value);
            if(currentToken().value.equals("|")){
                reportError("a");
            }
            advance(); // 消耗 '||'
            tmp.addChild(lOrExpNode); // 将当前的 LOrExp 作为左子节点
            tmp.addChild(opNode);
            tmp.addChild(parseLAndExp()); // 解析右侧的 LAndExp
            lOrExpNode = tmp; // 更新 lOrExpNode 为新的根节点
        }

        return lOrExpNode;
    }

    private Node parseLAndExp() {
        Node lAndExpNode = new Node("<LAndExp>");
        // 首先解析第一个 EqExp
        lAndExpNode.addChild(parseEqExp());

        // 处理后续的 '&&' 运算符及其后的 EqExp
        while (currentToken() != null && currentToken().type == TokenType.AND) {
            Node tmp = new Node("<LAndExp>");
            Node opNode = new Node("AND", currentToken().value);
            if(currentToken().value.equals("&")){
                reportError("a");
            }
            advance(); // 消耗 '&&'
            tmp.addChild(lAndExpNode); // 将当前的 LAndExp 作为左子节点
            tmp.addChild(opNode);
            tmp.addChild(parseEqExp()); // 解析右侧的 EqExp
            lAndExpNode = tmp; // 更新 lAndExpNode 为新的根节点
        }

        return lAndExpNode;
    }

    private Node parseEqExp() {
        Node eqExpNode = new Node("<EqExp>");
        // 首先解析第一个 RelExp
        eqExpNode.addChild(parseRelExp());

        // 处理后续的 '==' 或 '!=' 运算符及其后的 RelExp
        while (currentToken() != null &&
                (currentToken().type == TokenType.EQL ||
                        currentToken().type == TokenType.NEQ)) {
            Node tmp = new Node("<EqExp>");
            Node opNode = new Node(currentToken().type.name(), currentToken().value);
            advance(); // 消耗运算符
            tmp.addChild(eqExpNode); // 将当前的 EqExp 作为左子节点
            tmp.addChild(opNode);
            tmp.addChild(parseRelExp()); // 解析右侧的 RelExp
            eqExpNode = tmp; // 更新 eqExpNode 为新的根节点
        }

        return eqExpNode;
    }

    private Node parseRelExp() {
        Node relExpNode = new Node("<RelExp>");
        // 首先解析第一个 AddExp
        relExpNode.addChild(parseAddExp());

        // 处理后续的关系运算符 ('<', '>', '<=', '>=')
        while (currentToken() != null &&
                (currentToken().type == TokenType.LSS ||
                        currentToken().type == TokenType.GRE ||
                        currentToken().type == TokenType.LEQ ||
                        currentToken().type == TokenType.GEQ)) {
            Node tmp = new Node("<RelExp>");
            Node opNode = new Node(currentToken().type.name(), currentToken().value);
            advance(); // 消耗关系运算符
            tmp.addChild(relExpNode); // 将当前的 RelExp 作为左子节点
            tmp.addChild(opNode);
            tmp.addChild(parseAddExp()); // 解析右侧的 AddExp
            relExpNode = tmp; // 更新 relExpNode 为新的根节点
        }

        return relExpNode;
    }

    private void outputResults() {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter("parser.txt"))) {
            writeNode(writer, root);
        } catch (IOException e) {
            e.printStackTrace();
        }

        try (BufferedWriter writer = new BufferedWriter(new FileWriter("error.txt"))) {
            for (String error : errors) {
                writer.write(error);
                writer.newLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void writeNode(BufferedWriter writer, Node node) throws IOException {
        if (node == null) return;
        for (Node child : node.children) {
            writeNode(writer, child);
        }
        writer.write(node.type);
        if (node.value != null) {
            writer.write(" " + node.value);
        }
        writer.newLine();
    }
}
