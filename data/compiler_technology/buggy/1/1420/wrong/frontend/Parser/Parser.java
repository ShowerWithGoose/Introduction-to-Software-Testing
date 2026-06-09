package frontend.Parser;

import frontend.ErrorChecker.ErrorBlock;
import frontend.Lexer.Token;
import frontend.SyntaxTree.SyntaxTreeNode;
import frontend.Lexer.LexType;


import java.util.ArrayList;
import java.util.List;

public class Parser {
    private List<Token> tokens;
    private int currentTokenIndex;
    private List<String> errors; // 存储错误信息

    public Parser(List<Token> tokens) {
        this.tokens = tokens;
        this.currentTokenIndex = 0;
        this.errors = new ArrayList<>(); // 初始化错误列表
    }

    private Token getCurrentToken() {
        if (currentTokenIndex < tokens.size()) {
            return tokens.get(currentTokenIndex);
        }
        return null;
    }

    private Token getNextKToken(int k) {
        if (currentTokenIndex + k < tokens.size()) {
            return tokens.get(currentTokenIndex + k);
        } else {
            return null;
        }
    }

    // 获取前一个 Token
    private Token getPreviousToken() {
        if (currentTokenIndex > 0) {
            return tokens.get(currentTokenIndex - 1); // 返回当前索引的前一个 Token
        } else {
            return null; // 如果当前是第一个 Token，返回 null
        }
    }

    // 跳到下一个 Token
    private void advance() {
        if (currentTokenIndex < tokens.size()) {
            currentTokenIndex++; // 移动到下一个 Token
        }
    }

    public List<String> getErrors() {
        return errors;
    }

    // 记录错误信息
    private void recordError(int lineNumber, String errorCode) {
        errors.add(lineNumber + " " + errorCode);
    }

    // 将语法分析的错误转换为 ErrorBlock 对象，并加入到主程序的 errorList 中
    public void transformError(List<ErrorBlock> errorList) {
        for (String error : errors) {
            // 解析 "lineNumber errorCode" 的格式
            String[] parts = error.split(" ");
            int lineNumber = Integer.parseInt(parts[0]);  // 获取行号
            String errorCode = parts[1];  // 获取错误码

            // 创建 ErrorBlock 并加入到 errorList 中
            errorList.add(new ErrorBlock(lineNumber, errorCode));
        }
    }

    // 编译单元 CompUnit → {Decl} {FuncDef} MainFuncDef
    public SyntaxTreeNode parseCompUnit() {
        SyntaxTreeNode compUnitNode = new SyntaxTreeNode("CompUnit");

        // 解析多个声明 Decl 或函数定义 FuncDef 或主函数定义 MainFuncDef
        while (getCurrentToken() != null) {
            if (isMainFuncDef()) {
                // 解析 MainFuncDef
                compUnitNode.addChild(parseMainFuncDef());
            } else if (getCurrentToken().getTokenType() == LexType.INTTK ||
                    getCurrentToken().getTokenType() == LexType.CHARTK ||
                    getCurrentToken().getTokenType() == LexType.VOIDTK) {
                // 如果当前是 'int'、'char' 或 'void'，则可能是声明或函数定义
                Token nextToken = getNextKToken(1);

                // 检查下一个 Token 是否为标识符，且其后是否是 '('
                if (nextToken != null && nextToken.getTokenType() == LexType.IDENFR) {
                    // 判断函数定义：如果标识符后面跟的是 '('，说明是函数定义
                    if (getNextKToken(2) != null && getNextKToken(2).getTokenType() == LexType.LPARENT) {
                        // 解析函数定义 FuncDef
                        compUnitNode.addChild(parseFuncDef());
                    } else {
                        // 解析声明 Decl1
                        compUnitNode.addChild(parseDecl());
                    }
                } else {
                    // 如果没有正确匹配到标识符或者后续的符号，输出错误
                    System.out.println("Error: Expected identifier after type specifier");
                    // System.exit(currentTokenIndex);
                    break;
                }
            } else if (getCurrentToken().getTokenType() == LexType.CONSTTK) {
                // 如果当前是 'const'，则可能是声明
                Token nextToken = getNextKToken(1);

                // 检查下一个 Token 是否为标识符
                if (nextToken != null && (nextToken.getTokenType() == LexType.INTTK || nextToken.getTokenType() == LexType.CHARTK)) {
                    // 解析声明 Decl
                    compUnitNode.addChild(parseDecl());
                } else {
                    // 如果没有正确匹配到标识符，输出错误
                    System.out.println("Error: Expected identifier after 'const'");
                    System.exit(currentTokenIndex);
                    break;
                }
            } else {
                System.out.println("Error: Unrecognized token in CompUnit");
                // System.exit(currentTokenIndex);
                break;
            }
        }

        return compUnitNode;
    }


    private boolean isMainFuncDef() {
        // 判断当前 token 是否是主函数定义
        return getCurrentToken().getValue().equals("int") && getNextKToken(1).getValue().equals("main");
    }


    //    声明 Decl → ConstDecl | VarDecl
    private SyntaxTreeNode parseDecl() {
        SyntaxTreeNode declNode = new SyntaxTreeNode("Decl");

        // 判断当前的声明类型：ConstDecl 或 VarDecl
        if (getCurrentToken().getValue().equals("const")) {
            // 如果是 'const'，说明是常量声明
            declNode.addChild(parseConstDecl());
        } else {
            // 否则是变量声明
            declNode.addChild(parseVarDecl());
        }

        return declNode;
    }

    // 常量声明 ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';' // i
    private SyntaxTreeNode parseConstDecl() {
        // 创建 ConstDecl 非终结符节点
        SyntaxTreeNode constDeclNode = new SyntaxTreeNode("ConstDecl");

        // 匹配 'const' 关键字
        if (getCurrentToken().getValue().equals("const")) {
            constDeclNode.addChild(new SyntaxTreeNode("CONSTTK", "const"));
            advance(); // 跳过 'const'
        }

        // 解析基本类型 BType
        constDeclNode.addChild(parseBType());

        // 解析第一个 ConstDef
        constDeclNode.addChild(parseConstDef());

        // 处理多个逗号分隔的 ConstDef
        while (getCurrentToken().getTokenType() == LexType.COMMA) {
            constDeclNode.addChild(new SyntaxTreeNode("COMMA", ","));
            advance(); // 跳过逗号
            constDeclNode.addChild(parseConstDef());
        }

        // 检查是否有分号 ';'
        if (getCurrentToken().getTokenType() == LexType.SEMICN) {
            constDeclNode.addChild(new SyntaxTreeNode("SEMICN", ";"));
            advance(); // 跳过分号
        } else {
            // 缺少分号，记录错误 i，错误行号为分号前一个非终结符行号
            recordError(getPreviousToken().getLineNumber(), "i");
        }

        return constDeclNode;
    }

    // 基本类型 BType → 'int' | 'char'
    private SyntaxTreeNode parseBType() {
        SyntaxTreeNode bTypeNode = new SyntaxTreeNode("BType");
        String tokenValue = getCurrentToken().getValue();

        if (tokenValue.equals("int")) {
            // 解析 'int' 关键字，创建终结符节点
            bTypeNode.addChild(new SyntaxTreeNode("INTTK", "int"));
            advance(); // 跳过 'int'
        } else if (tokenValue.equals("char")) {
            // 解析 'char' 关键字，创建终结符节点
            bTypeNode.addChild(new SyntaxTreeNode("CHARTK", "char"));
            advance(); // 跳过 'char'
        } else {
            System.out.println("Error: Expected 'int' or 'char' in BType");
            // System.exit(currentTokenIndex);
        }

        return bTypeNode;
    }

