package frontend.parser.expression.lOrExp;

import frontend.lexer.Token;
import frontend.parser.SyntaxUnit;

import java.util.ArrayList;

public class EqExp implements SyntaxUnit {
    private String name = "<EqExp>";

    //EqExp-> RelExp {(==|!=)RelExp}
    private RelExp first;
    private ArrayList<Token> ops;
    private ArrayList<RelExp> relExps;

    public EqExp(RelExp first, ArrayList<Token> ops,
                 ArrayList<RelExp> relExps) {
        this.first = first;
        this.ops = ops;
        this.relExps = relExps;
    }

    @Override
    public String syntaxPrint() {
        //EqExp-> RelExp {(==|!=)RelExp}
        //EqExp â†’ RelExp | EqExp ('==' | '!=') RelExp
        StringBuilder sb = new StringBuilder();
        sb.append(first.syntaxPrint());
        sb.append(name + "\n");
        if (ops != null && relExps != null) {
            for (int i = 0; i < ops.size(); i++) {
                sb.append(ops.get(i).syntaxPrint());
                sb.append(relExps.get(i).syntaxPrint());
                sb.append(name + "\n");
            }
        }
        return sb.toString();
    }
}
