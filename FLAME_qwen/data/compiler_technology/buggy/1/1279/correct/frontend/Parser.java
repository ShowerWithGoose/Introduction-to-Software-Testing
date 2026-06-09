package frontend;

import frontend.Token.Token;
import frontend.Token.TokenType;

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.Writer;
import java.util.*;

public class Parser {
    private Lexer lexer;
    private Token currentToken;
    private Token nextTokenBuffer;      // 用于预览下一个 Token
    private Token nextNextTokenBuffer;  // 用于预览下下个 Token
    private BufferedWriter parserWriter; // 用于输出 parser.txt
    private BufferedWriter errorWriter; // 用于输出 error.txt
    private ErrorHandler errorHandler;

    public Parser(InputStream input, Writer parserWriter, ErrorHandler errorHandler, Writer errorWriter) {
        this.errorHandler = errorHandler;
        this.lexer = new Lexer(input, errorHandler);
        this.currentToken = lexer.getNextToken();
        this.nextTokenBuffer = null;
        this.nextNextTokenBuffer = null;
        this.parserWriter = new BufferedWriter(parserWriter);
        this.errorWriter = new BufferedWriter(errorWriter);
    }

    public void parse() throws IOException {
        parseCompUnit();
        errorHandler.reportErrors(errorWriter);
        parserWriter.flush();
    }


    private void nextToken() {
        if (nextTokenBuffer != null) {
            currentToken = nextTokenBuffer;
            nextTokenBuffer = nextNextTokenBuffer;
            nextNextTokenBuffer = null;
        } else {
            currentToken = lexer.getNextToken();
        }
    }

    private Token peekNextTokenWithoutConsuming() {
        if (nextTokenBuffer == null) {
            nextTokenBuffer = lexer.getNextToken();
        }
        return nextTokenBuffer;
    }

    private Token peekTwoTokensAhead() {
        if (nextTokenBuffer == null) {
            nextTokenBuffer = lexer.getNextToken();
        }
        if (nextNextTokenBuffer == null) {
            nextNextTokenBuffer = lexer.getNextToken();
        }
        return nextNextTokenBuffer;
    }

    private void outputToken(Token token) throws IOException {
        parserWriter.write(token.getType().toString() + " " + token.getLexeme());
        parserWriter.newLine();
    }

    private void outputGrammar(String grammarName) throws IOException {
        parserWriter.write(grammarName);
        parserWriter.newLine();
    }

    private void addError(int lineNumber, char errorCode) {
        errorHandler.addError(lineNumber, errorCode);
    }

    // 判断是否为声明
    private boolean isDecl() {
        if (currentToken.getType() == TokenType.CONSTTK) {
            return true;
        } else if (currentToken.getType() == TokenType.INTTK ||
                currentToken.getType() == TokenType.CHARTK) {
            Token next = peekNextTokenWithoutConsuming();
            if (next != null && next.getType() == TokenType.IDENFR) {
                Token nextNext = peekTwoTokensAhead();
                // 如果不是 '(', 则认为是变量声明
                return nextNext != null && nextNext.getType() != TokenType.LPARENT;
            }
        }
        return false;
    }

    // 判断是否为函数定义
    private boolean isFuncDef() {
        if (currentToken.getType() == TokenType.VOIDTK ||
                currentToken.getType() == TokenType.INTTK ||
                currentToken.getType() == TokenType.CHARTK) {
            Token next = peekNextTokenWithoutConsuming();
            if (next != null && next.getType() == TokenType.IDENFR) {
                Token nextNext = peekTwoTokensAhead();
                // 如果是 '(', 则认为是函数定义
                return nextNext != null && nextNext.getType() == TokenType.LPARENT;
            }
        }
        return false;
    }

    // 判断是否为主函数定义
    private boolean isMainFuncDef() {
        if (currentToken.getType() == TokenType.INTTK) {
            Token next = peekNextTokenWithoutConsuming();
            return next != null && next.getType() == TokenType.MAINTK;
        }
        return false;
    }

    // 解析编译单元
    private void parseCompUnit() throws IOException {
        // CompUnit → {Decl} {FuncDef} MainFuncDef
        while (isDecl()) {
            parseDecl();
        }
        while (isFuncDef()) {
            if (isMainFuncDef()) {
                break;
            } else {
                parseFuncDef();
            }
        }
        parseMainFuncDef();
        outputGrammar("<CompUnit>");
    }