    // 常量定义 ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal // k
    private SyntaxTreeNode parseConstDef() {
        SyntaxTreeNode constDefNode = new SyntaxTreeNode("ConstDef");

        // 匹配 Ident（标识符）
        if (getCurrentToken().getTokenType() == LexType.IDENFR) {
            constDefNode.addChild(new SyntaxTreeNode("IDENFR", getCurrentToken().getValue()));
            advance();  // 跳过 Ident
        } else {
            System.out.println("Error: Expected Ident in ConstDef");
            // System.exit(currentTokenIndex);
        }

        // 可选的数组形式：匹配 '[' ConstExp ']'
        if (getCurrentToken().getTokenType() == LexType.LBRACK) {
            constDefNode.addChild(new SyntaxTreeNode("LBRACK", "["));
            advance();  // 跳过 '['
            constDefNode.addChild(parseConstExp());

            // 检查是否有右中括号 ']'
            if (getCurrentToken().getTokenType() == LexType.RBRACK) {
                constDefNode.addChild(new SyntaxTreeNode("RBRACK", "]"));
                advance();  // 跳过 ']'
            } else {
                // 缺少右中括号，记录错误 (错误类型 k)
                recordError(getPreviousToken().getLineNumber(), "k");
            }
        }

        // 匹配 '='
        if (getCurrentToken().getTokenType() == LexType.ASSIGN) {
            constDefNode.addChild(new SyntaxTreeNode("ASSIGN", "="));
            advance();  // 跳过 '='
        } else {
            System.out.println("Error: Expected '=' in ConstDef");
            // System.exit(currentTokenIndex);
        }

        // 匹配 ConstInitVal
        constDefNode.addChild(parseConstInitVal());

        return constDefNode;
    }

    // 常量初值 ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
    private SyntaxTreeNode parseConstInitVal() {
        SyntaxTreeNode constInitValNode = new SyntaxTreeNode("ConstInitVal");

        // 判断是否为 '{'，表示初始化一个数组或结构体
        if (getCurrentToken().getValue().equals("{")) {
            constInitValNode.addChild(new SyntaxTreeNode("LBRACE", "{"));
            advance(); // 跳过 '{'

            // 可选的匹配第一个 ConstExp
            if (!getCurrentToken().getValue().equals("}")) {
                constInitValNode.addChild(parseConstExp());

                // 检查是否有更多的 ConstExp，用逗号分隔
                while (getCurrentToken().getValue().equals(",")) {
                    constInitValNode.addChild(new SyntaxTreeNode("COMMA", ","));
                    advance(); // 跳过逗号
                    constInitValNode.addChild(parseConstExp());
                }
            }

            // 匹配 '}'，此处假设一定有匹配的右大括号
            if (getCurrentToken().getValue().equals("}")) {
                constInitValNode.addChild(new SyntaxTreeNode("RBRACE", "}"));
                advance(); // 跳过 '}'
            } else {
                System.out.println("Error: Expected '}' to close initializer");
                // System.exit(currentTokenIndex);
            }

        } else if (getCurrentToken().getTokenType() == LexType.STRCON) {
            // 匹配字符串常量 StringConst
            constInitValNode.addChild(new SyntaxTreeNode("STRCON", getCurrentToken().getValue()));
            advance(); // 跳过字符串常量

        } else {
            // 匹配 ConstExp
            constInitValNode.addChild(parseConstExp());
        }

        return constInitValNode;
    }

    // 变量声明 VarDecl → BType VarDef { ',' VarDef } ';' // i
    private SyntaxTreeNode parseVarDecl() {
        SyntaxTreeNode varDeclNode = new SyntaxTreeNode("VarDecl");

        // 解析基本类型 BType
        varDeclNode.addChild(parseBType());

        // 解析第一个变量定义 VarDef
        varDeclNode.addChild(parseVarDef());

        // 处理逗号分隔的多个变量定义
        while (getCurrentToken().getValue().equals(",")) {
            varDeclNode.addChild(new SyntaxTreeNode("COMMA", ","));
            advance(); // 跳过逗号
            varDeclNode.addChild(parseVarDef());
        }

        // 检查是否有分号 ';'
        if (getCurrentToken().getTokenType() == LexType.SEMICN) {
            varDeclNode.addChild(new SyntaxTreeNode("SEMICN", ";"));
            advance(); // 跳过分号
        } else {
            // 如果缺少分号，记录错误 (错误类型 i)
            recordError(getPreviousToken().getLineNumber(), "i");
        }

        return varDeclNode;
    }

    // 变量定义 VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal // k
    private SyntaxTreeNode parseVarDef() {
        SyntaxTreeNode varDefNode = new SyntaxTreeNode("VarDef");

        // 匹配 Ident (变量名)
        if (getCurrentToken().getTokenType() == LexType.IDENFR) {
            varDefNode.addChild(new SyntaxTreeNode("IDENFR", getCurrentToken().getValue()));
            advance(); // 跳过 Ident
        } else {
            System.out.println("Error: Expected Ident in VarDef");
            // System.exit(currentTokenIndex);
        }

        // 匹配数组定义 [ '[' ConstExp ']' ]
        if (getCurrentToken().getTokenType() == LexType.LBRACK) {
            varDefNode.addChild(new SyntaxTreeNode("LBRACK", "["));
            advance(); // 跳过 '['

            // 解析 ConstExp
            varDefNode.addChild(parseConstExp());

            // 检查是否有右中括号 ']'
            if (getCurrentToken().getTokenType() == LexType.RBRACK) {
                varDefNode.addChild(new SyntaxTreeNode("RBRACK", "]"));
                advance(); // 跳过 ']'
            } else {
                // 缺少右中括号，记录错误 (错误类型 k)
                recordError(getPreviousToken().getLineNumber(), "k"); // 错误行号为 '[' 或 ConstExp 所在行
            }
        }

        // 匹配赋值 '=' InitVal
        if (getCurrentToken().getTokenType() == LexType.ASSIGN) {
            varDefNode.addChild(new SyntaxTreeNode("ASSIGN", "="));
            advance(); // 跳过 '='
            varDefNode.addChild(parseInitVal());
        }

        return varDefNode;
    }

    // 变量初值 InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
    private SyntaxTreeNode parseInitVal() {
        SyntaxTreeNode initValNode = new SyntaxTreeNode("InitVal");

        // 判断是否为数组或结构体初始化 (即 '{' 开头)
        if (getCurrentToken().getValue().equals("{")) {
            initValNode.addChild(new SyntaxTreeNode("LBRACE", "{"));
            advance(); // 跳过 '{'

            // 可选的匹配第一个 Exp
            if (!getCurrentToken().getValue().equals("}")) {
                initValNode.addChild(parseExp());

                // 处理多个 Exp，逗号分隔
                while (getCurrentToken().getValue().equals(",")) {
                    initValNode.addChild(new SyntaxTreeNode("COMMA", ","));
                    advance(); // 跳过逗号
                    initValNode.addChild(parseExp());
                }
            }

            // 匹配 '}'
            if (getCurrentToken().getValue().equals("}")) {
                initValNode.addChild(new SyntaxTreeNode("RBRACE", "}"));
                advance(); // 跳过 '}'
            } else {
                System.out.println("Error: Expected '}' after array initialization");
                // System.exit(currentTokenIndex);
            }

        } else if (getCurrentToken().getTokenType() == LexType.STRCON) {
            // 匹配 StringConst
            initValNode.addChild(new SyntaxTreeNode("STRCON", getCurrentToken().getValue()));
            advance(); // 跳过 StringConst

        } else {
            // 匹配 Exp
            initValNode.addChild(parseExp());
        }

        return initValNode;
    }

