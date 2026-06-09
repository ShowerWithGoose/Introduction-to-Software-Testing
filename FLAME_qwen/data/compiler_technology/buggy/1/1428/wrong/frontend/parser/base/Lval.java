package frontend.parser.base;

import frontend.lexer.TokenType;
import frontend.parser.exp.Exp;

import java.util.HashSet;

public class Lval {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.add(TokenType.IDENFR);
    }

    private String Ident;
    private Exp exp;

    public Lval(String Ident, Exp exp) {
        this.Ident = Ident;
        this.exp = exp;
    }

    @Override
    public String toString() {
        String string = "";
        string += (TokenType.IDENFR + " " + this.Ident + "\n");
        if (this.exp != null) {
            string += (TokenType.LBRACK + " " + "[" + "\n");
            string += this.exp.toString();
            string += (TokenType.RBRACK + " " + "]" + "\n");
        }
        string += "<LVal>\n";
        return string;
    }
}
