package parser.exp;

import lexer.Token;

import java.util.ArrayList;

public class RelExp {
    private final ArrayList<AddExp> addExps;
    private final ArrayList<Token> ops;

    public RelExp(AddExp addExp) {
        this.addExps = new ArrayList<>();
        this.addExps.add(addExp);
        this.ops = new ArrayList<>();
    }

    public void addAddExp(AddExp addExp) {
        this.addExps.add(addExp);
    }

    public void addOp(Token op) {
        this.ops.add(op);
    }

    public String toString() {
        StringBuilder str = new StringBuilder(this.addExps.get(0).toString());
        str.append("<RelExp>\n");
        for (int i = 0; i < this.ops.size(); i++) {
            Token op = this.ops.get(i);
            AddExp addExp = this.addExps.get(i + 1);
            str.append(op.getType() + " " + op.getName() + "\n");
            str.append(addExp.toString());
            str.append("<RelExp>\n");
        }
        return str.toString();
    }
}
