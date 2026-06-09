package frontend.parser.expression.unaryExp;

import frontend.lexer.Token;
import frontend.parser.SyntaxUnit;

public class UnaryOp implements SyntaxUnit {
    private String name = "<UnaryOp>";
    private Token op;

    // UnaryOp → '+' | '−' | '!'
    public UnaryOp(Token op) {
        this.op = op;
    }

    @Override
    public String syntaxPrint() {
        StringBuilder sb = new StringBuilder();
        sb.append(op.syntaxPrint());
        sb.append(name + "\n");
        return sb.toString();
    }
}
