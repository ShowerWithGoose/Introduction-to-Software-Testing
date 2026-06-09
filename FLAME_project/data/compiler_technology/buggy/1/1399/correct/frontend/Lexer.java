/********************************************************************************
 * @FileName     : Lexer.java
 * @Author       :
 * @Description  : 词法分析器类
 * @Notice       : None
 * @Time         : 2024-10-03 18:46
 * @Version      : 0.0
 ********************************************************************************/

package frontend;

import java.util.ArrayList;
import java.util.Objects;

import error.ErrorHandler;
import error.ErrorType;
import debug.Debug;
import type.LexType;

public class Lexer {
    private final ArrayList<Token> tokens; // 用于存储分析得到的词法单元
    private StringBuilder currentToken; // 用于构建当前正在分析的词法单元
    private String sourceCode; // 存储要分析的源代码
    private int codeLength; // 源代码长度
    private int pointer; // 表示当前分析的位置
    private int lineNumber; // 当前的行号
//    public static HashMap<String, LexType> keyTokenMap = new HashMap<String, LexType>() {{
//        put("main", LexType.MAINTK);
//        put("const", LexType.CONSTTK);
//        put("int", LexType.INTTK);
//        put("char", LexType.CHARTK);
//        put("break", LexType.BREAKTK);
//        put("continue", LexType.CONTINUETK);
//        put("if", LexType.IFTK);
//        put("else", LexType.ELSETK);
//        put("for", LexType.FORTK);
//        put("getint", LexType.GETINTTK);
//        put("getchar", LexType.GETCHARTK);
//        put("printf", LexType.PRINTFTK);
//        put("return", LexType.RETURNTK);
//        put("void", LexType.VOIDTK);
//        put("+", LexType.PLUS);
//        put("-", LexType.MINU);
//        put("!", LexType.NOT);
//        put("&&", LexType.AND);
//        put("||", LexType.OR);
//        put("*", LexType.MULT);
//        put("/", LexType.DIV);
//        put("%", LexType.MOD);
//        put("<", LexType.LSS);
//        put("<=", LexType.LEQ);
//        put(">", LexType.GRE);
//        put(">=", LexType.GEQ);
//        put("==", LexType.EQL);
//        put("!=", LexType.NEQ);
//        put("=", LexType.ASSIGN);
//        put(";", LexType.SEMICN);
//        put(",", LexType.COMMA);
//        put("(", LexType.LPARENT);
//        put(")", LexType.RPARENT);
//        put("[", LexType.LBRACK);
//        put("]", LexType.RBRACK);
//        put("{", LexType.LBRACE);
//        put("}", LexType.RBRACE);
//    }}; // 存储Sys语言的保留字和对应的类别码

    public Lexer() {
        // 初始化
        tokens = new ArrayList<>();
        lineNumber = 1;
        pointer = 0;
        sourceCode = "";
    }


    public void lexerPanic() {
        // 在debug模式下显示错误信息（错误行位置）
        Debug.panic("Error during lexical analysis at line " + lineNumber);
    }

    public void lexerPanic(String info) {
        // 在debug模式下显示错误信息（错误行位置）
        Debug.panic("Error during lexical analysis at line " + lineNumber + "\n    " + info);
    }


    public void analyze(String sourceCode) {
        // 分析传入的源代码字符串，生成词法单元
        setPointer(0);
        setLineNumber(1); // 从第一行开始分析
        setSourceCode(sourceCode);
        setCodeLength(sourceCode.length()); // 源代码长度
        while (this.pointer < this.codeLength) {
            this.currentToken = new StringBuilder();
            LexType currentTokenType = getNextToken(); // 当前词法单元的类型
            if (LexType.isValid(currentTokenType)) {
                tokens.add(new Token(currentTokenType, currentToken.toString(), lineNumber));
            }
            else if (!currentTokenType.isOtherType()) {
                // todo 错误处理：不存在的类型
                lexerPanic(currentToken.toString());
            }
        }
    }

