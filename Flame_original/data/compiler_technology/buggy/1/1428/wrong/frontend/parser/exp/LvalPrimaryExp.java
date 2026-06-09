package frontend.parser.exp;

import frontend.lexer.TokenType;
import frontend.parser.base.Lval;

import java.util.HashSet;

public class LvalPrimaryExp extends PrimaryExp {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.addAll(Lval.FIRST);
    }

    private Lval lval;

    public LvalPrimaryExp(Lval lval) {
        super();
        this.lval = lval;
    }

    @Override
    public String toString() {
        String string = "";
        string += this.lval.toString();
        string += "<PrimaryExp>\n";
        return string;
    }
}
