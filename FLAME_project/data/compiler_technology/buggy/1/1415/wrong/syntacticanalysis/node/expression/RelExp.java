package syntacticanalysis.node.expression;

import lexicalanalysis.Token;

import java.util.ArrayList;

public class RelExp {
    private String name = "<RelExp>";
    private ArrayList<AddExp> addExps;
    private ArrayList<Token> ops;

    public RelExp(ArrayList<AddExp> addExps, ArrayList<Token> ops)
    {
        this.addExps = addExps;
        this.ops = ops;
    }

    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        if (addExps.size() == 1) {
            sb.append(addExps.get(0).syntaxOutput());
            sb.append("\n");
            sb.append(name);
        } else if (addExps.size() > 1) {
            AddExp addExp = addExps.get(addExps.size() - 1);
            addExps.remove(addExps.size() - 1);
            Token op = ops.get(ops.size() - 1);
            ops.remove(ops.size() - 1);
            RelExp relExp = new RelExp(addExps, ops);
            sb.append(relExp.syntaxOutput());
            sb.append("\n");
            sb.append(op);
            sb.append("\n");
            sb.append(addExp.syntaxOutput());
            sb.append("\n");
            sb.append(name);
            addExps.add(addExp);
            ops.add(op);
        }
        return sb.toString();
    }
}
