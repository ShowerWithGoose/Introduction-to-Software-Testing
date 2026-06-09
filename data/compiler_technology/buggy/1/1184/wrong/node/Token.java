package node;

import node.TreeNode;

public class Token implements TreeNode {
    private String content;
    private TokenType tokenType;
    private int lineNum;

    public Token(String content, TokenType tokenType, int lineNum) {
        super();
        this.content = content;
        this.tokenType = tokenType;
        this.lineNum = lineNum;
    }

    public String getIdent() {
        return content;
    }

    public int getLine() {
        return lineNum;
    }

    @Override
    public String toString() {
        return tokenType.toString() + " " + content;
    }

    @Override
    public void print(){
        System.out.println(tokenType.toString() + " " + content);
    }

    public TokenType getTokenType() {
        return tokenType;
    }

    public boolean isIdent() {
        return tokenType.equals(TokenType.IDENFR);
    }

}