    // 解析声明
    private void parseDecl() throws IOException {
        // Decl → ConstDecl | VarDecl
        if (currentToken.getType() == TokenType.CONSTTK) {
            parseConstDecl();
        } else {
            parseVarDecl();
        }
    }

    // 解析常量声明
    private void parseConstDecl() throws IOException {
        // ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';' // i
        outputToken(currentToken); // const
        nextToken();
        int currentLine = getPreviousTokenLineNumber();
        parseBType();
        parseConstDef();
        while (currentToken.getType() == TokenType.COMMA) {
            outputToken(currentToken);
            nextToken();
            parseConstDef();
        }
        if (currentToken.getType() == TokenType.SEMICN) {
            outputToken(currentToken);
            nextToken();
        } else {
            addError(currentLine, 'i'); // 缺少分号
        }
        outputGrammar("<ConstDecl>");
    }

    // 解析基本类型
    private void parseBType() throws IOException {
        // BType → 'int' | 'char'
        if (currentToken.getType() == TokenType.INTTK || currentToken.getType() == TokenType.CHARTK) {
            outputToken(currentToken);
            nextToken();
        } else {
            // 错误处理
            addError(currentToken.getLineNumber(), 'a'); // 非法字符
            nextToken();
        }
        // 不需要输出 <BType>
    }

    // 解析常量定义
    private void parseConstDef() throws IOException {
        // ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal // k
        if (currentToken.getType() == TokenType.IDENFR) {
            outputToken(currentToken);
            nextToken();
            if (currentToken.getType() == TokenType.LBRACK) {
                outputToken(currentToken);
                nextToken();
                parseConstExp();
                if (currentToken.getType() == TokenType.RBRACK) {
                    outputToken(currentToken);
                    nextToken();
                } else {
                    addError(getPreviousTokenLineNumber(), 'k'); // 缺少 ']'
                }
            }
            if (currentToken.getType() == TokenType.ASSIGN) {
                outputToken(currentToken);
                nextToken();
                parseConstInitVal();
            } else {
                addError(getPreviousTokenLineNumber(), 'k'); // 缺少 '='
            }
            outputGrammar("<ConstDef>");
        } else {
            addError(currentToken.getLineNumber(), 'k'); // 缺少标识符
        }
    }

    // 解析常量初值
    private void parseConstInitVal() throws IOException {
        // ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
        if (currentToken.getType() == TokenType.LBRACE) {
            outputToken(currentToken);
            nextToken();
            if (currentToken.getType() != TokenType.RBRACE) {
                parseConstExp();
                while (currentToken.getType() == TokenType.COMMA) {
                    outputToken(currentToken);
                    nextToken();
                    parseConstExp();
                }
            }
            if (currentToken.getType() == TokenType.RBRACE) {
                outputToken(currentToken);
                nextToken();
            } else {
                addError(getPreviousTokenLineNumber(), 'k'); // 缺少 '}'
            }
            outputGrammar("<ConstInitVal>");
        } else if (currentToken.getType() == TokenType.STRCON) {
            outputToken(currentToken);
            nextToken();
            outputGrammar("<ConstInitVal>");
        } else {
            parseConstExp();
            outputGrammar("<ConstInitVal>");
        }
    }

    // 解析常量表达式
    private void parseConstExp() throws IOException {
        // ConstExp → AddExp
        parseAddExp();
        outputGrammar("<ConstExp>");
        // 需要输出 <ConstExp>
    }

    private void parseCond() throws IOException {
        // Cond → LOrExp
        parseLOrExp();
        outputGrammar("<Cond>");
    }

    private void parseLOrExp() throws IOException {
        // LOrExp → LAndExp { '||' LAndExp }
        parseLAndExp();
        while (currentToken.getType() == TokenType.OR) {
            outputGrammar("<LOrExp>");
            outputToken(currentToken); // 输出 '||'
            nextToken();
            parseLAndExp();
        }
        outputGrammar("<LOrExp>");
    }

    private void parseLAndExp() throws IOException {
        // LAndExp → EqExp { '&&' EqExp }
        parseEqExp();
        while (currentToken.getType() == TokenType.AND) {
            outputGrammar("<LAndExp>");
            outputToken(currentToken); // 输出 '&&'
            nextToken();
            parseEqExp();
        }
        outputGrammar("<LAndExp>");
    }

