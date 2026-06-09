package frontend.parser.exp;

import frontend.lexer.TokenType;

import java.util.ArrayList;
import java.util.HashSet;

public class AddExp {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.addAll(MulExp.FIRST);
    }

    private ArrayList<MulExp> mulExps;
    private ArrayList<TokenType> signs;

    public AddExp(ArrayList<MulExp> mulExps, ArrayList<TokenType> signs) {
        this.mulExps = mulExps;
        this.signs = signs;
    }

    @Override
    public String toString() {
        String string = "";
        string += this.mulExps.get(0).toString();
        string += "<AddExp>\n";
        for (int i = 0; i < signs.size(); i++) {
            string += this.signs.get(i);
            if (this.signs.get(i) == TokenType.PLUS) {
                string += " +\n";
            } else {
                string += " -\n";
            }
            string += this.mulExps.get(i + 1).toString();
            string += "<AddExp>\n";
        }
        return string;
    }
}
