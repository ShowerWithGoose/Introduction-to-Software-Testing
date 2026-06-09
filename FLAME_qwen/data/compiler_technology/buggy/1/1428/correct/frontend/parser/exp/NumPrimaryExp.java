package frontend.parser.exp;

import frontend.lexer.TokenType;

import java.util.HashSet;

public class NumPrimaryExp extends PrimaryExp {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.add(TokenType.INTCON);
    }

    private String num;

    public NumPrimaryExp(String num) {
        super();
        this.num = String.valueOf(num);
    }

    @Override
    public String toString() {
        String string = "";
        string += (TokenType.INTCON + " " + this.num + "\n");
        string += "<Number>\n";
        string += "<PrimaryExp>\n";
        return string;
    }
}
