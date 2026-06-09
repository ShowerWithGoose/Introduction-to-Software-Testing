package frontend.parser.stmt.Decl;


import frontend.lexer.TokenType;
import frontend.parser.exp.ConstExp;

import java.util.HashSet;

public class ExpConstInitVal extends ConstInitVal {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.addAll(ConstExp.FIRST);
    }

    private ConstExp constExp;

    public ExpConstInitVal(ConstExp constExp) {
        this.constExp = constExp;
    }

    @Override
    public String toString() {
        String string = "";
        string += this.constExp.toString();
        string += "<ConstInitVal>\n";
        return string;
    }
}
