
    package frontend.tokens;

    public class Lss extends Token {

        // constructor
        public Lss(String content, int line) {
            super(content, line);
            type = TokenType.LSS;
        }
    }
    