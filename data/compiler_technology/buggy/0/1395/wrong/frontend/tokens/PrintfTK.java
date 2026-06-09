
    package frontend.tokens;

    public class PrintfTK extends Token {

        // constructor
        public PrintfTK(String content, int line) {
            super(content, line);
            type = TokenType.PRINTFTK;
        }
    }
    