    // 函数定义 FuncDef → FuncType Ident '(' [FuncFParams] ')' Block // j
    private SyntaxTreeNode parseFuncDef() {
        SyntaxTreeNode funcDefNode = new SyntaxTreeNode("FuncDef");

        // 解析函数类型 FuncType
        funcDefNode.addChild(parseFuncType());

        // 解析函数名 Ident
        if (getCurrentToken().getTokenType() == LexType.IDENFR) {
            funcDefNode.addChild(new SyntaxTreeNode("IDENFR", getCurrentToken().getValue()));
            advance(); // 跳过 Ident
        } else {
            System.out.println("Error: Expected function name (Ident) in FuncDef");
            // System.exit(currentTokenIndex);
        }

        // 匹配左小括号 '('
        if (getCurrentToken().getTokenType() == LexType.LPARENT) {
            funcDefNode.addChild(new SyntaxTreeNode("LPARENT", "("));
            advance(); // 跳过 '('
        } else {
            System.out.println("Error: Expected '(' in FuncDef");
            // System.exit(currentTokenIndex);
        }

        // 可选的解析函数参数表 FuncFParams
        if (getCurrentToken().getTokenType() != LexType.RPARENT) {
            funcDefNode.addChild(parseFuncFParams());
        }

        // 检查是否有右小括号 ')'
        if (getCurrentToken().getTokenType() == LexType.RPARENT) {
            funcDefNode.addChild(new SyntaxTreeNode("RPARENT", ")"));
            advance(); // 跳过 ')'
        } else {
            // 缺少右小括号，记录错误 (错误类型 j)
            recordError(getPreviousToken().getLineNumber(), "j");
        }

        // 解析函数体 Block
        funcDefNode.addChild(parseBlock());

        return funcDefNode;
    }

    // 主函数定义 MainFuncDef → 'int' 'main' '(' ')' Block // j
    private SyntaxTreeNode parseMainFuncDef() {
        SyntaxTreeNode mainFuncDefNode = new SyntaxTreeNode("MainFuncDef");

        // 匹配 'int'
        if (getCurrentToken().getValue().equals("int")) {
            mainFuncDefNode.addChild(new SyntaxTreeNode("INTTK", "int"));
            advance(); // 跳过 'int'
        } else {
            System.out.println("Error: Expected 'int' in MainFuncDef");
            // System.exit(currentTokenIndex);
        }

        // 匹配 'main'
        if (getCurrentToken().getValue().equals("main")) {
            mainFuncDefNode.addChild(new SyntaxTreeNode("MAINTK", "main"));
            advance(); // 跳过 'main'
        } else {
            System.out.println("Error: Expected 'main' in MainFuncDef");
            // System.exit(currentTokenIndex);
        }

        // 匹配左小括号 '('
        if (getCurrentToken().getValue().equals("(")) {
            mainFuncDefNode.addChild(new SyntaxTreeNode("LPARENT", "("));
            advance(); // 跳过 '('
        } else {
            System.out.println("Error: Expected '(' in MainFuncDef");
            // System.exit(currentTokenIndex);
        }

        // 检查是否有右小括号 ')'
        if (getCurrentToken().getValue().equals(")")) {
            mainFuncDefNode.addChild(new SyntaxTreeNode("RPARENT", ")"));
            advance(); // 跳过 ')'
        } else {
            // 缺少右小括号，记录错误 (错误类型 j)
            recordError(getPreviousToken().getLineNumber(), "j");
        }

        // 解析函数体 Block
        mainFuncDefNode.addChild(parseBlock());

        return mainFuncDefNode;
    }

    // 函数类型 FuncType → 'void' | 'int' | 'char'
    private SyntaxTreeNode parseFuncType() {
        SyntaxTreeNode funcTypeNode = new SyntaxTreeNode("FuncType");

        // 匹配 'void' | 'int' | 'char'
        String tokenValue = getCurrentToken().getValue();
        if (tokenValue.equals("void")) {
            // 匹配 'void'
            funcTypeNode.addChild(new SyntaxTreeNode("VOIDTK", "void"));
            advance(); // 跳过 'void'
        } else if (tokenValue.equals("int")) {
            // 匹配 'int'
            funcTypeNode.addChild(new SyntaxTreeNode("INTTK", "int"));
            advance(); // 跳过 'int'
        } else if (tokenValue.equals("char")) {
            // 匹配 'char'
            funcTypeNode.addChild(new SyntaxTreeNode("CHARTK", "char"));
            advance(); // 跳过 'char'
        } else {
            System.out.println("Error: Expected function type (void, int, or char)");
            // System.exit(currentTokenIndex);
        }

        return funcTypeNode;
    }

    // 函数形参表 FuncFParams → FuncFParam { ',' FuncFParam }
    private SyntaxTreeNode parseFuncFParams() {
        SyntaxTreeNode funcFParamsNode = new SyntaxTreeNode("FuncFParams");

        // 解析第一个函数形参 FuncFParam
        funcFParamsNode.addChild(parseFuncFParam());

        // 处理多个逗号分隔的函数形参
        while (getCurrentToken().getValue().equals(",")) {
            funcFParamsNode.addChild(new SyntaxTreeNode("COMMA", ",")); // 添加逗号节点
            advance(); // 跳过逗号
            funcFParamsNode.addChild(parseFuncFParam()); // 解析下一个形参
        }

        return funcFParamsNode;
    }

    // 函数形参 FuncFParam → BType Ident ['[' ']'] // k
    private SyntaxTreeNode parseFuncFParam() {
        SyntaxTreeNode funcFParamNode = new SyntaxTreeNode("FuncFParam");

        // 解析基本类型 BType
        funcFParamNode.addChild(parseBType());

        // 匹配 Ident (参数名)
        if (getCurrentToken().getTokenType() == LexType.IDENFR) {
            funcFParamNode.addChild(new SyntaxTreeNode("IDENFR", getCurrentToken().getValue()));
            advance(); // 跳过 Ident
        } else {
            System.out.println("Error: Expected Ident in FuncFParam");
            // System.exit(currentTokenIndex);
        }

        // 检查是否有数组定义 '[' ']'
        if (getCurrentToken().getTokenType() == LexType.LBRACK) {
            funcFParamNode.addChild(new SyntaxTreeNode("LBRACK", "["));
            advance(); // 跳过 '['

            // 检查是否有右中括号 ']'
            if (getCurrentToken().getTokenType() == LexType.RBRACK) {
                funcFParamNode.addChild(new SyntaxTreeNode("RBRACK", "]"));
                advance(); // 跳过 ']'
            } else {
                // 缺少右中括号，记录错误 (错误类型 k)，错误行号为 '[' 所在行
                recordError(getPreviousToken().getLineNumber(), "k");
            }
        }

        return funcFParamNode;
    }

    // 语句块 Block → '{' { BlockItem } '}'
    private SyntaxTreeNode parseBlock() {
        SyntaxTreeNode blockNode = new SyntaxTreeNode("Block");

        // 匹配左大括号 '{'
        if (getCurrentToken().getValue().equals("{")) {
            blockNode.addChild(new SyntaxTreeNode("LBRACE", "{"));
            advance(); // 跳过 '{'
        } else {
            System.out.println("Error: Expected '{' in Block");
            // System.exit(currentTokenIndex);
        }

        // 解析多个 BlockItem，直到匹配到右大括号 '}'
        while (!getCurrentToken().getValue().equals("}")) {
            blockNode.addChild(parseBlockItem());
        }

        // 匹配右大括号 '}'
        if (getCurrentToken().getValue().equals("}")) {
            blockNode.addChild(new SyntaxTreeNode("RBRACE", "}"));
            advance(); // 跳过 '}'
        } else {
            System.out.println("Error: Expected '}' to close Block");
            // System.exit(currentTokenIndex);
        }

        return blockNode;
    }

    // 语句块项 BlockItem → Decl | Stmt
    private SyntaxTreeNode parseBlockItem() {
        SyntaxTreeNode blockItemNode = new SyntaxTreeNode("BlockItem");

        // 判断当前 Token 是否可能是声明 (Decl) 还是语句 (Stmt)
        if (getCurrentToken().getTokenType() == LexType.INTTK ||
                getCurrentToken().getTokenType() == LexType.CHARTK ||
                getCurrentToken().getTokenType() == LexType.CONSTTK) {
            // 如果当前 Token 是 'int'、'char' 或 'const'，认为这是一个声明 (Decl)
            blockItemNode.addChild(parseDecl());
        } else {
            // 否则认为是语句 (Stmt)，解析语句
            blockItemNode.addChild(parseStmt());
        }

        return blockItemNode;
    }

