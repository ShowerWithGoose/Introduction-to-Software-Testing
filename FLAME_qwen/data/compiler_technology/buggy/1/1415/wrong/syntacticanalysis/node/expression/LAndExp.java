package syntacticanalysis.node.expression;

import java.util.ArrayList;

public class LAndExp {
    private String name = "<LAndExp>";
    private ArrayList<EqExp> eqExps;

    public LAndExp(ArrayList<EqExp> eqExps)
    {
        this.eqExps = eqExps;
    }

    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        if (eqExps.size() == 1) {
            sb.append(eqExps.get(0).syntaxOutput());
            sb.append("\n");
            sb.append(name);
        } else if (eqExps.size() > 1) {
            EqExp eqExp = eqExps.get(eqExps.size() - 1);
            eqExps.remove(eqExps.size() - 1);
            LAndExp landExp = new LAndExp(eqExps);
            sb.append(landExp.syntaxOutput());
            sb.append("\n");
            sb.append("AND &&\n");
            sb.append(eqExp.syntaxOutput());
            sb.append("\n");
            sb.append(name);
            eqExps.add(eqExp);
        }
        return sb.toString();
    }

}
