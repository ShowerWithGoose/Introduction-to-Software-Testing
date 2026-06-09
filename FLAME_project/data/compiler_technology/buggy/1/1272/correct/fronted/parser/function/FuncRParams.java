package fronted.parser.function;

import fronted.lexer.Token;
import fronted.lexer.TokenList;
import fronted.lexer.TokenType;
import fronted.parser.expression.Exp;

import java.util.ArrayList;

public class FuncRParams {
    //FuncRParams â†’ Exp { ',' Exp }

    private ArrayList<Exp> exps;

    private static final String name = "<FuncRParams>\n";

    private static final Token comma = new Token(TokenType.Type.COMMA,",",1);

    public FuncRParams( ArrayList<Exp> params) {
        this.exps = params;
    }


    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(exps.get(0).toString());
        int num = exps.size();
        for (int i = 1; i<num;i=i+1) {
            sb.append(comma);
            sb.append(exps.get(i).toString());
        }
        sb.append(name);
        return sb.toString();
    }

    public static FuncRParams parse(TokenList list) {
        ArrayList<Exp> exps = new ArrayList<>();
        Exp exp = Exp.parse(list);
        exps.add(exp);
        while (list.now().getType().equals(TokenType.Type.COMMA)) {
            list.next();
            exps.add(Exp.parse(list));
        }
        return new FuncRParams(exps);
    }
}
