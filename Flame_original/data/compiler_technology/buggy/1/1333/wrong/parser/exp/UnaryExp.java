package parser.exp;

import lexer.Token;

import java.util.ArrayList;

public class UnaryExp {
    private ArrayList<Token> unaryOp;
    private SimpleUnaryExp simpleUnaryExp;

    public UnaryExp() {
        this.unaryOp = new ArrayList<>();
        this.simpleUnaryExp = null;
    }

    public void addOp(Token op) {
        this.unaryOp.add(op);
    }

    public void setSimpleUnaryExp(SimpleUnaryExp simpleUnaryExp) {
        this.simpleUnaryExp = simpleUnaryExp;
    }

    public String toString() {
        StringBuilder str = new StringBuilder();
        for (Token op : this.unaryOp) {
            str.append(op.getType() + " " + op.getName() + "\n<UnaryOp>\n");
        }
        str.append(this.simpleUnaryExp.toString() + "<UnaryExp>\n".repeat(this.unaryOp.size() + 1));
        return str.toString();
    }
}
