package frontend.parser.stmt.Decl;

import frontend.lexer.TokenType;

import java.util.HashSet;

public class StringConstInitVal extends ConstInitVal {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.add(TokenType.STRCON);
    }

    private String stringConst;

    public StringConstInitVal(String stringConst) {
        this.stringConst = stringConst;
    }

    @Override
    public String toString() {
        String string = "";
        string += (TokenType.STRCON + " " + this.stringConst + "\n");
        string += "<ConstInitVal>\n";
        return string;
    }
}
