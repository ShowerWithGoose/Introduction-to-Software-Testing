package frontend;

import java.io.InputStream;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Lexer {
    private BufferedReader reader;
    private int currentChar;
    private int lineNumber;
    private StringBuilder tokenBuffer;
    private boolean reachedEOF;
    private List<Error> errors;

    public Lexer(InputStream input) {
        reader = new BufferedReader(new InputStreamReader(input));
        lineNumber = 1;
        tokenBuffer = new StringBuilder();
        reachedEOF = false;
        errors = new ArrayList<>();
        advance();
    }

    private void advance() {
        try {
            currentChar = reader.read();
            if (currentChar == '\n') {
                lineNumber++;
            }
            if (currentChar == -1) {
                reachedEOF = true;
            }
        } catch (IOException e) {
            currentChar = -1;
            reachedEOF = true;
        }
    }

    private void skipWhitespaceAndComments() {
        while (!reachedEOF) {
            if (Character.isWhitespace(currentChar)) {
                advance();
            } else if (currentChar == '/') {
                int nextChar = peek();
                if (nextChar == '/') {
                    // 单行注释
                    advance(); // 消耗 '/'
                    advance(); // 消耗第二个 '/'
                    while (currentChar != '\n' && !reachedEOF) {
                        advance();
                    }
                } else if (nextChar == '*') {
                    // 多行注释
                    advance(); // 消耗 '/'
                    advance(); // 消耗 '*'
                    boolean endComment = false;
                    while (!reachedEOF && !endComment) {
                        if (currentChar == '*') {
                            advance();
                            if (currentChar == '/') {
                                endComment = true;
                                advance();
                            }
                        } else {
                            if (currentChar == '\n') {
                                lineNumber++;
                            }
                            advance();
                        }
                    }
                    if (!endComment) {
                        // 未结束的注释错误处理
                        addError(lineNumber, 'a');
                    }
                } else {
                    break;
                }
            } else {
                break;
            }
        }
    }

    private int peek() {
        try {
            reader.mark(1);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        int nextChar = -1;
        try {
            nextChar = reader.read();
            reader.reset();
        } catch (IOException e) {
            nextChar = -1;
        }
        return nextChar;
    }

    public Token getNextToken() {
        skipWhitespaceAndComments();

        if (reachedEOF) {
            return new Token(TokenType.EOF, "", lineNumber);
        }

        if (Character.isLetter(currentChar) || currentChar == '_') {
            return recognizeIdentifierOrKeyword();
        } else if (Character.isDigit(currentChar)) {
            return recognizeNumber();
        } else if (currentChar == '\'') {
            return recognizeCharConst();
        } else if (currentChar == '"') {
            return recognizeStringConst();
        } else if (isOperatorStart(currentChar)) {
            return recognizeOperatorOrSeparator();
        } else {
            // 未知字符
            int errorLine = lineNumber;
            advance();
            addError(errorLine, 'a');
            // 跳过该字符并继续
            return getNextToken();
        }
    }

    private Token recognizeIdentifierOrKeyword() {
        tokenBuffer.setLength(0);
        int startLine = lineNumber;
        while (Character.isLetterOrDigit(currentChar) || currentChar == '_') {
            tokenBuffer.append((char) currentChar);
            advance();
        }
        String lexeme = tokenBuffer.toString();
        TokenType type = getKeywordTokenType(lexeme);
        if (type == null) {
            type = TokenType.IDENFR;
        }
        return new Token(type, lexeme, startLine);
    }

    private TokenType getKeywordTokenType(String lexeme) {
        switch (lexeme) {
            case "int": return TokenType.INTTK;
            case "char": return TokenType.CHARTK;
            case "void": return TokenType.VOIDTK;
            case "const": return TokenType.CONSTTK;
            case "if": return TokenType.IFTK;
            case "else": return TokenType.ELSETK;
            case "for": return TokenType.FORTK;
            case "break": return TokenType.BREAKTK;
            case "continue": return TokenType.CONTINUETK;
            case "return": return TokenType.RETURNTK;
            case "getint": return TokenType.GETINTTK;
            case "getchar": return TokenType.GETCHARTK;
            case "printf": return TokenType.PRINTFTK;
            case "main": return TokenType.MAINTK;
            default: return null;
        }
    }

    private Token recognizeNumber() {
        tokenBuffer.setLength(0);
        int startLine = lineNumber;
        if (currentChar == '0') {
            tokenBuffer.append('0');
            advance();
        } else {
            while (Character.isDigit(currentChar)) {
                tokenBuffer.append((char) currentChar);
                advance();
            }
        }
        return new Token(TokenType.INTCON, tokenBuffer.toString(), startLine);
    }

    private Token recognizeCharConst() {
        tokenBuffer.setLength(0);
        int startLine = lineNumber;
        tokenBuffer.append('\''); // 包含开头的 '
        advance(); // 消耗开头的 '

        if (currentChar == '\\') {
            tokenBuffer.append('\\'); // 包含反斜杠
            advance(); // 消耗 '\'
            if (isValidEscapeChar((char) currentChar)) {
                tokenBuffer.append((char) currentChar); // 包含转义字符
                advance(); // 消耗转义字符
            } else {
                addError(startLine, 'a');
                advance(); // 跳过错误字符
            }
        } else if (isASCIIChar(currentChar) && currentChar != '\'' && currentChar != '\\') {
            tokenBuffer.append((char) currentChar); // 包含字符
            advance(); // 消耗字符
        } else {
            addError(startLine, 'a');
            advance(); // 跳过错误字符
        }

        if (currentChar == '\'') {
            tokenBuffer.append('\''); // 包含结尾的 '
            advance(); // 消耗结尾的 '
            return new Token(TokenType.CHRCON, tokenBuffer.toString(), startLine);
        } else {
            addError(startLine, 'a');
            // 跳过直到找到结尾的 ' 或 EOF
            while (currentChar != '\'' && !reachedEOF) {
                advance();
            }
            if (currentChar == '\'') {
                advance();
            }
            return getNextToken();
        }
    }

    private boolean isASCIIChar(int c) {
        return c >= 32 && c <= 126;
    }

    private boolean isValidEscapeChar(char c) {
        return c == '0' || c == 'a' || c == 'b' || c == 'f' || c == 'n' || c == 'r' || c == 't' || c == 'v' || c == '\\' || c == '\'' || c == '"';
    }

    private char getEscapeChar(char c) {
        return switch (c) {
            case '0' -> '\0';
            case 'a' -> '\007';
            case 'b' -> '\b';
            case 'f' -> '\f';
            case 'n' -> '\n';
            case 'r' -> '\r';
            case 't' -> '\t';
            case 'v' -> '\013';
            case '\\' -> '\\';
            case '\'' -> '\'';
            case '"' -> '"';
            default -> c;
        };
    }

    private Token recognizeStringConst() {
        tokenBuffer.setLength(0);
        int startLine = lineNumber;
        tokenBuffer.append('"'); // 包含开头的 "
        advance(); // 消耗开头的 "
        while (currentChar != '"' && !reachedEOF) {
            if (currentChar == '\\') {
                tokenBuffer.append('\\'); // 包含反斜杠
                advance(); // 消耗 '\'
                if (isValidEscapeChar((char) currentChar)) {
                    tokenBuffer.append((char) currentChar); // 包含转义字符
                    advance(); // 消耗转义字符
                } else {
                    addError(startLine, 'a');
                    advance();
                }
            } else if (isASCIIChar(currentChar) && currentChar != '"' && currentChar != '\\') {
                tokenBuffer.append((char) currentChar);
                advance();
            } else {
                addError(startLine, 'a');
                advance();
            }
        }
        if (currentChar == '"') {
            tokenBuffer.append('"'); // 包含结尾的 "
            advance(); // 消耗结尾的 "
            return new Token(TokenType.STRCON, tokenBuffer.toString(), startLine);
        } else {
            addError(startLine, 'a');
            return getNextToken();
        }
    }

    private boolean isOperatorStart(int c) {
        return "+-*/%!<>=&|;:,(){}[]".indexOf(c) != -1;
    }

    private Token recognizeOperatorOrSeparator() {
        int startLine = lineNumber;
        switch (currentChar) {
            case '+' -> {
                advance();
                return new Token(TokenType.PLUS, "+", startLine);
            }
            case '-' -> {
                advance();
                return new Token(TokenType.MINU, "-", startLine);
            }
            case '*' -> {
                advance();
                return new Token(TokenType.MULT, "*", startLine);
            }
            case '/' -> {
                advance();
                return new Token(TokenType.DIV, "/", startLine);
            }
            case '%' -> {
                advance();
                return new Token(TokenType.MOD, "%", startLine);
            }
            case '!' -> {
                advance();
                if (currentChar == '=') {
                    advance();
                    return new Token(TokenType.NEQ, "!=", startLine);
                } else {
                    return new Token(TokenType.NOT, "!", startLine);
                }
            }
            case '&' -> {
                advance();
                if (currentChar == '&') {
                    advance();
                    return new Token(TokenType.AND, "&&", startLine);
                } else {
                    addError(startLine, 'a');
                    return getNextToken();
                }
            }
            case '|' -> {
                advance();
                if (currentChar == '|') {
                    advance();
                    return new Token(TokenType.OR, "||", startLine);
                } else {
                    addError(startLine, 'a');
                    return getNextToken();
                }
            }
            case '=' -> {
                advance();
                if (currentChar == '=') {
                    advance();
                    return new Token(TokenType.EQL, "==", startLine);
                } else {
                    return new Token(TokenType.ASSIGN, "=", startLine);
                }
            }
            case '<' -> {
                advance();
                if (currentChar == '=') {
                    advance();
                    return new Token(TokenType.LEQ, "<=", startLine);
                } else {
                    return new Token(TokenType.LSS, "<", startLine);
                }
            }
            case '>' -> {
                advance();
                if (currentChar == '=') {
                    advance();
                    return new Token(TokenType.GEQ, ">=", startLine);
                } else {
                    return new Token(TokenType.GRE, ">", startLine);
                }
            }
            case ';' -> {
                advance();
                return new Token(TokenType.SEMICN, ";", startLine);
            }
            case ',' -> {
                advance();
                return new Token(TokenType.COMMA, ",", startLine);
            }
            case '(' -> {
                advance();
                return new Token(TokenType.LPARENT, "(", startLine);
            }
            case ')' -> {
                advance();
                return new Token(TokenType.RPARENT, ")", startLine);
            }
            case '{' -> {
                advance();
                return new Token(TokenType.LBRACE, "{", startLine);
            }
            case '}' -> {
                advance();
                return new Token(TokenType.RBRACE, "}", startLine);
            }
            case '[' -> {
                advance();
                return new Token(TokenType.LBRACK, "[", startLine);
            }
            case ']' -> {
                advance();
                return new Token(TokenType.RBRACK, "]", startLine);
            }
            default -> {
                char errorChar = (char) currentChar;
                advance();
                addError(startLine, 'a');
                return getNextToken();
            }
        }
    }

    private void addError(int lineNumber, char errorCode) {
        errors.add(new Error(lineNumber, errorCode));
    }

    public List<Error> getErrors() {
        return errors;
    }
}
