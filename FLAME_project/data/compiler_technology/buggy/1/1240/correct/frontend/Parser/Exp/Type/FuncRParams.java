package frontend.Parser.Exp.Type;

import frontend.Lexer.LexType;

import java.util.ArrayList;

public class FuncRParams {
    // FuncRParams â†’ Exp { ',' Exp }
    private final ArrayList<Exp> exp;
    private final ArrayList<LexType> tokens;

    public FuncRParams(ArrayList<Exp> exp, ArrayList<LexType> tokens) {
        this.exp = exp;
        this.tokens = tokens;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        int index = 0;
        sb.append(exp.get(index));
        index++;
        for (LexType token : tokens) {
            sb.append(token).append(exp.get(index++));
        }
        sb.append("<FuncRParams>\n");
        return sb.toString();
    }
}
