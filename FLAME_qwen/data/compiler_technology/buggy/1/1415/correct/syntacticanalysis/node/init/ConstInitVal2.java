package syntacticanalysis.node.init;

import lexicalanalysis.Token;
import syntacticanalysis.node.expression.ConstExp;

import java.util.ArrayList;

public class ConstInitVal2 extends ConstInitVal {
    private String name = "<ConstInitVal>";
    private Token lbrace;
    private ArrayList<ConstExp> constExps;
    private Token rbrace;

    public ConstInitVal2(Token lbrace, ArrayList<ConstExp> constExps, Token rbrace) {
        this.lbrace = lbrace;
        this.constExps = constExps;
        this.rbrace = rbrace;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(lbrace);
        if (constExps.size() == 1) {
            sb.append("\n");
            sb.append(constExps.get(0).syntaxOutput());
        } else if (constExps.size() > 1) {
            sb.append("\n");
            sb.append(constExps.get(0).syntaxOutput());
            for (int i = 1; i < constExps.size(); i++) {
                sb.append("\n");
                sb.append("COMMA ,\n");
                sb.append(constExps.get(i).syntaxOutput());
            }
        }
        sb.append("\n");
        sb.append(rbrace);
        sb.append("\n");
        sb.append(name);
        return sb.toString();
    }
}
