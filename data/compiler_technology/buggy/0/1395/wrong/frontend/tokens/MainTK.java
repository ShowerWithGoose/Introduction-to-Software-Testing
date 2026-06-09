
    package frontend.tokens;

    public class MainTK extends Token {

        // constructor
        public MainTK(String content, int line) {
            super(content, line);
            type = TokenType.MAINTK;
        }
    }
    