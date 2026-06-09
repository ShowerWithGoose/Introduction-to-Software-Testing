
    package frontend.tokens;

    public class LParen extends Token {

        // constructor
        public LParen(String content, int line) {
            super(content, line);
            type = TokenType.LPARENT;
        }
    }
    