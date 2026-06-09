package frontend.Parser.expression.unaryexp;

import frontend.Lexer.Token;
import frontend.Parser.GrammarNode;

public class UnaryOp implements GrammarNode {
    private final String grammarName = "<UnaryOp>";
    private Token token;

    public UnaryOp(Token token) {
        this.token = token;
    }
    @Override
    public String grammarOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.token.grammarOutput());
        sb.append(this.grammarName).append("\n");
        return sb.toString();
    }
}
