package frontend.parser.expression.unaryexp;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.parser.Node;

public class UnaryOp implements Node {
    private final String name = "<UnaryOp>";
    private Token token;

    private TokenList tokenList;

    public UnaryOp(TokenList tokenList) {
        this.tokenList = tokenList;
    }

    public void parseUnaryOp(){
        this.token = tokenList.getNextToken();
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(token.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
