package syntacticanalysis.node.init;

import lexicalanalysis.Token;
import syntacticanalysis.node.expression.Exp;

import java.util.ArrayList;

public class InitVal2 extends InitVal {
    private String name = "<InitVal>";
    private Token lbrace;
    private ArrayList<Exp> exps;
    private Token rbrace;

    public InitVal2(Token lbrace, ArrayList<Exp> exps, Token rbrace) {
        this.lbrace = lbrace;
        this.exps = exps;
        this.rbrace = rbrace;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(lbrace);
        sb.append("\n");
        if (exps.size() == 1) {
            sb.append(exps.get(0).syntaxOutput());
        } else if (exps.size() > 1) {
            sb.append(exps.get(0).syntaxOutput());
            for (int i = 1; i < exps.size(); i++) {
                sb.append("\n");
                sb.append("COMMA ,\n");
                sb.append(exps.get(i).syntaxOutput());
            }
        }
        sb.append("\n");
        sb.append(rbrace);
        sb.append("\n");
        sb.append(name);
        return sb.toString();
    }
}
