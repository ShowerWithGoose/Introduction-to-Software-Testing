package frontend.Parser.SyntaxNode.ConstInitVal;
import frontend.Lexer.Token.Token;
import frontend.Parser.SyntaxNode.ConstExp;

import java.util.ArrayList;

/*
 '{' [ ConstExp { ',' ConstExp } ] '}'
 */
public class ConstInitValExps extends ConstInitVal {
    private Token lbrace;
    private ConstExp firstConstExp = null;
    private ArrayList<ConstExp> constExps;
    private ArrayList<Token> commas;
    private Token rbrace;

    public ConstInitValExps(Token lbrace, ConstExp firstConstExp, ArrayList<ConstExp> constExps,
                            ArrayList<Token> commas, Token rbrace) {
        this.lbrace = lbrace;
        this.rbrace = rbrace;
        this.firstConstExp = firstConstExp;
        this.constExps = constExps;
        this.commas = commas;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(lbrace);
        if (firstConstExp != null) {
            sb.append(firstConstExp);
        }

        for (int i = 0; i < constExps.size(); i++) {
            sb.append(commas.get(i));
            sb.append(constExps.get(i));
        }

        sb.append(rbrace);
        sb.append(name + "\n");
        return sb.toString();
    }
}
