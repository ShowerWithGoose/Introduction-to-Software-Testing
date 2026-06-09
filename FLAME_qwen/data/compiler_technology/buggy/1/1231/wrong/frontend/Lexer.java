package frontend;

import java.util.ArrayList;

import error.ErrorList;
import error.MyErrorType;
import nodes.Token;
import nodes.TokenMap;
import nodes.TokenType;
import utils.Utils;

public class Lexer {
    private ArrayList<String> sourceCode;

    private ArrayList<Token> tokens = new ArrayList<>();

    private boolean hasError = false;

    private int lineNum = 1;
    private int content = 0;
    private boolean inAnnotation = false;

    public Lexer(ArrayList<String> sourceCode) {
        this.sourceCode = sourceCode;
    }

    public void process() {
        for (String line : sourceCode) {
            processLine(line);
            lineNum++;
        }
    }

    private void processLine(String line) {
        content = 0;
        while (content < line.length()) {
            char c = line.charAt(content++);
            if (inAnnotation) {
                if (c == '*') {
                    if (content < line.length()) {
                        c = line.charAt(content++);
                        if (c == '/') {
                            inAnnotation = false;
                        }
                    }
                }
            } else if (isWhite(c)) {
                continue;
            } else if (isAlphaOrUnder(c)) {
                StringBuilder builder = new StringBuilder();
                builder.append(c);
                while (content < line.length()) {
                    c = line.charAt(content++);
                    if (isAlphaOrUnderOrDigit(c)) {
                        builder.append(c);
                    } else {
                        content--;
                        break;
                    }
                }
                tokens.add(processWord(builder.toString()));// IDENT
            } else if (isDigit(c)) {
                StringBuilder builder = new StringBuilder();
                builder.append(c);
                while (content < line.length()) {
                    c = line.charAt(content++);
                    if (isDigit(c)) {
                        builder.append(c);
                    } else {
                        content--;
                        break;
                    }
                }
                tokens.add(new Token(TokenType.INTCON, builder.toString(), lineNum, content));// INTCON
            } else if (c == '"') {
                // NOTE: [[文法.pdf#page=6|p.6]] 
                // STRCON 很简单
                StringBuilder builder = new StringBuilder();
                do {
                    builder.append(c);
                    c = line.charAt(content++);
                } while (c != '"' && content < line.length());
                builder.append(c);
                tokens.add(new Token(TokenType.STRCON, builder.toString(), lineNum, content));
            } else if (c == '\'') {
                StringBuilder builder = new StringBuilder();
                builder.append(c);
                c = line.charAt(content++);
                if (c == '\\') {
                    builder.append(c);
                    c = line.charAt(content++);
                    Utils.aaaaAssert(isValidEscape(c));
                    builder.append(c);
                    c = line.charAt(content++);
                    Utils.aaaaAssert(c == '\'');
                    builder.append(c);
                } else {
                    Utils.aaaaAssert(c != '\'');
                    builder.append(c);
                    c = line.charAt(content++);
                    Utils.aaaaAssert(c == '\'');
                    builder.append(c);
                }
                tokens.add(new Token(TokenType.CHRCON, builder.toString(), lineNum, content));// CHARCON
            } else if (c == '!') {
                c = line.charAt(content++);
                if (c == '=') {
                    tokens.add(processWord("!="));// NEQ
                } else {
                    content--;
                    tokens.add(processWord("!"));// NOT
                }
            } else if (c == '&') {
                c = line.charAt(content++);
                if (c == '&') {
                    tokens.add(processWord("&&"));// AND
                } else {
                    content--;
                    hasError = true;
                    // tokens.add(new UndefinedToken(TokenType.UNDEFINE, "&", lineNum, content));// &, error a
                    tokens.add(new Token(TokenType.AND, "&", lineNum, content));// &, error a
                    ErrorList.addError(MyErrorType.A_ILLEGAL_SYMBOL, lineNum);
                }
            } else if (c == '|') {
                c = line.charAt(content++);
                if (c == '|') {
                    tokens.add(processWord("||"));// OR 
                } else {
                    content--;
                    hasError = true;
                    // tokens.add(new UndefinedToken(TokenType.UNDEFINE, "|", lineNum, content));// &, error a
                    tokens.add(new Token(TokenType.OR, "|", lineNum, content));// |, error a
                    ErrorList.addError(MyErrorType.A_ILLEGAL_SYMBOL, lineNum);
                }
            } else if (c == '+') {
                tokens.add(processWord("+"));// ADD
            } else if (c == '-') {
                tokens.add(processWord("-"));// MINU
            } else if (c == '*') {
                tokens.add(processWord("*"));// MULT
            } else if (c == '/') {
                c = line.charAt(content++);
                if (c == '/') { // 单行注释直接下一行
                    break;
                } else if (c == '*') { // 多行注释
                    inAnnotation = true;
                } else {
                    content--;
                    tokens.add(processWord("/"));// DIV
                }
            } else if (c == '%') {
                tokens.add(processWord("%"));// MOD
            } else if (c == '<') {
                c = line.charAt(content++);
                if (c == '=') {
                    tokens.add(processWord("<="));// LEQ
                } else {
                    content--;
                    tokens.add(processWord("<"));// LSS
                }
            } else if (c == '>') {
                c = line.charAt(content++);
                if (c == '=') {
                    tokens.add(processWord(">="));// LEQ
                } else {
                    content--;
                    tokens.add(processWord(">"));// LSS
                }
            } else if (c == '=') {
                c = line.charAt(content++);
                if (c == '=') {
                    tokens.add(processWord("=="));// LEQ
                } else {
                    content--;
                    tokens.add(processWord("="));// LSS
                }
            } else if (c == ';') {
                tokens.add(processWord(";"));
            } else if (c == ',') {
                tokens.add(processWord(","));
            } else if (c == '(') {
                tokens.add(processWord("("));
            } else if (c == ')') {
                tokens.add(processWord(")"));
            } else if (c == '[') {
                tokens.add(processWord("["));
            } else if (c == ']') {
                tokens.add(processWord("]"));
            } else if (c == '{') {
                tokens.add(processWord("{"));
            } else if (c == '}') {
                tokens.add(processWord("}"));
            } else {
                continue;
            }
        }
    }

    private Token processWord(String word) {
        TokenType tokenType = TokenMap.getTokenType(word);
        return new Token(tokenType, word, lineNum, content);
    }

    private boolean isDigit(char c) {
        return (c >= '0' && c <= '9');
    }

    private boolean isAlphaOrUnder(char c) {
        return (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) || (c == '_'));
    }

    private boolean isAlphaOrUnderOrDigit(char c) {
        return (isAlphaOrUnder(c) || isDigit(c));
    }

    private boolean isWhite(char c) {
        return (c == ' ' || c == '\t' || c == '\n');
    }

    public boolean isHasError() {
        return hasError;
    }

    // 合法转义符名, abtnvf"'\0
    public boolean isValidEscape(char c) {
        return (c == 'a' || c == 'b' || c == 't' || c == 'n' || c == 'v' || c == 'f' || c == '"' || c == '\''
                || c == '\\' || c == '0');
    }

    public ArrayList<Token> getTokens() {
        return tokens;
    }
}