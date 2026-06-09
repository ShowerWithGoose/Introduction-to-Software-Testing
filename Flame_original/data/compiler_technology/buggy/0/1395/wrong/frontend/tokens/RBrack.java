
    package frontend.tokens;

    public class RBrack extends Token {

        // constructor
        public RBrack(String content, int line) {
            super(content, line);
            type = TokenType.RBRACK;
        }
    }
    