    private void parseEqExp() throws IOException {
        // EqExp → RelExp { ('==' | '!=') RelExp }
        parseRelExp();
        while (currentToken.getType() == TokenType.EQL ||
                currentToken.getType() == TokenType.NEQ) {
            outputGrammar("<EqExp>");
            outputToken(currentToken); // 输出 '==' 或 '!='
            nextToken();
            parseRelExp();
        }
        outputGrammar("<EqExp>");
    }

    private void parseRelExp() throws IOException {
        // RelExp → AddExp { ('<' | '>' | '<=' | '>=') AddExp }
        parseAddExp();
        outputGrammar("<RelExp>");
        int flag = 0;
        while (currentToken.getType() == TokenType.LSS ||
                currentToken.getType() == TokenType.GRE ||
                currentToken.getType() == TokenType.LEQ ||
                currentToken.getType() == TokenType.GEQ) {
            outputToken(currentToken); // 输出关系运算符
            nextToken();
            parseAddExp();
            flag = 1;
        }
        if (flag == 1) {
            outputGrammar("<RelExp>");
        }
    }

    // 解析变量声明
    private void parseVarDecl() throws IOException {
        // VarDecl → BType VarDef { ',' VarDef } ';' // i
        parseBType();
        int currentLine = getPreviousTokenLineNumber();
        parseVarDef();
        while (currentToken.getType() == TokenType.COMMA) {
            outputToken(currentToken);
            nextToken();
            parseVarDef();
        }
        if (currentToken.getType() == TokenType.SEMICN) {
            outputToken(currentToken);
            nextToken();
        } else {
            addError(currentLine, 'i'); // 缺少分号
        }
        // 需要输出 <VarDecl>
        outputGrammar("<VarDecl>");
    }

    // 解析变量定义
    private void parseVarDef() throws IOException {
        // VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal // k
        if (currentToken.getType() == TokenType.IDENFR) {
            outputToken(currentToken);
            nextToken();
            if (currentToken.getType() == TokenType.LBRACK) {
                outputToken(currentToken);
                nextToken();
                parseConstExp();
                if (currentToken.getType() == TokenType.RBRACK) {
                    outputToken(currentToken);
                    nextToken();
                } else {
                    addError(getPreviousTokenLineNumber(), 'k'); // 缺少 ']'
                }
            }
            if (currentToken.getType() == TokenType.ASSIGN) {
                outputToken(currentToken);
                nextToken();
                parseInitVal();
            }
            outputGrammar("<VarDef>");
        } else {
            addError(currentToken.getLineNumber(), 'k'); // 缺少标识符
        }
    }

    // 解析变量初值
    private void parseInitVal() throws IOException {
        // InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
        if (currentToken.getType() == TokenType.LBRACE) {
            outputToken(currentToken);
            nextToken();
            if (currentToken.getType() != TokenType.RBRACE) {
                parseExp();
                while (currentToken.getType() == TokenType.COMMA) {
                    outputToken(currentToken);
                    nextToken();
                    parseExp();
                }
            }
            if (currentToken.getType() == TokenType.RBRACE) {
                outputToken(currentToken);
                nextToken();
            } else {
                addError(getPreviousTokenLineNumber(), 'k'); // 缺少 '}'
            }
        } else if (currentToken.getType() == TokenType.STRCON) {
            outputToken(currentToken);
            nextToken();
        } else {
            parseExp();
        }
        outputGrammar("<InitVal>");
    }

    // 解析函数定义
    private void parseFuncDef() throws IOException {
        // FuncDef → FuncType Ident '(' [FuncFParams] ')' Block // j
        parseFuncType();
        int currentLine = getPreviousTokenLineNumber();
        if (currentToken.getType() == TokenType.IDENFR) {
            outputToken(currentToken);
            nextToken();
            if (currentToken.getType() == TokenType.LPARENT) {
                outputToken(currentToken);
                nextToken();
                if (currentToken.getType() != TokenType.RPARENT) {
                    if (currentToken.getType() == TokenType.INTTK || currentToken.getType() == TokenType.CHARTK) {
                        parseFuncFParams();
                    } else {
                        addError(currentLine, 'j'); // 缺少 ')'
                        while (currentToken.getType() != TokenType.LBRACE &&
                                currentToken.getType() != TokenType.EOF) {
                            nextToken();
                        }
                        parseBlock();
                        outputGrammar("<FuncDef>");
                        return;
                    }
                }
                if (currentToken.getType() == TokenType.RPARENT) {
                    outputToken(currentToken);
                    nextToken();
                } else {
                    addError(currentLine, 'j'); // 缺少 ')'
                    while (currentToken.getType() != TokenType.LBRACE &&
                            currentToken.getType() != TokenType.EOF) {
                        nextToken();
                    }
                }
                parseBlock();
                outputGrammar("<FuncDef>");

            } else {
                addError(currentLine, 'j'); // 缺少 '('
            }
        } else {
            addError(currentToken.getLineNumber(), 'k'); // 缺少标识符
        }
    }

