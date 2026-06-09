
    package frontend.tokens;

    public class Not extends Token {

        // constructor
        public Not(String content, int line) {
            super(content, line);
            type = TokenType.NOT;
        }
    }
    