
    package frontend.tokens;

    public class Neq extends Token {

        // constructor
        public Neq(String content, int line) {
            super(content, line);
            type = TokenType.NEQ;
        }
    }
    