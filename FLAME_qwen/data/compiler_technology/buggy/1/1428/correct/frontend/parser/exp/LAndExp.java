package frontend.parser.exp;

import frontend.lexer.TokenType;

import java.util.ArrayList;
import java.util.HashSet;

public class LAndExp {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.addAll(EqExp.FIRST);
    }

    private ArrayList<EqExp> eqExps;
    private ArrayList<TokenType> signs;

    public LAndExp(ArrayList<EqExp> eqExps, ArrayList<TokenType> signs) {
        this.eqExps = eqExps;
        this.signs = signs;
    }

    @Override
    public String toString() {
        String string = "";
        string += this.eqExps.get(0).toString();
        string += "<LAndExp>\n";
        for (int i = 0; i < this.signs.size(); i++) {
            string += (this.signs.get(i) + " &&\n");
            string += this.eqExps.get(i + 1).toString();
            string += "<LAndExp>\n";
        }
        return string;
    }
}
