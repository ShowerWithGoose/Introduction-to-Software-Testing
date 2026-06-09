
    package frontend.tokens;

    public class GetIntTK extends Token {

        // constructor
        public GetIntTK(String content, int line) {
            super(content, line);
            type = TokenType.GETINTTK;
        }
    }
    