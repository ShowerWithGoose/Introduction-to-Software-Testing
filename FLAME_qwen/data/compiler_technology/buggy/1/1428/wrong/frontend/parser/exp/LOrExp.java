package frontend.parser.exp;

import frontend.lexer.TokenStream;
import frontend.lexer.TokenType;
import frontend.parser.base.Lval;

import java.util.ArrayList;
import java.util.HashSet;

public class LOrExp {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.addAll(LAndExp.FIRST);
    }

    private ArrayList<LAndExp> lAndExps;
    private ArrayList<TokenType> signs;

    public LOrExp(ArrayList<LAndExp> lAndExps, ArrayList<TokenType> signs) {
        this.lAndExps = lAndExps;
        this.signs = signs;
    }

    @Override
    public String toString() {
        String string = "";
        string += this.lAndExps.get(0).toString();
        string += "<LOrExp>\n";
        for (int i = 0; i < this.signs.size(); i++) {
            string += (this.signs.get(i) + " ||\n");
            string += this.lAndExps.get(i + 1).toString();
            string += "<LOrExp>\n";
        }
        return string;
    }
}
