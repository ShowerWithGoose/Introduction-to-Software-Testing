package parser.exp;

import lexer.Token;

import java.util.ArrayList;

public class AddExp {
    private final ArrayList<MulExp> mulExps;
    private final ArrayList<Token> ops;

    public AddExp(MulExp mulExp) {
        this.mulExps = new ArrayList<>();
        this.mulExps.add(mulExp);
        this.ops = new ArrayList<>();
    }

    public void addMulExp(MulExp mulExp) {
        this.mulExps.add(mulExp);
    }

    public void addOp(Token op) {
        this.ops.add(op);
    }

    public String toString() {
        StringBuilder str = new StringBuilder(this.mulExps.get(0).toString());
        str.append("<AddExp>\n");
        for (int i = 0; i < this.ops.size(); i++) {
            Token op = this.ops.get(i);
            MulExp mulExp = this.mulExps.get(i + 1);
            str.append(op.getType() + " " + op.getName() + "\n");
            str.append(mulExp.toString());
            str.append("<AddExp>\n");
        }
        return str.toString();
    }
}
