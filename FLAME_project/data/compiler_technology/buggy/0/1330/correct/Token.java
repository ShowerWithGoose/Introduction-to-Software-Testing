
public class Token {
        public String source;
        public String word;
        public TokenType type;
        public int length;
        public int curPos = 0; //
        public int lineNum = 1; //行号

        public Token(String source) {
            this.source = source;
            this.length = source.length();
        }

        public void clearToken() {
            word = "";
            type = null;
        }
    }

