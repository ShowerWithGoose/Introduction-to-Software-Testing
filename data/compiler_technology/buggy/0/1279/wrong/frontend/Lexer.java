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
            type = TokenType.IDENTIFIER;
        }
        return new Token(type, lexeme, startLine);
    }

    private TokenType getKeywordTokenType(String lexeme) {
        return switch (lexeme) {
            case "int" -> TokenType.INT;
            case "char" -> TokenType.CHAR;
            case "void" -> TokenType.VOID;
            case "const" -> TokenType.CONST;
            case "if" -> TokenType.IF;
            case "else" -> TokenType.ELSE;
            case "for" -> TokenType.FOR;
            case "break" -> TokenType.BREAK;
            case "continue" -> TokenType.CONTINUE;
            case "return" -> TokenType.RETURN;
            case "getint" -> TokenType.GETINT;
            case "getchar" -> TokenType.GETCHAR;
            case "printf" -> TokenType.PRINTF;
            case "main" -> TokenType.MAIN;
            default -> null;
        };
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
        return new Token(TokenType.INT_CONST, tokenBuffer.toString(), startLine);
    }

    private Token recognizeCharConst() {
        int startLine = lineNumber;
        advance(); // 消耗开头的 '
        if (currentChar == '\\') {
            advance(); // 消耗 '\'
            if (isValidEscapeChar((char) currentChar)) {
                char escapeChar = getEscapeChar((char) currentChar);
                advance(); // 消耗转义字符
                if (currentChar == '\'') {
                    advance(); // 消耗结尾的 '
                    return new Token(TokenType.CHAR_CONST, "'" + "\\" + (char) currentChar + "'", startLine);
                } else {
                    addError(startLine, 'a');
                }
            } else {
                addError(startLine, 'a');
                advance();
            }
        } else if (isASCIIChar(currentChar) && currentChar != '\'' && currentChar != '\\') {
            char c = (char) currentChar;
            advance(); // 消耗字符
            if (currentChar == '\'') {
                advance(); // 消耗结尾的 '
                return new Token(TokenType.CHAR_CONST, "'" + c + "'", startLine);
            } else {
                addError(startLine, 'a');
            }
        } else {
            addError(startLine, 'a');
            advance();
        }
        // 跳过直到找到结尾的 ' 或 EOF
        while (currentChar != '\'' && !reachedEOF) {
            advance();
        }
        if (currentChar == '\'') {
            advance();
        }
        return getNextToken();
    }

    private boolean isASCIIChar(int c) {
        return c >= 32 && c <= 126;
    }

    private boolean isValidEscapeChar(char c) {
        return c == 'a' || c == 'b' || c == 'f' || c == 'n' || c == 'r' || c == 't' || c == 'v' || c == '\\' || c == '\'' || c == '"';
    }

    private char getEscapeChar(char c) {
        return switch (c) {
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
                int nextChar = peek();
                if (nextChar == 'n') {
                    tokenBuffer.append('\\');
                    tokenBuffer.append('n');
                    advance(); // 消耗 '\'
                    advance(); // 消耗 'n'
                } else {
                    // 无效的转义序列
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
            return new Token(TokenType.STRING_CONST, tokenBuffer.toString(), startLine);
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
                return new Token(TokenType.MINUS, "-", startLine);
            }
            case '*' -> {
                advance();
                return new Token(TokenType.MULTIPLY, "*", startLine);
            }
            case '/' -> {
                advance();
                return new Token(TokenType.DIVIDE, "/", startLine);
            }
            case '%' -> {
                advance();
                return new Token(TokenType.MODULO, "%", startLine);
            }
            case '!' -> {
                advance();
                if (currentChar == '=') {
                    advance();
                    return new Token(TokenType.NOT_EQUAL, "!=", startLine);
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
                    return new Token(TokenType.EQUAL, "==", startLine);
                } else {
                    return new Token(TokenType.ASSIGN, "=", startLine);
                }
            }
            case '<' -> {
                advance();
                if (currentChar == '=') {
                    advance();
                    return new Token(TokenType.LESS_EQUAL, "<=", startLine);
                } else {
                    return new Token(TokenType.LESS, "<", startLine);
                }
            }
            case '>' -> {
                advance();
                if (currentChar == '=') {
                    advance();
                    return new Token(TokenType.GREATER_EQUAL, ">=", startLine);
                } else {
                    return new Token(TokenType.GREATER, ">", startLine);
                }
            }
            case ';' -> {
                advance();
                return new Token(TokenType.SEMICOLON, ";", startLine);
            }
            case ',' -> {
                advance();
                return new Token(TokenType.COMMA, ",", startLine);
            }
            case '(' -> {
                advance();
                return new Token(TokenType.LEFT_PAREN, "(", startLine);
            }
            case ')' -> {
                advance();
                return new Token(TokenType.RIGHT_PAREN, ")", startLine);
            }
            case '{' -> {
                advance();
                return new Token(TokenType.LEFT_BRACE, "{", startLine);
            }
            case '}' -> {
                advance();
                return new Token(TokenType.RIGHT_BRACE, "}", startLine);
            }
            case '[' -> {
                advance();
                return new Token(TokenType.LEFT_BRACKET, "[", startLine);
            }
            case ']' -> {
                advance();
                return new Token(TokenType.RIGHT_BRACKET, "]", startLine);
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
