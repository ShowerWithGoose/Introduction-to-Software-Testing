package frontend;
public class Token {
    private Lexer.Symbol type; // this.TokenType
    private int lineNum; // this.lineNum
    private String content; // this.content


    public Token(Lexer.Symbol type, int lineNum, String content) {
        this.type = type;
        this.lineNum = lineNum;
        this.content = content;
    }

    public String getContent() {
        return content;
    }

    public int getLineNum() {
        return lineNum;
    }

    public Lexer.Symbol getType() {
        return type;
    }

    public void setType(Lexer.Symbol type) {
        this.type = type;
    }

    public void setContent(String content) {
        this.content = content;
    }

    public void setLineNum(int lineNum) {
        this.lineNum = lineNum;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.type + " " + this.content + "\n");
        return sb.toString();
    }
}
