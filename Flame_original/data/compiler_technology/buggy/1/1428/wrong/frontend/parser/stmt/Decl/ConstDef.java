package frontend.parser.stmt.Decl;

import frontend.lexer.TokenType;
import frontend.parser.exp.ConstExp;

import java.util.HashSet;

public class ConstDef {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.add(TokenType.IDENFR);
    }

    private String Ident;
    private ConstExp constExp;
    private ConstInitVal constInitVal;

    public ConstDef(String Ident, ConstExp constExp, ConstInitVal constInitVal) {
        this.Ident = Ident;
        this.constExp = constExp;
        this.constInitVal = constInitVal;
    }

    @Override
    public String toString() {
        String string = "";
        string += (TokenType.IDENFR + " " + this.Ident + "\n");
        if (this.constExp != null) {
            string += (TokenType.LBRACK + " [\n");
            string += this.constExp.toString();
            string += (TokenType.RBRACK + " ]\n");
        }
        string += (TokenType.ASSIGN + " =\n");
        string += this.constInitVal.toString();
        string += "<ConstDef>\n";
        return string;
    }
}
