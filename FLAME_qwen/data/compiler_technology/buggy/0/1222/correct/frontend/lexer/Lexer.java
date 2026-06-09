package frontend.lexer;

import frontend.error.ErrorHandle;
import frontend.error.ErrorType;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Lexer {
    private static Lexer instance; // 单例模式
    private int currentLine = 1; // 当前行数
    private BufferedReader reader;
    private BufferedWriter lexerWriter, errorWriter;
    private Token currentToken;
    private List<Token> tokenList = new ArrayList<>(2000); // 词法分析结果
    private List<ErrorHandle> errorList = new ArrayList<>(); // 错误处理结果
    private char currentChar; // 当前字符
    private char nextChar; // 下一个字符
    private StringBuilder currentWord = new StringBuilder(); // 当前单词
    private int currentNum; // 当前数字
    private boolean hasError = false; // 是否有错误

    private int charIndex = -1;  // 追踪当前字符的位置
    private String inputBuffer = "";  // 存储整个输入文件的内容

    private Lexer() {
    }

    public static Lexer getInstance() {
        if (instance == null) {
            instance = new Lexer();
        }
        return instance;
    }

    public void initBuffer(String inputFile, String outputFile, String errorFile) throws IOException {
        reader = new BufferedReader(new FileReader(inputFile));
        lexerWriter = new BufferedWriter(new FileWriter(outputFile));
        errorWriter = new BufferedWriter(new FileWriter(errorFile));
    }

    public void closeBuffer() throws IOException {
        reader.close();
        lexerWriter.close();
        errorWriter.close();
    }

    public void retract() {
        // 将索引回退
        if (charIndex > 0) {
            charIndex--;
            currentChar = inputBuffer.charAt(charIndex);
            nextChar = (charIndex + 1 < inputBuffer.length()) ? inputBuffer.charAt(charIndex + 1) : '\0';
        }
    }

    public void getChar() throws IOException {
        // 如果缓冲区为空，则将整个文件读入缓冲区
        if (inputBuffer.isEmpty()) {
            StringBuilder sb = new StringBuilder();
            String line;
            while ((line = reader.readLine()) != null) {
                sb.append(line).append("\n");  // 逐行读取文件
            }
            inputBuffer = sb.toString();
        }

        // 更新当前字符和下一个字符
        if (charIndex < inputBuffer.length() - 1) {
            charIndex++;
            currentChar = inputBuffer.charAt(charIndex);
            nextChar = (charIndex + 1 < inputBuffer.length()) ? inputBuffer.charAt(charIndex + 1) : '\0';
            if (currentChar == '\n') {
                currentLine++;  // 如果遇到换行符，增加当前行数
            }
        } else {
            currentChar = '\0';  // 如果到达文件末尾，设置为特殊字符表示结束
            nextChar = '\0';
        }
    }


    public void clearToken() {
        currentWord = new StringBuilder();
        currentNum = 0;
    }

    public void addChar() {
        currentWord.append(currentChar);
    }

    public void skipSpace() throws IOException {
        while (isSpace() || isNewLine() || isTab()) {
            getChar();
        }
    }

    public boolean isSpace() {
        return currentChar == ' ';
    }

    public boolean isNewLine() {
        return currentChar == '\n';
    }

    public boolean isTab() {
        return currentChar == '\t';
    }

    public boolean isSingleDelim() {
        return currentChar == '+' || currentChar == '-' || currentChar == '%' || currentChar == '*'
                || currentChar == ';' || currentChar == ',' || currentChar == '(' || currentChar == ')'
                || currentChar == '[' || currentChar == ']' || currentChar == '{' || currentChar == '}'
                || (currentChar == '/' && nextChar != '/' && nextChar != '*')
                || (currentChar == '<' && nextChar != '=') || (currentChar == '>' && nextChar != '=')
                || (currentChar == '=' && nextChar != '=') || (currentChar == '!' && nextChar != '=');
    }

    public boolean isDoubleDelim() {
        return currentChar == '<' || currentChar == '>'
                || currentChar == '=' || currentChar == '!';
    }

    public boolean isAnnotation() {
        return currentChar == '/';
    }

    public boolean isSingleQuote() {
        return currentChar == '\'';
    }

    public boolean isDoubleQuote() {
        return currentChar == '\"';
    }

    public boolean isAndorOr() {
        return currentChar == '&' || currentChar == '|';
    }

    public boolean isLetter() {
        return (currentChar >= 'a' && currentChar <= 'z') || (currentChar >= 'A' && currentChar <= 'Z');
    }

    public boolean isDigit() {
        return currentChar >= '0' && currentChar <= '9';
    }

    public boolean isUnderline() {
        return currentChar == '_';
    }

    private boolean isEnd() {
        return currentChar == '\0';
    }

    public int reserver() {
        String word = currentWord.toString();
        for (LexType type : LexType.values()) {
            if (type.getNameString().equals(word)) {
                return type.ordinal();
            }
        }
        return 0;
    }

    public Token getsym() throws IOException {
        getChar();
        clearToken();
        skipSpace();

        if (isLetter()||isUnderline()) {
            handleIdent();
        } else if (isDigit()) {
            handleIntConst();
        } else if (isSingleDelim()) {
            handleSingleDelim();
        } else if (isSingleQuote()) {
            handleCharConst();
        } else if (isDoubleQuote()) {
            handleStringConst();
        } else if (isAnnotation()) {
            handleAnnotation();
        } else if (isDoubleDelim()) {
            handleDoubleDelim();
        } else if (isAndorOr()) {
            handleAndorOr();
        } else if (isEnd()) {
            return null;
        } else {
            // hasError = true;
            // addError(new ErrorHandle(currentLine,ErrorType.N));
            return null;
        }
        return currentToken;
    }

    private void handleIdent() throws IOException {
        while (isLetter() || isDigit() || isUnderline()) {
            addChar();
            getChar();
        }
        retract();
        int result = reserver();
        if (result != 0) {
            currentToken = new Token(currentLine, LexType.values()[result], currentWord.toString());
            addToken(currentToken);
        } else {
            currentToken = new Token(currentLine, LexType.IDENFR, currentWord.toString());
            addToken(currentToken);
        }
    }

    private void handleIntConst() throws IOException {
        while (isDigit()) {
            currentNum = currentNum * 10 + currentChar - '0';
            addChar();
            getChar();
        }
        retract();
        currentToken = new Token(currentLine, LexType.INTCON, currentWord.toString(), currentNum);
        addToken(currentToken);
    }

    private void handleSingleDelim() throws IOException {
    switch (currentChar) {
        case '+':
            currentToken = new Token(currentLine, LexType.PLUS, "+");
            addToken(currentToken);
            break;
        case '-':
            currentToken = new Token(currentLine, LexType.MINU, "-");
            addToken(currentToken);
            break;
        case '*':
            currentToken = new Token(currentLine, LexType.MULT, "*");
            addToken(currentToken);
            break;
        case '/':
            currentToken = new Token(currentLine, LexType.DIV, "/");
            addToken(currentToken);
            break;
        case '%':
            currentToken = new Token(currentLine, LexType.MOD, "%");
            addToken(currentToken);
            break;
        case '=':
            currentToken = new Token(currentLine, LexType.ASSIGN, "=");
            addToken(currentToken);
            break;
        case '<':
            currentToken = new Token(currentLine, LexType.LSS, "<");
            addToken(currentToken);
            break;
        case '>':
            currentToken = new Token(currentLine, LexType.GRE, ">");
            addToken(currentToken);
            break;
        case '!':
            currentToken = new Token(currentLine, LexType.NOT, "!");
            addToken(currentToken);
            break;
        case ';':
            currentToken = new Token(currentLine, LexType.SEMICN, ";");
            addToken(currentToken);
            break;
        case ',':
            currentToken = new Token(currentLine, LexType.COMMA, ",");
            addToken(currentToken);
            break;
        case '(':
            currentToken = new Token(currentLine, LexType.LPARENT, "(");
            addToken(currentToken);
            break;
        case ')':
            currentToken = new Token(currentLine, LexType.RPARENT, ")");
            addToken(currentToken);
            break;
        case '[':
            currentToken = new Token(currentLine, LexType.LBRACK, "[");
            addToken(currentToken);
            break;
        case ']':
            currentToken = new Token(currentLine, LexType.RBRACK, "]");
            addToken(currentToken);
            break;
        case '{':
            currentToken = new Token(currentLine, LexType.LBRACE, "{");
            addToken(currentToken);
            break;
        case '}':
            currentToken = new Token(currentLine, LexType.RBRACE, "}");
            addToken(currentToken);
            break;
        default:
            break;
        }
    }

    private void handleCharConst() throws IOException {
        addChar();
        getChar();

        // 单独处理转义字符
        if (currentChar == '\\') {
        addChar();  // 添加反斜杠
        getChar();  // 获取转义字符
        addChar();  // 添加转义后的字符
        } else {
            addChar(); // 添加普通字符
        }
        getChar();
        if (!isSingleQuote()) {
            // 这里可能出现字符常量缺少右单引号的错误，在词法分析阶段忽略此错误
            // TODO: 字符常量缺少右单引号的错误
        }
        addChar();

        currentToken = new Token(currentLine, LexType.CHRCON, currentWord.toString());
        addToken(currentToken);
    }

    private void handleStringConst() throws IOException {
        addChar();
        getChar();
        while (!isDoubleQuote()) {
            // 单独处理转义字符
            if (currentChar == '\\') {
                addChar();  // 添加反斜杠
                getChar();  // 获取转义字符
                addChar();  // 添加转义后的字符
            } else {
                addChar();  // 添加普通字符
            }
            getChar();
        }
        addChar();
        currentToken = new Token(currentLine, LexType.STRCON, currentWord.toString());
        addToken(currentToken);
    }

    private void handleAnnotation() throws IOException {
        if (nextChar == '/') {
            while (!isNewLine()) {
                getChar();
            }
        } else if (nextChar == '*') {
            getChar();
            getChar();
            while (!((currentChar == '*' && nextChar == '/') || currentChar == '\0')) {
                getChar();
            }
            getChar();
        }
        // 如果遇到了注释，返回一个非空的Token，继续读取下一个Token
        currentToken = new Token();
    }

    private void handleDoubleDelim() throws IOException {
        addChar();
        getChar();
        if (currentChar == '=') {
            addChar();
        } else {
            retract();
        }
        currentToken = new Token(currentLine, LexType.values()[reserver()], currentWord.toString());
        addToken(currentToken);
    }

    private void handleAndorOr() throws IOException {
        if (currentChar == '&' && nextChar == '&') {
            addChar();
            getChar();
            addChar();
            currentToken = new Token(currentLine, LexType.values()[reserver()], currentWord.toString());
            addToken(currentToken);
        } else if (currentChar == '|' && nextChar == '|') {
            addChar();
            getChar();
            addChar();
            currentToken = new Token(currentLine, LexType.values()[reserver()], currentWord.toString());
            addToken(currentToken);
        } else {
            // 这里出现a类错误，我们将忽略此符号
            hasError = true;
            addError(new ErrorHandle(currentLine, ErrorType.A));
        }
    }

    public void showLexer() throws IOException {
        if (getHasError()) {
            for (ErrorHandle error : errorList) {
                errorWriter.write(error.getLineno() + " " + error.getErrorType().getKindString() + "\n");
            }
        } else {
            for (Token token : tokenList) {
                lexerWriter.write(token.getLexType().getKindString() + " " + token.getContent() + "\n");
            }
        }
    }

    public int getCurrentLine() {
        return currentLine;
    }

    public void setCurrentLine(int currentLine) {
        this.currentLine = currentLine;
    }

    public void addCurrentLine() {
        currentLine++;
    }

    public List<Token> getTokenList() {
        return tokenList;
    }

    public void setTokenList(List<Token> tokenList) {
        this.tokenList = tokenList;
    }

    public void addToken(Token token) {
        tokenList.add(token);
    }

    public void addError(ErrorHandle errorHandle) {
        errorList.add(errorHandle);
    }

    public List<ErrorHandle> getErrorList() {
        return errorList;
    }

    public boolean getHasError() {
        return hasError;
    }
}
