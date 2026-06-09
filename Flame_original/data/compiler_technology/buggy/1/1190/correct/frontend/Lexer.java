package frontend;

import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

public class Lexer {
    private final String text;
    private int pos;
    public static int nowLine;
    private char currentChar;
    private final List<Token> tokens = new ArrayList<>();

    public Lexer(String text) {
        this.text = text;
        this.pos = 0;
        nowLine = 1;
        this.currentChar = text.charAt(pos);

        Token token;
        while (currentChar != '\0') {
            token = getOneToken();
            tokens.add(token);
        }
        while (tokens.get(tokens.size() - 1) == null) {
            tokens.remove(tokens.size() - 1);
        }
    }

    public List<Token> getTokens() {
        return tokens;
    }

    private void advance() {
        if (currentChar == '\n') {
            nowLine++;
        }
        pos++;
        if (pos >= text.length()) {
            currentChar = '\0';
        } else {
            currentChar = text.charAt(pos);
        }
    }

    public void print() throws Exception {
        OutputStreamWriter writer1 = new OutputStreamWriter(new FileOutputStream("lexer.txt"));
        OutputStreamWriter writer2 = new OutputStreamWriter(new FileOutputStream("error.txt"));
        for (Token token : tokens) {
            if (token == null) {
                continue;
            }
            if (token.getErrorCode() != 0) {
                writer2.write(token.error());
            } else {
                writer1.write(token.toString());
            }
        }
        writer1.close();
        writer2.close();
    }

    private char peekNextChar() {
        if (pos >= text.length() - 1) {
            return '\0';
        }
        return text.charAt(pos + 1);
    }

    private char peekPrevChar() {
        if (pos == 0) {
            return '\0';
        }
        return text.charAt(pos - 1);
    }

    private boolean handleComment() {
        if (currentChar == '/') { // 去除注释
            if (peekNextChar() == '/') {
                advance();
                advance();
                while (currentChar != '\0' && currentChar != '\n') {
                    advance();
                }
                return true;
            } else if (peekNextChar() == '*') {
                advance();
                advance();
                advance();
                while (currentChar != '\0' && !(peekPrevChar() == '*' && currentChar == '/')) {
                    advance();
                }
                advance();
                return true;
            }
        }
        return false;
    }

    private Token handleNumber() {
        StringBuilder sb = new StringBuilder();
        while (Character.isDigit(currentChar)) {
            sb.append(currentChar);
            advance();
        }
        return new Token.NumberToken(sb.toString());
    }

    private Token handleIdentifier() {
        StringBuilder sb = new StringBuilder();
        while (currentChar == '_' || Character.isLetter(currentChar) || Character.isDigit(currentChar)) {
            sb.append(currentChar);
            advance();
        }
        return new Token.IdentToken(sb.toString());
    }

    private Token handleStringOrChar() {
        StringBuilder sb = new StringBuilder();
        char quoteType = currentChar;
        sb.append(currentChar);
        advance();
        while (currentChar != '\0' && currentChar != quoteType) {
            if (currentChar == '\\') {
                // TODO: 处理转义字符
                sb.append(currentChar);
                advance();
            }
            sb.append(currentChar);
            advance();
        }
        sb.append(currentChar);
        advance();
        return new Token.SymbolToken(sb.toString());
    }

    private Token handleSymbol() {
        StringBuilder sb = new StringBuilder();
        String tmp = String.format("%c%c", currentChar, peekNextChar());
        if (!Character.isWhitespace(currentChar) && !Character.isLetter(currentChar) && !Character.isDigit(currentChar)) {
            sb.append(currentChar);
            advance();
        }
        if (tmp.equals("!=") || tmp.equals("&&") || tmp.equals("||") || tmp.equals("==") || tmp.equals(">=") || tmp.equals("<=")) {
            sb.append(currentChar);
            advance();
        }
        try {
            return new Token.SymbolToken(sb.toString());
        } catch (RuntimeException e) {
            System.err.println(e.getMessage());
            return null;
        }
    }

    private Token getOneToken() {
        while (true) { // 去除空格和注释
            if (currentChar == '\0') {
                break;
            } else if (Character.isWhitespace(currentChar)) {
                advance();
            } else if (currentChar == '/') {
                if (!handleComment()) {
                    break;
                }
            } else {
                break;
            }
        }
        if (currentChar == '\0') {
            return null;
        } else if (Character.isDigit(currentChar)) {
            return handleNumber();
        } else if (Character.isLetter(currentChar) || currentChar == '_') {
            return handleIdentifier();
        } else {
            if (currentChar == '"' || currentChar == '\'') {
                return handleStringOrChar();
            } else {
                return handleSymbol();
            }
        }
    }
}
