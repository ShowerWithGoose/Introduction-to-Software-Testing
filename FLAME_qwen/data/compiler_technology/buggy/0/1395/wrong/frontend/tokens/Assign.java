
    package frontend.tokens;

    public class Assign extends Token {

        // constructor
        public Assign(String content, int line) {
            super(content, line);
            type = TokenType.ASSIGN;
        }
    }
    