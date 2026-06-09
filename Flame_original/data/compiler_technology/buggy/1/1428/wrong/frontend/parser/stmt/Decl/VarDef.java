package frontend.parser.stmt.Decl;

import frontend.lexer.TokenType;
import frontend.parser.exp.ConstExp;

import java.util.HashSet;

public class VarDef {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.add(TokenType.IDENFR);
    }

    private String Ident;
    private ConstExp constExp;
    private InitVal initVal;

    public VarDef(String Ident, ConstExp constExp, InitVal initVal) {
        this.Ident = Ident;
        this.constExp = constExp;
        this.initVal = initVal;
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
        if (this.initVal != null) {
            string += (TokenType.ASSIGN + " =\n");
            string += this.initVal.toString();
        }
        string += "<VarDef>\n";
        return string;
    }
}
