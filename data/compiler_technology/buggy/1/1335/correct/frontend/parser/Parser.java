package frontend.parser;

import frontend.error.ErrorInformation;
import frontend.lexer.Token;
import frontend.lexer.Type;
import frontend.parser.ast.ASTNode;

import java.util.ArrayList;
import java.util.Objects;

public class Parser {
    private final ArrayList<Token> tokens;
    private Token currentToken;

    private boolean hasError;

    private ArrayList<ErrorInformation> errors;

    private int lineNum;

    private final ASTNode compUnitNode;

    private Judge judge;
    public Parser(ArrayList<Token> tokens,ArrayList<ErrorInformation> errorInformation) {
        this.tokens = tokens;
        this.currentToken = tokens.get(0);
        this.hasError = false;
        this.compUnitNode = new ASTNode(SynComponent.CompUnit,true,null,false);
        this.judge = new Judge();
        this.errors = new ArrayList<>();
        this.errors = errorInformation;
    }

    private void consume() {
        int currentIndex = tokens.indexOf(currentToken);
        if(currentIndex + 1 >= tokens.size()) {
            lineNum = currentToken.getLineNum();
            currentToken = null;
        } else {
            currentToken = tokens.get(currentIndex + 1);
            lineNum = currentToken.getLineNum();
        }
    }

    private Token checkNext() {
        int currentIndex = tokens.indexOf(currentToken);
        Token nextToken;
        if(currentIndex + 1 >= tokens.size()) {
            nextToken = null;
        } else {
            nextToken = tokens.get(currentIndex + 1);
        }
        return nextToken;
    }

    private int beforeLine() {
        if (currentToken == null) {
            // 直接访问最后一个元素
            return tokens.get(tokens.size() - 1).getLineNum();
        } else {
            // 检查 currentToken 是否是第一个元素
            int index = tokens.indexOf(currentToken);
            if (index > 0) {
                return tokens.get(index - 1).getLineNum();
            } else {
                return 1;  // 示例：返回 -1 或其他特定逻辑
            }
        }
    }


    private Token checkNext2() {
        int currentIndex = tokens.indexOf(currentToken);
        Token nextToken;
        if(currentIndex + 2 >= tokens.size()) {
            nextToken = null;
        } else {
            nextToken = tokens.get(currentIndex + 2);
        }
        return nextToken;
    }

    public ASTNode parse() {
        parseCompUnit();
        return compUnitNode;
    }

    private void parseCompUnit() {
        while (currentToken != null) {
            if(currentToken.getType() == Type.INTTK && checkNext().getType() == Type.MAINTK){
                ASTNode main = parseMain();
                compUnitNode.addChild(main);
            }else if (judge.isFuncDef(currentToken,checkNext(),checkNext2())) {
                ASTNode funcDefNode = parseFuncDef();
                compUnitNode.addChild(funcDefNode);
            } else if (judge.isDecl(currentToken)) {
                ASTNode declNode = parseDecl();
                compUnitNode.addChild(declNode);
            }
        }
    }

    private ASTNode parseMain() {
        ASTNode main = new ASTNode(SynComponent.MainFuncDef,true,null,false);
        main.addChild(new ASTNode(null, false, currentToken, true));
        consume();//int
        main.addChild(new ASTNode(null, false, currentToken, true));
        consume();//main
        main.addChild(new ASTNode(null, false, currentToken, true));
        consume();//(
        if (currentToken.getType() == Type.RPARENT) {
            main.addChild(new ASTNode(null, false, currentToken, true));
            consume(); // Expecting ')'
        } else {
            hasError = true;
            errors.add(new ErrorInformation(beforeLine(),'j'));
        }

        main.addChild(parseBlock());

        return main;
    }

    private ASTNode parseFuncDef() {
        // Syntax: FuncType Ident '(' [FuncFParams] ')' Block
        ASTNode funcDefNode = new ASTNode(SynComponent.FuncDef,true,null,false);

        ASTNode funcTypeNode = parseFuncType();
        funcDefNode.addChild(funcTypeNode);

        ASTNode identNode = parseIdent();
        funcDefNode.addChild(identNode);

        funcDefNode.addChild(new ASTNode(null,false,currentToken,true));
        consume(); // Expecting '('

        if (judge.isFuncFParams(currentToken)) {
            ASTNode funcFParamsNode = parseFuncFParams();
            funcDefNode.addChild(funcFParamsNode);
        }

        if (currentToken.getType() == Type.RPARENT) {
            funcDefNode.addChild(new ASTNode(null, false, currentToken, true));
            consume(); // Expecting ')'
        } else {
            hasError = true;
            errors.add(new ErrorInformation(beforeLine(),'j'));
        }
        ASTNode blockNode = parseBlock();
        funcDefNode.addChild(blockNode);

        return funcDefNode;
    }

