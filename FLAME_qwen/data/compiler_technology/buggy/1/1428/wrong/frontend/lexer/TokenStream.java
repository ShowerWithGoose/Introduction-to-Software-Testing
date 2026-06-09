package frontend.lexer;

import java.util.ArrayList;

public class TokenStream {
    public static class Token {
        private TokenType tokenType;
        private String content;
        private int lineNum;

        public Token(TokenType tokenType ,String content, int lineNum) {
            this.tokenType = tokenType;
            this.content = content;
            this.lineNum = lineNum;
        }

        public TokenType getTokenType() {
            return this.tokenType;
        }

        public String getContent() {
            return this.content;
        }

        public int getLineNum() {
            return this.lineNum;
        }

        public String toString() {
            return this.tokenType + " " + this.content;
        }
    }

    private ArrayList<Token> tokens;
    private int pos;

    public TokenStream() {
        this.tokens = new ArrayList<>();
        this.pos = 0;
    }

    public void addToken(Token token) {
        this.tokens.add(token);
    }

    public Token getToken() {
        if (this.pos >= this.tokens.size()) {
            return null;
        } else {
            return this.tokens.get(this.pos);
        }
    }

    public void move() {
        this.pos++;
    }

    public void back(int pace) {
        this.pos -= pace;
    }

    public int getPos() {
        return this.pos;
    }

    public String toString() {
        String string = "";
        for (Token token : tokens) {
            string += token.toString() + "\n";
        }
        return string;
    }
}
