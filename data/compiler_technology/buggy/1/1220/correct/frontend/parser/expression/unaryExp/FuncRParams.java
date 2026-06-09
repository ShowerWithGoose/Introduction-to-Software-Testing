package frontend.parser.expression.unaryExp;

import frontend.lexer.Token;
import frontend.parser.SyntaxUnit;
import frontend.parser.expression.Exp;

import java.util.ArrayList;

public class FuncRParams implements SyntaxUnit {
    // FuncRParams → Exp { ',' Exp }
    private String name = "<FuncRParams>";
    private Exp first;
    private ArrayList<Token> commas;
    private ArrayList<Exp> exps;

    public FuncRParams(Exp first, ArrayList<Token> commas, ArrayList<Exp> exps) {
        this.first = first;
        this.commas = commas;
        this.exps = exps;
    }

    @Override
    public String syntaxPrint() {
        //// FuncRParams → Exp { ',' Exp }
        StringBuilder sb = new StringBuilder();
        sb.append(first.syntaxPrint());
        if (commas != null && exps != null) {
            for (int i = 0; i < commas.size(); i++) {
                sb.append(commas.get(i).syntaxPrint());
                sb.append(exps.get(i).syntaxPrint());
            }
        }
        sb.append(name + "\n");
        return sb.toString();
    }
}