    // 解析函数类型
    private void parseFuncType() throws IOException {
        // FuncType → 'void' | 'int' | 'char'
        if (currentToken.getType() == TokenType.VOIDTK ||
                currentToken.getType() == TokenType.INTTK ||
                currentToken.getType() == TokenType.CHARTK) {
            outputToken(currentToken);
            nextToken();
        } else {
            // 错误处理
            addError(currentToken.getLineNumber(), 'a'); // 非法字符
            nextToken();
        }
        outputGrammar("<FuncType>");
    }

    // 解析函数形参表
    private void parseFuncFParams() throws IOException {
        // FuncFParams → FuncFParam { ',' FuncFParam }
        parseFuncFParam();
        while (currentToken.getType() == TokenType.COMMA) {
            outputToken(currentToken);
            nextToken();
            parseFuncFParam();
        }
        outputGrammar("<FuncFParams>");

    }

    // 解析函数形参
    private void parseFuncFParam() throws IOException {
        // FuncFParam → BType Ident ['[' ']'] // k
        parseBType();
        if (currentToken.getType() == TokenType.IDENFR) {
            outputToken(currentToken);
            nextToken();
            if (currentToken.getType() == TokenType.LBRACK) {
                outputToken(currentToken);
                nextToken();
                if (currentToken.getType() == TokenType.RBRACK) {
                    outputToken(currentToken);
                    nextToken();
                } else {
                    addError(getPreviousTokenLineNumber(), 'k'); // 缺少 ']'
                }
            }
            // 需要输出 <FuncFParam>
            outputGrammar("<FuncFParam>");
        } else {
            addError(currentToken.getLineNumber(), 'k'); // 缺少标识符
        }
    }

    // 解析语句块
    private void parseBlock() throws IOException {
        // Block → '{' { BlockItem } '}'
        if (currentToken.getType() == TokenType.LBRACE) {
            outputToken(currentToken);
            nextToken();
            while (currentToken.getType() != TokenType.RBRACE &&
                    currentToken.getType() != TokenType.EOF) {
                parseBlockItem();
            }
            if (currentToken.getType() == TokenType.RBRACE) {
                outputToken(currentToken);
                nextToken();
            } else {
                addError(getPreviousTokenLineNumber(), 'i'); // 缺少 '}'
            }
            outputGrammar("<Block>");
        } else {
            // 错误处理
            addError(currentToken.getLineNumber(), 'a'); // 非法字符
            nextToken();
        }
    }

    // 解析语句块项
    private void parseBlockItem() throws IOException {
        // BlockItem → Decl | Stmt
        if (isDecl()) {
            parseDecl();
        } else {
            parseStmt();
        }
        // 不需要输出 <BlockItem>
    }

    private void parseEmptyStmt() throws IOException {
        // 空语句
        outputToken(currentToken);
        nextToken();
        outputGrammar("<Stmt>");
    }

    private void parseBlockStmt() throws IOException {
        // 复合语句块
        parseBlock();
        outputGrammar("<Stmt>");
    }

    private void parseIfStmt(int currentLine) throws IOException {
        // 处理 if 语句
        outputToken(currentToken);
        nextToken();
        if (currentToken.getType() == TokenType.LPARENT) {
            outputToken(currentToken);
            nextToken();
            parseCond();
            if (currentToken.getType() == TokenType.RPARENT) {
                outputToken(currentToken);
                nextToken();
            } else {
                addError(currentLine, 'j'); // 缺少 ')'
            }
            parseStmt();
            if (currentToken.getType() == TokenType.ELSETK) {
                outputToken(currentToken);
                nextToken();
                parseStmt();
            }
            outputGrammar("<Stmt>");
        } else {
            addError(currentLine, 'j'); // 缺少 '(' 并不能完全处理所有情况，但是保证不会有这种情况
        }
    }

