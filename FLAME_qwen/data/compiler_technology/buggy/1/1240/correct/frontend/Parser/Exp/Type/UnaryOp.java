package frontend.Parser.Exp.Type;

import frontend.Lexer.LexType;

public class UnaryOp {
    // UnaryOp → '+' | '−' | '!'
    private final LexType op;

    public UnaryOp(LexType op) {
        this.op = op;
    }

    @Override
    public String toString() {
        return op.toString() + "<UnaryOp>\n";
    }
}
