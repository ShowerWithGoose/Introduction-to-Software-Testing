package struct;

import token.Token;

/* UnaryOp → '+' | '−' | '!' 注：'!'仅出现在条件表达式中 */
public class UnaryOp {
    private final Token operator;

    public UnaryOp(Token operator) {
        this.operator = operator;
    }

    public Token getOperator() {
        return operator;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(operator.toString());
        sb.append("<UnaryOp>\n");
        return sb.toString();
    }
}
