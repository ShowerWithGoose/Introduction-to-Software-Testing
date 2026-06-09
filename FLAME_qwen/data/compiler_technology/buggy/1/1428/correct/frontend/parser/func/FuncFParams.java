package frontend.parser.func;

import frontend.lexer.TokenType;

import java.util.ArrayList;
import java.util.HashSet;

public class FuncFParams {

    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.addAll(FuncFParam.FIRST);
    }

    private ArrayList<FuncFParam> funcFParams;

    public FuncFParams(ArrayList<FuncFParam> funcFParams) {
        this.funcFParams = funcFParams;
    }

    @Override
    public String toString() {
        String string = "";
        string += this.funcFParams.get(0).toString();
        for (int i = 1; i < this.funcFParams.size(); i++) {
            string += (TokenType.COMMA + " ,\n");
            string += this.funcFParams.get(i).toString();
        }
        string += "<FuncFParams>\n";
        return string;
    }
}
