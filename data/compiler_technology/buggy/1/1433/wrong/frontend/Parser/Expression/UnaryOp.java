package frontend.Parser.Expression;

import frontend.Lexer.Token;
import frontend.Parser.ASTNode;

public class UnaryOp implements ASTNode {
    private Token token;    // '+' '-' '!' ('!'仅出现在条件表达式)

    public UnaryOp(Token token) {
        this.token = token;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(token.toString());
        sb.append("<" + "UnaryOp" + ">\n");
        return sb.toString();
    }
}
