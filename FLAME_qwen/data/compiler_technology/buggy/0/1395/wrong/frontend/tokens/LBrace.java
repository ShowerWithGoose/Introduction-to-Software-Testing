
    package frontend.tokens;

    public class LBrace extends Token {

        // constructor
        public LBrace(String content, int line) {
            super(content, line);
            type = TokenType.LBRACE;
        }
    }
    