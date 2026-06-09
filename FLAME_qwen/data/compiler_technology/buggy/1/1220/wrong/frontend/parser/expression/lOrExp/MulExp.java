package frontend.parser.expression.lOrExp;

import frontend.lexer.Token;
import frontend.parser.SyntaxUnit;
import frontend.parser.expression.unaryExp.UnaryExp;

import java.util.ArrayList;

public class MulExp implements SyntaxUnit {
    private String name = "<MulExp>";
    // MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
    // MulExp —> UnaryExp{('*'|'/'|'%')UnaryExp}
    private UnaryExp first;
    private ArrayList<Token> ops;
    private ArrayList<UnaryExp> unaryExps;

    public MulExp(UnaryExp first, ArrayList<Token> ops,
                  ArrayList<UnaryExp> unaryExps) {
        this.first = first;
        this.ops = ops;
        this.unaryExps = unaryExps;
    }


    @Override
    public String syntaxPrint() {
        StringBuilder sb = new StringBuilder();
        sb.append(first.syntaxPrint());
        sb.append(name + "\n");
        if (ops != null && unaryExps != null) {
            for (int i = 0; i < ops.size(); i++) {
                sb.append(ops.get(i).syntaxPrint());
                sb.append(unaryExps.get(i).syntaxPrint());
                sb.append(name + "\n");
            }
        }
        return sb.toString();
    }
}
