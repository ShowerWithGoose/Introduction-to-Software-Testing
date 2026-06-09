package frontend.parser.exp;

import frontend.lexer.TokenType;

import java.util.HashSet;

public class Exp {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.addAll(AddExp.FIRST);
    }

    private AddExp addExp;

    public Exp(AddExp addExp) {
        this.addExp = addExp;
    }

    @Override
    public String toString() {
        String string = "";
        string += this.addExp.toString();
        string += "<Exp>\n";
        return string;
    }
}
