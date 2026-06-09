
    package frontend.tokens;

    public class Leq extends Token {

        // constructor
        public Leq(String content, int line) {
            super(content, line);
            type = TokenType.LEQ;
        }
    }
    