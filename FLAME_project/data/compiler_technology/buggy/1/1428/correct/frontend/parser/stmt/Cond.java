package frontend.parser.stmt;

import frontend.lexer.TokenType;
import frontend.parser.exp.LOrExp;

import java.util.HashSet;

public class Cond {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.addAll(LOrExp.FIRST);
    }

    private LOrExp lOrExp;

    public Cond(LOrExp lOrExp) {
        this.lOrExp = lOrExp;
    }

    @Override
    public String toString() {
        String string = "";
        string += this.lOrExp.toString();
        string += "<Cond>\n";
        return string;
    }
}
