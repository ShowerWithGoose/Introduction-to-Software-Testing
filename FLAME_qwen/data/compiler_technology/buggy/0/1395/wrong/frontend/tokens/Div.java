
    package frontend.tokens;

    public class Div extends Token {

        // constructor
        public Div(String content, int line) {
            super(content, line);
            type = TokenType.DIV;
        }
    }
    