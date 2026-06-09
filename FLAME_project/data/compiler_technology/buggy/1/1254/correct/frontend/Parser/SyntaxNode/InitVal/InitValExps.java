package frontend.Parser.SyntaxNode.InitVal;

import frontend.Lexer.Token.Token;
import frontend.Parser.SyntaxNode.Exp;
import java.util.ArrayList;
/*
 '{' [ ConstExp { ',' ConstExp } ] '}'
 */
public class InitValExps extends InitVal {
    private Token lbrace;
    private Exp firstExp = null;
    private ArrayList<Exp> exps;
    private ArrayList<Token> commas;
    private Token rbrace;

    public InitValExps(Token lbrace, Exp firstExp, ArrayList<Exp> exps,
                       ArrayList<Token> commas, Token rbrace) {
        this.lbrace = lbrace;
        this.rbrace = rbrace;
        this.firstExp = firstExp;
        this.exps = exps;
        this.commas = commas;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(lbrace);
        if (firstExp != null) {
            sb.append(firstExp);
        }
        for (int i = 0; i < exps.size(); i++) {
            sb.append(commas.get(i));
            sb.append(exps.get(i));
        }
        sb.append(rbrace);
        sb.append(name + "\n");
        return sb.toString();
    }
}
