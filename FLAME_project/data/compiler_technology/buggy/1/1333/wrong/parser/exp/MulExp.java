package parser.exp;

import lexer.Token;

import java.util.ArrayList;

public class MulExp {
    private final ArrayList<UnaryExp> unaryExps;
    private final ArrayList<Token> ops;

    public MulExp(UnaryExp unaryExp) {
        this.unaryExps = new ArrayList<>();
        this.unaryExps.add(unaryExp);
        this.ops = new ArrayList<>();
    }

    public void addUnaryExp(UnaryExp unaryExp) {
        this.unaryExps.add(unaryExp);
    }

    public void addOp(Token op) {
        this.ops.add(op);
    }

    public String toString() {
        StringBuilder str = new StringBuilder(this.unaryExps.get(0).toString());
        str.append("<MulExp>\n");
        for (int i = 0; i < this.ops.size(); i++) {
            Token op = this.ops.get(i);
            UnaryExp unaryExp = this.unaryExps.get(i + 1);
            str.append(op.getType() + " " + op.getName() + "\n");
            str.append(unaryExp.toString());
            str.append("<MulExp>\n");
        }
        return str.toString();
    }
}