    // 解析语句 Stmt → LVal '=' Exp ';' | [Exp] ';' | Block | 'if' '(' Cond ')' Stmt [
    // 'else' Stmt ] | ...
    private SyntaxTreeNode parseStmt() {
        SyntaxTreeNode stmtNode = new SyntaxTreeNode("Stmt");
        boolean isLVal = false;
        // 处理可能的 LVal 赋值情况
        if (getCurrentToken().getTokenType() == LexType.IDENFR) {
            int savedTokenIndex = currentTokenIndex; // 保存当前位置
            SyntaxTreeNode possibleLValNode = parseLVal(); // 尝试解析 LVal

            // 检查下一个 Token 是否是赋值符号 '='
            if (getCurrentToken() != null && getCurrentToken().getTokenType() == LexType.ASSIGN) {
                // 如果是赋值符号，添加 LVal 节点到 stmtNode 并处理赋值语句
                isLVal = true;
                stmtNode.addChild(possibleLValNode);
                stmtNode.addChild(new SyntaxTreeNode("ASSIGN", "="));
                advance(); // 跳过 '='

                // 处理 `getint()` 或 `getchar()` 特殊情况
                if (getCurrentToken().getTokenType() == LexType.GETINTTK
                        || getCurrentToken().getTokenType() == LexType.GETCHARTK) {
                    stmtNode.addChild(new SyntaxTreeNode(getCurrentToken().getTokenType().toString(),
                            getCurrentToken().getValue()));
                    advance(); // 跳过 'getint' 或 'getchar'

                    // 匹配 '('
                    if (getCurrentToken().getTokenType() == LexType.LPARENT) {
                        stmtNode.addChild(new SyntaxTreeNode("LPARENT", "("));
                        advance(); // 跳过 '('
                    } else {
                        // 缺少左小括号，记录错误
                        recordError(getPreviousToken().getLineNumber(), "j");
                        return stmtNode;
                    }

                    // 匹配 ')'
                    if (getCurrentToken().getTokenType() == LexType.RPARENT) {
                        stmtNode.addChild(new SyntaxTreeNode("RPARENT", ")"));
                        advance(); // 跳过 ')'
                    } else {
                        // 缺少右小括号，记录错误 j
                        recordError(getPreviousToken().getLineNumber(), "j");
                    }

                } else {
                    // 解析 Exp
                    stmtNode.addChild(parseExp());
                }

                // 检查是否有分号 ';'
                if (getCurrentToken().getTokenType() == LexType.SEMICN) {
                    stmtNode.addChild(new SyntaxTreeNode("SEMICN", ";"));
                    advance(); // 跳过 ';'
                } else {
                    // 缺少分号，记录错误 i
                    recordError(getPreviousToken().getLineNumber(), "i");
                }

            } else {
                // 如果不是赋值语句，退回之前保存的位置，继续往后解析
                currentTokenIndex = savedTokenIndex;
            }
        }

        if (!isLVal) {
            // 如果是块语句
            if (getCurrentToken().getTokenType() == LexType.LBRACE) {
                stmtNode.addChild(parseBlock());

            } else if (getCurrentToken().getTokenType() == LexType.IFTK) {
                // 处理 if 语句
                stmtNode.addChild(new SyntaxTreeNode("IFTK", "if"));
                advance(); // 跳过 'if'

                // 匹配 '(' 和条件表达式
                if (getCurrentToken().getTokenType() == LexType.LPARENT) {
                    stmtNode.addChild(new SyntaxTreeNode("LPARENT", "("));
                    advance(); // 跳过 '('
                } else {
                    // 缺少左小括号，记录错误
                    recordError(getPreviousToken().getLineNumber(), "j");
                    return stmtNode;
                }

                stmtNode.addChild(parseCond());

                // 匹配 ')'
                if (getCurrentToken().getTokenType() == LexType.RPARENT) {
                    stmtNode.addChild(new SyntaxTreeNode("RPARENT", ")"));
                    advance(); // 跳过 ')'
                } else {
                    // 缺少右小括号，记录错误 j
                    recordError(getPreviousToken().getLineNumber(), "j");
                }

                // 解析 if 语句后的 Stmt
                stmtNode.addChild(parseStmt());

                // 处理可选的 else 分支
                if (getCurrentToken().getTokenType() == LexType.ELSETK) {
                    stmtNode.addChild(new SyntaxTreeNode("ELSETK", "else"));
                    advance(); // 跳过 'else'
                    stmtNode.addChild(parseStmt());
                }

            } else if (getCurrentToken().getTokenType() == LexType.FORTK) {
                // 处理 for 语句
                stmtNode.addChild(new SyntaxTreeNode("FORTK", "for"));
                advance(); // 跳过 'for'

                // 匹配 '('
                if (getCurrentToken().getTokenType() == LexType.LPARENT) {
                    stmtNode.addChild(new SyntaxTreeNode("LPARENT", "("));
                    advance(); // 跳过 '('
                } 

                // 处理可选的 ForStmt、Cond
                if (getCurrentToken().getTokenType() != LexType.SEMICN) {
                    stmtNode.addChild(parseForStmt());
                }

                // 匹配第一个 ';'
                if (getCurrentToken().getTokenType() == LexType.SEMICN) {
                    stmtNode.addChild(new SyntaxTreeNode("SEMICN", ";"));
                    advance(); // 跳过 ';'
                } 

                if (getCurrentToken().getTokenType() != LexType.SEMICN) {
                    stmtNode.addChild(parseCond());
                }

                // 匹配第二个 ';'
                if (getCurrentToken().getTokenType() == LexType.SEMICN) {
                    stmtNode.addChild(new SyntaxTreeNode("SEMICN", ";"));
                    advance(); // 跳过 ';'
                } 

                if (getCurrentToken().getTokenType() != LexType.RPARENT) {
                    stmtNode.addChild(parseForStmt());
                }

                // 匹配 ')'
                if (getCurrentToken().getTokenType() == LexType.RPARENT) {
                    stmtNode.addChild(new SyntaxTreeNode("RPARENT", ")"));
                    advance(); // 跳过 ')'
                } else {
                    // 缺少右小括号，记录错误 j
                    recordError(getPreviousToken().getLineNumber(), "j");
                }

                // 解析 for 语句后的 Stmt
                stmtNode.addChild(parseStmt());

            } else if (getCurrentToken().getTokenType() == LexType.BREAKTK
                    || getCurrentToken().getTokenType() == LexType.CONTINUETK) {
                // 处理 break 或 continue 语句
                stmtNode.addChild(
                        new SyntaxTreeNode(getCurrentToken().getTokenType().toString(), getCurrentToken().getValue()));
                advance();

                // 匹配 ';'
                if (getCurrentToken().getTokenType() == LexType.SEMICN) {
                    stmtNode.addChild(new SyntaxTreeNode("SEMICN", ";"));
                    advance(); // 跳过 ';'
                } else {
                    // 缺少分号，记录错误 i
                    recordError(getPreviousToken().getLineNumber(), "i");
                }

            } else if (getCurrentToken().getTokenType() == LexType.RETURNTK) {
                // 处理 return 语句
                stmtNode.addChild(new SyntaxTreeNode("RETURNTK", "return"));
                advance();

                // 可选的 Exp
                if (getCurrentToken().getTokenType() != LexType.SEMICN) {
                    stmtNode.addChild(parseExp());
                }

                // 匹配 ';'
                if (getCurrentToken().getTokenType() == LexType.SEMICN) {
                    stmtNode.addChild(new SyntaxTreeNode("SEMICN", ";"));
                    advance(); // 跳过 ';'
                } else {
                    // 缺少分号，记录错误 i
                    recordError(getPreviousToken().getLineNumber(), "i");
                }

            } else if (getCurrentToken().getTokenType() == LexType.PRINTFTK) {
                // 处理 printf 语句
                stmtNode.addChild(new SyntaxTreeNode("PRINTFTK", "printf"));
                advance();

                // 匹配 '('
                if (getCurrentToken().getTokenType() == LexType.LPARENT) {
                    stmtNode.addChild(new SyntaxTreeNode("LPARENT", "("));
                    advance(); // 跳过 '('
                } else {
                    // 缺少左小括号，记录错误
                    recordError(getPreviousToken().getLineNumber(), "j");
                    return stmtNode;
                }

                // 匹配 StringConst
                if (getCurrentToken().getTokenType() == LexType.STRCON) {
                    stmtNode.addChild(new SyntaxTreeNode("STRCON", getCurrentToken().getValue()));
                    advance(); // 跳过 StringConst
                }

                // 处理可选的 ',' Exp
                while (getCurrentToken().getTokenType() == LexType.COMMA) {
                    stmtNode.addChild(new SyntaxTreeNode("COMMA", ","));
                    advance(); // 跳过 ','
                    stmtNode.addChild(parseExp());
                }

                // 匹配 ')'
                if (getCurrentToken().getTokenType() == LexType.RPARENT) {
                    stmtNode.addChild(new SyntaxTreeNode("RPARENT", ")"));
                    advance(); // 跳过 ')'
                } else {
                    // 缺少右小括号，记录错误 j
                    recordError(getPreviousToken().getLineNumber(), "j");
                }

                // 匹配 ';'
                if (getCurrentToken().getTokenType() == LexType.SEMICN) {
                    stmtNode.addChild(new SyntaxTreeNode("SEMICN", ";"));
                    advance(); // 跳过 ';'
                } else {
                    // 缺少分号，记录错误 i
                    recordError(getPreviousToken().getLineNumber(), "i");
                }

            } else {
                // 处理 [Exp] ';' 的情况
                if (getCurrentToken().getTokenType() != LexType.SEMICN) {
                    stmtNode.addChild(parseExp());
                }

                // 匹配 ';'
                if (getCurrentToken().getTokenType() == LexType.SEMICN) {
                    stmtNode.addChild(new SyntaxTreeNode("SEMICN", ";"));
                    advance(); // 跳过 ';'
                } else {
                    // 缺少分号，记录错误 i
                    recordError(getPreviousToken().getLineNumber(), "i");
                }
            }

        }

        return stmtNode;
    }

