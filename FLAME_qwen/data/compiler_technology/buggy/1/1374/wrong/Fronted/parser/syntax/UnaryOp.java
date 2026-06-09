package Fronted.parser.syntax;

import Fronted.lexer.Token;

//  UnaryOp → '+' | '−' | '!'
public class UnaryOp {

    private static final String name = "<UnaryOp>";

    private Token op = null;

    public UnaryOp(Token op) {
        this.op = op;
    }

    @Override
    public String toString() {
        StringBuilder out = new StringBuilder();
        out.append(op);
        out.append(name).append("\n");
        return out.toString();
    }

    public Token getOp() {
        return op;
    }

    public void setOp(Token op) {
        this.op = op;
    }
}