    private ASTNode parseFuncType() {
        // Syntax: FuncType -> 'void' | 'int' | 'char'
        ASTNode funcTypeNode = new ASTNode(SynComponent.FuncType,true,null,false);
        if (currentToken != null) {
            ASTNode node = new ASTNode(null, false, currentToken, true);
            funcTypeNode.addChild(node);
            consume(); // Consume the 'void' token
        }

        return funcTypeNode;
    }

    private ASTNode parseBlock() {
        // Syntax: '{' { BlockItem } '}'
        ASTNode blockNode = new ASTNode(SynComponent.Block,true,null,false);

        blockNode.addChild(new ASTNode(null,false,currentToken,true));
        consume();//{
        while (!currentToken.getType().equals(Type.RBRACE)) {
            ASTNode blockItemNode = parseBlockItem();
            blockNode.addChild(blockItemNode);
        }

        blockNode.addChild(new ASTNode(null,false,currentToken,true));
        consume(); // Expecting '}'
        return blockNode;
    }

    //{ a = 1; }

    private ASTNode parseBlockItem() {
        // Syntax: BlockItem -> Decl | Stmt
        if (judge.isDecl(currentToken)) {
            return parseDecl();
        } else {
            return parseStmt();
           // return node;
        }

    }

    private ASTNode parseDecl() {
        if (currentToken.getType().equals(Type.CONSTTK)) {
            return parseConstDecl();
        } else return parseVarDecl();
    }

    private ASTNode parseConstDecl() {
        // Syntax:ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';'
        ASTNode constDeclNode = new ASTNode(SynComponent.ConstDecl,true,null,false);
        constDeclNode.addChild(new ASTNode(null,false,currentToken,true));
        consume();//consttk
        ASTNode bTypeNode = parseBType();
        constDeclNode.addChild(bTypeNode);
        do {
            ASTNode constDefNode = parseConstDef();
            constDeclNode.addChild(constDefNode);
            if (currentToken != null && currentToken.getType().equals(Type.COMMA)) {
                constDeclNode.addChild(new ASTNode(null,false,currentToken,true));
                consume(); // consume comma
            } else {
                break;
            }
        } while (currentToken != null);
        if (currentToken != null && currentToken.getType() == Type.SEMICN) {
            constDeclNode.addChild(new ASTNode(null, false, currentToken, true));
            consume();
        } else {
            this.hasError = true;
            errors.add(new ErrorInformation(beforeLine(),'i'));
        }
        return constDeclNode;
    }

    private ASTNode parseVarDecl() {
        ASTNode varDeclNode = new ASTNode(SynComponent.VarDecl,true,null,false);
        ASTNode bTypeNode = parseBType();
        varDeclNode.addChild(bTypeNode);
        do {
            ASTNode varDefNode = parseVarDef();
            varDeclNode.addChild(varDefNode);
            if (currentToken != null && currentToken.getType().equals(Type.COMMA)) {
                varDeclNode.addChild(new ASTNode(null, false, currentToken, true));
                consume(); // consume comma
            } else {
                break;
            }
        } while (currentToken != null);

        if (currentToken != null && currentToken.getType() == Type.SEMICN) {
            varDeclNode.addChild(new ASTNode(null, false, currentToken, true));
            consume();
        } else {
            this.hasError = true;
            errors.add(new ErrorInformation(beforeLine(),'i'));
        }
        return varDeclNode;
    }


