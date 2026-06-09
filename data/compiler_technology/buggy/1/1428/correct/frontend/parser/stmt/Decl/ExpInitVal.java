package frontend.parser.stmt.Decl;

import frontend.lexer.TokenType;
import frontend.parser.exp.Exp;

import java.util.HashSet;

public class ExpInitVal extends InitVal {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.addAll(Exp.FIRST);
    }

    private Exp exp;

    public ExpInitVal(Exp exp) {
        this.exp = exp;
    }

    @Override
    public String toString() {
        String string = "";
        string += this.exp.toString();
        string += "<InitVal>\n";
        return string;
    }
}
