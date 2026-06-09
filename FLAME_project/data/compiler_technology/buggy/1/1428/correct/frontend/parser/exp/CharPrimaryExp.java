package frontend.parser.exp;

import frontend.lexer.TokenType;

import java.util.HashSet;

public class CharPrimaryExp extends PrimaryExp{
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.add(TokenType.CHRCON);
    }

    private String ch;

    public CharPrimaryExp(String ch) {
        super();
        this.ch = String.valueOf(ch);
    }

    @Override
    public String toString() {
        String string = "";
        string += (TokenType.CHRCON + " " + this.ch + "\n");
        string += "<Character>\n";
        string += "<PrimaryExp>\n";
        return string;
    }
}
