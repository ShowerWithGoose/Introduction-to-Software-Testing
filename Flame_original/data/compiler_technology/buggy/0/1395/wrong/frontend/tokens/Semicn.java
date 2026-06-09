
    package frontend.tokens;

    public class Semicn extends Token {

        // constructor
        public Semicn(String content, int line) {
            super(content, line);
            type = TokenType.SEMICN;
        }
    }
    