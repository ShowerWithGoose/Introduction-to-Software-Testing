package parser.exp;

import lexer.Token;

import java.util.ArrayList;

public class EqExp {
    private final ArrayList<RelExp> relExps;
    private final ArrayList<Token> ops;

    public EqExp(RelExp relExp) {
        this.relExps = new ArrayList<>();
        this.ops = new ArrayList<>();
        this.relExps.add(relExp);
    }

    public void addRelExp(RelExp relExp) {
        this.relExps.add(relExp);
    }

    public void addOp(Token op) {
        this.ops.add(op);
    }

    public String toString() {
        StringBuilder str = new StringBuilder(this.relExps.get(0).toString());
        str.append("<EqExp>\n");
        for (int i = 0; i < this.ops.size(); i++) {
            Token op = this.ops.get(i);
            RelExp relExp = this.relExps.get(i + 1);
            str.append(op.getType() + " " + op.getName() + "\n");
            str.append(relExp.toString());
            str.append("<EqExp>\n");
        }
        return str.toString();
    }
}
