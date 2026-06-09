import java.util.ArrayList;

class SyntaxAnalyzer {
    private ArrayList<Token> tokens;
    private int currentTokenIndex;
    private ArrayList<SyntaxError> errors;

    public SyntaxAnalyzer(ArrayList<Token> tokens, ArrayList<SyntaxError> errors) {
        this.tokens = tokens;
        this.currentTokenIndex = 0;
        this.errors = errors;
    }

    public SyntaxTreeNode parse() {
        return parseCompUnit();
    }

    public String getNextTokeType() {
        if (currentTokenIndex + 1 < tokens.size()) {
            return tokens.get(currentTokenIndex + 1).getType();
        }
        return null;
    }

    public String getNext2TokeType() {
        if (currentTokenIndex + 2 < tokens.size()) {
            return tokens.get(currentTokenIndex + 2).getType();
        }
        return null;
    }

    public void match(SyntaxTreeNode syntaxTreeNode, Token token) {
        syntaxTreeNode.addChild(new SyntaxTreeNode(SyntaxType.Token, token));
        currentTokenIndex++;
    }

    public SyntaxTreeNode parseCompUnit() {
        SyntaxTreeNode compUnitNode = new SyntaxTreeNode(SyntaxType.CompUnit, null);

        // 解析零个或多个 Decl
        while (currentTokenIndex < tokens.size()) {
            Token currentToken = tokens.get(currentTokenIndex);

            if (currentToken.getType().equals("CONSTTK")
                    || currentToken.getType().equals("INTTK") && !getNext2TokeType().equals("LPARENT")
                    || currentToken.getType().equals("CHARTK") && !getNext2TokeType().equals("LPARENT")) {
                compUnitNode.addChild(parseDecl());
            } else {
                break;
            }
        }

        // 解析零个或多个 FuncDef
        while (currentTokenIndex < tokens.size()) {
            Token currentToken = tokens.get(currentTokenIndex);

            if (currentToken.getType().equals("VOIDTK")
                    || currentToken.getType().equals("INTTK") && getNextTokeType().equals("IDENFR") && getNext2TokeType().equals("LPARENT")
                    || currentToken.getType().equals("CHARTK") && getNext2TokeType().equals("LPARENT")) {
                compUnitNode.addChild(parseFuncDef());
            } else {
                break;
            }
        }

        // 解析 MainFuncDef
        compUnitNode.addChild(parseMainFuncDef());

        return compUnitNode;
    }

    /**
     * 解析声明 Decl → ConstDecl | VarDecl
     */
    public SyntaxTreeNode parseDecl() {
        SyntaxTreeNode declNode = new SyntaxTreeNode(SyntaxType.Decl, null);
        Token currentToken = tokens.get(currentTokenIndex);

        // 判断当前 token 是否为 const 开头，即常量声明 ConstDecl
        if (currentToken.getType().equals("CONSTTK")) {
            declNode.addChild(parseConstDecl());
        }
        // 判断当前 token 是否为变量声明 VarDecl 的类型
        else {
            declNode.addChild(parseVarDecl());
        }

        return declNode;
    }

    /**
     * 解析常量声明 ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';'
     */
    public SyntaxTreeNode parseConstDecl() {
        SyntaxTreeNode constDeclNode = new SyntaxTreeNode(SyntaxType.ConstDecl, null); // 创建语法树节点

        // 匹配 'const' 关键字
        match(constDeclNode, tokens.get(currentTokenIndex));

        // 解析基本类型 BType (如 'int', 'char')
        constDeclNode.addChild(parseBType());

        // 解析第一个常量定义 ConstDef
        constDeclNode.addChild(parseConstDef());

        Token currentToken = tokens.get(currentTokenIndex);

        // 处理可能的多个常量定义 (用逗号 ',' 分隔)
        while (currentToken.getType().equals("COMMA")) {
            match(constDeclNode, tokens.get(currentTokenIndex));
            constDeclNode.addChild(parseConstDef());
            currentToken = tokens.get(currentTokenIndex);
        }

        // 匹配分号 ';'
        if (currentToken.getType().equals("SEMICN")) {
            match(constDeclNode, tokens.get(currentTokenIndex));
        } else {
            errors.add(new SyntaxError("i", tokens.get(currentTokenIndex - 1).getLine()));
        }

        return constDeclNode; // 返回完整的常量声明语法树节点
    }

    /**
     * 解析基本类型 BType → 'int' | 'char'
     */
    public SyntaxTreeNode parseBType() {
        SyntaxTreeNode bTypeNode = new SyntaxTreeNode(SyntaxType.BType, null); // 创建语法树节点
        Token currentToken = tokens.get(currentTokenIndex);
        // 检查当前的符号是否是 'int' 或 'char'
        match(bTypeNode, tokens.get(currentTokenIndex)); // 匹配当前符号

        return bTypeNode; // 返回基本类型的语法树节点
    }