    private void parseReturnStmt(int currentLine) throws IOException {
        outputToken(currentToken);
        nextToken();
        if (currentToken.getType() != TokenType.SEMICN) {
            int currentLine2 = getPreviousTokenLineNumber();
            if (currentLine == currentLine2) {
                parseExp();
            } else {
                addError(currentLine, 'i');
                return;
            }
        }
        if (currentToken.getType() == TokenType.SEMICN) {
            outputToken(currentToken);
            nextToken();
        } else {
            addError(currentLine, 'i'); // 缺少 ';'
        }
        outputGrammar("<Stmt>");
    }

    //处理printf语句
    private void parsePrintfStmt(int currentLine) throws IOException {
        outputToken(currentToken);
        nextToken();
        if (currentToken.getType() == TokenType.LPARENT) {
            outputToken(currentToken);
            nextToken();
            if (currentToken.getType() == TokenType.STRCON) {
                outputToken(currentToken);
                nextToken();
                while (currentToken.getType() == TokenType.COMMA) {
                    outputToken(currentToken);
                    nextToken();
                    parseExp();
                }
            }
            if (currentToken.getType() == TokenType.RPARENT) {
                outputToken(currentToken);
                nextToken();
            } else {
                addError(currentLine, 'j'); // 缺少 ')'
            }
            if (currentToken.getType() == TokenType.SEMICN) {
                outputToken(currentToken);
                nextToken();
            } else {
                addError(currentLine, 'i'); // 缺少 ';'
            }
            outputGrammar("<Stmt>");
        } else {
            addError(currentLine, 'j'); // 缺少 '('
        }
    }
    private void parseAssignmentOrFunctionCallStmt(int currentLine) throws IOException {
        Token next = peekNextTokenWithoutConsuming();
        if (next != null) {
            switch (next.getType()) {
                case ASSIGN -> parseAssignmentStmt(currentLine);
                case LPARENT -> parseFunctionCallStmt(currentLine);
                case LBRACK -> parseArrayAssignmentStmt(currentLine);
                default -> parseExpressionStmt(currentLine);
            }
        } else {
            // 无法预读下一个 Token，按表达式语句处理
            parseExpressionStmt(currentLine);
        }
    }

    private void parseAssignmentStmt(int currentLine) throws IOException {
        parseLVal(); // 解析左值
        if (currentToken.getType() == TokenType.ASSIGN) {
            outputToken(currentToken); // 输出 '='
            nextToken();

            if (currentToken.getType() == TokenType.GETCHARTK || currentToken.getType() == TokenType.GETINTTK) {
                parseGetExp(); // 解析 getint/getchar 表达式
            } else {
                parseExp(); // 解析表达式
            }

            if (currentToken.getType() == TokenType.SEMICN) {
                outputToken(currentToken); // 输出 ';'
                nextToken();
            } else {
                addError(currentLine, 'i'); // 缺少 ';'
            }
        }
        outputGrammar("<Stmt>");
    }

    private void parseArrayAssignmentStmt(int currentLine) throws IOException {
        parseLVal();
        if (currentToken.getType() == TokenType.ASSIGN) {
            outputToken(currentToken);
            nextToken();
            if (currentToken.getType() == TokenType.GETCHARTK || currentToken.getType() == TokenType.GETINTTK) {
                parseGetExp();
            } else {
                parseExp();
            }
            if (currentToken.getType() == TokenType.SEMICN) {
                outputToken(currentToken);
                nextToken();
            } else {
                addError(currentLine, 'i'); // 缺少 ';'
            }
            outputGrammar("<Stmt>");
        } else if (currentToken.getType() == TokenType.SEMICN) {
            outputGrammar("<PrimaryExp>");
            outputGrammar("<UnaryExp>");
            outputGrammar("<MulExp>");
            outputGrammar("<AddExp>");
            outputGrammar("<Exp>");
            outputToken(currentToken);
            nextToken();
            outputGrammar("<Stmt>");
        } else {
            addError(currentLine, 'i'); // 缺少 ';'
        }
    }

    private void parseFunctionCallStmt(int currentLine) throws IOException {
        // 函数调用语句
        parseExp();
        if (currentToken.getType() == TokenType.SEMICN) {
            outputToken(currentToken);
            nextToken();
        } else {
            addError(currentLine, 'i'); // 缺少 ';'
        }
        outputGrammar("<Stmt>");
    }