    private ASTNode parseStmt() {
        // Syntax: Stmt -> LVal '=' Exp ';'
        //           | [Exp] ';'
        //           | Block
        //           | 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
        //           | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
        //           | 'break' ';'
        //           | 'continue' ';'
        //           | 'return' [Exp] ';'
        //           | LVal '=' 'getint' '(' ')' ';'
        //           | LVal '=' 'getchar' '(' ')' ';'
        //           | 'printf' '(' StringConst {',' Exp} ')' ';'
        ASTNode stmtNode = new ASTNode(SynComponent.Stmt,true,null,false);
        if (judge.isLVal(currentToken) && checkNext().getType()!=Type.LPARENT ) {
            ArrayList<ErrorInformation> now = new ArrayList<>();
            int size = errors.size();
            if(expectAssign()) {
                int sizeNext = errors.size();
                if (sizeNext > size) {
                    for(int i = 0;i < sizeNext-size;i++) {
                        errors.remove(errors.size() - i - 1);
                    }
                }
                ASTNode lvalNode = parseLVal();
                stmtNode.addChild(lvalNode);
                stmtNode.addChild(new ASTNode(null, false, currentToken, true));
                consume(); // consume '='
                if (currentToken.getType() == Type.GETINTTK) {
                    stmtNode.addChild(new ASTNode(null, false, currentToken, true));
                    consume();//getint
                    stmtNode.addChild(new ASTNode(null, false, currentToken, true));
                    consume();//(
                    if (currentToken.getType() == Type.RPARENT) {
                        stmtNode.addChild(new ASTNode(null, false, currentToken, true));
                        consume(); // Expecting ')'
                    } else {
                        hasError = true;
                        errors.add(new ErrorInformation(beforeLine(),'j'));
                    }
                } else if (currentToken.getType() == Type.GETCHARTK) {
                    stmtNode.addChild(new ASTNode(null, false, currentToken, true));
                    consume();//getchar
                    stmtNode.addChild(new ASTNode(null, false, currentToken, true));
                    consume();//(
                    if (currentToken.getType() == Type.RPARENT) {
                        stmtNode.addChild(new ASTNode(null, false, currentToken, true));
                        consume(); // Expecting ')'
                    } else {
                        hasError = true;
                        errors.add(new ErrorInformation(beforeLine(),'j'));
                    }
                } else {
                    ASTNode expNode = parseExp();
                    stmtNode.addChild(expNode);
                }
                if (currentToken != null && currentToken.getType() == Type.SEMICN) {
                    stmtNode.addChild(new ASTNode(null, false, currentToken, true));
                    consume();
                } else {
                    this.hasError = true;
                    errors.add(new ErrorInformation(beforeLine(), 'i'));
                }
            } else {
                int sizeNext = errors.size();
                if (sizeNext > size) {
                    for(int i = 0;i < sizeNext-size;i++) {
                        errors.remove(errors.size() - i - 1);
                    }
                }
                ASTNode expNode = parseExp(); // Parse the expression
                stmtNode.addChild(expNode);
                if (currentToken != null && currentToken.getType() == Type.SEMICN) {
                    stmtNode.addChild(new ASTNode(null, false, currentToken, true));
                    consume();
                } else {
                    this.hasError = true;
                    errors.add(new ErrorInformation(beforeLine(),'i'));
                }
            }
        } else if (judge.isBlock(currentToken)) {
            ASTNode blockNode = parseBlock();
            stmtNode.addChild(blockNode);
        } else if (currentToken.getType() == Type.IFTK) { // 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
            parseIfStmt(stmtNode);
        } else if (currentToken.getType() == Type.FORTK) { // 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
            parseForStmt(stmtNode);
        } else if (currentToken.getType() == Type.BREAKTK) { // 'break' ';'
            parseBreakStmt(stmtNode);
        } else if (currentToken.getType() == Type.CONTINUETK) { // 'continue' ';'
            parseContinueStmt(stmtNode);
        } else if (currentToken.getType() == Type.RETURNTK) { // 'return' [Exp] ';'
            parseReturnStmt(stmtNode);
        } else if (currentToken.getType() == Type.PRINTFTK) { // 'printf' '(' StringConst {',' Exp} ')' ';'
            parsePrintfStmt(stmtNode);
        } else if (currentToken.getType() == Type.SEMICN) {
            stmtNode.addChild(new ASTNode(null, false, currentToken, true)); // Handle empty statement
            consume();
        } else { //isExp
            ASTNode expNode = parseExp(); // Parse the expression
            stmtNode.addChild(expNode);
            if (currentToken != null && currentToken.getType() == Type.SEMICN) {
                stmtNode.addChild(new ASTNode(null, false, currentToken, true));
                consume();
            } else {
                this.hasError = true;
                errors.add(new ErrorInformation(beforeLine(),'i'));
            }
        }
        return stmtNode;
    }

    private boolean expectAssign() {
        int currentIndex = tokens.indexOf(currentToken);
        parseLVal();
        if(currentToken.getType()==Type.ASSIGN){
            currentToken = tokens.get(currentIndex);
            return true;
        } else {
            currentToken = tokens.get(currentIndex);
            return false;
        }
    }

