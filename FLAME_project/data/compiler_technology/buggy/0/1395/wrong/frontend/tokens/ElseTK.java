
    package frontend.tokens;

    public class ElseTK extends Token {

        // constructor
        public ElseTK(String content, int line) {
            super(content, line);
            type = TokenType.ELSETK;
        }
    }
    