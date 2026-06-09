package frontend.parser.exp;

import frontend.lexer.TokenType;

import java.util.HashSet;

public class ConstExp {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.addAll(AddExp.FIRST);
    }

    private AddExp addExp;

    public ConstExp(AddExp addExp) {
        this.addExp = addExp;
    }

    @Override
    public String toString() {
        String string = "";
        string += this.addExp.toString();
        string += "<ConstExp>\n";
        return string;
    }
}
