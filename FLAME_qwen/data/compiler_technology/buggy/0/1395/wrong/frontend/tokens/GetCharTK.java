
    package frontend.tokens;

    public class GetCharTK extends Token {

        // constructor
        public GetCharTK(String content, int line) {
            super(content, line);
            type = TokenType.GETCHARTK;
        }
    }
    