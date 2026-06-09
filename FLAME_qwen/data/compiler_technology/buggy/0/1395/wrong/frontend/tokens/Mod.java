
    package frontend.tokens;

    public class Mod extends Token {

        // constructor
        public Mod(String content, int line) {
            super(content, line);
            type = TokenType.MOD;
        }
    }
    