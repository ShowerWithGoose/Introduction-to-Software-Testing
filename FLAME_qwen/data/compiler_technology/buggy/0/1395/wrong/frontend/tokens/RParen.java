
    package frontend.tokens;

    public class RParen extends Token {

        // constructor
        public RParen(String content, int line) {
            super(content, line);
            type = TokenType.RPARENT;
        }
    }
    