    private void parseExpressionStmt(int currentLine) throws IOException {
        // 无法预读下一个 Token，按表达式语句处理
        // 其他情况，可能是表达式语句
        if (currentToken.getType() != TokenType.SEMICN) {
            parseExp();
        }
        if (currentToken.getType() == TokenType.SEMICN) {
            outputToken(currentToken);
            nextToken();
        } else {
            addError(currentLine, 'i'); // 缺少 ';'
        }
        outputGrammar("<Stmt>");
    }

    private void parseGetStmt(int currentLine) throws IOException {
        // 处理 getint() 或 getchar() 函数调用语句
        parseGetExp();
        if (currentToken.getType() == TokenType.SEMICN) {
            outputToken(currentToken);
            nextToken();
        } else {
            addError(currentLine, 'i'); // 缺少 ';'
        }
        outputGrammar("<Stmt>");
    }

    private void parseForLoopStmt(int currentLine) throws IOException {
        outputToken(currentToken);
        nextToken();
        // 递归解析下一语句
        if (currentToken.getType() == TokenType.LPARENT) {
            outputToken(currentToken);
            nextToken();
            if (currentToken.getType() != TokenType.SEMICN) {
                parseForStmt(); // First ForStmt
                if (currentToken.getType() != TokenType.SEMICN) {
                    addError(currentLine, 'i'); // 缺少 ';'
                }
            }

            if (currentToken.getType() == TokenType.SEMICN) {
                outputToken(currentToken);
                nextToken();
            } else {
                addError(currentLine, 'i'); // 缺少 ';'
            }

            if (currentToken.getType() != TokenType.SEMICN) {
                parseCond(); // 条件表达式
            }

            // 解析第二个分号 ';'
            if (currentToken.getType() == TokenType.SEMICN) {
                outputToken(currentToken);
                nextToken();
            } else {
                addError(currentLine, 'i'); // 缺少 ';'
            }
            // 解析 ForLoop（循环部分）：可以为空或表达式
            if (currentToken.getType() != TokenType.RPARENT) {
                parseForStmt(); // Second FormStmt
            }

            // 解析右括号 ')'
            if (currentToken.getType() == TokenType.RPARENT) {
                outputToken(currentToken);
                nextToken();
            } else {
                addError(currentLine, 'j'); // 缺少 ')'
            }
            // 解析 for 循环体
        } else {
            addError(currentLine, 'j'); // 缺少 '('
            // 跳过直到遇到 '{' 或其他语句起始符
            while (currentToken.getType() != TokenType.LBRACE &&
                    currentToken.getType() != TokenType.IFTK &&
                    currentToken.getType() != TokenType.FORTK &&
                    currentToken.getType() != TokenType.RETURNTK &&
                    currentToken.getType() != TokenType.PRINTFTK &&
                    currentToken.getType() != TokenType.IDENFR &&
                    currentToken.getType() != TokenType.SEMICN &&
                    currentToken.getType() != TokenType.EOF) {
                nextToken();
            }
        }
        parseStmt();
        outputGrammar("<Stmt>");
    }

    private void parseBreakStmt(int currentLine) throws IOException {
        outputToken(currentToken); // 输出 'break' Token
        nextToken();
        if (currentToken.getType() == TokenType.SEMICN) {
            outputToken(currentToken); // 输出 ';' Token
            nextToken();
        } else {
            addError(currentLine, 'i'); // 缺少 ';'
        }
        outputGrammar("<Stmt>");
    }

    private void parseContinueStmt(int currentLine) throws IOException {
        outputToken(currentToken); // 输出 'break' Token
        nextToken();
        if (currentToken.getType() == TokenType.SEMICN) {
            outputToken(currentToken); // 输出 ';' Token
            nextToken();
        } else {
            addError(currentLine, 'i'); // 缺少 ';'
        }
        outputGrammar("<Stmt>");
    }

    // 解析语句
    private void parseStmt() throws IOException {
        int currentLine = getPreviousTokenLineNumber();
        switch (currentToken.getType()) {
            case SEMICN ->
                // 空语句
                    parseEmptyStmt();
            case LBRACE ->
                // 复合语句块
                    parseBlockStmt();
            case IFTK ->
                // 处理 if 语句
                    parseIfStmt(currentLine);
            case RETURNTK ->
                // 处理 return 语句
                    parseReturnStmt(currentLine);
            case PRINTFTK ->
                // 处理 printf 语句
                    parsePrintfStmt(currentLine);
            case IDENFR ->
                // 可能是赋值语句或函数调用语句
                    parseAssignmentOrFunctionCallStmt(currentLine);
            case GETINTTK, GETCHARTK ->
                // 处理 getint() 或 getchar() 函数调用语句
                    parseGetStmt(currentLine);
            case FORTK ->
                // 处理 for 循环语句
                    parseForLoopStmt(currentLine);
            case CONTINUETK ->
                // 处理 continue 语句
                    parseContinueStmt(currentLine);
            case BREAKTK ->
                // 处理 break 语句
                    parseBreakStmt(currentLine);
            default ->
                // 其他情况，可能是表达式语句
                    parseExpressionStmt(currentLine);
        }
    }