    private ASTNode parseLVal() {
        ASTNode node = new ASTNode(SynComponent.LVal,true,null,false);
        // LVal -> Ident '[' Exp ']'
        if (currentToken.getType() == Type.IDENFR) { // Expecting an identifier (e.g., variable name)
            node.addChild(new ASTNode(null, false, currentToken, true));
            consume(); //ident

            // Check if we are dealing with array access (Ident '[' Exp ']')
            if (currentToken.getType() == Type.LBRACK) { // '['
                node.addChild(new ASTNode(null, false, currentToken, true));
                consume(); // Consume '['
                ASTNode indexNode = parseExp(); // Parse the expression inside the brackets
                node.addChild(indexNode);
                if (currentToken.getType().equals(Type.RBRACK)) {
                    node.addChild(new ASTNode(null,false,currentToken,true));
                    consume();
                }  else {
                    this.hasError = true;
                    System.out.println("2");
                    errors.add(new ErrorInformation(beforeLine(),'k'));
                }
            }
        }
        return node;
    }

    private void parseReturnStmt(ASTNode returnNode) {
        // 创建新的 AST 节点用于 return 语句
        int pos1 = currentToken.getLineNum();
        returnNode.addChild(new ASTNode(null, false, currentToken, true));
        consume(); // 消耗 ';' // 消耗 'return'
        if (currentToken != null) {
            if (currentToken.getType() == Type.SEMICN) {
                // 如果是分号，直接添加并消费它
                returnNode.addChild(new ASTNode(null, false, currentToken, true));
                consume(); // 消耗 ';'
            } else {
                // 尝试解析表达式
                int pos2 = currentToken.getLineNum();
                if(pos2 == pos1) {
                    ASTNode expNode = parseExp(); // 解析表达式
                    if (expNode != null) {
                        returnNode.addChild(expNode); // 添加表达式节点
                    }
                    if (currentToken != null && currentToken.getType() == Type.SEMICN) {
                        returnNode.addChild(new ASTNode(null, false, currentToken, true));
                        consume();
                    } else {
                        this.hasError = true;
                        errors.add(new ErrorInformation(beforeLine(), 'i'));
                    }
                } else {
                    if (currentToken != null && currentToken.getType() == Type.SEMICN) {
                        returnNode.addChild(new ASTNode(null, false, currentToken, true));
                        consume();
                    } else {
                        this.hasError = true;
                        errors.add(new ErrorInformation(beforeLine(), 'i'));
                    }
                }
            }
        }
    }


    private void parseContinueStmt(ASTNode node) {
        node.addChild(new ASTNode(null, false, currentToken, true));
        consume(); // consume ';'
        if (currentToken != null && currentToken.getType() == Type.SEMICN) {
            node.addChild(new ASTNode(null, false, currentToken, true));
            consume(); // consume ';'
        } else {
            this.hasError = true;
            errors.add(new ErrorInformation(beforeLine(), 'i'));
        }
    }

    private void parseBreakStmt(ASTNode node) {
        node.addChild(new ASTNode(null, false, currentToken, true));
        consume(); // consume ';'

        if (currentToken != null && currentToken.getType() == Type.SEMICN) {
            node.addChild(new ASTNode(null, false, currentToken, true));
            consume(); // consume ';'
        } else {
            this.hasError = true;
            errors.add(new ErrorInformation(beforeLine(), 'i'));
        }
    }



    private void parseIfStmt(ASTNode node) {
        node.addChild(new ASTNode(null,false,currentToken,true));
        consume(); // consume 'if'
        node.addChild(new ASTNode(null,false,currentToken,true));
        consume(); // expect '('
        ASTNode condNode = parseCond(); // Parse condition
        node.addChild(condNode);
        if (currentToken.getType() == Type.RPARENT) {
            node.addChild(new ASTNode(null, false, currentToken, true));
            consume(); // expect ')'
        } else {
            this.hasError = true;
            errors.add(new ErrorInformation(beforeLine(),'j'));
        }
        ASTNode thenStmtNode = parseStmt(); // Parse then statement
        node.addChild(thenStmtNode);
        ASTNode elseStmtNode = null;

        if (currentToken!=null && currentToken.getType() == Type.ELSETK) {
            node.addChild(new ASTNode(null,false,currentToken,true));
            consume(); // consume 'else'
            elseStmtNode = parseStmt(); // Parse else statement
            node.addChild(elseStmtNode);
        }
    }