    // 解析 ForStmt → LVal '=' Exp
    private SyntaxTreeNode parseForStmt() {
        SyntaxTreeNode forStmtNode = new SyntaxTreeNode("ForStmt");

        // 解析 LVal
        forStmtNode.addChild(parseLVal());

        // 匹配 '='
        if (getCurrentToken().getTokenType() == LexType.ASSIGN) {
            forStmtNode.addChild(new SyntaxTreeNode("ASSIGN", "="));
            advance(); // 跳过 '='
        } else {
            System.out.println("Error: Expected '=' in ForStmt");
            // System.exit(currentTokenIndex);
        }

        // 解析 Exp
        forStmtNode.addChild(parseExp());

        return forStmtNode;
    }

    // 解析表达式 Exp → AddExp
    private SyntaxTreeNode parseExp() {
        SyntaxTreeNode expNode = new SyntaxTreeNode("Exp");

        // 解析 AddExp
        expNode.addChild(parseAddExp());

        return expNode;
    }


    // 解析条件表达式 Cond → LOrExp
    private SyntaxTreeNode parseCond() {
        SyntaxTreeNode condNode = new SyntaxTreeNode("Cond");

        // 解析 LOrExp
        condNode.addChild(parseLOrExp());

        return condNode;
    }


    // 左值表达式 LVal → Ident ['[' Exp ']'] // k
    private SyntaxTreeNode parseLVal() {
        SyntaxTreeNode lValNode = new SyntaxTreeNode("LVal");

        // 匹配 Ident (标识符)
        if (getCurrentToken().getTokenType() == LexType.IDENFR) {
            lValNode.addChild(new SyntaxTreeNode("IDENFR", getCurrentToken().getValue()));
            advance(); // 跳过 Ident
        } else {
            System.out.println("Error: Expected Ident in LVal");
            // System.exit(currentTokenIndex);
        }

        // 可选的数组访问 '[' Exp ']'
        if (getCurrentToken().getTokenType() == LexType.LBRACK) {
            lValNode.addChild(new SyntaxTreeNode("LBRACK", "["));
            advance(); // 跳过 '['

            // 解析 Exp
            lValNode.addChild(parseExp());

            // 检查是否有右中括号 ']'
            if (getCurrentToken().getTokenType() == LexType.RBRACK) {
                lValNode.addChild(new SyntaxTreeNode("RBRACK", "]"));
                advance(); // 跳过 ']'
            } else {
                // 缺少右中括号，记录错误 (错误类型 k)，错误行号为 Exp 或 '[' 所在的行号
                recordError(getPreviousToken().getLineNumber(), "k");
            }
        }

        return lValNode;
    }


    // 基本表达式 PrimaryExp → '(' Exp ')' | LVal | Number | Character // j
    private SyntaxTreeNode parsePrimaryExp() {
        SyntaxTreeNode primaryExpNode = new SyntaxTreeNode("PrimaryExp");

        // 检查是否是括号表达式 '(' Exp ')'
        if (getCurrentToken().getValue().equals("(")) {
            primaryExpNode.addChild(new SyntaxTreeNode("LPARENT", "("));
            advance(); // 跳过 '('

            // 解析 Exp
            primaryExpNode.addChild(parseExp());

            // 检查是否有右小括号 ')'
            if (getCurrentToken().getValue().equals(")")) {
                primaryExpNode.addChild(new SyntaxTreeNode("RPARENT", ")"));
                advance(); // 跳过 ')'
            } else {
                // 缺少右小括号，记录错误 (错误类型 j)，错误行号为前一个非终结符行号
                recordError(getPreviousToken().getLineNumber(), "j");
            }

        } else if (isNumber()) {
            // 匹配数字 Number，调用 parseNumber()
            primaryExpNode.addChild(parseNumber());

        } else if (isCharacter()) {
            // 匹配字符 Character，调用 parseCharacter()
            primaryExpNode.addChild(parseCharacter());

        } else {
            // 匹配左值表达式 LVal
            primaryExpNode.addChild(parseLVal());
        }

        return primaryExpNode;
    }


    // 判断当前 Token 是否是数字 (Number)
    private boolean isNumber() {
        return getCurrentToken().getTokenType() == LexType.INTCON;
    }

    // 判断当前 Token 是否是字符 (Character)
    private boolean isCharacter() {
        return getCurrentToken().getTokenType() == LexType.CHRCON;
    }

    // 解析数值 Number → IntConst
    private SyntaxTreeNode parseNumber() {
        SyntaxTreeNode numberNode = new SyntaxTreeNode("Number");

        // 匹配 IntConst (整数常量)
        if (getCurrentToken().getTokenType() == LexType.INTCON) {
            numberNode.addChild(new SyntaxTreeNode("INTCON", getCurrentToken().getValue()));
            advance(); // 跳过 IntConst
        } else {
            System.out.println("Error: Expected IntConst in Number");
            // System.exit(currentTokenIndex);
        }

        return numberNode;
    }

    // 解析字符 Character → CharConst
    private SyntaxTreeNode parseCharacter() {
        SyntaxTreeNode characterNode = new SyntaxTreeNode("Character");

        // 匹配 CharConst (字符常量)
        if (getCurrentToken().getTokenType() == LexType.CHRCON) {
            characterNode.addChild(new SyntaxTreeNode("CHRCON", getCurrentToken().getValue()));
            advance(); // 跳过字符常量 CharConst
        } else {
            System.out.println("Error: Expected CharConst in Character");
            // System.exit(currentTokenIndex);
        }

        return characterNode;
    }

