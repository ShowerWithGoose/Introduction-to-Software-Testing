package syntacticanalysis.node.function;

import java.util.ArrayList;

public class FuncFParams {
    private String name = "<FuncFParams>";
    private ArrayList<FuncFParam> funcFParams;

    public FuncFParams(ArrayList<FuncFParam> funcFParams) {
        this.funcFParams = funcFParams;
    }

    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        if (funcFParams != null) {
            sb.append(funcFParams.get(0).syntaxOutput());
            if (funcFParams.size() > 1) {
                for (int i = 1; i < funcFParams.size(); i++) {
                    sb.append("\n");
                    sb.append("COMMA ,\n");
                    sb.append(funcFParams.get(i).syntaxOutput());
                }
            }
            sb.append("\n");
        }
        sb.append(name);
        return sb.toString();
    }
}