    private ASTNode parseCond() {
        ASTNode node = new ASTNode(SynComponent.Cond,false,null,false);
        node.addChild(parseLOrExp());
        return node;
    }

    private void parseForStmt(ASTNode node) {
        node.addChild(new ASTNode(null,false,currentToken,true));
        consume(); // consume 'for'

        if (currentToken.getType() == Type.LPARENT) {
            node.addChild(new ASTNode(null,false,currentToken,true));
            consume(); // consume '('
        } else {
            this.hasError = true;
            errors.add(new ErrorInformation(beforeLine(),'j'));
        }

        ASTNode forInitNode = null;
        if (judge.isForStmt(currentToken)) {
            forInitNode = parseStmt2(); // Parse for initialization
            node.addChild(forInitNode);
        }
        node.addChild(new ASTNode(null,false,currentToken,true));
        consume(); // expect ';'

        ASTNode condNode = null;
        if (!currentToken.getType().equals(Type.SEMICN)) {
            condNode = parseCond(); // Parse condition
            node.addChild(condNode);
        }

        node.addChild(new ASTNode(null,false,currentToken,true));
        consume(); // expect ';'

        ASTNode forUpdateNode = null;
        if (judge.isForStmt(currentToken)) {
            forUpdateNode = parseStmt2(); // Parse for update statement
            node.addChild(forUpdateNode);
        }

        if (currentToken.getType() == Type.RPARENT) {
            node.addChild(new ASTNode(null,false,currentToken,true));
            consume(); // consume '('
        } else {
            this.hasError = true;
            errors.add(new ErrorInformation(beforeLine(),'j'));
        }
        node.addChild(parseStmt());
    }

    private ASTNode parseStmt2() {
        ASTNode stmtNode = new ASTNode(SynComponent.ForStmt,true,null,false);
        if (judge.isLVal(currentToken)) {
            ASTNode lvalNode = parseLVal();
            stmtNode.addChild(lvalNode);
            stmtNode.addChild(new ASTNode(null,false,currentToken,true));
            consume(); // consume '='
            ASTNode expNode = parseExp();
            stmtNode.addChild(expNode);
        }
        return stmtNode;
    }


    private void parsePrintfStmt(ASTNode node) {
        ASTNode printfNode = new ASTNode(null, false, currentToken, true);
        node.addChild(printfNode);
        consume(); // consume 'printf'
        node.addChild(new ASTNode(null,false,currentToken,true));
        consume(); // consume '('

        if (currentToken.getType() == Type.STRCON) {
            ASTNode stringNode = new ASTNode(null, false, currentToken, true);
            node.addChild(stringNode);
            consume(); // consume string constant
        }
        while (currentToken != null && currentToken.getType() == Type.COMMA) {
            node.addChild(new ASTNode(null,false,currentToken,true));
            consume(); // consume ','
            ASTNode expNode = parseExp();
            node.addChild(expNode);
        }

        if (currentToken != null && currentToken.getType() == Type.RPARENT) {
            node.addChild(new ASTNode(null, false, currentToken, true));
            consume(); // consume ')'
        } else {
            this.hasError = true;
            errors.add(new ErrorInformation(beforeLine(), 'j'));
        }

        if (currentToken != null && currentToken.getType() == Type.SEMICN) {
            node.addChild(new ASTNode(null, false, currentToken, true));
            consume(); // consume ';'
        } else {
            this.hasError = true;
            errors.add(new ErrorInformation(beforeLine(), 'i'));
        }
    }



    private ASTNode parseFuncFParams() {
        // Syntax: FuncFParam { ',' FuncFParam }
        ASTNode funcFParamsNode = new ASTNode(SynComponent.FuncFParams,true,null,false);
        do {
            ASTNode funcFParamNode = parseFuncFParam();
            funcFParamsNode.addChild(funcFParamNode);
            if (currentToken != null && currentToken.getType().equals(Type.COMMA)) {
                funcFParamsNode.addChild(new ASTNode(null, false, currentToken, true));
                consume(); // consume comma
            } else {
                break;
            }
        } while (currentToken != null);

        return funcFParamsNode;
    }

