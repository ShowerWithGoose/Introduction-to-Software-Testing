
    package frontend.tokens;

    public class LBrack extends Token {

        // constructor
        public LBrack(String content, int line) {
            super(content, line);
            type = TokenType.LBRACK;
        }
    }
    