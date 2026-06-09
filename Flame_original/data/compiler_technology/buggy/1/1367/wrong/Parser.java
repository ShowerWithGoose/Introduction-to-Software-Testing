
import java.util.ArrayList;

public class Parser {
    private ArrayList<Token> tokens;
    private int currentTokenIndex = 0;
    private ArrayList<ErrorToken> errorTokens;

    public Parser(ArrayList<Token> tokens, ArrayList<ErrorToken> errorTokens) {
        this.tokens = tokens;
        this.errorTokens = errorTokens;
    }

    private Token currentToken() {
        if (currentTokenIndex < tokens.size()) {
            return tokens.get(currentTokenIndex);
        }
        return null;
    }

    private void nextToken() {
        if (currentTokenIndex < tokens.size()) {
            currentTokenIndex++;
        }
    }

    private boolean match(String expectedType, SyntaxNode syntaxNode) {
        if (currentToken() != null && currentToken().getType().equals(expectedType)) {
            SyntaxNode syntaxNode1 = new SyntaxNode(expectedType + " " + currentToken().getName());
            syntaxNode.addChild(syntaxNode1);
            nextToken();
            return true;
        }
        return false;
    }

    private Token preRead(int plusIndex) {
        // plusIndex表示我在当前的token想要往后预读第几位的数据
        if (currentTokenIndex < tokens.size() && currentTokenIndex + plusIndex < tokens.size()) {
            int preReadIndex = currentTokenIndex + plusIndex;
            return tokens.get(preReadIndex);
        }
        return null;
    }

    public SyntaxNode parse() {
        return parseCompUnit();  // 开始从根节点 CompUnit 解析
    }

    private SyntaxNode parseCompUnit() {
        SyntaxNode compUnitNode = new SyntaxNode("<CompUnit>");
        // 编译单元 CompUnit → {Decl} {FuncDef} MainFuncDef // 1.是否存在Decl 2.是否存在FuncDef
        while (currentToken() != null && (isDecl() || isFuncDef())) {
            if (isDecl()) {
                compUnitNode.addChild(parseDecl());
            } else if (isFuncDef()) {
                compUnitNode.addChild(parseFuncDef());
            }
        }
        compUnitNode.addChild(parseMainFuncDef());  // MainFuncDef 一定存在
        return compUnitNode;
    }