    // 一元表达式 UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp // j
    private SyntaxTreeNode parseUnaryExp() {
        SyntaxTreeNode unaryExpNode = new SyntaxTreeNode("UnaryExp");

        if (isPrimaryExp()) {
            // 解析 PrimaryExp
            unaryExpNode.addChild(parsePrimaryExp());

        } else if (getCurrentToken().getTokenType() == LexType.IDENFR) {
            // 匹配 Ident (函数调用)
            unaryExpNode.addChild(new SyntaxTreeNode("IDENFR", getCurrentToken().getValue()));
            advance(); // 跳过 Ident

            // 匹配左小括号 '('
            if (getCurrentToken().getValue().equals("(")) {
                unaryExpNode.addChild(new SyntaxTreeNode("LPARENT", "("));
                advance(); // 跳过 '('

                // 解析可选的函数实参表 [FuncRParams]
                if (!getCurrentToken().getValue().equals(")")) {
                    unaryExpNode.addChild(parseFuncRParams());
                }

                // 检查是否有右小括号 ')'
                if (getCurrentToken().getValue().equals(")")) {
                    unaryExpNode.addChild(new SyntaxTreeNode("RPARENT", ")"));
                    advance(); // 跳过 ')'
                } else {
                    // 缺少右小括号，记录错误 (错误类型 j)，错误行号为之前的非终结符行号
                    recordError(getPreviousToken().getLineNumber(), "j");
                }

            } else {
                System.out.println("Error: Expected '(' after function name in UnaryExp");
                // System.exit(currentTokenIndex);
            }

        } 
        else if (isUnaryOp()) {

            unaryExpNode.addChild(parseUnaryOp());
            advance(); // 跳过当前的一元运算符

            // 解析 UnaryExp
            unaryExpNode.addChild(parseUnaryExp());

        } else {
            System.out.println("Error: Expected PrimaryExp, function call, or UnaryOp in UnaryExp");
            // System.exit(currentTokenIndex);
        }
        // else{
        //     unaryExpNode.addChild(parseUnaryOp());
        //     advance(); // 跳过当前的一元运算符

        //     // 解析 UnaryExp
        //     unaryExpNode.addChild(parseUnaryExp());
        // }

        return unaryExpNode;
    }

    // 解析单目运算符 UnaryOp → '+' | '−' | '!'
    private SyntaxTreeNode parseUnaryOp() {
        SyntaxTreeNode unaryOpNode = new SyntaxTreeNode("UnaryOp");

        // 检查当前 Token 是否为一元运算符
        String unaryOp = getCurrentToken().getValue();

        // 根据当前的运算符构造相应的节点
        if (unaryOp.equals("+")) {
            unaryOpNode.addChild(new SyntaxTreeNode(LexType.PLUS.toString(), "+"));
//            unaryOpNode = new SyntaxTreeNode(LexType.PLUS.toString(), "+");
        } else if (unaryOp.equals("-")) {
            unaryOpNode.addChild(new SyntaxTreeNode(LexType.MINU.toString(), "-"));
//            unaryOpNode = new SyntaxTreeNode(LexType.MINU.toString(), "-");
        } else if (unaryOp.equals("!")) {
            unaryOpNode.addChild(new SyntaxTreeNode(LexType.NOT.toString(), "!"));
//            unaryOpNode = new SyntaxTreeNode(LexType.NOT.toString(), "!");
        } else {
            System.out.println("Error: Unexpected unary operator " + unaryOp);
            System.exit(currentTokenIndex);
        }

        return unaryOpNode;
    }

    // 判断当前的 Token 是否为 PrimaryExp
    private boolean isPrimaryExp() {
        // 如果当前 Token 是左小括号 '('，表示可能是带括号的表达式
        if (getCurrentToken().getTokenType() == LexType.LPARENT) {
            return true;
        }

        // 如果当前 Token 是标识符，表示可能是 LVal，但也可能是Ident '(' [FuncRParams] ')'，需要进一步判断
        //两个语法如下：
        // LVal → Ident ['[' Exp ']']
        // UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp // j
        // 如果当前 Token 是标识符，需要进一步判断是否是 LVal

        if (getCurrentToken().getTokenType() == LexType.IDENFR) {
            // 获取下一个 Token，判断是否是左小括号 '('，如果是则表示是函数调用，返回 false
            if (getNextKToken(1) != null && getNextKToken(1).getTokenType() == LexType.LPARENT) {
                return false;
            }
            // 否则，表示是 LVal，返回 true
            return true;
        }

        // 如果当前 Token 是整数常量，表示是 Number
        if (getCurrentToken().getTokenType() == LexType.INTCON) {
            return true;
        }

        //如果当前 Token 是字符常量，表示是 Character
        if (getCurrentToken().getTokenType() == LexType.CHRCON) {
            return true;
        }

        // 其他情况都不符合 PrimaryExp 的定义
        return false;
    }

    // 判断当前 Token 是否是单目运算符 UnaryOp
    private boolean isUnaryOp() {
        LexType tokenType = getCurrentToken().getTokenType();
        return tokenType == LexType.PLUS || tokenType == LexType.MINU || tokenType == LexType.NOT;
    }

    // 解析函数实参表 FuncRParams → Exp { ',' Exp }
    private SyntaxTreeNode parseFuncRParams() {
        SyntaxTreeNode funcRParamsNode = new SyntaxTreeNode("FuncRParams");

        // 解析第一个表达式 Exp
        funcRParamsNode.addChild(parseExp());

        // 处理多个以逗号 ',' 分隔的表达式 Exp
        while (getCurrentToken().getTokenType() == LexType.COMMA) {
            funcRParamsNode.addChild(new SyntaxTreeNode("COMMA", ",")); // 添加逗号节点
            advance(); // 跳过逗号
            funcRParamsNode.addChild(parseExp()); // 解析下一个 Exp
        }

        return funcRParamsNode;
    }

    //    // 解析乘除模表达式 MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
//    private SyntaxTreeNode parseMulExp() {
//        SyntaxTreeNode mulExpNode = new SyntaxTreeNode("MulExp");
//
//        // 解析第一个 UnaryExp
//        mulExpNode.addChild(parseUnaryExp());
//
//        // 处理乘除模运算符 ('*', '/', '%')
//        while (getCurrentToken().getTokenType() == LexType.MULT ||
//                getCurrentToken().getTokenType() == LexType.DIV ||
//                getCurrentToken().getTokenType() == LexType.MOD) {
//            // 添加运算符节点 ('*', '/', '%')
//            mulExpNode.addChild(new SyntaxTreeNode(getCurrentToken().getTokenType().toString(), getCurrentToken().getValue()));
//            advance(); // 跳过运算符
//
//            // 解析后续的 UnaryExp
//            mulExpNode.addChild(parseUnaryExp());
//        }
//
//        return mulExpNode;
//    }

// 解析乘除模表达式 MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
    private SyntaxTreeNode parseMulExp() {
        // 解析第一个 UnaryExp
        SyntaxTreeNode unaryExpNode = parseUnaryExp();
        if (unaryExpNode == null) {
            // 处理解析错误
            return null;
        }

        // 将第一个 UnaryExp 节点包装在一个新的 MulExp 节点中
        SyntaxTreeNode mulExpNode = new SyntaxTreeNode("MulExp");
        mulExpNode.addChild(unaryExpNode);

        // 循环处理乘除模运算符
        while (getCurrentToken().getTokenType() == LexType.MULT ||
                getCurrentToken().getTokenType() == LexType.DIV ||
                getCurrentToken().getTokenType() == LexType.MOD) {

            // 获取运算符
            LexType opType = getCurrentToken().getTokenType();
            String opValue = getCurrentToken().getValue();
            advance(); // 跳过运算符

            // 解析下一个 UnaryExp
            SyntaxTreeNode rightUnaryExpNode = parseUnaryExp();
            if (rightUnaryExpNode == null) {
                // 处理解析错误
                return null;
            }

            // 创建新的 MulExp 节点
            SyntaxTreeNode newMulExpNode = new SyntaxTreeNode("MulExp");
            // 将之前的 MulExp 节点作为左子节点
            newMulExpNode.addChild(mulExpNode);
            // 添加运算符节点
            newMulExpNode.addChild(new SyntaxTreeNode(opType.toString(), opValue));
            // 添加右侧的 UnaryExp 节点
            newMulExpNode.addChild(rightUnaryExpNode);

            // 更新 mulExpNode 为新的节点，以便处理可能的后续运算符
            mulExpNode = newMulExpNode;
        }

        return mulExpNode;
    }

//    // 解析加减表达式 AddExp → MulExp | AddExp ('+' | '−') MulExp
//    private SyntaxTreeNode parseAddExp() {
//        SyntaxTreeNode addExpNode = new SyntaxTreeNode("AddExp");
//
//        // 解析第一个 MulExp
//        addExpNode.addChild(parseMulExp());
//
//        // 处理加减运算符
//        while (getCurrentToken().getTokenType() == LexType.PLUS ||
//                getCurrentToken().getTokenType() == LexType.MINU) {
//            // 添加运算符节点 ('+' 或 '−')
//            if (getCurrentToken().getTokenType() == LexType.PLUS) {
//                addExpNode.addChild(new SyntaxTreeNode("PLUS", "+"));
//            } else if (getCurrentToken().getTokenType() == LexType.MINU) {
//                addExpNode.addChild(new SyntaxTreeNode("MINU", "−"));
//            }
//            advance(); // 跳过运算符
//
//            // 解析后续的 MulExp
//            addExpNode.addChild(parseMulExp());
//        }
//
//        return addExpNode;
//    }

