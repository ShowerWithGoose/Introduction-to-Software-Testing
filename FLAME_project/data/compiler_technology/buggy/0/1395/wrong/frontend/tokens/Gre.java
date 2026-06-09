
    package frontend.tokens;

    public class Gre extends Token {

        // constructor
        public Gre(String content, int line) {
            super(content, line);
            type = TokenType.GRE;
        }
    }
    