    public LexType getNextToken() {
        // 获取下一个词法单元
        LexType tokenType = null;
        while (isWhitespace(pointer) || isTab(pointer) || isNewLine()) {
            if (isNewLine()) {
                if (isValidPointer(pointer + 1) && getCurrentChar() == '\r' && getNextChar() == '\n')
                    pointer += 2;
                else pointer += 1;
                lineNumber++;
            }
            else pointer++;
        }
        if (isLetter(pointer)) { // 标识符
            while (isLetter(pointer) || isDigit(pointer)) {
                handleTokenChar();
            }
            tokenType = LexType.keyTokenMap.getOrDefault(currentToken.toString(), LexType.IDENFR);
        }
        else if (isSingleQuote(pointer)) { // 字符常量
            tokenType = handleChar();
        }
        else if (isDigit(pointer)) { // 数字
            while (isDigit(pointer)) {
                handleTokenChar();
            }
            // todo 优化
            if (currentToken.toString().length() > 1 && currentToken.toString().charAt(0) == '0') {
                // 0开头的数字不合法
                lexerPanic();
            }
            tokenType = LexType.INTCON;
        }
        else if (isDoubleQuote(pointer)) { // "
            tokenType = handleString();
        }
        else if (isSlash(pointer)) { // /
            tokenType = handleSlash();
        }
        else {
            tokenType = handleSymbol();
        }
        return Objects.requireNonNullElse(tokenType, LexType.ERROR);
    }

    private void handleTokenChar() {
        currentToken.append(getCurrentChar());
        pointer++;
    }

    // 处理字符常量
    private LexType handleChar() {
        int flag = 0;
        handleTokenChar();
        if (isValidPointer()) {
            char ch = getCurrentChar();
            if (ch <= 126 && ch >= 32) {
                if (ch == '\\') {
                    handleTokenChar();
                }
                handleTokenChar();
                if (isSingleQuote(pointer)) {
                    handleTokenChar();
                    flag = 1;
                }
            }
        }
        if (flag == 1) return LexType.CHRCON;
        else {
            lexerPanic();
            return LexType.ERROR;
        }
    }

    // 处理字符串常量
    private LexType handleString() {
        handleTokenChar();
        while (isValidPointer()) {
            char ch = getCurrentChar();
            handleTokenChar();
            if (ch == '\\') {
                handleTokenChar();
            }
            else if (ch == '\"') {
                break;
            }
        }
        return LexType.STRCON;
    }

    // 处理各种其他符号
    private LexType handleSymbol() {
        char ch = getCurrentChar();
        handleTokenChar();
        if ((isDoubleEquals(pointer - 1)
                || isLeftAngleBracket(pointer - 1)
                || isRightAngleBracket(pointer - 1)
                || isExclamationMark(pointer - 1))
                && isDoubleEquals(pointer)) {
            handleTokenChar();
        }
        else if (ch == '&' || ch == '|') { // & 或者 |
            if (getCurrentChar() == ch) {
                handleTokenChar();
            }
            else {
                // todo 解决错误
                currentToken.append(ch);
                pointer++;
                ErrorHandler.recordError(ErrorType.ILLEGAL_SYM, lineNumber);
            }
        }
        return LexType.keyTokenMap.getOrDefault(currentToken.toString(), LexType.ERROR);
    }

    // 处理 / 开头的内容
    private LexType handleSlash() {
        pointer++;
        if (isSlash(pointer)) { // 单行注释
            while (!isNewLine()) {
                pointer++;
            }
            // todo 研究换行符
            if (isValidPointer(pointer + 1) && getCurrentChar() == '\r' && getNextChar() == '\n')
                pointer++;
            lineNumber += 1;
            pointer++; // 跳过换行符
            return LexType.ANNOTATION;
        }
        else if (isAsterisk(pointer)) { // 多行注释
            int flag = 0;
            pointer++;
            while (isValidPointer()) {
                if (isNewLine()) {
                    lineNumber += 1;
                    if (isValidPointer(pointer + 1) && getCurrentChar() == '\r' && getNextChar() == '\n')
                        pointer++;
                }
                else if (isAsterisk(pointer)) {
                    if (isValidPointer(pointer + 1) && getNextChar() == '/') {
                        pointer += 2;
                        flag = 1;
                        break;
                    }
                }
                pointer++;
            }
            if (0 == flag) { // 源代码提前完结
                lexerPanic();
                return LexType.ERROR;
            }
            else {
                return LexType.ANNOTATION;
            }
        }
        else { // 除法
            currentToken.append(sourceCode.charAt(pointer - 1));
            return LexType.DIV;
        }
    }


