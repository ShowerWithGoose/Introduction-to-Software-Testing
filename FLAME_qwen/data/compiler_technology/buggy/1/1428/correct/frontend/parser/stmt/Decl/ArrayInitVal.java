package frontend.parser.stmt.Decl;

import frontend.lexer.TokenType;
import frontend.parser.exp.Exp;

import java.util.ArrayList;
import java.util.HashSet;

public class ArrayInitVal extends InitVal {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.add(TokenType.LBRACE);
    }

    private ArrayList<Exp> exps;

    public ArrayInitVal(ArrayList<Exp> exps) {
        this.exps = exps;
    }

    @Override
    public String toString() {
        String string = "";
        string += (TokenType.LBRACE + " {\n");
        for (int i = 0; i < this.exps.size(); i++) {
            if (i > 0) {
                string += (TokenType.COMMA + " ,\n");
            }
            string += this.exps.get(i).toString();
        }
        string += (TokenType.RBRACE + " }\n");
        string += "<InitVal>\n";
        return string;
    }
}
