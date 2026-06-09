package frontend.parser.exp;

import frontend.lexer.TokenType;

import java.util.ArrayList;
import java.util.HashSet;

public class MulExp {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.addAll(UnaryExp.FIRST);
    }

    private ArrayList<UnaryExp> unaryExps;
    private ArrayList<TokenType> signs;

    public MulExp(ArrayList<UnaryExp> unaryExps, ArrayList<TokenType> signs) {
        this.unaryExps = unaryExps;
        this.signs = signs;
    }

    @Override
    public String toString() {
        String string = "";
        string += this.unaryExps.get(0).toString();
        string += "<MulExp>\n";
        for (int i = 0; i < this.signs.size(); i++) {
            string += this.signs.get(i);
            if (this.signs.get(i) == TokenType.MULT) {
                string += " *\n";
            } else if (this.signs.get(i) == TokenType.DIV) {
                string += " /\n";
            } else {
                string += " %\n";
            }
            string += this.unaryExps.get(i + 1).toString();
            string += "<MulExp>\n";
        }
        return string;
    }
}