    private boolean isDecl() {
        // 判断是否是声明，根据下一个 token 类型，const int 或者 char
        if (currentToken().getType().equals("CONSTTK")) {
            if (preRead(1).getType().equals("INTTK") || preRead(1).getType().equals("CHARTK")) {
                if (preRead(2).getType().equals("SEMICN")) {
                    return true;
                }
                if (preRead(2).getType().equals("IDENFR") &&
                        (preRead(3).getType().equals("ASSIGN") || preRead(3).getType().equals("LBRACK") || preRead(3).getType().equals("COMMA"))) {
                    return true;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        } else if (currentToken().getType().equals("INTTK") || currentToken().getType().equals("CHARTK")) {
            if (preRead(1).getType().equals("IDENFR") && !preRead(2).getType().equals("LPARENT")) {
                return true;
            } else {
                return false;
            }
        }
        return false;
    }

    private boolean isFuncDef() {
        // SyntaxNode一定是  int char 判断indent后面是否为左括号。
        if (currentToken().getType().equals("INTTK") || currentToken().getType().equals("CHARTK")) {
            if (preRead(1).getType().equals("IDENFR") && preRead(2).getType().equals("LPARENT")) {
                return true;
            } else {
                return false;
            }
        } else if (currentToken().getType().equals("VOIDTK")) {
            return true;
        }
        return false;
    }

    private SyntaxNode parseMainFuncDef() {
        // 主函数定义 MainFuncDef → 'int' 'main' '(' ')' Block // 存在main函数
        SyntaxNode mainFuncDefNode = new SyntaxNode("<MainFuncDef>");
        match("INTTK", mainFuncDefNode);
        match("MAINTK", mainFuncDefNode);
        match("LPARENT", mainFuncDefNode);
        errorJ(mainFuncDefNode);//match("RPARENT");
        mainFuncDefNode.addChild(parseBlock());
        return mainFuncDefNode;
    }


    private SyntaxNode parseDecl() {
        // 声明 Decl → ConstDecl | VarDecl // 覆盖两种声明
        if (currentToken().getType().equals("CONSTTK")) {
            return parseConstDecl();
        } else {
            return parseVarDecl();
        }
    }

    private SyntaxNode parseConstDecl() {
        // 常量声明 ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';' // 1.花括号内重复0次
        //2.花括号内重复多次
        SyntaxNode constDeclNode = new SyntaxNode("<ConstDecl>");
        match("CONSTTK", constDeclNode);
        constDeclNode.addChild(parseBType());
        constDeclNode.addChild(parseConstDef());
        while (match("COMMA", constDeclNode)) {
            constDeclNode.addChild(parseConstDef());
        }
        errorI(constDeclNode);//match("SEMICN");
        return constDeclNode;
    }

    private SyntaxNode parseBType() {
        if (currentToken().getType().equals("INTTK")) {
            SyntaxNode syntaxNode = new SyntaxNode("INTTK int");
            currentTokenIndex++;
            return syntaxNode;
        } else {
            SyntaxNode syntaxNode = new SyntaxNode("CHARTK char");
            currentTokenIndex++;
            return syntaxNode;
        }
    }

    private SyntaxNode parseFuncType() {
        // 函数类型 FuncType → 'void' | 'int' | 'char'// 覆盖三种类型的函数
        SyntaxNode funcTypeNode = new SyntaxNode("<FuncType>");
        if (currentToken().getType().equals("INTTK")) {
            match("INTTK", funcTypeNode);
        } else if (currentToken().getType().equals("CHARTK")) {
            match("CHARTK", funcTypeNode);
        } else {
            match("VOIDTK", funcTypeNode);
        }
        return funcTypeNode;
    }

    private SyntaxNode parseVarDecl() {
        // 变量声明 VarDecl → BType VarDef { ',' VarDef } ';' // 1.花括号内重复0次 2.花括号内重复多次
        SyntaxNode varDeclNode = new SyntaxNode("<VarDecl>");
        varDeclNode.addChild(parseBType());
        varDeclNode.addChild(parseVarDef());
        while (match("COMMA", varDeclNode)) {
            varDeclNode.addChild(parseVarDef());
        }
        errorI(varDeclNode);//match("SEMICN");
        return varDeclNode;
    }

    private SyntaxNode parseConstDef() {
        // 常量定义 ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal // 包含普通变量、一维数组两种情况
        SyntaxNode constDefNode = new SyntaxNode("<ConstDef>");
        match("IDENFR", constDefNode);
        if (match("LBRACK", constDefNode)) {
            constDefNode.addChild(parseConstExp());
            errorK(constDefNode);//match("RBRACK");
        }
        match("ASSIGN", constDefNode);
        constDefNode.addChild(parseConstInitVal());
        return constDefNode;
    }

    private SyntaxNode parseVarDef() {
        // 变量定义 VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '='InitVal // 包含普通常量、一维数组定义
        SyntaxNode varDefNode = new SyntaxNode("<VarDef>");
        match("IDENFR", varDefNode);
        if (match("LBRACK", varDefNode)) {
            varDefNode.addChild(parseConstExp());
            errorK(varDefNode);//match("RBRACK");
        }
        if (match("ASSIGN", varDefNode)) {
            varDefNode.addChild(parseInitVal());
        }
        return varDefNode;
    }

    private SyntaxNode parseConstExp() {
        // 常量表达式 ConstExp → AddExp 注：使用的 Ident 必须是常量 // 存在即可
        SyntaxNode constExpNode = new SyntaxNode("<ConstExp>");
        constExpNode.addChild(parseAddExp());
        return constExpNode;
    }

    private SyntaxNode parseAddExp() {
        // 加减表达式 AddExp → MulExp | AddExp ('+' | '−') MulExp // 1.MulExp 2.+ 需覆盖 3.- 需覆盖
        SyntaxNode addExpNode = new SyntaxNode("<AddExp>");
        SyntaxNode leftNode = parseMulExp();
        addExpNode.addChild(leftNode);
        while (currentToken().getType().equals("PLUS") || currentToken().getType().equals("MINU")) {
            SyntaxNode addExpNode1 = new SyntaxNode("<AddExp>");
            addExpNode1.addChild(addExpNode);
            match(currentToken().getType(), addExpNode1);
            addExpNode1.addChild(parseMulExp());
            addExpNode = addExpNode1;
        }
        return addExpNode;
    }

    private SyntaxNode parseMulExp() {
        // 乘除模表达式 MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp // 1.UnaryExp2.* 3./ 4.% 均需覆盖
        SyntaxNode mulExpNode = new SyntaxNode("<MulExp>");
        SyntaxNode leftNode = parseUnaryExp();
        mulExpNode.addChild(leftNode);
        while (currentToken().getType().equals("MULT") || currentToken().getType().equals("DIV") || currentToken().getType().equals("MOD")) {
            SyntaxNode mulExpNode1 = new SyntaxNode("<MulExp>");
            mulExpNode1.addChild(mulExpNode);
            match(currentToken().getType(), mulExpNode1);
            mulExpNode1.addChild(parseUnaryExp());
            mulExpNode = mulExpNode1;
        }
        return mulExpNode;
    }

    private SyntaxNode parseUnaryExp() {
        // 一元表达式 UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
        // 3种情况均需覆盖,函数调用也需要覆盖FuncRParams的不同情况
        SyntaxNode unaryExpNode = new SyntaxNode("<UnaryExp>");
        if (currentToken().getType().equals("IDENFR") && preRead(1).getType().equals("LPARENT")) {
            match("IDENFR", unaryExpNode);
            match("LPARENT", unaryExpNode);
            if (!currentToken().getType().equals("RPARENT"))unaryExpNode.addChild(parseFuncRParams());
            errorJ(unaryExpNode);//match("RPARENT");
        } else if (currentToken().getType().equals("PLUS") || currentToken().getType().equals("MINU") || currentToken().getType().equals("NOT")) {
            // 单目运算符 UnaryOp → '+' | '−' | '!' 注：'!'仅出现在条件表达式中 // 三种均需覆盖
            unaryExpNode.addChild(parseUnaryOp());
            unaryExpNode.addChild(parseUnaryExp());
        } else {
            unaryExpNode.addChild(parsePrimaryExp());
        }
        return unaryExpNode;
    }

    private SyntaxNode parseUnaryOp() {
        // 单目运算符 UnaryOp → '+' | '−' | '!' 注：'!'仅出现在条件表达式中 // 三种均需覆盖
        SyntaxNode unaryOpNode = new SyntaxNode("<UnaryOp>");
        if (match("PLUS", unaryOpNode)) {
        } else if (match("MINU", unaryOpNode)) {
        } else if (match("NOT", unaryOpNode)) {
        }
        return unaryOpNode;
    }

    private SyntaxNode parseFuncRParams() {
        //函数实参表 FuncRParams → Exp { ',' Exp } // 1.花括号内重复0次 2.花括号内重复多次 3.Exp需要覆盖数组传参和部分数组传参
        SyntaxNode funcRParamsNode = new SyntaxNode("<FuncRParams>");
        funcRParamsNode.addChild(parseExp());
        while (match("COMMA", funcRParamsNode)) {
            funcRParamsNode.addChild(parseExp());
        }
        return funcRParamsNode;
    }

    private SyntaxNode parsePrimaryExp() {
        // 基本表达式 PrimaryExp → '(' Exp ')' | LVal | Number | Character// 四种情况均需覆盖
        SyntaxNode primaryExpNode = new SyntaxNode("<PrimaryExp>");
        if (match("LPARENT", primaryExpNode)) {
            primaryExpNode.addChild(parseExp());
            errorJ(primaryExpNode);//match("RPARENT");
        } else if (currentToken().getType().equals("CHRCON")) {
            primaryExpNode.addChild(parseCharacter());
        } else if (currentToken().getType().equals("INTCON")) {
            primaryExpNode.addChild(parseNumber());
        } else {
            primaryExpNode.addChild(parseLVal());
        }
        return primaryExpNode;
    }

    private SyntaxNode parseCharacter() {
        //字符 Character → CharConst // CharConst详细解释见下方 (4) 字符常量
        SyntaxNode charNode = new SyntaxNode("<Character>");
        match("CHRCON", charNode);
        return charNode;
    }

    private SyntaxNode parseNumber() {
        //数值 Number → IntConst // 存在即可，IntConst详细解释见下方 (3) 数值常量
        SyntaxNode numberNode = new SyntaxNode("<Number>");
        match("INTCON", numberNode);
        return numberNode;
    }

    private SyntaxNode parseExp() {
        // 表达式 Exp → AddExp // 存在即可
        SyntaxNode expNode = new SyntaxNode("<Exp>");
        expNode.addChild(parseAddExp());
        return expNode;
    }

    private SyntaxNode parseLVal() {
        // 左值表达式 LVal → Ident ['[' Exp ']'] //1.普通变量、常量 2.一维数组
        SyntaxNode lValNode = new SyntaxNode("<LVal>");
        match("IDENFR", lValNode);
        if (match("LBRACK", lValNode)) {
            lValNode.addChild(parseExp());
            errorK(lValNode);//match("RBRACK");
        }
        return lValNode;
    }

    private SyntaxNode parseConstInitVal() {
        // 常量初值 ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst // 1.常表达式初值 2.一维数组初值
        SyntaxNode constIniValNode = new SyntaxNode("<ConstInitVal>");
        if (match("STRCON", constIniValNode)) {
        } else if (match("LBRACE", constIniValNode)) {
            if (!match("RBRACE", constIniValNode)) {
                constIniValNode.addChild(parseConstExp());
                while (match("COMMA", constIniValNode)) {
                    constIniValNode.addChild(parseConstExp());
                }
                match("RBRACE", constIniValNode);
            }
        } else {
            constIniValNode.addChild(parseConstExp());
        }
        return constIniValNode;
    }

    private SyntaxNode parseInitVal() {
        // 变量初值 InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst // 1.表达式初值 2.一维数组初值
        SyntaxNode initValNode = new SyntaxNode("<InitVal>");
        if (match("LBRACE", initValNode)) {
            if (!match("RBRACE", initValNode)) {
                initValNode.addChild(parseExp());
                while (match("COMMA", initValNode)) {
                    initValNode.addChild(parseExp());
                }
                match("RBRACE", initValNode);
            }
        } else if (match("STRCON", initValNode)){
        }else {
            initValNode.addChild(parseExp());
        }
        return initValNode;
    }

    private SyntaxNode parseFuncDef() {
        // 函数定义 FuncDef → FuncType Ident '(' [FuncFParams] ')' Block // 1.无形参 2.有形参
        SyntaxNode funcDefNode = new SyntaxNode("<FuncDef>");
        funcDefNode.addChild(parseFuncType());
        match("IDENFR", funcDefNode);
        match("LPARENT", funcDefNode);
        if (!currentToken().getType().equals("RPARENT")) {
            funcDefNode.addChild(parseFuncFParams());
            errorJ(funcDefNode);//match("RPARENT");
        } else {
            errorJ(funcDefNode);//match("RPARENT");
        }
        funcDefNode.addChild(parseBlock());
        return funcDefNode;
    }

    private SyntaxNode parseFuncFParams() {
        // 函数形参表 FuncFParams → FuncFParam { ',' FuncFParam } // 1.花括号内重复0次 2.花括号内重复多次
        SyntaxNode funcFParamsNode = new SyntaxNode("<FuncFParams>");
        funcFParamsNode.addChild(parseFuncFParam());
        while (match("COMMA", funcFParamsNode)) {
            funcFParamsNode.addChild(parseFuncFParam());
        }
        return funcFParamsNode;
    }

    private SyntaxNode parseFuncFParam() {
        // 函数形参 FuncFParam → BType Ident ['[' ']'] // 1.普通变量2.一维数组变量
        SyntaxNode funcFParamNode = new SyntaxNode("<FuncFParam>");
        funcFParamNode.addChild(parseBType());
        match("IDENFR", funcFParamNode);
        if (match("LBRACK", funcFParamNode)) {
            errorK(funcFParamNode);//match("RBRACK");
        }
        return funcFParamNode;
    }

    private SyntaxNode parseBlock() {
        // 语句块 Block → '{' { BlockItem } '}' // 1.花括号内重复0次 2.花括号内重复多次
        SyntaxNode blockNode = new SyntaxNode("<Block>");
        match("LBRACE", blockNode);
        while (!currentToken().getType().equals("RBRACE")) {
            blockNode.addChild(parseBlockItem());
        }
        match("RBRACE", blockNode);
        return blockNode;
    }

    private SyntaxNode parseBlockItem() {
        // 语句块项 BlockItem → Decl | Stmt // 覆盖两种语句块项
        if (isDecl()) {
            return parseDecl();
        } else {
            return parseStmt();
        }
    }

    private SyntaxNode parseStmt() {
        //语句 Stmt → LVal '=' Exp ';' // 每种类型的语句都要覆盖
        //| [Exp] ';' //有无Exp两种情况
        //| Block
        //| 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // 1.有else 2.无else
        //| 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt // 1. 无缺省，1种情况 2.
        //ForStmt与Cond中缺省一个，3种情况 3. ForStmt与Cond中缺省两个，3种情况 4. ForStmt与Cond全部缺省，1种情况
        //| 'break' ';' | 'continue' ';'
        //| 'return' [Exp] ';' // 1.有Exp 2.无Exp
        //| LVal '=' 'getint''('')'';'
        //| LVal '=' 'getchar''('')'';'
        //| 'printf''('StringConst {','Exp}')'';' // 1.有Exp 2.无Exp
        SyntaxNode stmtNode = new SyntaxNode("<Stmt>");
        // Block   语句块 Block → '{' { BlockItem } '}' // 1.花括号内重复0次 2.花括号内重复多次
        if (currentToken().getType().equals("LBRACE")) {
            stmtNode.addChild(parseBlock());
        }
        //  'if' '(' Cond ')' Stmt [ 'else' Stmt ] // 1.有else 2.无else
        else if (match("IFTK", stmtNode)) {
            match("LPARENT", stmtNode);
            stmtNode.addChild(parseCond()); // 解析条件
            errorJ(stmtNode);//match("RPARENT");
            stmtNode.addChild(parseStmt());
            // 如果当前符号是关键字 'else'
            if (currentToken().getType().equals("ELSETK")) {
                match("ELSETK", stmtNode);
                stmtNode.addChild(parseStmt());
            }
        }
        // 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
        else if (match("FORTK", stmtNode)) {
            match("LPARENT", stmtNode);
            if (!currentToken().getType().equals("SEMICN"))stmtNode.addChild(parseForStmt());
            errorI(stmtNode);//match("SEMICN");
            if (!currentToken().getType().equals("SEMICN"))stmtNode.addChild(parseCond());
            errorI(stmtNode);//match("SEMICN");
            if (!currentToken().getType().equals("RPARENT"))stmtNode.addChild(parseForStmt());
            errorJ(stmtNode);//match("RPARENT");
            stmtNode.addChild(parseStmt());
        }
        // 'break' ';'
        else if (match("BREAKTK", stmtNode)) {
            errorI(stmtNode);//match("SEMICN");
        }
        // 'continue' ';'
        else if (match("CONTINUETK", stmtNode)) {
            errorI(stmtNode);//match("SEMICN");
        }
        // 'return' [Exp] ';' // 1.有Exp 2.无Exp
        else if (match("RETURNTK", stmtNode)) {
            // 如果下一个符号是表达式，则解析表达式
            if (!currentToken().getType().equals("SEMICN")) {
                stmtNode.addChild(parseExp()); // 解析返回值表达式
            }
            errorI(stmtNode);//match("SEMICN"); // 匹配 ';'
        }
        // 'printf''('StringConst {','Exp}')'';' // 1.有Exp 2.无Exp
        else if (match("PRINTFTK", stmtNode)) {
            match("LPARENT", stmtNode);
            match("STRCON", stmtNode); // 解析字符串常量
            // 如果有其他表达式
            while (match("COMMA", stmtNode)) {
                stmtNode.addChild(parseExp());
            }
            errorJ(stmtNode);//match("RPARENT");
            errorI(stmtNode);//match("SEMICN");
        }
        // 如果当前符号是变量 LVal
        else {
            if (isGetInt() || isGetChar()) {
                stmtNode.addChild(parseLVal());
                match("ASSIGN", stmtNode);
                if (isGetInt()) match("GETINTTK", stmtNode);
                else match("GETCHARTK", stmtNode);
                match("LPARENT", stmtNode);
                errorJ(stmtNode);//match("RPARENT");
                errorI(stmtNode);//match("SEMICN");
            } else if (isLvalExp()) {//Stmt → LVal '=' Exp ';'
                stmtNode.addChild(parseLVal());
                match("ASSIGN", stmtNode);
                stmtNode.addChild(parseExp());
                errorI(stmtNode);//match("SEMICN");
            } else {
                if (!currentToken().getType().equals("SEMICN")) {
                    stmtNode.addChild(parseExp());
                }
                errorI(stmtNode);//match("SEMICN");
            }
        }
        return stmtNode;
    }

    private SyntaxNode parseCond() {
        // 条件表达式 Cond → LOrExp // 存在即可
        SyntaxNode condNode = new SyntaxNode("<Cond>");
        condNode.addChild(parseLorExp());
        return condNode;
    }

    private SyntaxNode parseForStmt() {
        // 语句 ForStmt → LVal '=' Exp // 存在即可
        SyntaxNode forStmtNode = new SyntaxNode("<ForStmt>");
        forStmtNode.addChild(parseLVal());
        match("ASSIGN", forStmtNode);
        forStmtNode.addChild(parseExp());
        return forStmtNode;
    }

    // 判断是否是LVal '=' Exp ';'
    private boolean isLvalExp() {
        int lineNum = currentToken().getLineNum();
        for (int i = 0; currentTokenIndex + i < tokens.size(); i++) {
            if (preRead(i).getType().equals("SEMICN")) {
                return false;
            } else if (preRead(i).getType().equals("ASSIGN")) {
                return true;
            }
            if (preRead(i).getLineNum() > lineNum) {
                return false;
            }
        }
        return false;
    }

    private boolean isGetInt() {
        int lineNum = currentToken().getLineNum();
        for (int i = 0; currentTokenIndex + i < tokens.size(); i++) {
            if (preRead(i).getType().equals("SEMICN")) {
                return false;
            } else if (preRead(i).getType().equals("GETINTTK")) {
                return true;
            }
            if (preRead(i).getLineNum() > lineNum) {
                return false;
            }
        }
        return false;
    }

    private boolean isGetChar() {
        int lineNum = currentToken().getLineNum();
        for (int i = 1; currentTokenIndex + i < tokens.size(); i++) {
            if (preRead(i).getType().equals("SEMICN")) {
                return false;
            } else if (preRead(i).getType().equals("GETCHARTK")) {
                return true;
            }
            if (preRead(i).getLineNum() > lineNum) {
                return false;
            }
        }
        return false;
    }

    private SyntaxNode parseLorExp() {
        // 逻辑或表达式 LOrExp → LAndExp | LOrExp '||' LAndExp // 1.LAndExp 2.|| 均需覆盖
        SyntaxNode lorExpNode = new SyntaxNode("<LOrExp>");
        SyntaxNode leftNode = parseLAndExp();
        lorExpNode.addChild(leftNode);
        while (currentToken().getType().equals("OR")) {
            SyntaxNode lorExpNode1 = new SyntaxNode("<LOrExp>");
            lorExpNode1.addChild(lorExpNode);
            match(currentToken().getType(), lorExpNode1);
            lorExpNode1.addChild(parseLAndExp());
            lorExpNode = lorExpNode1;
        }
        return lorExpNode;
    }

    private SyntaxNode parseLAndExp() {
        // 逻辑与表达式 LAndExp → EqExp | LAndExp '&&' EqExp // 1.EqExp 2.&& 均需覆盖
        SyntaxNode lAndExpNode = new SyntaxNode("<LAndExp>");
        SyntaxNode leftNode = parseEqExp();
        lAndExpNode.addChild(leftNode);
        while (currentToken().getType().equals("AND")) {
            SyntaxNode lAndExpNode1 = new SyntaxNode("<LAndExp>");
            lAndExpNode1.addChild(lAndExpNode);
            match(currentToken().getType(), lAndExpNode1);
            lAndExpNode1.addChild(parseEqExp());
            lAndExpNode = lAndExpNode1;
        }
        return lAndExpNode;
    }

    private SyntaxNode parseEqExp() {
        // 相等性表达式 EqExp → RelExp | EqExp ('==' | '!=') RelExp // 1.RelExp 2.== 3.!= 均需覆盖
        SyntaxNode eqExpNode = new SyntaxNode("<EqExp>");
        SyntaxNode leftNode = parseRelExp();
        eqExpNode.addChild(leftNode);
        while (currentToken().getType().equals("EQL") || currentToken().getType().equals("NEQ")) {
            SyntaxNode eqExpNode1 = new SyntaxNode("<EqExp>");
            eqExpNode1.addChild(eqExpNode);
            match(currentToken().getType(), eqExpNode1);
            eqExpNode1.addChild(parseRelExp());
            eqExpNode = eqExpNode1;
        }
        return eqExpNode;
    }

    private SyntaxNode parseRelExp() {
        // 关系表达式 RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp // 1.AddExp 2.< 3.> 4.<= 5.>= 均需覆盖
        SyntaxNode relExpNode = new SyntaxNode("<RelExp>");
        SyntaxNode leftNode = parseAddExp();
        relExpNode.addChild(leftNode);
        while (currentToken().getType().equals("LSS") || currentToken().getType().equals("LEQ")
                || currentToken().getType().equals("GRE") || currentToken().getType().equals("GEQ")) {
            SyntaxNode relExpNode1 = new SyntaxNode("<RelExp>");
            relExpNode1.addChild(relExpNode);
            match(currentToken().getType(), relExpNode1);
            relExpNode1.addChild(parseAddExp());
            relExpNode = relExpNode1;
        }
        return relExpNode;
    }

    //缺少分号 i
    //报错行号为分号前一个非终结符所在行号。
    private void errorI(SyntaxNode node) {
        if (!match("SEMICN", node)) {
            int lineNum = tokens.get(currentTokenIndex - 1).getLineNum();
            ErrorToken errorToken = new ErrorToken(lineNum, "i");
            errorTokens.add(errorToken);
        }
    }

    private void errorJ(SyntaxNode node) {
        if (!match("RPARENT", node)) {
            int lineNum = tokens.get(currentTokenIndex - 1).getLineNum();
            ErrorToken errorToken = new ErrorToken(lineNum, "j");
            errorTokens.add(errorToken);
        }
    }

    private void errorK(SyntaxNode node) {
        if (!match("RBRACK", node)) {
            int lineNum = tokens.get(currentTokenIndex - 1).getLineNum();
            ErrorToken errorToken = new ErrorToken(lineNum, "k");
            errorTokens.add(errorToken);
        }
    }
}