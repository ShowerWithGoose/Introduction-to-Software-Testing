
    package frontend.tokens;

    public class ForTK extends Token {

        // constructor
        public ForTK(String content, int line) {
            super(content, line);
            type = TokenType.FORTK;
        }
    }
    