    private void parseForStmt() throws IOException {
        // 解析左值
        parseLVal();
        // 解析赋值运算符 '='
        if (currentToken.getType() == TokenType.ASSIGN) {
            outputToken(currentToken); // 输出 '=' Token
            nextToken();
        } else {
            addError(getPreviousTokenLineNumber(), 'k'); // 缺少 '='
        }
        // 解析表达式
        parseExp();
        // 生成 <ForStmt> 语法节点
        outputGrammar("<ForStmt>");
    }

    // 解析表达式
    private void parseExp() throws IOException {
        // Exp → AddExp
        parseAddExp();
        outputGrammar("<Exp>");
    }

    private void parseGetExp() throws IOException {
        // Exp → AddExp;
        parseUnaryExp();
    }

    // 解析加减表达式
    private void parseAddExp() throws IOException {
        // AddExp → MulExp { ('+' | '−') MulExp }
        parseMulExp();
        while (currentToken.getType() == TokenType.PLUS ||
                currentToken.getType() == TokenType.MINU) {
            outputGrammar("<AddExp>");
            outputToken(currentToken);
            nextToken();
            parseMulExp();
        }
        outputGrammar("<AddExp>");
    }

    // 解析乘除模表达式
    private void parseMulExp() throws IOException {
        // MulExp → UnaryExp { ('*' | '/' | '%') UnaryExp }
        parseUnaryExp();
        while (currentToken.getType() == TokenType.MULT ||
                currentToken.getType() == TokenType.DIV ||
                currentToken.getType() == TokenType.MOD) {
            outputGrammar("<MulExp>");
            outputToken(currentToken);
            nextToken();
            parseUnaryExp();
        }
        outputGrammar("<MulExp>");
    }

    // 解析一元表达式
    private void parseUnaryExp() throws IOException {
        // UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp // j
        if (currentToken.getType() == TokenType.PLUS ||
                currentToken.getType() == TokenType.MINU ||
                currentToken.getType() == TokenType.NOT) {
            parseUnaryOp();
            parseUnaryExp();
            outputGrammar("<UnaryExp>");
        } else if (currentToken.getType() == TokenType.IDENFR ||
                currentToken.getType() == TokenType.GETINTTK ||
                currentToken.getType() == TokenType.GETCHARTK ||
                currentToken.getType() == TokenType.PRINTFTK) {
            // 处理函数调用或变量
            Token identToken = currentToken;
            Token next = peekNextTokenWithoutConsuming();
            int currentLine = getPreviousTokenLineNumber();
            if (next != null && next.getType() == TokenType.LPARENT) {
                // 函数调用
                outputToken(currentToken); // Ident or GETINTTK, etc.
                nextToken();
                outputToken(currentToken); // '('
                nextToken();
                if (currentToken.getType() != TokenType.RPARENT) {
                    if (currentToken.getType() == TokenType.SEMICN) {
                        addError(currentLine, 'j'); // 缺少 ')'
                        return;
                    }
                    parseFuncRParams();
                }
                if (currentToken.getType() == TokenType.RPARENT) {
                    outputToken(currentToken);
                    nextToken();
                } else {
                    addError(currentLine, 'j'); // 缺少 ')'
                }
                if (identToken.getType() == TokenType.IDENFR || identToken.getType() == TokenType.PRINTFTK) {
                    outputGrammar("<UnaryExp>");
                }
            } else {
                // 变量
                parsePrimaryExp();
                outputGrammar("<UnaryExp>");
            }
        } else {
            parsePrimaryExp();
            outputGrammar("<UnaryExp>");
        }
    }

