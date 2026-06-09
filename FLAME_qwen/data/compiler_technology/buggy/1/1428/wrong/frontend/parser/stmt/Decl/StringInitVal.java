package frontend.parser.stmt.Decl;

import frontend.lexer.TokenType;

import java.util.HashSet;

public class StringInitVal extends InitVal {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.add(TokenType.STRCON);
    }

    private String stringConst;

    public StringInitVal(String stringConst) {
        this.stringConst = stringConst;
    }

    @Override
    public String toString() {
        String string = "";
        string += (TokenType.STRCON + " " + this.stringConst + "\n");
        string += "<InitVal>\n";
        return string;
    }
}