    /**
     * 解析常量定义 ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal
     */
    public SyntaxTreeNode parseConstDef() {
        SyntaxTreeNode constDefNode = new SyntaxTreeNode(SyntaxType.ConstDef, null); // 创建语法树节点
        Token currentToken = tokens.get(currentTokenIndex);
        // 匹配标识符 Ident
        match(constDefNode, tokens.get(currentTokenIndex));

        currentToken = tokens.get(currentTokenIndex);
        // 可选部分：处理数组声明 '[' ConstExp ']' （如果存在的话）
        if (currentToken.getType().equals("LBRACK")) {
            match(constDefNode, tokens.get(currentTokenIndex)); // 消耗左方括号 '['
            constDefNode.addChild(parseConstExp()); // 解析数组维度表达式 ConstExp
            currentToken = tokens.get(currentTokenIndex);
            if (currentToken.getType().equals("RBRACK")) {
                match(constDefNode, tokens.get(currentTokenIndex)); // 消耗右方括号 ']'
            } else {
                errors.add(new SyntaxError("k", tokens.get(currentTokenIndex - 1).getLine()));
            }
        }

        // 匹配 '='
        match(constDefNode, tokens.get(currentTokenIndex));

        // 解析常量初值 ConstInitVal
        constDefNode.addChild(parseConstInitVal());

        return constDefNode; // 返回完整的常量定义语法树节点
    }

    public SyntaxTreeNode parseConstInitVal() {
        SyntaxTreeNode constInitValNode = new SyntaxTreeNode(SyntaxType.ConstInitVal, null); // 创建语法树节点

        Token currentToken = tokens.get(currentTokenIndex);

        // 处理第二种情况：'{' [ ConstExp { ',' ConstExp } ] '}'
        if (currentToken.getType().equals("LBRACE")) { // 检查是否为左花括号 '{'
            match(constInitValNode, tokens.get(currentTokenIndex)); // 匹配并消耗左花括号 '{'

            currentToken = tokens.get(currentTokenIndex); // 更新 currentToken

            // 可选部分：如果存在 ConstExp，进行解析
            if (!currentToken.getType().equals("RBRACE")) {
                constInitValNode.addChild(parseConstExp()); // 解析第一个 ConstExp
                currentToken = tokens.get(currentTokenIndex); // 更新 currentToken

                // 循环处理可选部分：逗号后续的 ConstExp
                while (currentToken.getType().equals("COMMA")) {
                    match(constInitValNode, tokens.get(currentTokenIndex)); // 匹配并消耗逗号
                    constInitValNode.addChild(parseConstExp()); // 解析下一个 ConstExp
                    currentToken = tokens.get(currentTokenIndex); // 更新 currentToken
                }
            }


            match(constInitValNode, tokens.get(currentTokenIndex));
            // 匹配右花括号 '}'

            return constInitValNode; // 返回常量初值节点
        }

        // 处理第三种情况：StringConst
        if (currentToken.getType().equals("STRCON")) {
            match(constInitValNode, tokens.get(currentTokenIndex)); // 匹配并消耗字符串常量
            return constInitValNode; // 返回常量初值节点
        }

        // 处理第一种情况：ConstExp
        constInitValNode.addChild(parseConstExp()); // 解析常量表达式 ConstExp
        return constInitValNode; // 直接返回

    }

    public SyntaxTreeNode parseVarDecl() {
        SyntaxTreeNode varDeclNode = new SyntaxTreeNode(SyntaxType.VarDecl, null); // 创建语法树节点

        // 匹配基本类型 BType
        varDeclNode.addChild(parseBType());

        // 解析第一个 VarDef
        varDeclNode.addChild(parseVarDef());

        Token currentToken = tokens.get(currentTokenIndex);

        // 处理多个 VarDef 的情况，通过逗号分隔
        while (currentToken.getType().equals("COMMA")) {
            match(varDeclNode, tokens.get(currentTokenIndex)); // 匹配并消耗逗号
            varDeclNode.addChild(parseVarDef()); // 解析下一个 VarDef
            currentToken = tokens.get(currentTokenIndex); // 更新 currentToken
        }

        // 匹配分号 ';'
        if (currentToken.getType().equals("SEMICN")) {
            match(varDeclNode, tokens.get(currentTokenIndex)); // 匹配并消耗分号
        } else {
            errors.add(new SyntaxError("i", tokens.get(currentTokenIndex - 1).getLine()));
        }

        return varDeclNode; // 返回完整的变量声明语法树节点
    }

    public SyntaxTreeNode parseVarDef() {
        SyntaxTreeNode varDefNode = new SyntaxTreeNode(SyntaxType.VarDef, null); // 创建语法树节点

        // 匹配标识符 Ident
        match(varDefNode, tokens.get(currentTokenIndex));

        Token currentToken = tokens.get(currentTokenIndex);

        // 可选部分：处理数组定义 '[' ConstExp ']' （如果存在）
        if (currentToken.getType().equals("LBRACK")) {
            match(varDefNode, tokens.get(currentTokenIndex)); // 匹配并消耗左方括号 '['
            varDefNode.addChild(parseConstExp()); // 解析数组维度表达式 ConstExp
            currentToken = tokens.get(currentTokenIndex); // 更新 currentToken
            if (currentToken.getType().equals("RBRACK")) {
                match(varDefNode, tokens.get(currentTokenIndex)); // 匹配并消耗右方括号 ']'
            } else {
                errors.add(new SyntaxError("k", tokens.get(currentTokenIndex - 1).getLine())); // 缺少右方括号错误
            }
        }

        currentToken = tokens.get(currentTokenIndex); // 更新 currentToken

        // 匹配 '=' 和初始化值 InitVal （如果存在）
        if (currentToken.getType().equals("ASSIGN")) { // 检查是否存在等号 '='
            match(varDefNode, tokens.get(currentTokenIndex)); // 匹配并消耗等号 '='
            varDefNode.addChild(parseInitVal()); // 解析初始化值 InitVal
        }

        return varDefNode; // 返回完整的变量定义语法树节点
    }

