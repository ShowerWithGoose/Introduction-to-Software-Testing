package frontend.parser.expression.lOrExp;

import frontend.lexer.Token;
import frontend.parser.SyntaxUnit;

import java.util.ArrayList;

public class LAndExp implements SyntaxUnit {
    private String name = "<LAndExp>";
    //LAndExp -> EqExp {&& EqExp}
    private EqExp first;
    private ArrayList<Token> ops;
    private ArrayList<EqExp> eqExps;

    public LAndExp(EqExp first, ArrayList<Token> ops,
                   ArrayList<EqExp> eqExps) {
        this.first = first;
        this.ops = ops;
        this.eqExps = eqExps;
    }

    @Override
    public String syntaxPrint() {
        //LAndExp â†’ EqExp | LAndExp '&&' EqExp
        //LAndExp -> EqExp {&& EqExp}
        StringBuilder sb = new StringBuilder();
        sb.append(first.syntaxPrint());
        sb.append(name + "\n");
        if (ops != null && eqExps != null) {
            for (int i = 0; i < ops.size(); i++) {
                sb.append(ops.get(i).syntaxPrint());
                sb.append(eqExps.get(i).syntaxPrint());
                sb.append(name + "\n");
            }
        }
        return sb.toString();
    }
}
