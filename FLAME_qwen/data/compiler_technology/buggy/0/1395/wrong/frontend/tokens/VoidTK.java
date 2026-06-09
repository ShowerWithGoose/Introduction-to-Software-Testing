
    package frontend.tokens;

    public class VoidTK extends Token {

        // constructor
        public VoidTK(String content, int line) {
            super(content, line);
            type = TokenType.VOIDTK;
        }
    }
    