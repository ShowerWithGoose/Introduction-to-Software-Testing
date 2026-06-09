
    package frontend.tokens;

    public class Eql extends Token {

        // constructor
        public Eql(String content, int line) {
            super(content, line);
            type = TokenType.EQL;
        }
    }
    