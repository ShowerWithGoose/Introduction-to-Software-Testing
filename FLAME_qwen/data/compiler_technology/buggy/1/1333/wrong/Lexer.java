import lexer.Token;
import lexer.TokenType;

import java.util.ArrayList;
import java.util.HashMap;

public class Lexer {
    private static final HashMap<String, TokenType> wordTable = new HashMap<>();

    static {
        for (TokenType token : TokenType.values()) {
            if (token != TokenType.IDENT && token != TokenType.INT_CONST &&
                    token != TokenType.CHAR_CONST && token != TokenType.STRING_CONST) {
                wordTable.put(token.getName(), token);
            }
        }
    }

    private final String resource;
    private final ArrayList<Token> tokens;
    private int lineNum;

    public Lexer(String str) {
        this.resource = str;
        this.tokens = new ArrayList<>();
        this.lineNum = 1;
        int pos = 0;
        while (pos < this.resource.length()) {
            char cur = this.resource.charAt(pos);
            StringBuilder word = new StringBuilder();
            word.append(cur);
            pos++;
            if (Character.isLetter(cur) || cur == '_') {
                pos = identLexer(pos, word);
            } else if (Character.isDigit(cur)) {
                pos = numLexer(pos, word);
            } else if (cur == '\"') {
                pos = stringLexer(pos);
            } else if (cur == '\'') {
                pos = charLexer(pos);
            } else if (cur == '\n') {
                this.lineNum++;
            } else if (cur == '/') {
                pos = noteLexer(pos);
            } else if (cur == '!' || cur == '<' || cur == '>' || cur == '=') {
                if (this.resource.charAt(pos) == '=') {
                    pos++;
                    String s = cur + "=";
                    this.tokens.add(new Token(this.lineNum, wordTable.get(s), s));
                } else {
                    String s = String.valueOf(cur);
                    this.tokens.add(new Token(this.lineNum, wordTable.get(s), s));
                }
            } else if (cur == '|' || cur == '&') {
                if (this.resource.charAt(pos) == cur) {
                    pos++;
                } else {
                    ErrorSet.errorSet.add(new Error(this.lineNum, "a"));
                }
                String s = String.valueOf(cur) + cur;
                this.tokens.add(new Token(this.lineNum, wordTable.get(s), s));
            } else if (wordTable.containsKey(String.valueOf(cur))) {
                this.tokens.add(new Token(this.lineNum, wordTable.get(String.valueOf(cur)), String.valueOf(cur)));
            }
        }
    }

    public int identLexer(int pos, StringBuilder word) {
        char cur;
        while (pos < this.resource.length()) {
            cur = this.resource.charAt(pos);
            if (!Character.isLetterOrDigit(cur) && cur != '_') {
                break;
            }
            word.append(cur);
            pos++;
        }
        String s = word.toString();
        if (wordTable.containsKey(s)) {
            this.tokens.add(new Token(this.lineNum, wordTable.get(s), s));
        } else {
            this.tokens.add(new Token(this.lineNum, TokenType.IDENT, s));
        }
        return pos;
    }

    public int numLexer(int pos, StringBuilder word) {
        char cur;
        while (pos < this.resource.length()) {
            cur = this.resource.charAt(pos);
            if (!Character.isDigit(cur)) {
                break;
            }
            word.append(cur);
            pos++;
        }
        String s = word.toString();
        this.tokens.add(new Token(this.lineNum, TokenType.INT_CONST, s));
        return pos;
    }

    public int stringLexer(int pos) {
        StringBuilder str = new StringBuilder();
        str.append('\"');
        char cur;
        while (pos < this.resource.length()) {
            cur = this.resource.charAt(pos);
            if (cur == '\"') {
                str.append('\"');
                break;
            }
            str.append(cur);
            pos++;
        }
        pos++;
        String s = str.toString();
        this.tokens.add(new Token(this.lineNum, TokenType.STRING_CONST, s));
        return pos;
    }

    public int charLexer(int pos) {
        StringBuilder ch = new StringBuilder();
        ch.append('\'');
        char cur = this.resource.charAt(pos);
        ch.append(cur);
        if (cur == '\\') {
            pos++;
            cur = this.resource.charAt(pos);
            ch.append(cur);
        }
        pos++;
        pos++;
        ch.append('\'');
        String s = ch.toString();
        this.tokens.add(new Token(this.lineNum, TokenType.CHAR_CONST, s));
        return pos;
    }

    public int noteLexer(int pos) {
        char cur = this.resource.charAt(pos);
        if (cur == '/') {
            pos++;
            while (pos < this.resource.length()) {
                cur = this.resource.charAt(pos);
                pos++;
                if (cur == '\n') {
                    this.lineNum++;
                    break;
                }
            }
        } else if (cur == '*') {
            pos++;
            while (pos < this.resource.length()) {
                cur = this.resource.charAt(pos);
                pos++;
                if (cur == '*') {
                    cur = this.resource.charAt(pos);
                    pos++;
                    if (cur == '/') {
                        break;
                    }
                } else if (cur == '\n') {
                    this.lineNum++;
                }
            }
        } else {
            this.tokens.add(new Token(this.lineNum, TokenType.DIV, "/"));
        }
        return pos;
    }

    public ArrayList<Token> getTokens() {
        return this.tokens;
    }
}
