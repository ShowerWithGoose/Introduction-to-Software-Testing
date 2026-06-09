package frontend.parser.expr.types;

import frontend.lexer.Token;
import frontend.lexer.TokenType;

import java.util.ArrayList;

public class AddExp {
    private final ArrayList<MulExp> exps = new ArrayList<>();
    private final ArrayList<Token> seps = new ArrayList<>();
    public AddExp(MulExp firstExp) {
        exps.add(firstExp);
    }
    public void appendMulExp(Token sep, MulExp exp) {
        seps.add(sep);
        exps.add(exp);
    }
    public static boolean isSep(Token token) {
        return token.getType() == TokenType.PLUS ||
                token.getType() == TokenType.MINU;
    }

    @Override
    public String toString() {
        StringBuilder res = new StringBuilder();
        res.append(exps.get(0));
        res.append("<AddExp>\n");
        for (int i = 0; i < seps.size(); i++) {
            res.append(seps.get(i));
            res.append(exps.get(i + 1));
            res.append("<AddExp>\n");
        }
        return res.toString();
    }

    public ArrayList<MulExp> getMulExps() {
        return this.exps;
    }
}
