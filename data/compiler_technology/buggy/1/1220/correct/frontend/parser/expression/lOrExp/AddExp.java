package frontend.parser.expression.lOrExp;

import frontend.lexer.Token;
import frontend.parser.SyntaxUnit;

import java.util.ArrayList;

public class AddExp implements SyntaxUnit {
    // AddExp → MulExp | AddExp ('+' | '−') MulExp
    //MulExp {('+'|'-')MulExp}
    private String name = "<AddExp>";
    private MulExp first;
    private ArrayList<Token> ops;
    private ArrayList<MulExp> mulExps;

    public AddExp(MulExp first, ArrayList<Token> ops,
                  ArrayList<MulExp> mulExps) {
        this.first = first;
        this.ops = ops;
        this.mulExps = mulExps;
    }


    @Override
    public String syntaxPrint() {
        //// AddExp → MulExp | AddExp ('+' | '−') MulExp
        //    //MulExp {('+'|'-')MulExp}
        StringBuilder sb = new StringBuilder();
        sb.append(first.syntaxPrint());
        sb.append(name + "\n");
        if (ops != null && !ops.isEmpty()
        && mulExps != null && !mulExps.isEmpty()) {
            for (int i = 0; i < ops.size(); i++) {
                sb.append(ops.get(i).syntaxPrint());
                sb.append(mulExps.get(i).syntaxPrint());
                sb.append(name + "\n");
            }
        }
        return sb.toString();
    }
}