    //    // 解析加减表达式 AddExp → MulExp | AddExp ('+' | '−') MulExp
//    private SyntaxTreeNode parseAddExp() {
//        // 首先解析第一个 MulExp
//        SyntaxTreeNode left = parseMulExp();
//
//        // 循环处理可能的加减运算符 ('+' 或 '−')
//        while (getCurrentToken().getTokenType() == LexType.PLUS ||
//                getCurrentToken().getTokenType() == LexType.MINU) {
//
//            // 获取当前运算符
//            LexType opType = getCurrentToken().getTokenType();
//            String opValue = getCurrentToken().getValue();
//            advance(); // 跳过运算符
//
//            // 解析下一个 MulExp
//            SyntaxTreeNode right = parseMulExp();
//
//            // 创建新的 AddExp 节点
//            SyntaxTreeNode newAddExpNode = new SyntaxTreeNode("AddExp");
//            // 将左操作数、运算符、右操作数添加为子节点
//            newAddExpNode.addChild(left); // 左子节点
//            newAddExpNode.addChild(new SyntaxTreeNode(opType.toString(), opValue)); // 运算符节点
//            newAddExpNode.addChild(right); // 右子节点
//
//            // 更新左操作数为新的 AddExp 节点
//            left = newAddExpNode;
//        }
//
//        // 返回最终的节点
//        return left;
//    }
// 解析加减表达式 AddExp → MulExp | AddExp ('+' | '−') MulExp
    private SyntaxTreeNode parseAddExp() {
        // 解析第一个 MulExp
        SyntaxTreeNode mulExpNode = parseMulExp();
        if (mulExpNode == null) {
            // 处理解析错误
            return null;
        }

        // 将第一个 MulExp 节点包装在一个新的 AddExp 节点中
        SyntaxTreeNode addExpNode = new SyntaxTreeNode("AddExp");
        addExpNode.addChild(mulExpNode);

        // 循环处理加减运算符
        while (getCurrentToken().getTokenType() == LexType.PLUS ||
                getCurrentToken().getTokenType() == LexType.MINU) {
            // 获取运算符
            LexType opType = getCurrentToken().getTokenType();
            String opValue = getCurrentToken().getValue();
            advance(); // 跳过运算符

            // 解析下一个 MulExp
            SyntaxTreeNode rightMulExpNode = parseMulExp();
            if (rightMulExpNode == null) {
                // 处理解析错误
                return null;
            }

            // 创建新的 AddExp 节点
            SyntaxTreeNode newAddExpNode = new SyntaxTreeNode("AddExp");
            // 将之前的 AddExp 节点作为左子节点
            newAddExpNode.addChild(addExpNode);
            // 添加运算符节点
            newAddExpNode.addChild(new SyntaxTreeNode(opType.toString(), opValue));
            // 添加右侧的 MulExp 节点
            newAddExpNode.addChild(rightMulExpNode);
            // 更新 addExpNode 为新的节点，以便处理可能的后续运算符
            addExpNode = newAddExpNode;
        }

        return addExpNode;
    }


//    // 解析关系表达式 RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
//    private SyntaxTreeNode parseRelExp() {
//        SyntaxTreeNode relExpNode = new SyntaxTreeNode("RelExp");
//
//        // 解析第一个 AddExp
//        relExpNode.addChild(parseAddExp());
//
//        // 处理关系运算符 ('<' | '>' | '<=' | '>=')
//        while (getCurrentToken().getTokenType() == LexType.LSS ||
//                getCurrentToken().getTokenType() == LexType.GRE ||
//                getCurrentToken().getTokenType() == LexType.LEQ ||
//                getCurrentToken().getTokenType() == LexType.GEQ) {
//            // 添加运算符节点 ('<' | '>' | '<=' | '>=')
//            relExpNode.addChild(new SyntaxTreeNode(getCurrentToken().getTokenType().toString(), getCurrentToken().getValue()));
//            advance(); // 跳过运算符
//
//            // 解析后续的 AddExp
//            relExpNode.addChild(parseAddExp());
//        }
//
//        return relExpNode;
//    }

    // 解析关系表达式 RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>='') AddExp
    private SyntaxTreeNode parseRelExp() {
        // 解析第一个 AddExp
        SyntaxTreeNode addExpNode = parseAddExp();
        if (addExpNode == null) {
            // 处理解析错误
            return null;
        }

        // 将第一个 AddExp 节点包装在一个新的 RelExp 节点中
        SyntaxTreeNode relExpNode = new SyntaxTreeNode("RelExp");
        relExpNode.addChild(addExpNode);

        // 循环处理关系运算符
        while (getCurrentToken().getTokenType() == LexType.LSS ||
                getCurrentToken().getTokenType() == LexType.GRE ||
                getCurrentToken().getTokenType() == LexType.LEQ ||
                getCurrentToken().getTokenType() == LexType.GEQ) {

            // 获取运算符
            LexType opType = getCurrentToken().getTokenType();
            String opValue = getCurrentToken().getValue();
            advance(); // 跳过运算符

            // 解析下一个 AddExp
            SyntaxTreeNode rightAddExpNode = parseAddExp();
            if (rightAddExpNode == null) {
                // 处理解析错误
                return null;
            }

            // 创建新的 RelExp 节点
            SyntaxTreeNode newRelExpNode = new SyntaxTreeNode("RelExp");
            // 将之前的 RelExp 节点作为左子节点
            newRelExpNode.addChild(relExpNode);
            // 添加运算符节点
            newRelExpNode.addChild(new SyntaxTreeNode(opType.toString(), opValue));
            // 添加右侧的 AddExp 节点
            newRelExpNode.addChild(rightAddExpNode);

            // 更新 relExpNode 为新的节点，以便处理可能的后续运算符
            relExpNode = newRelExpNode;
        }

        return relExpNode;
    }


//    // 解析相等性表达式 EqExp → RelExp | EqExp ('==' | '!=') RelExp
//    private SyntaxTreeNode parseEqExp() {
//        SyntaxTreeNode eqExpNode = new SyntaxTreeNode("EqExp");
//
//        // 解析第一个 RelExp
//        eqExpNode.addChild(parseRelExp());
//
//        // 处理相等性运算符 ('==' 或 '!=')
//        while (getCurrentToken().getTokenType() == LexType.EQL ||
//                getCurrentToken().getTokenType() == LexType.NEQ) {
//            // 添加运算符节点 ('==' 或 '!=')
//            if (getCurrentToken().getTokenType() == LexType.EQL) {
//                eqExpNode.addChild(new SyntaxTreeNode("EQL", "=="));
//            } else if (getCurrentToken().getTokenType() == LexType.NEQ) {
//                eqExpNode.addChild(new SyntaxTreeNode("NEQ", "!="));
//            }
//            advance(); // 跳过运算符
//
//            // 解析后续的 RelExp
//            eqExpNode.addChild(parseRelExp());
//        }
//
//        return eqExpNode;
//    }

