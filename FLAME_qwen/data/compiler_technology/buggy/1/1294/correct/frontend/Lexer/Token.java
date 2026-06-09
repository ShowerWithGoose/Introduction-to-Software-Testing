package frontend.Lexer;

import frontend.Parser.GrammarNode;

public class Token implements GrammarNode {
    private TokenType tokenType;
    private int lineNo; //行号
    private String value; //token具体的内容

    public Token(TokenType tokenType, int lineNo, String value) {
        this.tokenType = tokenType;
        this.lineNo = lineNo;
        this.value = value;
    }

    public String getValue(){
        return value;
    }

    public int getLineNo(){
        return lineNo;
    }

    public TokenType getTokenType() {
        return tokenType;
    }

    public String grammarOutput(){
        StringBuilder sb = new StringBuilder();
        sb.append(this.tokenType.toString());
        sb.append(" ");
        sb.append(this.getValue());
        sb.append("\n");
        return sb.toString();
    }
}