    public SyntaxTreeNode parseInitVal() {
        SyntaxTreeNode initValNode = new SyntaxTreeNode(SyntaxType.InitVal, null); // 创建语法树节点

        Token currentToken = tokens.get(currentTokenIndex); // 获取当前符号

        // 情况二：处理大括号 '{' [ Exp { ',' Exp } ] '}'
        if (currentToken.getType().equals("LBRACE")) { // 检查当前符号是否为左大括号 '{'
            match(initValNode, tokens.get(currentTokenIndex)); // 匹配并消耗左大括号 '{'
            currentToken = tokens.get(currentTokenIndex);

            if (!currentToken.getType().equals("RBRACE")) {
                initValNode.addChild(parseExp());
                currentToken = tokens.get(currentTokenIndex); // 更新 currentToken

                // 循环处理可选部分：逗号后续的 ConstExp
                while (currentToken.getType().equals("COMMA")) {
                    match(initValNode, tokens.get(currentTokenIndex)); // 匹配并消耗逗号
                    initValNode.addChild(parseExp()); // 解析表达式
                    currentToken = tokens.get(currentTokenIndex); // 更新 currentToken
                }
            }

            match(initValNode, tokens.get(currentTokenIndex)); // 匹配并消耗右大括号 '}'


            return initValNode; // 返回包含初始化列表的初始化值节点
        }

        // 情况三：处理字符串常量 StringConst
        if (currentToken.getType().equals("STRCON")) {
             // 解析字符串常量
            match(initValNode, tokens.get(currentTokenIndex));
            return initValNode; // 返回包含字符串常量的初始化值节点
        }

        // 情况一：处理表达式 Exp
        initValNode.addChild(parseExp()); // 解析表达式
        return initValNode; // 返回节点（可能为空）
    }

    public SyntaxTreeNode parseFuncDef() {
        SyntaxTreeNode funcDefNode = new SyntaxTreeNode(SyntaxType.FuncDef, null); // 创建语法树节点

        // 解析函数类型 FuncType
        funcDefNode.addChild(parseFuncType());

        // 匹配标识符 Ident
        match(funcDefNode, tokens.get(currentTokenIndex));

        // 匹配左括号 '('
        match(funcDefNode, tokens.get(currentTokenIndex));

        // 可选部分：解析函数形参表 FuncFParams
        Token currentToken = tokens.get(currentTokenIndex);
        if (!currentToken.getType().equals("RPARENT") && !currentToken.getType().equals("LBRACE")) { // 检查当前符号是否为函数形参
            funcDefNode.addChild(parseFuncFParams()); // 解析函数形参表
        }

        currentToken = tokens.get(currentTokenIndex);
        if (currentToken.getType().equals("RPARENT")) {
            match(funcDefNode, tokens.get(currentTokenIndex));
        } else {
            errors.add(new SyntaxError("j", tokens.get(currentTokenIndex - 1).getLine()));
        }

        // 解析语句块 Block
        funcDefNode.addChild(parseBlock());

        return funcDefNode; // 返回完整的函数定义语法树节点
    }

    public SyntaxTreeNode parseMainFuncDef() {
        SyntaxTreeNode mainFuncDefNode = new SyntaxTreeNode(SyntaxType.MainFuncDef, null); // 创建语法树节点

        // 匹配 'int'
        match(mainFuncDefNode, tokens.get(currentTokenIndex));

        // 匹配 'main'
        match(mainFuncDefNode, tokens.get(currentTokenIndex));

        // 匹配左括号 '('
        match(mainFuncDefNode, tokens.get(currentTokenIndex));

        // 匹配右括号 ')'
        Token currentToken = tokens.get(currentTokenIndex);
        if (currentToken.getType().equals("RPARENT")) {
            match(mainFuncDefNode, tokens.get(currentTokenIndex));
        } else {
            errors.add(new SyntaxError("j", tokens.get(currentTokenIndex - 1).getLine()));
        }

        // 解析语句块 Block
        mainFuncDefNode.addChild(parseBlock());

        return mainFuncDefNode; // 返回完整的主函数定义语法树节点
    }

    public SyntaxTreeNode parseFuncType() {
        SyntaxTreeNode funcTypeNode = new SyntaxTreeNode(SyntaxType.FuncType, null); // 创建语法树节点

        // 判断并匹配函数类型
        match(funcTypeNode, tokens.get(currentTokenIndex));

        return funcTypeNode; // 返回完整的函数类型语法树节点
    }

