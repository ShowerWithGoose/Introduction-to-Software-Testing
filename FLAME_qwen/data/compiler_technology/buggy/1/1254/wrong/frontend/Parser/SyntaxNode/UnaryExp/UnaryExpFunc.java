package frontend.Parser.SyntaxNode.UnaryExp;

import frontend.Lexer.Token.Token;
import frontend.Parser.SyntaxNode.Exp;
import java.util.ArrayList;

public class UnaryExpFunc extends UnaryExp {
    private Token ident;
    private Token lParent;
    private Exp firstExp;
    private ArrayList<Exp> exps;
    private ArrayList<Token> commas;
    private Token rParent;

    public UnaryExpFunc(Token ident, Token lParent, Exp firstExp,
                        ArrayList<Exp> exps, ArrayList<Token> commas, Token rParent) {
        this.ident = ident;
        this.lParent = lParent;
        this.rParent = rParent;
        this.firstExp = firstExp;
        this.exps = exps;
        this.commas = commas;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident);
        sb.append(lParent);
        if (firstExp != null) {
            sb.append(firstExp);

            for (int i = 0; i < commas.size(); i++) {
                sb.append(commas.get(i));
                sb.append(exps.get(i));
            }

            sb.append("<FuncRParams>\n");
        }
        sb.append(rParent);
        sb.append(name + "\n");
        return sb.toString();
    }
}

