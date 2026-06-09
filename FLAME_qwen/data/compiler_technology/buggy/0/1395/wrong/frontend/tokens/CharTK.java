
    package frontend.tokens;

    public class CharTK extends Token {

        // constructor
        public CharTK(String content, int line) {
            super(content, line);
            type = TokenType.CHARTK;
        }
    }
    