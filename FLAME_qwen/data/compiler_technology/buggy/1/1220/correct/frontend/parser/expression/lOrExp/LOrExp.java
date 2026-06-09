package frontend.parser.expression.lOrExp;

import frontend.lexer.Token;
import frontend.parser.SyntaxUnit;

import java.util.ArrayList;

public class LOrExp implements SyntaxUnit {
    private String name = "<LOrExp>";
    //LOrExp -> LAndExp {|| LAndExp}
    private LAndExp first;
    private ArrayList<Token> ops;
    private ArrayList<LAndExp> lAndExps;

    public LOrExp(LAndExp first, ArrayList<Token> ops,
                  ArrayList<LAndExp> lAndExps) {
        this.first = first;
        this.ops = ops;
        this.lAndExps = lAndExps;
    }


    @Override
    public String syntaxPrint() {
        //LAndExp | LOrExp '||' LAndExp
        StringBuilder sb = new StringBuilder();
        sb.append(first.syntaxPrint());
        sb.append(name + "\n");
        if (ops != null && lAndExps != null) {
            for (int i = 0; i < ops.size(); i++) {
                sb.append(ops.get(i).syntaxPrint());
                sb.append(lAndExps.get(i).syntaxPrint());
                sb.append(name + "\n");
            }
        }
        return sb.toString();
    }
}
