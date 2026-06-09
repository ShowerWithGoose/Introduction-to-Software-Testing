
    package frontend.tokens;

    public class ContinueTK extends Token {

        // constructor
        public ContinueTK(String content, int line) {
            super(content, line);
            type = TokenType.CONTINUETK;
        }
    }
    