    private ASTNode parseFuncFParam() {
        // Syntax: BType Ident ['[' ']']
        ASTNode funcFParamNode = new ASTNode(SynComponent.FuncFParam,true,null,false);
        ASTNode bTypeNode = parseBType();
        funcFParamNode.addChild(bTypeNode);

        ASTNode identNode = parseIdent();
        funcFParamNode.addChild(identNode);

        if (currentToken.getType().equals(Type.LBRACK)) {
            funcFParamNode.addChild(new ASTNode(null,false,currentToken,true));
            consume();
            if (currentToken.getType().equals(Type.RBRACK)) {
                funcFParamNode.addChild(new ASTNode(null,false,currentToken,true));
                consume();
            }  else {
                this.hasError = true;
                System.out.println("3");
                errors.add(new ErrorInformation(beforeLine(),'k'));
            }
        }


        return funcFParamNode;
    }

    private ASTNode parseBType() {
        // Syntax: 'int' | 'char'
        ASTNode node = new ASTNode(null,false,currentToken,true);
        consume();
        return node;
    }

    private ASTNode parseIdent() {
        ASTNode node = new ASTNode(null,false,currentToken,true);
        consume();
        return node;
    }

    private ASTNode parseConstDef() {
        ASTNode node = new ASTNode(SynComponent.ConstDef, true, null, false);
        node.addChild(new ASTNode(null, false, currentToken, true));
        consume(); // ident

        // 检查是否是数组定义
        if (currentToken.getType() == Type.LBRACK) {
            node.addChild(new ASTNode(null, false, currentToken, true));
            consume(); // '['

            ASTNode arraySize = parseConstExp();
            node.addChild(arraySize);
            if (currentToken.getType().equals(Type.RBRACK)) {
                node.addChild(new ASTNode(null,false,currentToken,true));
                consume();
            }  else {
                this.hasError = true;
                System.out.println("4");
                errors.add(new ErrorInformation(beforeLine(),'k'));
            }
        }

        node.addChild(new ASTNode(null, false, currentToken, true));
        consume(); // ' '='

        ASTNode initVal = parseConstInitVal();
        node.addChild(initVal);
        return node;
    }

    private ASTNode parseConstInitVal() {
        //  ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' |StringConst // 1.常表达式初值 2.一维数组初值
        ASTNode node = new ASTNode(SynComponent.ConstInitVal, false, null, false);
        if (currentToken.getType() == Type.LBRACE) {
            node.addChild(new ASTNode(null, false, currentToken, true));
            consume(); // 消费 '{'
            while (currentToken.getType() != Type.RBRACE){
                node.addChild(parseConstExp()); // 递归解析数组中的每个元素
                if (currentToken.getType() == Type.COMMA) {
                    node.addChild(new ASTNode(null, false, currentToken, true));
                    consume(); //  ','
                }
            }
            node.addChild(new ASTNode(null, false, currentToken, true));
            consume(); // '}'
        } else if(currentToken.getType().equals(Type.STRCON)) {
            node.addChild(new ASTNode(null, false, currentToken, true));
            consume(); //  ','
        } else {
            node.addChild(parseConstExp()); // 解析并添加单个表达式或值
        }

        return node;
    }

    private ASTNode parseConstExp() {
        ASTNode node = new ASTNode(SynComponent.ConstExp,false,null,false);
        node.addChild(parseAddExp());
        return node;
    }

    private ASTNode parseVarDef() {
        ASTNode node = new ASTNode(SynComponent.VarDef, false, null, false);


        node.addChild(new ASTNode(null, false, currentToken, true));
        consume(); // ident

        // 检查是否定义了数组
        if (currentToken.getType() == Type.LBRACK) {
            node.addChild(new ASTNode(null, false, currentToken, true));
            consume(); // '['
            node.addChild(parseConstExp()); // 解析数组大小
            System.out.println(currentToken.toString());
            if (currentToken.getType().equals(Type.RBRACK)) {
                node.addChild(new ASTNode(null,false,currentToken,true));
                consume();
            }  else {
                this.hasError = true;
                errors.add(new ErrorInformation(beforeLine(),'k'));
            }
        }

        // 检查是否有初始值
        if (currentToken.getType() == Type.ASSIGN) {
            node.addChild(new ASTNode(null, false, currentToken, true));
            consume(); // =
            node.addChild(parseInitVal()); // 解析初始值
        }
        return node;
    }