    public String lexerResult() {
        StringBuilder output = new StringBuilder();
        for (Token token : tokens) {
            output.append(token.toString()).append("\n");
        }
        return output.toString();
    }

    // 判断当前指针位置是否在有效范围内
    public boolean isValidPointer() {
        return pointer < sourceCode.length();
    }

    // 判断指定位置是否在有效范围内
    public boolean isValidPointer(int pos) {
        return 0 <= pos && pos < sourceCode.length();
    }

    // 获取当前字符
    public char getCurrentChar() {
        if (isValidPointer()) {
            return sourceCode.charAt(pointer);
        }
        else return '\0';
    }

    // 获取下一个字符
    public char getNextChar() {
        if (isValidPointer(pointer + 1))
            return sourceCode.charAt(pointer + 1);
        else return '\0';
    }


    public boolean isWhitespace(int pos) {
        // 判断指针位置是否为空格
        return this.isValidPointer(pos) && sourceCode.charAt(pos) == ' ';
    }

    // todo 换行符问题
    public boolean isNewLine() {
        // 判断指针位置是否为换行符
        return (this.isValidPointer() && (getCurrentChar() == '\n' || getCurrentChar() == '\r'));
    }

    public boolean isTab(int pos) {
        // 判断指针位置是否为制表符
        return this.isValidPointer(pos) && sourceCode.charAt(pos) == '\t';
    }

    public boolean isLetter(int pos) {
        // 判断指针位置是否为字母或下划线
        // note 不使用 Character.isLetter ，因为其会将汉字看做字母！
        return this.isValidPointer(pos) &&
                (Character.isUpperCase(sourceCode.charAt(pos))
                        || Character.isLowerCase(sourceCode.charAt(pos))
                        || sourceCode.charAt(pos) == '_');
    }

    // 是否为纯字母
    public boolean isPureLetter(int pos) {
        return this.isValidPointer(pos) &&
                (Character.isUpperCase(sourceCode.charAt(pos)) || Character.isLowerCase(sourceCode.charAt(pos)));
    }

    public boolean isDigit(int pos) {
        // 判断指针位置是否为数字
        return this.isValidPointer(pos) && Character.isDigit(sourceCode.charAt(pos));
    }

    public boolean isSemicolon(int pos) {
        // 判断指针位置是否为分号
        return this.isValidPointer(pos) && sourceCode.charAt(pos) == ';';
    }

    public boolean isComma(int pos) {
        // 判断指针位置是否为逗号
        return this.isValidPointer(pos) && sourceCode.charAt(pos) == ',';
    }

    public boolean isLeftAngleBracket(int pos) {
        // 判断指针位置是否为左尖括号
        return this.isValidPointer(pos) && sourceCode.charAt(pos) == '<';
    }

    public boolean isRightAngleBracket(int pos) {
        // 判断指针位置是否为右尖括号
        return this.isValidPointer(pos) && sourceCode.charAt(pos) == '>';
    }

    public boolean isVerticalBar(int pos) {
        // 判断指针位置是否为竖线
        return this.isValidPointer(pos) && sourceCode.charAt(pos) == '|';
    }

    public boolean isAmpersand(int pos) {
        // 判断指针位置是否为与号
        return this.isValidPointer(pos) && sourceCode.charAt(pos) == '&';
    }

    public boolean isLeftBrace(int pos) {
        // 判断指针位置是否为左大括号
        return this.isValidPointer(pos) && sourceCode.charAt(pos) == '{';
    }

    public boolean isRightBrace(int pos) {
        // 判断指针位置是否为右大括号
        return this.isValidPointer(pos) && sourceCode.charAt(pos) == '}';
    }

