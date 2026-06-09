
    package frontend.tokens;

    public class IntTK extends Token {

        // constructor
        public IntTK(String content, int line) {
            super(content, line);
            type = TokenType.INTTK;
        }
    }
    