    private ASTNode parseInitVal() {
        ASTNode node = new ASTNode(SynComponent.InitVal, false, null, false);

        if (currentToken.getType() == Type.LBRACE) {
            node.addChild(new ASTNode(null, false, currentToken, true));
            consume(); // '{'
            if (currentToken.getType() != Type.RBRACE) { // 确保非空数组初始化
                do {
                    node.addChild(parseExp());
                    if (currentToken.getType() == Type.COMMA) {
                        node.addChild(new ASTNode(null, false, currentToken, true));
                        consume(); //  ','
                    }
                } while (currentToken.getType() != Type.RBRACE);
            }
            node.addChild(new ASTNode(null, false, currentToken, true));
            consume(); //  '}'
        } else if (currentToken.getType() == Type.STRCON) {
            // 字符串常量
            node.addChild(new ASTNode(null, false, currentToken, true));
            consume();
        } else {
            // 单一表达式作为初始值
            node.addChild(parseExp());
        }

        return node;
    }


    private ASTNode parseExp() {
        ASTNode node = new ASTNode(SynComponent.Exp,false,null,false);
        node.addChild(parseAddExp());
        return node;
    }

    private ASTNode parseAddExp() {
        ASTNode node = new ASTNode(SynComponent.AddExp,false,null,false);
        node.addChild(parseMulExp());
        while (currentToken != null && (currentToken.getType() == Type.PLUS || currentToken.getType() == Type.MINU)) {
            ASTNode addNode = new ASTNode(null, false, currentToken, true);
            ASTNode newNode = new ASTNode(SynComponent.AddExp,false,null,false);
            newNode.addChild(node);
            newNode.addChild(addNode);
            consume();

            ASTNode rhs = parseMulExp();
            newNode.addChild(rhs);
            node = newNode;
        }

        return node;
    }

    private ASTNode parseMulExp() {
        ASTNode node = new ASTNode(SynComponent.MulExp,false,null,false);
        node.addChild(parseUnaryExp());
        while (currentToken != null && (currentToken.getType() == Type.MULT
                || currentToken.getType() == Type.DIV || currentToken.getType() == Type.MOD)) {
            ASTNode addNode = new ASTNode(null, false, currentToken, true);
            ASTNode newNode = new ASTNode(SynComponent.MulExp,false,null,false);

            newNode.addChild(node);
            newNode.addChild(addNode);
            consume();

            ASTNode rhs = parseUnaryExp();
            newNode.addChild(rhs);
            node = newNode;
        }
        return node;
    }

    private ASTNode parseLOrExp() {
        ASTNode orNode = new ASTNode(SynComponent.LOrExp,false,null,false);
        orNode.addChild(parseLAndExp());
        while (currentToken != null && currentToken.getType() == Type.OR) {
            ASTNode addNode = new ASTNode(null, false, currentToken, true);
            ASTNode newNode = new ASTNode(SynComponent.LOrExp,false,null,false);

            newNode.addChild(orNode);
            newNode.addChild(addNode);
            consume();

            ASTNode rhs = parseLAndExp();
            newNode.addChild(rhs);
            orNode = newNode;
        }
        return orNode;
    }

    private ASTNode parseLAndExp() {
        ASTNode andNode = new ASTNode(SynComponent.LAndExp,false,null,false);
        andNode.addChild(parseEqExp());
        while (currentToken != null && currentToken.getType() == Type.AND) {
            ASTNode addNode = new ASTNode(null, false, currentToken, true);
            ASTNode newNode = new ASTNode(SynComponent.LAndExp,false,null,false);

            newNode.addChild(andNode);
            newNode.addChild(addNode);
            consume();

            ASTNode rhs = parseEqExp();
            newNode.addChild(rhs);
            andNode = newNode;
        }
        return andNode;
    }

    private ASTNode parseEqExp() {
        ASTNode eqNode = new ASTNode(SynComponent.EqExp,false,null,false);
        eqNode.addChild(parseRelExp());
        while (currentToken != null && (currentToken.getType() == Type.EQL || currentToken.getType() == Type.NEQ)) {
            ASTNode addNode = new ASTNode(null, false, currentToken, true);
            ASTNode newNode = new ASTNode(SynComponent.EqExp,false,null,false);

            newNode.addChild(eqNode);
            newNode.addChild(addNode);
            consume();

            ASTNode rhs = parseRelExp();
            newNode.addChild(rhs);
            eqNode = newNode;
        }
        return eqNode;
    }

