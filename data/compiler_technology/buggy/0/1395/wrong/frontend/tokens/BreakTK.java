
    package frontend.tokens;

    public class BreakTK extends Token {

        // constructor
        public BreakTK(String content, int line) {
            super(content, line);
            type = TokenType.BREAKTK;
        }
    }
    