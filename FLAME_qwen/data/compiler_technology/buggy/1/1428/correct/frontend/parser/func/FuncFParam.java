package frontend.parser.func;

import frontend.lexer.TokenType;

import java.util.HashSet;

public class FuncFParam {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.add(TokenType.INTTK);
        FIRST.add(TokenType.CHARTK);
    }

    private TokenType BType;
    private String Ident;
    private boolean isArray;

    public FuncFParam(TokenType BType, String Ident, boolean isArray) {
        this.BType = BType;
        this.Ident = Ident;
        this.isArray = isArray;
    }

    @Override
    public String toString() {
        String string = "";
        string += this.BType;
        if (this.BType == TokenType.INTTK) {
            string += " int\n";
        } else {
            string += " char\n";
        }
        string += (TokenType.IDENFR + " " + this.Ident + "\n");
        if (this.isArray) {
            string += (TokenType.LBRACK + " [\n");
            string += (TokenType.RBRACK + " ]\n");
        }
        string += "<FuncFParam>\n";
        return string;
    }
}
