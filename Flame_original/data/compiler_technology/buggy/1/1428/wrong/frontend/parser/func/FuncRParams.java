package frontend.parser.func;

import frontend.lexer.TokenType;
import frontend.parser.exp.Exp;

import java.util.ArrayList;
import java.util.HashSet;

public class FuncRParams {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.addAll(Exp.FIRST);
    }

    private ArrayList<Exp> exps;

    public FuncRParams(ArrayList<Exp> exps) {
        this.exps = exps;
    }

    @Override
    public String toString() {
        String string = "";
        string += this.exps.get(0).toString();
        for (int i = 1; i < this.exps.size(); i++) {
            string += (TokenType.COMMA + " ,\n");
            string += this.exps.get(i).toString();
        }
        string += "<FuncRParams>\n";
        return string;
    }
}
