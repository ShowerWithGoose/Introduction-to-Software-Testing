package frontend.SyntaxUnits.Exps;

import frontend.SyntaxUnits.SyntaxUnit;
import frontend.Token;

public class UnaryOp implements SyntaxUnit {
    private final Token op;

    public UnaryOp(Token op) {
        this.op = op;
    }

    @Override
    public String toPrint() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(op.toPrint());
        stringBuilder.append("<UnaryOp>\n");
        return stringBuilder.toString();
    }
}
