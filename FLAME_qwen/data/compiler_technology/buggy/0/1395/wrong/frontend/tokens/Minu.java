
    package frontend.tokens;

    public class Minu extends Token {

        // constructor
        public Minu(String content, int line) {
            super(content, line);
            type = TokenType.MINU;
        }
    }
    