    public SyntaxTreeNode parseFuncFParams() {
        SyntaxTreeNode funcFParamsNode = new SyntaxTreeNode(SyntaxType.FuncFParams, null); // 创建语法树节点

        // 解析第一个函数形参 FuncFParam
        funcFParamsNode.addChild(parseFuncFParam());

        Token currentToken = tokens.get(currentTokenIndex);

        // 使用当前标记检查是否有更多的函数形参
        while (currentToken.getType().equals("COMMA")) {
            match(funcFParamsNode, tokens.get(currentTokenIndex)); // 匹配并消耗 ','
            funcFParamsNode.addChild(parseFuncFParam()); // 解析下一个函数形参
            currentToken = tokens.get(currentTokenIndex);
        }

        return funcFParamsNode; // 返回完整的函数形参表语法树节点
    }

    public SyntaxTreeNode parseFuncFParam() {
        SyntaxTreeNode funcFParamNode = new SyntaxTreeNode(SyntaxType.FuncFParam, null); // 创建语法树节点

        // 解析基本类型 BType
        funcFParamNode.addChild(parseBType());

        // 匹配标识符 Ident
        match(funcFParamNode, tokens.get(currentTokenIndex));

        // 可选部分：处理数组声明 '[' ']'
        Token currentToken = tokens.get(currentTokenIndex);
        if (currentToken.getType().equals("LBRACK")) {
            match(funcFParamNode, tokens.get(currentTokenIndex)); // 消耗左方括号 '['
            currentToken = tokens.get(currentTokenIndex);
            if (currentToken.getType().equals("RBRACK")) {
                match(funcFParamNode, tokens.get(currentTokenIndex)); // 匹配并消耗右方括号 ']'
            } else {
                errors.add(new SyntaxError("k", tokens.get(currentTokenIndex - 1).getLine())); // 缺少右方括号错误
            }
        }

        return funcFParamNode; // 返回完整的函数形参语法树节点
    }

    public SyntaxTreeNode parseBlock() {
        SyntaxTreeNode blockNode = new SyntaxTreeNode(SyntaxType.Block, null); // 创建语法树节点

        // 匹配 '{'
        match(blockNode, tokens.get(currentTokenIndex)); // 消耗左大括号 '{'

        // 解析零个或多个 BlockItem
        while (true) {
            // 检查当前标记是否为 '}'
            Token currentToken = tokens.get(currentTokenIndex);
            if (currentToken.getType().equals("RBRACE")) {
                break; // 如果是右大括号 '}'，退出循环
            }

            // 解析语句块项 BlockItem
            blockNode.addChild(parseBlockItem());
        }

        // 匹配 '}'
        match(blockNode, tokens.get(currentTokenIndex)); // 消耗右大括号 '}'

        return blockNode; // 返回完整的语句块语法树节点
    }

    public SyntaxTreeNode parseBlockItem() {
        SyntaxTreeNode blockItemNode = new SyntaxTreeNode(SyntaxType.BlockItem, null); // 创建语法树节点
        Token currentToken = tokens.get(currentTokenIndex);

        // 判断当前标记的类型以确定是声明还是语句
        if (currentToken.getType().equals("CONSTTK")
                || currentToken.getType().equals("INTTK")
                || currentToken.getType().equals("CHARTK")) {
            // 当前标记是常量声明或变量声明的类型，解析声明
            blockItemNode.addChild(parseDecl());
        } else {
            // 否则，解析语句
            blockItemNode.addChild(parseStmt());
        }
        return blockItemNode;
    }

