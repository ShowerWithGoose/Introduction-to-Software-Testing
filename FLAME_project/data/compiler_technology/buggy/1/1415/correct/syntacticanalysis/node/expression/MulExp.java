package syntacticanalysis.node.expression;

import lexicalanalysis.Token;

import java.util.ArrayList;

public class MulExp {
    private String name = "<MulExp>";
    private final ArrayList<UnaryExp> unaryExps;
    private final ArrayList<Token> ops;

    public MulExp(ArrayList<UnaryExp> unaryExps, ArrayList<Token> ops) {
        this.unaryExps = unaryExps;
        this.ops = ops;
    }

    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        if (unaryExps.size() == 1) {
            sb.append(unaryExps.get(0).syntaxOutput());
            sb.append("\n");
            sb.append(name);
        } else if (unaryExps.size() > 1) {
            UnaryExp unaryExp = unaryExps.get(unaryExps.size() - 1);
            unaryExps.remove(unaryExps.size() - 1);
            Token op = ops.get(ops.size() - 1);
            ops.remove(ops.size() - 1);
            MulExp mulExp = new MulExp(unaryExps, ops);
            sb.append(mulExp.syntaxOutput());
            sb.append("\n");
            sb.append(op);
            sb.append("\n");
            sb.append(unaryExp.syntaxOutput());
            sb.append("\n");
            sb.append(name);
            unaryExps.add(unaryExp);
            ops.add(op);
        }
        return sb.toString();
    }
}
