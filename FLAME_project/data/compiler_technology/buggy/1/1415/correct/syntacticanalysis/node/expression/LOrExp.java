package syntacticanalysis.node.expression;

import java.util.ArrayList;

public class LOrExp {
    private String name = "<LOrExp>";
    private final ArrayList<LAndExp> landExps;

    public LOrExp(ArrayList<LAndExp> landExps)
    {
        this.landExps = landExps;
    }

    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        if (landExps.size() == 1) {
            sb.append(landExps.get(0).syntaxOutput());
            sb.append("\n");
            sb.append(name);
        } else if (landExps.size() > 1) {
            LAndExp landExp = landExps.get(landExps.size() - 1);
            landExps.remove(landExps.size() - 1);
            LOrExp lorExp = new LOrExp(landExps);
            sb.append(lorExp.syntaxOutput());
            sb.append("\n");
            sb.append("OR ||\n");
            sb.append(landExp.syntaxOutput());
            sb.append("\n");
            sb.append(name);
            landExps.add(landExp);
        }
        return sb.toString();
    }
}
