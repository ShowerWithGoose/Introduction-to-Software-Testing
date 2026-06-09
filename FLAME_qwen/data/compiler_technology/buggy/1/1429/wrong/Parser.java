/**
 * Classname Parser
 * Description TODO
 * Date 2024/10/11 15:28
 * Created ZHW
 */
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Parser {
    private List<Token> tokens;
    private Token currentToken;
    private int currentIndex;
    private int nextIndex;
    private int maxIndex;
    public ArrayList<Error> errors;
    private static BufferedWriter right;

    static {
        try {
            right = new BufferedWriter(new FileWriter("parser.txt"));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public Parser(List<Token> tokens) {
        this.tokens = tokens;
        this.currentIndex = 0;
        this.nextIndex = 0;
        this.maxIndex = tokens.size();
        this.currentToken = tokens.get(currentIndex);
        this.errors = new ArrayList<>();
    }

    public ArrayList<Error> getErrors() {
        return errors;
    }

    // 语法解析起点
    public void parseCompUnit() {
        // 解析声明
        while (currentToken != null && (isFuncType(currentToken) || match(TokenType.CONSTTK))) {
            nextIndex = currentIndex;
            if (match(TokenType.CONSTTK)){
                parseDecl();
            }
            else {
                if (nextmatch(currentIndex + 1, TokenType.MAINTK)){
                    parseMainFuncDef();
                } else if (nextmatch(currentIndex + 2, TokenType.LPARENT)) {
                    parseFuncDef();
                } else {
                    parseDecl();
                }
            }
        }

        writeOutput("CompUnit");

        try {
            right.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // 判断是否是基本类型 (BType)
    private boolean isBType(Token token) {
        return token.type == TokenType.INTTK || token.type == TokenType.CHARTK;
    }

    // 判断是否是函数类型
    private boolean isFuncType(Token token) {
        return token.type == TokenType.VOIDTK || token.type == TokenType.INTTK || token.type == TokenType.CHARTK;
    }

    // 解析声明 (Decl)
    private void parseDecl() {
        if (nextmatch(nextIndex, TokenType.CONSTTK)) {
            writeOutputWord();
            nextIndex++;
            parseConstDecl();  // 解析常量声明
            currentIndex = nextIndex;
            if (currentIndex < maxIndex){
                currentToken = tokens.get(currentIndex);
            }else{
                currentToken = null;
            }
        } else if (isBType(tokens.get(nextIndex))) {
            writeOutputWord();
            nextIndex++;
            parseVarDecl();  // 解析变量声明
            currentIndex = nextIndex;
            if (currentIndex < maxIndex){
                currentToken = tokens.get(currentIndex);
            }else{
                currentToken = null;
            }
        }
    }

    // 解析常量声明 (ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';')
    private void parseConstDecl() {
        parseBType();  // 解析基本类型
        parseConstDef();  // 解析常量定义
        while (nextmatch(nextIndex, TokenType.COMMA)) {
            writeOutputWord();
            nextIndex++;
            parseConstDef();  // 解析多个常量定义
        }
        if (nextmatch(nextIndex, TokenType.SEMICN)){
            writeOutputWord();
            nextIndex++;
        }// 匹配分号
        else{
            addError(tokens.get(nextIndex - 1).lineNum, "i");
        }

        writeOutput("ConstDecl");
    }

    private void parseBType() {
        if (isBType(tokens.get(nextIndex))){
            writeOutputWord();
            nextIndex++;
        }
    }

    // 解析常量定义 (ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal)
    private void parseConstDef() {
        if (nextmatch(nextIndex, TokenType.IDENFR)){
            writeOutputWord();
            nextIndex++;
        }
        else{
            addError(currentToken.lineNum, "k");
            return;
        }
        // 匹配标识符

        if (nextmatch(nextIndex, TokenType.LBRACK)) {
            writeOutputWord();
            nextIndex++;
            parseConstExp();  // 解析常量表达式
            if (nextmatch(nextIndex, TokenType.RBRACK)){
                writeOutputWord();
                nextIndex++;
            }
            else{
                addError(tokens.get(nextIndex - 1).lineNum, "k");
            }
        }//数组

        if (nextmatch(nextIndex, TokenType.ASSIGN)){
            writeOutputWord();
            nextIndex++;
        }else{
            addError(currentToken.lineNum, "k");
            return;
        }

        parseConstInitVal();  // 解析常量初值

        writeOutput("ConstDef");
    }

    // 解析常量初值 (ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst)
    private void parseConstInitVal() {
        if (nextmatch(nextIndex, TokenType.LBRACE)) {
            writeOutputWord();
            nextIndex++;
            if (!nextmatch(nextIndex, TokenType.RBRACE)) {
                parseConstExp();
                while (nextmatch(nextIndex, TokenType.COMMA)) {
                    writeOutputWord();
                    nextIndex++;
                    parseConstExp();
                }
                if(nextmatch(nextIndex, TokenType.RBRACE)){
                    writeOutputWord();
                    nextIndex++;
                }
            } else {
                writeOutputWord();
                nextIndex++;
            }
        } else if (nextmatch(nextIndex, TokenType.STRCON)) {
            writeOutputWord();
            nextIndex++;
        } else {
            parseConstExp();  // 解析常量表达式
        }

        writeOutput("ConstInitVal");
    }

    private void parseConstExp() {
        parseAddExp();
        writeOutput("ConstExp");
    }

    // 解析变量声明 (VarDecl → BType VarDef { ',' VarDef } ';')
    private void parseVarDecl() {
        parseBType();  // 解析基本类型
        parseVarDef();  // 解析变量定义
        while (nextmatch(nextIndex, TokenType.COMMA)) {
            writeOutputWord();
            nextIndex++;
            parseVarDef();  // 解析多个变量定义
        }
        if (nextmatch(nextIndex, TokenType.SEMICN)) {
            writeOutputWord();
            nextIndex++;
        } else {
            addError(tokens.get(nextIndex - 1).lineNum, "i");  // 缺少分号
        }

        writeOutput("VarDecl");
    }


    // 解析变量定义 (VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal)
    private void parseVarDef() {
        if (nextmatch(nextIndex, TokenType.IDENFR)) {
            writeOutputWord();
            nextIndex++;
        } else {
            addError(currentToken.lineNum, "k");  // 缺少标识符
            return;
        }
        // 解析数组定义
        if (nextmatch(nextIndex, TokenType.LBRACK)) {
            writeOutputWord();
            nextIndex++;
            parseConstExp();  // 解析常量表达式
            if (nextmatch(nextIndex, TokenType.RBRACK)) {
                writeOutputWord();
                nextIndex++;
            } else {
                addError(tokens.get(nextIndex - 1).lineNum, "k");
            }
        }

        // 解析赋值
        if (nextmatch(nextIndex, TokenType.ASSIGN)) {
            writeOutputWord();
            nextIndex++;
            parseInitVal();  // 解析变量初值
        }

        writeOutput("VarDef");
    }

    // 解析变量初值 (InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst)
    private void parseInitVal() {
        if (nextmatch(nextIndex, TokenType.LBRACE)) {
            writeOutputWord();
            nextIndex++;
            if (!nextmatch(nextIndex, TokenType.RBRACE)) {
                parseExp();
                while (nextmatch(nextIndex, TokenType.COMMA)) {
                    writeOutputWord();
                    nextIndex++;
                    parseExp();
                }
                if (nextmatch(nextIndex, TokenType.RBRACE)) {
                    writeOutputWord();
                    nextIndex++;
                } else {
                    addError(currentToken.lineNum, "i");  // 缺少右大括号
                    return;
                }
            }
        } else if (nextmatch(nextIndex, TokenType.STRCON)) {
            writeOutputWord();
            nextIndex++;
        } else {
            parseExp();  // 解析表达式
        }

        writeOutput("InitVal");
    }

    // 解析表达式 (Exp → AddExp)
    private void parseExp() {
        parseAddExp();  // 解析加减表达式
        writeOutput("Exp");
    }

    // 解析函数定义 (FuncDef → FuncType Ident '(' [FuncFParams] ')' Block)
    private void parseFuncDef() {
        parseFuncType();  // 解析函数类型
        if (nextmatch(nextIndex, TokenType.IDENFR)) {
            writeOutputWord();
            nextIndex++;
        } else {
            addError(currentToken.lineNum, "k");  // 缺少标识符
            return;
        }

        if (nextmatch(nextIndex, TokenType.LPARENT)) {
            writeOutputWord();
            nextIndex++;
        } else {
            addError(currentToken.lineNum, "j");  // 缺少左括号
            return;
        }

        if (!nextmatch(nextIndex, TokenType.RPARENT)) {
            parseFuncFParams();  // 解析函数形参
        }

        if (nextmatch(nextIndex, TokenType.RPARENT)) {
            writeOutputWord();
            nextIndex++;
        } else {
            addError(tokens.get(nextIndex - 1).lineNum, "j");
        }

        parseBlock();  // 解析语句块

        currentIndex = nextIndex;
        if (currentIndex < maxIndex){
            currentToken = tokens.get(currentIndex);
        }else{
            currentToken = null;
        }

        writeOutput("FuncDef");
    }

    // 解析主函数定义 (MainFuncDef → 'int' 'main' '(' ')' Block)
    private void parseMainFuncDef() {
        if (nextmatch(nextIndex, TokenType.INTTK)) {
            writeOutputWord();
            nextIndex++;
        } else {
            addError(currentToken.lineNum, "j");  // 缺少 int 类型
            return;
        }

        if (nextmatch(nextIndex, TokenType.MAINTK)) {
            writeOutputWord();
            nextIndex++;
        } else {
            addError(currentToken.lineNum, "k");  // 缺少 main 标识符
            return;
        }

        if (nextmatch(nextIndex, TokenType.LPARENT)) {
            writeOutputWord();
            nextIndex++;
        } else {
            addError(currentToken.lineNum, "j");  // 缺少左括号
            return;
        }

        if (nextmatch(nextIndex, TokenType.RPARENT)) {
            writeOutputWord();
            nextIndex++;
        } else {
            addError(tokens.get(nextIndex - 1).lineNum, "j");//缺少右括号
        }

        parseBlock();  // 解析语句块

        currentIndex = nextIndex;
        if (currentIndex < maxIndex){
            currentToken = tokens.get(currentIndex);
        }else{
            currentToken = null;
        }

        writeOutput("MainFuncDef");
    }


    // 解析函数类型 (FuncType → 'void' | 'int' | 'char')
    private void parseFuncType() {
        if (nextmatch(nextIndex, TokenType.VOIDTK) || nextmatch(nextIndex, TokenType.INTTK) || nextmatch(nextIndex, TokenType.CHARTK)) {
            writeOutputWord();
            nextIndex++;// 匹配到函数类型
        } else {
            addError(currentToken.lineNum, "j");
        }

        writeOutput("FuncType");
    }

    // 解析函数形参表 (FuncFParams → FuncFParam { ',' FuncFParam })
    private void parseFuncFParams() {
        parseFuncFParam();  // 解析函数形参
        while (nextmatch(nextIndex, TokenType.COMMA)) {
            writeOutputWord();
            nextIndex++;
            parseFuncFParam();  // 解析多个函数形参
        }
        writeOutput("FuncFParams");
    }

    // 解析单个函数形参 (FuncFParam → BType Ident ['[' ']'])
    private void parseFuncFParam() {
        parseBType();  // 解析基本类型
        if (nextmatch(nextIndex, TokenType.IDENFR)) {
            writeOutputWord();
            nextIndex++;
        } else {
            return;
        }

        if (nextmatch(nextIndex, TokenType.LBRACK)) {
            writeOutputWord();
            nextIndex++;
            if (nextmatch(nextIndex, TokenType.RBRACK)) {
                writeOutputWord();
                nextIndex++;
            } else {
                addError(tokens.get(nextIndex - 1).lineNum, "k");//缺少右括号
            }
        }

        writeOutput("FuncFParam");
    }

    // 解析块 (Block → '{' { BlockItem } '}')
    private void parseBlock() {
        if (nextmatch(nextIndex, TokenType.LBRACE)) {
            writeOutputWord();
            nextIndex++;
        } else {
            addError(currentToken.lineNum, "j");  // 缺少左大括号
            return;
        }

        while (!nextmatch(nextIndex, TokenType.RBRACE)) {
            parseBlockItem();  // 解析块内元素（声明或语句）
        }

        if (nextmatch(nextIndex, TokenType.RBRACE)) {
            writeOutputWord();
            nextIndex++;
        } else {
            addError(currentToken.lineNum, "j");  // 缺少右大括号
        }

        writeOutput("Block");
    }

    // 解析块内元素 (BlockItem → Decl | Stmt)
    private void parseBlockItem() {
        if (nextmatch(nextIndex, TokenType.CONSTTK) || nextmatch(nextIndex, TokenType.INTTK) || nextmatch(nextIndex, TokenType.CHARTK)) {
            parseDecl();  // 解析声明
        } else {
            parseStmt();  // 解析语句
        }
    }

    // 解析语句 (Stmt → 多种语句)
    private void parseStmt() {
        if (nextmatch(nextIndex, TokenType.LBRACE)) {
            // Block
            parseBlock();
        } else if (nextmatch(nextIndex, TokenType.IFTK)) {
            // if 语句 (Stmt → 'if' '(' Cond ')' Stmt [ 'else' Stmt ])
            writeOutputWord();
            nextIndex++;
            if (nextmatch(nextIndex, TokenType.LPARENT)) {
                writeOutputWord();
                nextIndex++;
                parseCond();
                if (nextmatch(nextIndex, TokenType.RPARENT)) {
                    writeOutputWord();
                    nextIndex++;
                    parseStmt();  // if 分支语句
                    if (nextmatch(nextIndex, TokenType.ELSETK)) {
                        writeOutputWord();
                        nextIndex++;
                        parseStmt();  // else 分支语句
                    }
                } else {
                    addError(tokens.get(nextIndex - 1).lineNum, "j");//缺少右括号
                }
            } else {
                addError(currentToken.lineNum, "j");  // 缺少左括号
            }
        } else if (nextmatch(nextIndex, TokenType.FORTK)) {
            // for 语句 (Stmt → 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt)
            writeOutputWord();
            nextIndex++;
            if (nextmatch(nextIndex, TokenType.LPARENT)) {
                writeOutputWord();
                nextIndex++;
                if (!nextmatch(nextIndex, TokenType.SEMICN)) {
                    parseForStmt();  // ForStmt 第一个部分
                }
                if (nextmatch(nextIndex, TokenType.SEMICN)) {
                    writeOutputWord();
                    nextIndex++;
                    if (!nextmatch(nextIndex, TokenType.SEMICN)) {
                        parseCond();  // 解析条件表达式
                    }
                    if (nextmatch(nextIndex, TokenType.SEMICN)) {
                        writeOutputWord();
                        nextIndex++;
                        if (!nextmatch(nextIndex, TokenType.RPARENT)) {
                            parseForStmt();  // ForStmt 第二个部分
                        }
                        if (nextmatch(nextIndex, TokenType.RPARENT)) {
                            writeOutputWord();
                            nextIndex++;
                            parseStmt();  // for 循环的主体语句
                        } else {
                            addError(currentToken.lineNum, "j");  // 缺少右括号
                        }
                    }
                }
            }
        } else if (nextmatch(nextIndex, TokenType.BREAKTK)) {
            // break 语句 (Stmt → 'break' ';')
            writeOutputWord();
            nextIndex++;
            if (nextmatch(nextIndex, TokenType.SEMICN)) {
                writeOutputWord();
                nextIndex++;
            } else {
                addError(tokens.get(nextIndex - 1).lineNum, "i");//缺少分号
            }
        } else if (nextmatch(nextIndex, TokenType.CONTINUETK)) {
            // continue 语句 (Stmt → 'continue' ';')
            writeOutputWord();
            nextIndex++;
            if (nextmatch(nextIndex, TokenType.SEMICN)) {
                writeOutputWord();
                nextIndex++;
            } else {
                addError(tokens.get(nextIndex - 1).lineNum, "i");//缺少分号
            }
        } else if (nextmatch(nextIndex, TokenType.RETURNTK)) {
            // return 语句 (Stmt → 'return' [Exp] ';')
            writeOutputWord();
            nextIndex++;
            boolean flag = false;
            int returnLine = tokens.get(nextIndex - 1).lineNum;
            int findIndex = nextIndex;
            while (tokens.get(findIndex).lineNum == returnLine){
                if (tokens.get(findIndex).type == TokenType.SEMICN){
                    flag = true;
                    break;
                }
                findIndex++;
            }
            if (!flag){
                nextIndex = findIndex;
            }
            if (!nextmatch(nextIndex, TokenType.SEMICN) && flag) {
                parseExp();  // 可选的表达式
            }
            if (nextmatch(nextIndex, TokenType.SEMICN)) {
                writeOutputWord();
                nextIndex++;
            } else {
                addError(tokens.get(nextIndex - 1).lineNum, "i");//缺少分号
            }
        } else if (nextmatch(nextIndex, TokenType.PRINTFTK)) {
            // printf 语句 (Stmt → 'printf''('StringConst {','Exp}')'';')
            writeOutputWord();
            nextIndex++;
            if (nextmatch(nextIndex, TokenType.LPARENT)) {
                writeOutputWord();
                nextIndex++;
                if (nextmatch(nextIndex, TokenType.STRCON)) {
                    writeOutputWord();
                    nextIndex++;
                    while (nextmatch(nextIndex, TokenType.COMMA)) {
                        writeOutputWord();
                        nextIndex++;
                        parseExp();  // 解析表达式
                    }
                    if (nextmatch(nextIndex, TokenType.RPARENT)) {
                        writeOutputWord();
                        nextIndex++;
                        if (nextmatch(nextIndex, TokenType.SEMICN)) {
                            writeOutputWord();
                            nextIndex++;
                        } else {
                            addError(tokens.get(nextIndex - 1).lineNum, "i");//缺少分号
                        }
                    } else {
                        addError(tokens.get(nextIndex - 1).lineNum, "j");//缺少右括号
                    }
                } else {
                    addError(currentToken.lineNum, "j");  // 缺少字符串常量
                }
            } else {
                addError(currentToken.lineNum, "j");  // 缺少左括号
            }
        } else {
            // 解析 LVal '=' Exp ';' 或 [Exp] ';'
            if (isLVal(nextIndex)) {
                parseLVal();  // 左值表达式
                if (nextmatch(nextIndex, TokenType.ASSIGN)) {
                    writeOutputWord();
                    nextIndex++;
                    if (nextmatch(nextIndex, TokenType.GETINTTK)) {
                        // LVal '=' 'getint''('')'';'
                        writeOutputWord();
                        nextIndex++;
                        if (nextmatch(nextIndex, TokenType.LPARENT)) {
                            writeOutputWord();
                            nextIndex++;
                            if (nextmatch(nextIndex, TokenType.RPARENT)) {
                                writeOutputWord();
                                nextIndex++;
                                if (nextmatch(nextIndex, TokenType.SEMICN)) {
                                    writeOutputWord();
                                    nextIndex++;
                                } else {
                                    addError(tokens.get(nextIndex - 1).lineNum, "i");//缺少分号
                                }
                            } else {
                                addError(tokens.get(nextIndex - 1).lineNum, "j");//缺少右括号
                            }
                        } else {
                            addError(currentToken.lineNum, "j");  // 缺少左括号
                        }
                    } else if (nextmatch(nextIndex, TokenType.GETCHARTK)) {
                        // LVal '=' 'getchar''('')'';'
                        writeOutputWord();
                        nextIndex++;
                        if (nextmatch(nextIndex, TokenType.LPARENT)) {
                            writeOutputWord();
                            nextIndex++;
                            if (nextmatch(nextIndex, TokenType.RPARENT)) {
                                writeOutputWord();
                                nextIndex++;
                                if (nextmatch(nextIndex, TokenType.SEMICN)) {
                                    writeOutputWord();
                                    nextIndex++;
                                } else {
                                    addError(tokens.get(nextIndex - 1).lineNum, "i");//缺少分号
                                }
                            } else {
                                addError(tokens.get(nextIndex - 1).lineNum, "j");//缺少右括号
                            }
                        } else {
                            addError(currentToken.lineNum, "j");  // 缺少左括号
                        }
                    } else {
                        parseExp();  // 普通赋值语句
                        if (nextmatch(nextIndex, TokenType.SEMICN)) {
                            writeOutputWord();
                            nextIndex++;
                        } else {
                            addError(tokens.get(nextIndex - 1).lineNum, "i");//缺少分号
                        }
                    }
                } else {
                    addError(currentToken.lineNum, "i");  // 缺少等号
                }
            } else {
                if (!nextmatch(nextIndex, TokenType.SEMICN)) {
                    parseExp();  // 可选表达式
                }
                if (nextmatch(nextIndex, TokenType.SEMICN)) {
                    writeOutputWord();
                    nextIndex++;
                } else {
                    addError(tokens.get(nextIndex - 1).lineNum, "i");//缺少分号
                }
            }
        }
        writeOutput("Stmt");
    }

    // 判断是否为 LVal 表达式
    private boolean isLVal(int index) {
        boolean flag = false;
        while(tokens.get(index).type != TokenType.ASSIGN){
            if(tokens.get(index).type == TokenType.SEMICN){
                break;
            }
            index++;
        }
        return tokens.get(index).type == TokenType.ASSIGN;
    }

    // 解析 ForStmt (ForStmt → LVal '=' Exp)
    private void parseForStmt() {
        parseLVal();  // 解析左值表达式
        if (nextmatch(nextIndex, TokenType.ASSIGN)) {
            writeOutputWord();
            nextIndex++;
            parseExp();  // 解析表达式
        } else {
            addError(currentToken.lineNum, "i");  // 缺少等号
        }
        writeOutput("ForStmt");
    }

    // 解析条件表达式 (Cond → LOrExp)
    private void parseCond() {
        parseLOrExp();
        writeOutput("Cond");
    }

    // 解析左值表达式 (LVal → Ident ['[' Exp ']'])
    private void parseLVal() {
        if (nextmatch(nextIndex, TokenType.IDENFR)) {
            writeOutputWord();
            nextIndex++;
        } else {
            addError(currentToken.lineNum, "k");  // 缺少标识符
            return;
        }

        // 解析数组访问
        while (nextmatch(nextIndex, TokenType.LBRACK)) {
            writeOutputWord();
            nextIndex++;
            parseExp();  // 解析表达式
            if (nextmatch(nextIndex, TokenType.RBRACK)) {
                writeOutputWord();
                nextIndex++;
            } else {
                addError(tokens.get(nextIndex - 1).lineNum, "k");//缺少右括号
            }
        }

        writeOutput("LVal");
    }

    // 解析基本表达式 (PrimaryExp → '(' Exp ')' | LVal | Number | Character)
    private void parsePrimaryExp() {
        if (nextmatch(nextIndex, TokenType.LPARENT)) {
            writeOutputWord();
            nextIndex++;
            parseExp();
            if (nextmatch(nextIndex, TokenType.RPARENT)) {
                writeOutputWord();
                nextIndex++;
            } else {
                addError(tokens.get(nextIndex - 1).lineNum, "j");//缺少右括号
            }
        } else if (nextmatch(nextIndex, TokenType.IDENFR)) {
            parseLVal();  // 左值表达式
        } else if (nextmatch(nextIndex, TokenType.INTCON)) {
            parseNumber();  // 数值常量
        } else if (nextmatch(nextIndex, TokenType.CHRCON)) {
            parseCharacter();  // 字符常量
        } else {
            addError(currentToken.lineNum, "j");  // 不合法的基本表达式
        }
        writeOutput("PrimaryExp");
    }

    // 解析数值 (Number → IntConst)
    private void parseNumber() {
        if (nextmatch(nextIndex, TokenType.INTCON)) {
            writeOutputWord();
            nextIndex++;
        } else {
            addError(currentToken.lineNum, "k");  // 缺少数值常量
        }
        writeOutput("Number");
    }

    // 解析字符 (Character → CharConst)
    private void parseCharacter() {
        if (nextmatch(nextIndex, TokenType.CHRCON)) {
            writeOutputWord();
            nextIndex++;
        } else {
            addError(currentToken.lineNum, "k");  // 缺少字符常量
        }
        writeOutput("Character");
    }

    // 解析一元表达式 (UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp)
    private void parseUnaryExp() {
        if (nextmatch(nextIndex, TokenType.IDENFR)) {
            int tempIndex = nextIndex;
            nextIndex++;
            if (nextmatch(nextIndex, TokenType.LPARENT)) {
                int temp = nextIndex;
                nextIndex = tempIndex;
                writeOutputWord();
                nextIndex = temp;
                writeOutputWord();
                nextIndex++;
                boolean flag = false;
                int funcLine = tokens.get(nextIndex).lineNum;
                int findIndex = nextIndex;
                while (tokens.get(findIndex).lineNum == funcLine){
                    if (tokens.get(findIndex).type == TokenType.RPARENT){
                        flag = true;
                        break;
                    }
                    findIndex++;
                }
                if (!flag){
                    nextIndex = findIndex;
                }
                if (!nextmatch(nextIndex, TokenType.RPARENT) && flag) {
                    parseFuncRParams();  // 解析函数实参
                }
                if (nextmatch(nextIndex, TokenType.RPARENT)) {
                    writeOutputWord();
                    nextIndex++;
                } else {
                    addError(tokens.get(nextIndex - 1).lineNum, "j");//缺少右括号
                }
            } else {
                nextIndex = tempIndex;
                parsePrimaryExp();  // 左值或基本表达式
            }
        } else if (isUnaryOp(nextIndex)) {
            parseUnaryOp();  // 解析单目运算符
            parseUnaryExp();  // 递归解析
        } else {
            parsePrimaryExp();  // 基本表达式
        }
        writeOutput("UnaryExp");
    }

    // 判断是否为单目运算符
    private boolean isUnaryOp(int index) {
        return tokens.get(index).type == TokenType.PLUS || tokens.get(index).type == TokenType.MINU || tokens.get(index).type == TokenType.NOT;
    }

    // 解析单目运算符 (UnaryOp → '+' | '−' | '!')
    private void parseUnaryOp() {
        if (isUnaryOp(nextIndex)) {
            writeOutputWord();
            nextIndex++;
        } else {
            addError(currentToken.lineNum, "k");  // 缺少单目运算符
        }
        writeOutput("UnaryOp");
    }

    // 解析函数实参表 (FuncRParams → Exp { ',' Exp })
    private void parseFuncRParams() {
        parseExp();  // 解析第一个实参
        while (nextmatch(nextIndex, TokenType.COMMA)) {
            writeOutputWord();
            nextIndex++;
            parseExp();  // 解析后续实参
        }
        writeOutput("FuncRParams");
    }

    // 解析乘除模表达式 (MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp)
    private void parseMulExp() {
        parseUnaryExp();  // 解析一元表达式
        while (nextmatch(nextIndex, TokenType.MULT) || nextmatch(nextIndex, TokenType.DIV) || nextmatch(nextIndex, TokenType.MOD)) {
            writeOutput("MulExp");
            writeOutputWord();
            nextIndex++;
            parseUnaryExp();  // 递归解析
        }
        writeOutput("MulExp");
    }

    // 解析加减表达式 (AddExp → MulExp | AddExp ('+' | '−') MulExp)
    private void parseAddExp() {
        parseMulExp();  // 解析乘除模表达式
        while (nextmatch(nextIndex, TokenType.PLUS) || nextmatch(nextIndex, TokenType.MINU)) {
            writeOutput("AddExp");
            writeOutputWord();
            nextIndex++;
            parseMulExp();  // 递归解析
        }
        writeOutput("AddExp");
    }

    // 解析关系表达式 (RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp)
    private void parseRelExp() {
        parseAddExp();  // 解析加减表达式
        while (nextmatch(nextIndex, TokenType.LSS) || nextmatch(nextIndex, TokenType.GRE) || nextmatch(nextIndex, TokenType.LEQ) || nextmatch(nextIndex, TokenType.GEQ)) {
            writeOutput("RelExp");
            writeOutputWord();
            nextIndex++;
            parseAddExp();  // 递归解析
        }
        writeOutput("RelExp");
    }

    // 解析相等性表达式 (EqExp → RelExp | EqExp ('==' | '!=') RelExp)
    private void parseEqExp() {
        parseRelExp();  // 解析关系表达式
        while (nextmatch(nextIndex, TokenType.EQL) || nextmatch(nextIndex, TokenType.NEQ)) {
            writeOutput("EqExp");
            writeOutputWord();
            nextIndex++;
            parseRelExp();  // 递归解析
        }
        writeOutput("EqExp");
    }

    // 解析逻辑与表达式 (LAndExp → EqExp | LAndExp '&&' EqExp)
    private void parseLAndExp() {
        parseEqExp();  // 解析相等性表达式
        while (nextmatch(nextIndex, TokenType.AND)) {
            writeOutput("LAndExp");
            writeOutputWord();
            nextIndex++;
            parseEqExp();  // 递归解析
        }
        writeOutput("LAndExp");
    }

    // 解析逻辑或表达式 (LOrExp → LAndExp | LOrExp '||' LAndExp)
    private void parseLOrExp() {
        parseLAndExp();  // 解析逻辑与表达式
        while (nextmatch(nextIndex, TokenType.OR)) {
            writeOutput("LOrExp");
            writeOutputWord();
            nextIndex++;
            parseLAndExp();  // 递归解析
        }
        writeOutput("LOrExp");
    }

    // 检查当前 token 的类型是否匹配
    private boolean match(TokenType expectedType) {
        return currentToken != null && currentToken.type == expectedType;
    }

    private boolean nextmatch(int index, TokenType expectedType) {
        Token target = null;
        boolean flag = false;
        if (tokens.get(index) != null){
            target = tokens.get(index);
            if (target.type == expectedType){
                flag = true;
            }
        }
        return flag;
    }

    private void addError(int line, String message) {
        errors.add(new Error(line, message));
    }

    private void writeOutputWord() {
        Token targetToken = tokens.get(nextIndex);
        try {
            right.write(targetToken.type + " " + targetToken.word);
            right.newLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void writeOutput(String content) {
        try {
            right.write("<" + content + ">");
            right.newLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
