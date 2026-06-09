import java.util.ArrayList;

public class TokenStream {
    public static class Token {
        private TokenType tokenType;
        private String content;

        public Token(TokenType tokenType ,String content) {
            this.tokenType = tokenType;
            this.content = content;
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
        this.pos++;
    }

    public String toString() {
        String string = "";
        for (Token token : tokens) {
            string += token.toString() + "\n";
        }
        return string;
    }
}
