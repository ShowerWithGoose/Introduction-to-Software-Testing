
    package frontend.tokens;

    public class Or extends Token {

        // constructor
        public Or(String content, int line) {
            super(content, line);
            type = TokenType.OR;
        }
    }
    