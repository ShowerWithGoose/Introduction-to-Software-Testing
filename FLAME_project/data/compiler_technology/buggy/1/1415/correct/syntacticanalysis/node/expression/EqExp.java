package syntacticanalysis.node.expression;

import lexicalanalysis.Token;

import java.util.ArrayList;

public class EqExp {
    private String name = "<EqExp>";
    private final ArrayList<RelExp> relExps;
    private final ArrayList<Token> ops;

    public EqExp(ArrayList<RelExp> relExps, ArrayList<Token> ops)
    {
        this.relExps = relExps;
        this.ops = ops;
    }

    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        if (relExps.size() == 1) {
            sb.append(relExps.get(0).syntaxOutput());
            sb.append("\n");
            sb.append(name);
        } else if (relExps.size() > 1) {
            RelExp relExp = relExps.get(relExps.size() - 1);
            relExps.remove(relExps.size() - 1);
            Token op = ops.get(ops.size() - 1);
            ops.remove(ops.size() - 1);
            EqExp eqExp = new EqExp(relExps, ops);
            sb.append(eqExp.syntaxOutput());
            sb.append("\n");
            sb.append(op);
            sb.append("\n");
            sb.append(relExp.syntaxOutput());
            sb.append("\n");
            sb.append(name);
            relExps.add(relExp);
            ops.add(op);
        }
        return sb.toString();
    }
}
