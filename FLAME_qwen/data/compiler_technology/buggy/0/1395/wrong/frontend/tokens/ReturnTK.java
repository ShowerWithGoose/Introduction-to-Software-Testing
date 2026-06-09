
    package frontend.tokens;

    public class ReturnTK extends Token {

        // constructor
        public ReturnTK(String content, int line) {
            super(content, line);
            type = TokenType.RETURNTK;
        }
    }
    