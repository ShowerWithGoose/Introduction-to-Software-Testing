
    package frontend.tokens;

    public class RBrace extends Token {

        // constructor
        public RBrace(String content, int line) {
            super(content, line);
            type = TokenType.RBRACE;
        }
    }
    