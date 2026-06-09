package frontend.parser.exp;

import frontend.lexer.TokenType;

import java.util.HashSet;

public class ExpPrimaryExp extends PrimaryExp {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.add(TokenType.LPARENT);
    }

    private Exp exp;

    public ExpPrimaryExp(Exp exp) {
        super();
        this.exp = exp;
    }

    @Override
    public String toString() {
        String string = "";
        string += (TokenType.LPARENT + " (\n");
        string += this.exp.toString();
        string += (TokenType.RPARENT + " )\n");
        string += "<PrimaryExp>\n";
        return string;
    }
}
