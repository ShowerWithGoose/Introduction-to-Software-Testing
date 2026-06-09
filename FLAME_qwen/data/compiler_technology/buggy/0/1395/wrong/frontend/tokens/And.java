
    package frontend.tokens;

    public class And extends Token {

        // constructor
        public And(String content, int line) {
            super(content, line);
            type = TokenType.AND;
        }
    }
    