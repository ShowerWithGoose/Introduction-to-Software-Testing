package frontend.parser.stmt.Decl;

import frontend.lexer.TokenType;
import frontend.parser.exp.ConstExp;

import java.util.ArrayList;
import java.util.HashSet;

public class ArrayConstInitVal extends ConstInitVal {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.add(TokenType.LBRACE);
    }

    private ArrayList<ConstExp> constExps;

    public ArrayConstInitVal(ArrayList<ConstExp> constExps) {
        this.constExps = constExps;
    }

    @Override
    public String toString() {
        String string = "";
        string += (TokenType.LBRACE + " {\n");
        for (int i = 0; i < this.constExps.size(); i++) {
            if (i > 0) {
                string += (TokenType.COMMA + " ,\n");
            }
            string += this.constExps.get(i).toString();
        }
        string += (TokenType.RBRACE + " }\n");
        string += "<ConstInitVal>\n";
        return string;
    }
}
