
    package frontend.tokens;

    public class ConstTK extends Token {

        // constructor
        public ConstTK(String content, int line) {
            super(content, line);
            type = TokenType.CONSTTK;
        }
    }
    