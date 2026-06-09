
    package frontend.tokens;

    public class Mult extends Token {

        // constructor
        public Mult(String content, int line) {
            super(content, line);
            type = TokenType.MULT;
        }
    }
    