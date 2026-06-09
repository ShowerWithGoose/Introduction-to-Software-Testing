
    package frontend.tokens;

    public class Comma extends Token {

        // constructor
        public Comma(String content, int line) {
            super(content, line);
            type = TokenType.COMMA;
        }
    }
    