    // 解析相等性表达式 EqExp → RelExp | EqExp ('==' | '!=') RelExp
    private SyntaxTreeNode parseEqExp() {
        // 解析第一个 RelExp
        SyntaxTreeNode relExpNode = parseRelExp();
        if (relExpNode == null) {
            // 处理解析错误
            return null;
        }

        // 将第一个 RelExp 节点包装在一个新的 EqExp 节点中
        SyntaxTreeNode eqExpNode = new SyntaxTreeNode("EqExp");
        eqExpNode.addChild(relExpNode);

        // 循环处理相等性运算符
        while (getCurrentToken().getTokenType() == LexType.EQL ||
                getCurrentToken().getTokenType() == LexType.NEQ) {

            // 获取运算符
            LexType opType = getCurrentToken().getTokenType();
            String opValue = getCurrentToken().getValue();
            advance(); // 跳过运算符

            // 解析下一个 RelExp
            SyntaxTreeNode rightRelExpNode = parseRelExp();
            if (rightRelExpNode == null) {
                // 处理解析错误
                return null;
            }

            // 创建新的 EqExp 节点
            SyntaxTreeNode newEqExpNode = new SyntaxTreeNode("EqExp");
            // 将之前的 EqExp 节点作为左子节点
            newEqExpNode.addChild(eqExpNode);
            // 添加运算符节点
            newEqExpNode.addChild(new SyntaxTreeNode(opType.toString(), opValue));
            // 添加右侧的 RelExp 节点
            newEqExpNode.addChild(rightRelExpNode);

            // 更新 eqExpNode 为新的节点，以便处理可能的后续运算符
            eqExpNode = newEqExpNode;
        }

        return eqExpNode;
    }

//    // 解析逻辑与表达式 LAndExp → EqExp | LAndExp '&&' EqExp
//    private SyntaxTreeNode parseLAndExp() {
//        SyntaxTreeNode lAndExpNode = new SyntaxTreeNode("LAndExp");
//
//        // 解析第一个 EqExp
//        lAndExpNode.addChild(parseEqExp());
//
//        // 处理逻辑与运算符 '&&'
//        while (getCurrentToken().getTokenType() == LexType.AND) {
//            // 添加运算符节点 '&&'
//            lAndExpNode.addChild(new SyntaxTreeNode("AND", "&&"));
//            advance(); // 跳过 '&&'
//
//            // 解析后续的 EqExp
//            lAndExpNode.addChild(parseEqExp());
//        }
//
//        return lAndExpNode;
//    }

    // 解析逻辑与表达式 LAndExp → EqExp | LAndExp '&&' EqExp
    private SyntaxTreeNode parseLAndExp() {
        // 解析第一个 EqExp
        SyntaxTreeNode eqExpNode = parseEqExp();
        if (eqExpNode == null) {
            // 处理解析错误
            return null;
        }

        // 将第一个 EqExp 节点包装在一个新的 LAndExp 节点中
        SyntaxTreeNode lAndExpNode = new SyntaxTreeNode("LAndExp");
        lAndExpNode.addChild(eqExpNode);

        // 循环处理逻辑与运算符
        while (getCurrentToken().getTokenType() == LexType.AND) {
            // 获取运算符
            LexType opType = getCurrentToken().getTokenType();
            String opValue = getCurrentToken().getValue();
            advance(); // 跳过 '&&'

            // 解析下一个 EqExp
            SyntaxTreeNode rightEqExpNode = parseEqExp();
            if (rightEqExpNode == null) {
                // 处理解析错误
                return null;
            }

            // 创建新的 LAndExp 节点
            SyntaxTreeNode newLAndExpNode = new SyntaxTreeNode("LAndExp");
            // 将之前的 LAndExp 节点作为左子节点
            newLAndExpNode.addChild(lAndExpNode);
            // 添加运算符节点
            newLAndExpNode.addChild(new SyntaxTreeNode(opType.toString(), opValue));
            // 添加右侧的 EqExp 节点
            newLAndExpNode.addChild(rightEqExpNode);

            // 更新 lAndExpNode 为新的节点，以便处理可能的后续运算符
            lAndExpNode = newLAndExpNode;
        }

        return lAndExpNode;
    }

//    // 解析逻辑或表达式 LOrExp → LAndExp | LOrExp '||' LAndExp
//    private SyntaxTreeNode parseLOrExp() {
//        SyntaxTreeNode lOrExpNode = new SyntaxTreeNode("LOrExp");
//
//        // 解析第一个 LAndExp
//        lOrExpNode.addChild(parseLAndExp());
//
//        // 处理逻辑或运算符 '||'
//        while (getCurrentToken().getTokenType() == LexType.OR) {
//            // 添加运算符节点 '||'
//            lOrExpNode.addChild(new SyntaxTreeNode("OR", "||"));
//            advance(); // 跳过 '||'
//
//            // 解析后续的 LAndExp
//            lOrExpNode.addChild(parseLAndExp());
//        }
//
//        return lOrExpNode;
//    }
// 解析逻辑或表达式 LOrExp → LAndExp | LOrExp '||' LAndExp

    private SyntaxTreeNode parseLOrExp() {
        // 解析第一个 LAndExp
        SyntaxTreeNode lAndExpNode = parseLAndExp();
        if (lAndExpNode == null) {
            // 处理解析错误
            return null;
        }

        // 将第一个 LAndExp 节点包装在一个新的 LOrExp 节点中
        SyntaxTreeNode lOrExpNode = new SyntaxTreeNode("LOrExp");
        lOrExpNode.addChild(lAndExpNode);

        // 循环处理逻辑或运算符 '||'
        while (getCurrentToken().getTokenType() == LexType.OR) {
            // 获取运算符
            LexType opType = getCurrentToken().getTokenType(); // 应该是 LexType.OR
            String opValue = getCurrentToken().getValue();
            advance(); // 跳过 '||'

            // 解析下一个 LAndExp
            SyntaxTreeNode rightLAndExpNode = parseLAndExp();
            if (rightLAndExpNode == null) {
                // 处理解析错误
                return null;
            }

            // 创建新的 LOrExp 节点
            SyntaxTreeNode newLOrExpNode = new SyntaxTreeNode("LOrExp");
            // 将之前的 LOrExp 节点作为左子节点
            newLOrExpNode.addChild(lOrExpNode);
            // 添加运算符节点
            newLOrExpNode.addChild(new SyntaxTreeNode(opType.toString(), opValue));
            // 添加右侧的 LAndExp 节点
            newLOrExpNode.addChild(rightLAndExpNode);

            // 更新 lOrExpNode 为新的节点，以便处理可能的后续运算符
            lOrExpNode = newLOrExpNode;
        }

        return lOrExpNode;
    }

    // 解析常量表达式 ConstExp → AddExp
    private SyntaxTreeNode parseConstExp() {
        SyntaxTreeNode constExpNode = new SyntaxTreeNode("ConstExp");

        // 解析 AddExp 并作为 ConstExp 的子节点
        constExpNode.addChild(parseAddExp());

        return constExpNode;
    }

}