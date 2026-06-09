package frontend.parser.exp;

import frontend.lexer.TokenType;

import java.util.ArrayList;
import java.util.HashSet;

public class RelExp {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.addAll(AddExp.FIRST);
    }

    private ArrayList<AddExp> addExps;
    private ArrayList<TokenType> signs;

    public RelExp(ArrayList<AddExp> addExps, ArrayList<TokenType> signs) {
        this.addExps = addExps;
        this.signs = signs;
    }

    @Override
    public String toString() {
        String string = "";
        string += this.addExps.get(0).toString();
        string += "<RelExp>\n";
        for (int i = 0; i < this.signs.size(); i++) {
            string += this.signs.get(i);
            if (this.signs.get(i) == TokenType.LSS) {
                string += " <\n";
            } else if (this.signs.get(i) == TokenType.LEQ) {
                string += " <=\n";
            } else if (this.signs.get(i) == TokenType.GRE) {
                string += " >\n";
            } else {
                string += " >=\n";
            }
            string += this.addExps.get(i + 1).toString();
            string += "<RelExp>\n";
        }
        return string;
    }
}