    public SyntaxTreeNode parseStmt() {
        Token currentToken = tokens.get(currentTokenIndex);
        SyntaxTreeNode stmtNode = new SyntaxTreeNode(SyntaxType.Stmt, null); // 创建语法树节点

        // 判断当前标记类型以确定语句的类型
        if (currentToken.getType().equals("IDENFR")) {
            // 处理赋值语句 LVal '=' Exp ';'
            int i = currentTokenIndex;
            SyntaxTreeNode lvalNode = parseLVal();
            currentToken = tokens.get(currentTokenIndex);
            if (currentToken.getType().equals("ASSIGN")) {

                stmtNode.addChild(lvalNode);
                match(stmtNode, tokens.get(currentTokenIndex)); // 匹配 '='
                currentToken = tokens.get(currentTokenIndex);
                if (currentToken.getType().equals("GETINTTK")
                || currentToken.getType().equals("GETCHARTK") ) {
                    match(stmtNode, tokens.get(currentTokenIndex));
                    match(stmtNode, tokens.get(currentTokenIndex));
                    currentToken = tokens.get(currentTokenIndex);
                    if (currentToken.getType().equals("RPARENT")) {
                        match(stmtNode, tokens.get(currentTokenIndex));
                    } else {
                        errors.add(new SyntaxError("j", tokens.get(currentTokenIndex - 1).getLine()));
                    }
                    currentToken = tokens.get(currentTokenIndex);
                    if (currentToken.getType().equals("SEMICN")) {
                        match(stmtNode, tokens.get(currentTokenIndex));
                    } else {
                        errors.add(new SyntaxError("i", tokens.get(currentTokenIndex - 1).getLine()));
                    }
                } else {
                    stmtNode.addChild(parseExp()); // 解析表达式
                    currentToken = tokens.get(currentTokenIndex);
                    if (currentToken.getType().equals("SEMICN")) {
                        match(stmtNode, tokens.get(currentTokenIndex));
                    } else {
                        errors.add(new SyntaxError("i", tokens.get(currentTokenIndex - 1).getLine()));
                    }
                }

            } else {
                currentTokenIndex = i;
                stmtNode.addChild(parseExp());
                currentToken = tokens.get(currentTokenIndex);
                if (currentToken.getType().equals("SEMICN")) {
                    match(stmtNode, tokens.get(currentTokenIndex));
                } else {
                    errors.add(new SyntaxError("i", tokens.get(currentTokenIndex - 1).getLine()));
                }
            }
        } else if (currentToken.getType().equals("LBRACE")) {
            // 可能是 Block
            stmtNode.addChild(parseBlock());
        } else if (currentToken.getType().equals("IFTK")) {
            // 处理 if 语句
            match(stmtNode, tokens.get(currentTokenIndex));
            match(stmtNode, tokens.get(currentTokenIndex)); // 匹配 '('
            stmtNode.addChild(parseCond()); // 解析条件
            currentToken = tokens.get(currentTokenIndex);
            if (currentToken.getType().equals("RPARENT")) {
                match(stmtNode, tokens.get(currentTokenIndex));
            } else {
                errors.add(new SyntaxError("j", tokens.get(currentTokenIndex - 1).getLine()));
            }// 匹配 ')'
            stmtNode.addChild(parseStmt()); // 解析 if 语句体

            // 可选的 else 语句
            currentToken = tokens.get(currentTokenIndex);
            if (currentToken.getType().equals("ELSETK")) {
                match(stmtNode, tokens.get(currentTokenIndex)); // 匹配 'else'
                stmtNode.addChild(parseStmt()); // 解析 else 语句体
            }
        } else if (currentToken.getType().equals("FORTK")) {
            // 处理 for 循环
            match(stmtNode, tokens.get(currentTokenIndex)); // 匹配 'for'
            match(stmtNode, tokens.get(currentTokenIndex)); // 匹配 '('
            if (!tokens.get(currentTokenIndex).getType().equals("SEMICN")) {
                stmtNode.addChild(parseForStmt()); // 解析 ForStmt
            }
            match(stmtNode, tokens.get(currentTokenIndex)); // 匹配 ';'
            if (!tokens.get(currentTokenIndex).getType().equals("SEMICN")) {
                stmtNode.addChild(parseCond()); // 解析条件
            }
            match(stmtNode, tokens.get(currentTokenIndex)); // 匹配 ';'
            if (!tokens.get(currentTokenIndex).getType().equals("RPARENT")) {
                stmtNode.addChild(parseForStmt()); // 解析 ForStmt
            }
            match(stmtNode, tokens.get(currentTokenIndex)); // 匹配 ')'
            stmtNode.addChild(parseStmt()); // 解析循环体
        } else if (currentToken.getType().equals("BREAKTK")) {
            match(stmtNode, tokens.get(currentTokenIndex)); // 匹配 'break'
            currentToken = tokens.get(currentTokenIndex);
            if (currentToken.getType().equals("SEMICN")) {
                match(stmtNode, tokens.get(currentTokenIndex));
            } else {
                errors.add(new SyntaxError("i", tokens.get(currentTokenIndex - 1).getLine()));
            } // 匹配 ';'
        } else if (currentToken.getType().equals("CONTINUETK")) {
            match(stmtNode, tokens.get(currentTokenIndex)); // 匹配 'break'
            currentToken = tokens.get(currentTokenIndex);
            if (currentToken.getType().equals("SEMICN")) {
                match(stmtNode, tokens.get(currentTokenIndex));
            } else {
                errors.add(new SyntaxError("i", tokens.get(currentTokenIndex - 1).getLine()));
            } //  匹配 ';'
        } else if (currentToken.getType().equals("RETURNTK")) {
            match(stmtNode, tokens.get(currentTokenIndex)); // 匹配 'return'
            currentToken = tokens.get(currentTokenIndex);
            if (currentToken.getType().equals("IDENFR")
                    || currentToken.getType().equals("PLUS")
                    || currentToken.getType().equals("MINU")
                    || currentToken.getType().equals("LPARENT")
                    || currentToken.getType().equals("INTCON")
                    || currentToken.getType().equals("CHRCON")
                    || currentToken.getType().equals("NOT")) {
                stmtNode.addChild(parseExp()); // 可选的返回表达式
            }
            currentToken = tokens.get(currentTokenIndex);
            if (currentToken.getType().equals("SEMICN")) {
                match(stmtNode, tokens.get(currentTokenIndex));
            } else {
                errors.add(new SyntaxError("i", tokens.get(currentTokenIndex - 1).getLine()));
            } // 匹配 ';'
        } else if (currentToken.getType().equals("PRINTFTK")){
            // 处理 printf 语句
            match(stmtNode, tokens.get(currentTokenIndex)); // 匹配 'printf'
            match(stmtNode, tokens.get(currentTokenIndex)); // 匹配 '('
            match(stmtNode, tokens.get(currentTokenIndex)); // 匹配字符串常量
            while (tokens.get(currentTokenIndex).getType().equals("COMMA")) {
                match(stmtNode, tokens.get(currentTokenIndex)); // 匹配 ','
                stmtNode.addChild(parseExp()); // 解析表达式
            }
            currentToken = tokens.get(currentTokenIndex);
            if (currentToken.getType().equals("RPARENT")) {
                match(stmtNode, tokens.get(currentTokenIndex));
            } else {
                errors.add(new SyntaxError("j", tokens.get(currentTokenIndex - 1).getLine()));
            }
            currentToken = tokens.get(currentTokenIndex);
            if (currentToken.getType().equals("SEMICN")) {
                match(stmtNode, tokens.get(currentTokenIndex));
            } else {
                errors.add(new SyntaxError("i", tokens.get(currentTokenIndex - 1).getLine()));
            }
        } else { // exp情况
            currentToken = tokens.get(currentTokenIndex);
            if (!currentToken.getType().equals("SEMICN")) {
                stmtNode.addChild(parseExp());
            }
            currentToken = tokens.get(currentTokenIndex);
            if (currentToken.getType().equals("SEMICN")) {
                match(stmtNode, tokens.get(currentTokenIndex));
            } else {
                errors.add(new SyntaxError("i", tokens.get(currentTokenIndex - 1).getLine()));
            }
        }

        return stmtNode; // 返回完整的语句语法树节点
    }

