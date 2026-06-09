package frontend;

import error.Error;
import token.Token;
import token.TokenName;
import token.WordToToken;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class Lexer {
    private static final Lexer lexer = new Lexer();
    private final List<Token> tokens = new ArrayList<>();
    private final List<Error> errors = new ArrayList<>();
    public static Lexer lexer() {
        return lexer;
    }
    public List<Token> getTokens() {
        return tokens;
    }
    public boolean noError() {
        return errors.size() == 0;
    }
    public String exportError() {
        StringBuilder sb = new StringBuilder();
        for (Error error: errors) {
            sb.append(error.toString());
            sb.append('\n');
        }
        return sb.toString();
    }
    public String exportToken() {
        StringBuilder sb = new StringBuilder();
        for (Token token: tokens) {
            sb.append(token.toString());
            sb.append('\n');
        }
        return sb.toString();
    }
    public void analyse(String code) {
        int i = 0, len = code.length(), lineNumber = 1;
        char ch;
        while (i < len) {
            ch = code.charAt(i++);
            if (ch != ' ' && ch != '\n' && ch != '\r' && ch != '\t') {
                if (Character.isLetter(ch) || ch == '_') {
                    StringBuilder sb = new StringBuilder();
                    while (i < len && (Character.isLetter(ch) || Character.isDigit(ch) ||ch == '_')) {
                        sb.append(ch);
                        ch = code.charAt(i++);
                    }
                    i--;
                    String word = sb.toString();
                    TokenName tokenName = WordToToken.word2token(word);
                    this.tokens.add(new Token(Objects.requireNonNullElse(tokenName, TokenName.IDENFR), word, lineNumber));
                }
                else if (Character.isDigit(ch)) {
                    StringBuilder sb = new StringBuilder();
                    while (i < len && Character.isDigit(ch)) {
                        sb.append(ch);
                        ch = code.charAt(i++);
                    }
                    i--;
                    String word = sb.toString();
                    this.tokens.add(new Token(TokenName.INTCON, word, lineNumber));
                }
                else if (ch == '"') {
                    StringBuilder sb = new StringBuilder();
                    while (i < len) {
                        sb.append(ch);
                        ch = code.charAt(i++);
                        if (ch == '"') {
                            sb.append(ch);
                            break;
                        }
                    }
                    String word = sb.toString();
                    this.tokens.add(new Token(TokenName.STRCON, word, lineNumber));
                }
                else if (ch == '\'') {
                    StringBuilder sb = new StringBuilder();
                    sb.append(ch);
                    ch = code.charAt(i++);
                    sb.append(ch);
                    if (ch == '\\') {
                        ch = code.charAt(i++);
                        sb.append(ch);
                    }
                    ch = code.charAt(i++);
                    sb.append(ch);
                    this.tokens.add(new Token(TokenName.CHRCON, sb.toString(), lineNumber));
                }
                else if (ch == '!' || ch == '=' || ch == '>' || ch == '<') {
                    if (code.charAt(i) == '=') {
                        this.tokens.add(new Token(WordToToken.word2token(new String(new char[]{ch, '='})), new String(new char[]{ch, '='}), lineNumber));
                        i++;
                    }
                    else {
                        this.tokens.add(new Token(WordToToken.word2token(String.valueOf(ch)), String.valueOf(ch), lineNumber));
                    }
                }
                else if (ch == '|') {
                    if (code.charAt(i) != '|') {
                        errors.add(new Error(lineNumber, 'a'));
                    }
                    else {
                        this.tokens.add(new Token(TokenName.OR, "||", lineNumber));
                    }
                    i++;
                }
                else if (ch == '&') {
                    if (code.charAt(i) != '&') {
                        this.errors.add(new Error(lineNumber, 'a'));
                    }
                    else {
                        this.tokens.add(new Token(TokenName.AND, "&&", lineNumber));
                    }
                    i++;
                }
                else if (ch == '/') {
                    if (code.charAt(i) == '/') {
                        while(i < len && ch != '\n') {
                            ch = code.charAt(i++);
                        }
                    }
                    else if (code.charAt(i) == '*') {
                        while(i < len && !(ch == '*' && code.charAt(i) == '/')) {
                            ch = code.charAt(i++);
                            lineNumber += (ch == '\n' ? 1 : 0);
                        }
                        i++;
                    }
                    else {
                        this.tokens.add(new Token(TokenName.DIV, "/", lineNumber));
                    }
                }
                else {
                    this.tokens.add(new Token(WordToToken.word2token(String.valueOf(ch)), String.valueOf(ch), lineNumber));
                }
            }
            else {
                lineNumber += (ch == '\n' ? 1 : 0);
            }
        }
    }
}