    // 解析单目操作符
    private void parseUnaryOp() throws IOException {
        // UnaryOp → '+' | '−' | '!'
        if (currentToken.getType() == TokenType.PLUS ||
                currentToken.getType() == TokenType.MINU ||
                currentToken.getType() == TokenType.NOT) {
            outputToken(currentToken);  // 输出操作符 Token
            nextToken();                // 移动到下一个 Token
            outputGrammar("<UnaryOp>"); // 输出 <UnaryOp> 语法节点
        } else {
            // 非法的一元操作符
            addError(currentToken.getLineNumber(), 'm'); // 假设 'm' 代表非法的一元操作符
            nextToken(); // 跳过非法操作符
        }
    }


    // 解析主表达式
    private void parsePrimaryExp() throws IOException {
        // PrimaryExp → '(' Exp ')' | LVal | Number | Character //
        int currentLine = getPreviousTokenLineNumber();
        if (currentToken.getType() == TokenType.LPARENT) {
            outputToken(currentToken);
            nextToken();
            parseExp();
            if (currentToken.getType() == TokenType.RPARENT) {
                outputToken(currentToken);
                nextToken();
            } else {
                addError(currentLine, 'j'); // 缺少 ')'
            }
            outputGrammar("<PrimaryExp>");
        } else if (currentToken.getType() == TokenType.IDENFR ||
                currentToken.getType() == TokenType.GETINTTK ||
                currentToken.getType() == TokenType.GETCHARTK) {
            // 处理标识符或内置函数
            Token next = peekNextTokenWithoutConsuming();
            if (next != null && next.getType() == TokenType.LPARENT) {
                // 函数调用
                parseUnaryExp();
            } else {
                parseLVal();
            }
            outputGrammar("<PrimaryExp>");
        } else if (currentToken.getType() == TokenType.INTCON) {
            outputToken(currentToken);
            nextToken();
            outputGrammar("<Number>");
            outputGrammar("<PrimaryExp>");
        } else if (currentToken.getType() == TokenType.CHRCON) {
            outputToken(currentToken);
            nextToken();
            outputGrammar("<Character>");
            outputGrammar("<PrimaryExp>");
        } else {
            // 错误处理
            addError(currentToken.getLineNumber(), 'a'); // 非法字符
            nextToken();
        }
    }


    // 解析左值表达式
    private void parseLVal() throws IOException {
        // LVal → Ident ['[' Exp ']']
        if (currentToken.getType() == TokenType.IDENFR) {
            outputToken(currentToken);
            nextToken();
            if (currentToken.getType() == TokenType.LBRACK) {
                outputToken(currentToken);
                nextToken();
                parseExp();
                if (currentToken.getType() == TokenType.RBRACK) {
                    outputToken(currentToken);
                    nextToken();
                } else {
                    addError(getPreviousTokenLineNumber(), 'k'); // 缺少 ']'
                }
            }
            outputGrammar("<LVal>");
        } else {
            addError(currentToken.getLineNumber(), 'k'); // 缺少标识符
        }
    }

    // 解析函数实参表
    private void parseFuncRParams() throws IOException {
        // FuncRParams → Exp { ',' Exp }
        parseExp();
        while (currentToken.getType() == TokenType.COMMA) {
            outputToken(currentToken);
            nextToken();
            parseExp();
        }
        outputGrammar("<FuncRParams>");

    }

    // 解析主函数定义
    private void parseMainFuncDef() throws IOException {
        // MainFuncDef → 'int' 'main' '(' ')' Block
        int currentLine = getPreviousTokenLineNumber();
        if (currentToken.getType() == TokenType.INTTK) {
            outputToken(currentToken);
            nextToken();
            if (currentToken.getType() == TokenType.MAINTK) {
                outputToken(currentToken);
                nextToken();
                if (currentToken.getType() == TokenType.LPARENT) {
                    outputToken(currentToken);
                    nextToken();
                    if (currentToken.getType() == TokenType.RPARENT) {
                        outputToken(currentToken);
                        nextToken();
                    } else {
                        addError(currentLine, 'j'); // 缺少 ')'
                        while (currentToken.getType() != TokenType.LBRACE &&
                                currentToken.getType() != TokenType.EOF) {
                            nextToken();
                        }
                    }
                    parseBlock();
                    outputGrammar("<MainFuncDef>");
                } else {
                    addError(currentLine, 'j'); // 缺少 '('
                }
            } else {
                addError(currentLine, 'j'); // 缺少 'main'
            }
        } else {
            addError(currentToken.getLineNumber(), 'j'); // 缺少 'int'
        }
    }

    // 获取上一个 Token 的行号
    private int getPreviousTokenLineNumber() {
        return currentToken.getLineNumber();
    }

}