    public SyntaxTreeNode parseForStmt() {
        SyntaxTreeNode forStmtNode = new SyntaxTreeNode(SyntaxType.ForStmt, null); // 创建语法树节点
        Token currentToken = tokens.get(currentTokenIndex);

        // 解析左值 LVal
        forStmtNode.addChild(parseLVal());

        // 匹配 '='
        match(forStmtNode, tokens.get(currentTokenIndex));

        // 解析表达式 Exp
        forStmtNode.addChild(parseExp());

        return forStmtNode; // 返回完整的 ForStmt 语法树节点
    }

    public SyntaxTreeNode parseExp() {
        // 创建 Exp 的语法树节点
        SyntaxTreeNode expNode = new SyntaxTreeNode(SyntaxType.Exp, null);

        // 解析加减表达式 AddExp，并将其作为 Exp 的子节点
        expNode.addChild(parseAddExp());

        // 返回完整的 Exp 语法树节点
        return expNode;
    }

    public SyntaxTreeNode parseCond() {
        // 创建 Cond 的语法树节点
        SyntaxTreeNode condNode = new SyntaxTreeNode(SyntaxType.Cond, null);

        // 解析逻辑或表达式 LOrExp，并将其作为 Cond 的子节点
        condNode.addChild(parseLOrExp());

        // 返回完整的 Cond 语法树节点
        return condNode;
    }

    public SyntaxTreeNode parseLVal() {
        // 创建 LVal 的语法树节点
        SyntaxTreeNode lValNode = new SyntaxTreeNode(SyntaxType.LVal, null);

        // 解析标识符 Ident，并将其作为 LVal 的子节点
        match(lValNode, tokens.get(currentTokenIndex));

        // 检查是否有 '[' 符号（处理数组的可选部分）
        if (tokens.get(currentTokenIndex).getType().equals("LBRACK")) {
            match(lValNode, tokens.get(currentTokenIndex)); // 匹配 '['

            // 解析表达式 Exp
            lValNode.addChild(parseExp());

            // 匹配 ']'
            if (tokens.get(currentTokenIndex).getType().equals("RBRACK")) {
                match(lValNode, tokens.get(currentTokenIndex)); // 匹配 ']'
            } else {
                errors.add(new SyntaxError("k", tokens.get(currentTokenIndex - 1).getLine()));
            }
        }

        // 返回完整的 LVal 语法树节点
        return lValNode;
    }

    public SyntaxTreeNode parsePrimaryExp() {
        // 创建 PrimaryExp 的语法树节点
        SyntaxTreeNode primaryExpNode = new SyntaxTreeNode(SyntaxType.PrimaryExp, null);
        Token currentToken = tokens.get(currentTokenIndex);

        // 判断当前符号
        if (currentToken.getType().equals("LPARENT")) {
            // 匹配 '('
            match(primaryExpNode, tokens.get(currentTokenIndex));

            // 解析表达式 Exp
            primaryExpNode.addChild(parseExp());

            // 匹配 ')'
            if (tokens.get(currentTokenIndex).getType().equals("RPARENT")) {
                match(primaryExpNode, tokens.get(currentTokenIndex));
            } else {
                errors.add(new SyntaxError("j", tokens.get(currentTokenIndex - 1).getLine()));
            }
        } else if (currentToken.getType().equals("IDENFR")) {
            // 匹配左值表达式 LVal
            primaryExpNode.addChild(parseLVal());
        } else if (currentToken.getType().equals("INTCON")) {
            // 匹配数值或字符常量 Number 或 Character
            primaryExpNode.addChild(parseNumber());
        } else {
            // 如果没有匹配到任何合法的 PrimaryExp，记录错误
            primaryExpNode.addChild(parseCharacter());
        }

        // 返回完整的 PrimaryExp 语法树节点
        return primaryExpNode;
    }

