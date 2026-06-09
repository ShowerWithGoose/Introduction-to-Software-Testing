
    package frontend.tokens;

    public class Geq extends Token {

        // constructor
        public Geq(String content, int line) {
            super(content, line);
            type = TokenType.GEQ;
        }
    }
    