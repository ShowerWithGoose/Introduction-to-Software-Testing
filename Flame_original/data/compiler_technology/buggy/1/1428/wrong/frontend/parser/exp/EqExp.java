package frontend.parser.exp;

import frontend.lexer.TokenType;

import java.util.ArrayList;
import java.util.HashSet;

public class EqExp {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static  {
        FIRST.addAll(RelExp.FIRST);
    }

    private ArrayList<RelExp> relExps;
    private ArrayList<TokenType> signs;

    public EqExp(ArrayList<RelExp> relExps, ArrayList<TokenType> signs) {
        this.relExps = relExps;
        this.signs = signs;
    }

    @Override
    public String toString() {
        String string = "";
        string += this.relExps.get(0).toString();
        string += "<EqExp>\n";
        for (int i = 0; i < this.signs.size(); i++) {
            string += (this.signs.get(i));
            if (this.signs.get(i) == TokenType.EQL) {
                string += " ==\n";
            } else {
                string += " !=\n";
            }
            string += this.relExps.get(i + 1).toString();
            string += "<EqExp>\n";
        }
        return string;
    }
}