    private ASTNode parseRelExp() {
        ASTNode relNode = new ASTNode(SynComponent.RelExp,false,null,false);
        relNode.addChild(parseAddExp());
        while (currentToken != null && (currentToken.getType() == Type.LEQ || currentToken.getType() == Type.LSS
        || currentToken.getType() == Type.GEQ || currentToken.getType() == Type.GRE)) {
            ASTNode addNode = new ASTNode(null, false, currentToken, true);
            ASTNode newNode = new ASTNode(SynComponent.RelExp,false,null,false);

            newNode.addChild(relNode);
            newNode.addChild(addNode);
            consume();

            ASTNode rhs = parseAddExp();
            newNode.addChild(rhs);
            relNode = newNode;
        }
        return relNode;
    }

    private ASTNode parseUnaryExp() {
        ASTNode node = new ASTNode(SynComponent.UnaryExp, false, null, false);
        if (judge.isUnaryOp(currentToken)) {
            // 处理一元操作符表达式 - UnaryOp UnaryExp
            node.addChild(parseUnaryOp()); // 解析一元操作符
            node.addChild(parseUnaryExp()); // 递归解析一元表达式
        } else if (currentToken.getType() == Type.IDENFR) {
            // 处理可能的函数调用 - Ident '(' [FuncRParams] ')'
            if (Objects.requireNonNull(checkNext()).getType() == Type.LPARENT) {
                node.addChild(new ASTNode(null, false, currentToken, true));
                consume(); // ident
                node.addChild(new ASTNode(null, false, currentToken, true));
                consume(); //  '(';
                if (currentToken.getType() != Type.RPARENT) {
                    // 如果不是空的参数列表，解析函数参数
                    node.addChild(parseFuncRParams());
                }
                if (currentToken.getType() == Type.RPARENT) {
                    node.addChild(new ASTNode(null, false, currentToken, true));
                    consume(); // Expecting ')'
                } else {
                    hasError = true;
                    errors.add(new ErrorInformation(beforeLine(),'j'));
                }
            } else {
                // 如果不是函数调用，回退并处理为一个基础表达式
                node.addChild(parsePrimaryExp());
            }
        } else {
            // 处理基础表达式 - PrimaryExp
            node.addChild(parsePrimaryExp());
        }

        return node;
    }

    private ASTNode parseFuncRParams() {
        ASTNode paramsNode = new ASTNode(SynComponent.FuncRParams, false, null, false);

        ASTNode firstExp = parseExp();
        paramsNode.addChild(firstExp);

        while (currentToken.getType() == Type.COMMA) {
            paramsNode.addChild(new ASTNode(null, false, currentToken, true));
            consume();  // ,
            ASTNode nextExp = parseExp();
            paramsNode.addChild(nextExp);
        }

        return paramsNode;
    }

    private ASTNode parseUnaryOp() {
        ASTNode unaryOpNode = new ASTNode(SynComponent.UnaryOp, true, null, true);

        // 检查当前 token 是否为一元操作符
        if (!judge.isUnaryOp(currentToken)) {
            System.out.println("JUDGEoperror");
        }

        unaryOpNode.addChild(new ASTNode(null, false, currentToken, true));
        consume();
        return unaryOpNode;
    }

    private ASTNode parsePrimaryExp() {
        ASTNode priNode = new ASTNode(SynComponent.PrimaryExp, true, null, true);
        if (currentToken.getType() == Type.LPARENT) {
            priNode.addChild(new ASTNode(null, false, currentToken, true));
            consume();
            ASTNode node = parseExp();
            priNode.addChild(node);
            if (currentToken.getType() == Type.RPARENT) {
                priNode.addChild(new ASTNode(null, false, currentToken, true));
                consume(); // Expecting ')'
            } else {
                hasError = true;
                errors.add(new ErrorInformation(beforeLine(),'j'));
            }
        } else if (currentToken.getType() == Type.INTCON) {
            ASTNode node = new ASTNode(SynComponent.Number,false,null,false);
            node.addChild(new ASTNode(null, false, currentToken, true));
            priNode.addChild(node);
            consume();
        } else if (currentToken.getType() == Type.CHRCON) {
            ASTNode node = new ASTNode(SynComponent.Character,false,null,false);
            node.addChild(new ASTNode(null, false, currentToken, true));
            priNode.addChild(node);
            consume();
        } else {
            ASTNode node =  parseLVal();
            priNode.addChild(node);
        }
        return priNode;
    }


    public boolean hasError() {
        return this.hasError;
    }

    public ASTNode getCompUnitNode() {
        return compUnitNode;
    }

    public ArrayList<ErrorInformation> getErrors() {
        return this.errors;
    }

}