    public boolean isLeftBracket(int pos) {
        // 判断指针位置是否为左中括号
        return this.isValidPointer(pos) && sourceCode.charAt(pos) == '[';
    }

    public boolean isRightBracket(int pos) {
        // 判断指针位置是否为右中括号
        return this.isValidPointer(pos) && sourceCode.charAt(pos) == ']';
    }

    public boolean isLeftParenthesis(int pos) {
        // 判断指针位置是否为左小括号
        return this.isValidPointer(pos) && sourceCode.charAt(pos) == '(';
    }

    public boolean isRightParenthesis(int pos) {
        // 判断指针位置是否为右小括号
        return this.isValidPointer(pos) && sourceCode.charAt(pos) == ')';
    }

    public boolean isDoubleEquals(int pos) {
        // 判断指针位置是否为双等号
        return this.isValidPointer(pos) && sourceCode.charAt(pos) == '=';
    }

    public boolean isPlus(int pos) {
        // 判断指针位置是否为加号
        return this.isValidPointer(pos) && sourceCode.charAt(pos) == '+';
    }

    public boolean isMinus(int pos) {
        // 判断指针位置是否为减号
        return this.isValidPointer(pos) && sourceCode.charAt(pos) == '-';
    }

    public boolean isAsterisk(int pos) {
        // 判断指针位置是否为乘号
        return this.isValidPointer(pos) && sourceCode.charAt(pos) == '*';
    }

    public boolean isSlash(int pos) {
        // 判断指针位置是否为斜线
        return this.isValidPointer(pos) && sourceCode.charAt(pos) == '/';
    }

    public boolean isPercent(int pos) {
        // 判断指针位置是否为百分号
        return this.isValidPointer(pos) && sourceCode.charAt(pos) == '%';
    }


    public boolean isExclamationMark(int pos) {
        // 判断指针位置是否为感叹号
        return this.isValidPointer(pos) && sourceCode.charAt(pos) == '!';
    }

    public boolean isDoubleQuote(int pos) {
        // 判断指针位置是否为双引号
        return this.isValidPointer(pos) && sourceCode.charAt(pos) == '"';
    }

    // 是否为单引号
    public boolean isSingleQuote(int pos) {
        return this.isValidPointer(pos) && sourceCode.charAt(pos) == '\'';
    }

    public ArrayList<Token> getTokenList() {
        return tokens;
    }

    /**
     * 获取
     *
     * @return currentToken
     */
    public StringBuilder getCurrentToken() {
        return currentToken;
    }

    /**
     * 设置
     *
     * @param currentToken
     */
    public void setCurrentToken(StringBuilder currentToken) {
        this.currentToken = currentToken;
    }

    /**
     * 设置
     *
     * @param sourceCode
     */
    public void setSourceCode(String sourceCode) {
        this.sourceCode = sourceCode;
    }

    /**
     * 获取
     *
     * @return sourceCode
     */
    public String getSourceCode() {
        return sourceCode;
    }

    /**
     * 获取
     *
     * @return pointer
     */
    public int getPointer() {
        return pointer;
    }

    /**
     * 设置
     *
     * @param pointer
     */
    public void setPointer(int pointer) {
        this.pointer = pointer;
    }

    /**
     * 获取
     *
     * @return codeLength
     */
    public int getCodeLength() {
        return codeLength;
    }

    /**
     * 设置
     *
     * @param codeLength
     */
    public void setCodeLength(int codeLength) {
        this.codeLength = codeLength;
    }

    /**
     * 获取
     *
     * @return lineNumber
     */
    public int getLineNumber() {
        return lineNumber;
    }

    /**
     * 设置
     *
     * @param lineNumber
     */
    public void setLineNumber(int lineNumber) {
        this.lineNumber = lineNumber;
    }

    @Override
    public String toString() {
        return "Lexer{tokens = " + tokens + ", currentToken = " + currentToken + ", sourceCode = " + sourceCode + ", pointer = " + pointer + ", lineNumber = " + lineNumber + ", keywordMap = " + LexType.keyTokenMap + "}";
    }
}
