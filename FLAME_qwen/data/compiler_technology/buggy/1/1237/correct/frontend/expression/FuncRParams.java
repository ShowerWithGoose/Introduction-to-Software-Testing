package frontend.expression;

import frontend.Token;
import frontend.SyntaxNode;
import java.util.ArrayList;

/**
 * 函数实参表
 */
public class FuncRParams implements SyntaxNode {
    private final String name = "<FuncRParams>";
    private final Exp first;
    private final ArrayList<Token> commas;
    private final ArrayList<Exp> exps;

    public FuncRParams(Exp first, ArrayList<Token> commas, ArrayList<Exp> exps) {
        if (first == null) {
            throw new IllegalArgumentException("First expression cannot be null");
        }
        if ((commas != null && exps != null) && commas.size() != exps.size()) {
            throw new IllegalArgumentException("Commas and expressions must have the same size");
        }
        this.first = first;
        this.commas = commas;
        this.exps = exps;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(first.syntaxOutput());
        if (commas != null && exps != null) {
            int len = commas.size();
            for (int i = 0; i < len; i++) {
                sb.append(commas.get(i).syntaxOutput());
                sb.append(exps.get(i).syntaxOutput());
            }
        }
        sb.append(name).append("\n");
        return sb.toString();
    }

    @Override
    public String toString() {
        return syntaxOutput();
    }
}