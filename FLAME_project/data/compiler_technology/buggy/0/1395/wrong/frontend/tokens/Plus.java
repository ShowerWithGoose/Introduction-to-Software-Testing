
    package frontend.tokens;

    public class Plus extends Token {

        // constructor
        public Plus(String content, int line) {
            super(content, line);
            type = TokenType.PLUS;
        }
    }
    