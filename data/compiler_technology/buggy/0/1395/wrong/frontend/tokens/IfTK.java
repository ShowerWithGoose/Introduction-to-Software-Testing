
    package frontend.tokens;

    public class IfTK extends Token {

        // constructor
        public IfTK(String content, int line) {
            super(content, line);
            type = TokenType.IFTK;
        }
    }
    