    public SyntaxTreeNode parseNumber() {
        // 创建 Number 的语法树节点
        SyntaxTreeNode numberNode = new SyntaxTreeNode(SyntaxType.Number, null);
        match(numberNode, tokens.get(currentTokenIndex));

        // 返回完整的 Number 语法树节点
        return numberNode;
    }

    public SyntaxTreeNode parseCharacter() {
        // 创建 Character 的语法树节点
        SyntaxTreeNode characterNode = new SyntaxTreeNode(SyntaxType.Character, null);
        match(characterNode, tokens.get(currentTokenIndex));
        // 返回完整的 Character 语法树节点
        return characterNode;
    }

    public SyntaxTreeNode parseUnaryExp() {
        SyntaxTreeNode unaryExpNode = new SyntaxTreeNode(SyntaxType.UnaryExp, null);
        Token currentToken = tokens.get(currentTokenIndex);

        // 检查当前符号是否是单目运算符 UnaryOp
        if (currentToken.getType().equals("PLUS")
            || currentToken.getType().equals("MINU")
            || currentToken.getType().equals("NOT")) {
            // 创建 UnaryOp 节点并添加到一元表达式节点
            unaryExpNode.addChild(parseUnaryOp());

            unaryExpNode.addChild(parseUnaryExp());
        } else if (currentToken.getType().equals("IDENFR")
                    && getNextTokeType().equals("LPARENT")) {
            // 解析标识符 Ident
            match(unaryExpNode, tokens.get(currentTokenIndex));

            // 检查是否为函数调用

            match(unaryExpNode, tokens.get(currentTokenIndex)); // 消耗左括号 '('

            // 可选部分：解析函数实参表 FuncRParams
            if (!tokens.get(currentTokenIndex).getType().equals("RPARENT")
                && !tokens.get(currentTokenIndex).getType().equals("SEMICN")) {
                unaryExpNode.addChild(parseFuncRParams());
            }

            if (tokens.get(currentTokenIndex).getType().equals("RPARENT")) {
                match(unaryExpNode, tokens.get(currentTokenIndex));
            } else {
                errors.add(new SyntaxError("j", tokens.get(currentTokenIndex - 1).getLine()));
            } // 消耗右括号 ')'

        } else {
            // 解析基本表达式 PrimaryExp
            unaryExpNode.addChild(parsePrimaryExp());
        }

        return unaryExpNode; // 返回完整的一元表达式语法树节点
    }

    public SyntaxTreeNode parseUnaryOp() {
        SyntaxTreeNode unaryOpNode = new SyntaxTreeNode(SyntaxType.UnaryOp, null);
        match(unaryOpNode, tokens.get(currentTokenIndex));

        return unaryOpNode; // 返回单目运算符语法树节点
    }

    public SyntaxTreeNode parseFuncRParams() {
        SyntaxTreeNode funcRParamsNode = new SyntaxTreeNode(SyntaxType.FuncRParams, null); // 创建语法树节点

        // 解析第一个表达式 Exp
        funcRParamsNode.addChild(parseExp()); // 解析 Exp 并将其添加到节点中

        // 解析后续的 ',' Exp 部分（如果存在多个实参）
        while (tokens.get(currentTokenIndex).getType().equals("COMMA")) {
            match(funcRParamsNode, tokens.get(currentTokenIndex)); // 匹配逗号 ','
            funcRParamsNode.addChild(parseExp()); // 解析下一个表达式 Exp 并将其添加到节点中
        }

        return funcRParamsNode; // 返回完整的函数实参表语法树节点
    }

    public SyntaxTreeNode parseMulExp() {
        SyntaxTreeNode mulExpNode = new SyntaxTreeNode(SyntaxType.MulExp, null); // 创建语法树节点

        // 先解析第一个一元表达式 UnaryExp
        mulExpNode.addChild(parseUnaryExp()); // 解析 UnaryExp 并添加到节点中
        Token currentToken = tokens.get(currentTokenIndex);

        // 处理可选的乘除模运算符
        while (currentToken.getType().equals("MULT") ||
                currentToken.getType().equals("DIV") ||
                currentToken.getType().equals("MOD")) {

            match(mulExpNode, tokens.get(currentTokenIndex));
            mulExpNode.addChild(parseUnaryExp());
            currentToken = tokens.get(currentTokenIndex);
        }

        return mulExpNode; // 返回完整的乘除模表达式语法树节点
    }

