package frontend.parser.init;

import frontend.lexer.Token;
import frontend.parser.expression.Exp;

import java.util.ArrayList;

public class InitValMulti implements InitValUnit{
    private Token leftBrace;
    private Token rightBrace;
    private Exp first;
    private ArrayList<Token> commas;
    private ArrayList<Exp> exps;

    public InitValMulti(Token leftBrace, Token rightBrace, Exp first,
                        ArrayList<Token> commas, ArrayList<Exp> exps) {
        this.leftBrace = leftBrace;
        this.rightBrace = rightBrace;
        this.first = first;
        this.commas = commas;
        this.exps = exps;
    }

    @Override
    public String syntaxPrint() {
        // '{' [ Exp { ',' Exp } ] '}'
        StringBuilder sb = new StringBuilder();
        sb.append(leftBrace.syntaxPrint());
        if (first != null) {
            sb.append(first.syntaxPrint());
            if (commas != null && exps != null) {
                for (int i = 0; i < commas.size(); i++) {
                    sb.append(commas.get(i).syntaxPrint());
                    sb.append(exps.get(i).syntaxPrint());
                }
            }
        }
        if (rightBrace != null) {
            sb.append(rightBrace.syntaxPrint());
        }
        return sb.toString();
    }
}
