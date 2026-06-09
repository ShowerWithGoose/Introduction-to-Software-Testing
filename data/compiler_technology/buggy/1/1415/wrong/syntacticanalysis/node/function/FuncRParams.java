package syntacticanalysis.node.function;

import syntacticanalysis.node.expression.Exp;

import java.util.ArrayList;

public class FuncRParams {
    private String name = "<FuncRParams>";
    private ArrayList<Exp> exps;

    public FuncRParams(ArrayList<Exp> exps) {
        this.exps = exps;
    }

    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(exps.get(0).syntaxOutput());
        for (int i = 1; i < exps.size(); i++) {
            sb.append("\n");
            sb.append("COMMA ,\n");
            sb.append(exps.get(i).syntaxOutput());
        }
        sb.append("\n");
        sb.append(name);
        return sb.toString();
    }
}
