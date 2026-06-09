package frontend.parser.expression.lOrExp;

import frontend.lexer.Token;
import frontend.parser.SyntaxUnit;

import java.util.ArrayList;

public class RelExp implements SyntaxUnit {
    private String name = "<RelExp>";
    //RelExp->AddExp {('<'|'>'|'<='|'>=')AddExp}
    private AddExp first;
    private ArrayList<Token> ops;
    private ArrayList<AddExp> addExps;

    public RelExp(AddExp first, ArrayList<Token> ops, ArrayList<AddExp> addExps) {
        this.first = first;
        this.ops = ops;
        this.addExps = addExps;
    }

    @Override
    public String syntaxPrint() {
        StringBuilder sb = new StringBuilder();
        sb.append(first.syntaxPrint());
        sb.append(name + "\n");
        if (ops != null && addExps != null) {
            for (int i = 0; i < ops.size(); i++) {
                sb.append(ops.get(i).syntaxPrint());
                sb.append(addExps.get(i).syntaxPrint());
                sb.append(name + "\n");
            }
        }
        return sb.toString();
    }
}