    public SyntaxTreeNode parseAddExp() {
        SyntaxTreeNode addExpNode = new SyntaxTreeNode(SyntaxType.AddExp, null); // 创建语法树节点

        // 先解析第一个乘除模表达式 MulExp
        addExpNode.addChild(parseMulExp()); // 解析 MulExp 并添加到节点中
        Token currentToken = tokens.get(currentTokenIndex);

        // 处理可选的加减运算符
        while (currentToken.getType().equals("PLUS") ||
                currentToken.getType().equals("MINU")) {
            match(addExpNode, tokens.get(currentTokenIndex));
            addExpNode.addChild(parseMulExp());
            currentToken = tokens.get(currentTokenIndex);
        }

        return addExpNode; // 返回完整的加减表达式语法树节点
    }

    public SyntaxTreeNode parseRelExp() {
        SyntaxTreeNode relExpNode = new SyntaxTreeNode(SyntaxType.RelExp, null); // 创建语法树节点

        // 先解析第一个加减表达式 AddExp
        relExpNode.addChild(parseAddExp()); // 解析 AddExp 并添加到节点中

        // 获取当前 token
        Token currentToken = tokens.get(currentTokenIndex);

        // 处理可选的关系运算符
        while (currentToken.getType().equals("LSS") ||   // '<'
                currentToken.getType().equals("GRE") ||   // '>'
                currentToken.getType().equals("LEQ") ||   // '<='
                currentToken.getType().equals("GEQ")) {   // '>='

            // 匹配关系运算符并将其添加为子节点
            match(relExpNode, currentToken); // 消耗当前运算符
            relExpNode.addChild(parseAddExp()); // 解析下一个 AddExp 并添加到语法树中

            // 更新 currentToken，获取下一个 token
            currentToken = tokens.get(currentTokenIndex);
        }

        return relExpNode; // 返回完整的关系表达式语法树节点
    }

    public SyntaxTreeNode parseEqExp() {
        SyntaxTreeNode eqExpNode = new SyntaxTreeNode(SyntaxType.EqExp, null); // 创建语法树节点

        // 先解析第一个关系表达式 RelExp
        eqExpNode.addChild(parseRelExp()); // 解析 RelExp 并添加到节点中

        // 获取当前 token
        Token currentToken = tokens.get(currentTokenIndex);

        // 处理可选的相等性运算符
        while (currentToken.getType().equals("EQL") ||   // '=='
                currentToken.getType().equals("NEQ")) {  // '!='

            // 匹配相等性运算符并将其添加为子节点
            match(eqExpNode, currentToken); // 消耗当前运算符
            eqExpNode.addChild(parseRelExp()); // 解析下一个 RelExp 并添加到语法树中

            // 更新 currentToken，获取下一个 token
            currentToken = tokens.get(currentTokenIndex);
        }

        return eqExpNode; // 返回完整的相等性表达式语法树节点
    }

    public SyntaxTreeNode parseLAndExp() {
        SyntaxTreeNode lAndExpNode = new SyntaxTreeNode(SyntaxType.LAndExp, null); // 创建语法树节点

        // 先解析第一个相等性表达式 EqExp
        lAndExpNode.addChild(parseEqExp()); // 解析 EqExp 并添加到节点中

        // 获取当前 token
        Token currentToken = tokens.get(currentTokenIndex);

        // 处理可选的逻辑与运算符
        while (currentToken.getType().equals("AND")) { // '&&'
            // 匹配逻辑与运算符并将其添加为子节点
            match(lAndExpNode, currentToken); // 消耗当前运算符
            lAndExpNode.addChild(parseEqExp()); // 解析下一个 EqExp 并添加到语法树中

            // 更新 currentToken，获取下一个 token
            currentToken = tokens.get(currentTokenIndex);
        }

        return lAndExpNode; // 返回完整的逻辑与表达式语法树节点
    }

    public SyntaxTreeNode parseLOrExp() {
        SyntaxTreeNode lOrExpNode = new SyntaxTreeNode(SyntaxType.LOrExp, null); // 创建语法树节点

        // 先解析第一个逻辑与表达式 LAndExp
        lOrExpNode.addChild(parseLAndExp()); // 解析 LAndExp 并添加到节点中

        // 获取当前 token
        Token currentToken = tokens.get(currentTokenIndex);

        // 处理可选的逻辑或运算符
        while (currentToken.getType().equals("OR")) { // '||'
            // 匹配逻辑或运算符并将其添加为子节点
            match(lOrExpNode, currentToken); // 消耗当前运算符
            lOrExpNode.addChild(parseLAndExp()); // 解析下一个 LAndExp 并添加到语法树中

            // 更新 currentToken，获取下一个 token
            currentToken = tokens.get(currentTokenIndex);
        }

        return lOrExpNode; // 返回完整的逻辑或表达式语法树节点
    }

    public SyntaxTreeNode parseConstExp() {
        SyntaxTreeNode constExpNode = new SyntaxTreeNode(SyntaxType.ConstExp, null); // 创建语法树节点

        // 直接解析加法表达式 AddExp
        constExpNode.addChild(parseAddExp()); // 解析 AddExp 并添加到节点中

        return constExpNode; // 返回完整的常量表达式语法树节点
    }

    // 其他解析方法类似，根据具体的语法规则递归地生成语法树节点
}
