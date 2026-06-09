package frontend.lexer;

import frontend.parser.SyntaxUnit;

public class Token implements SyntaxUnit {
    private TokenType type;
    private String content;
    private int lineNum;

    public Token(TokenType type, String content, int lineNum) {
        this.type = type;
        this.content = content;
        this.lineNum = lineNum;
    }

    public int getLineNum() {
        return lineNum;
    }

    public String getContent() {
        return content;
    }

    public TokenType getType() {
        return type;
    }

    public void setType(TokenType type) {
        this.type = type;
    }

    @Override
    public String syntaxPrint() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.getType() + " " + this.getContent() + "\n");
        return sb.toString();
    }

}
