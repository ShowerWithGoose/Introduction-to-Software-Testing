package syntacticanalysis.node.expression;

import lexicalanalysis.Token;

import java.util.ArrayList;

public class AddExp {
    private String name = "<AddExp>";
    private ArrayList<MulExp> mulExps;
    private ArrayList<Token> ops;

    public AddExp(ArrayList<MulExp> mulExps, ArrayList<Token> ops)
    {
        this.mulExps = mulExps;
        this.ops = ops;
    }

    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        if (mulExps.size() == 1) {
            sb.append(mulExps.get(0).syntaxOutput());
            sb.append("\n");
            sb.append(name);
        } else if (mulExps.size() > 1) {
            MulExp mulExp = mulExps.get(mulExps.size() - 1);
            mulExps.remove(mulExps.size() - 1);
            Token op = ops.get(ops.size() - 1);
            ops.remove(ops.size() - 1);
            AddExp addExp = new AddExp(mulExps, ops);
            sb.append(addExp.syntaxOutput());
            sb.append("\n");
            sb.append(op);
            sb.append("\n");
            sb.append(mulExp.syntaxOutput());
            sb.append("\n");
            sb.append(name);
        }
        return sb.toString();
    }
}
