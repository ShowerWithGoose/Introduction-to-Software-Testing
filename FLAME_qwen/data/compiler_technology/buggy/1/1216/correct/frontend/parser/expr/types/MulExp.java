package frontend.parser.expr.types;

import frontend.lexer.Token;

import java.util.ArrayList;

public class MulExp {
    private final ArrayList<UnaryExp> exps = new ArrayList<>();
    private final ArrayList<Token> seps = new ArrayList<>();
    public MulExp(UnaryExp firstExp) {
        this.exps.add(firstExp);
    }
    public void appendUnaryExp(Token sep, UnaryExp exp) {
        seps.add(sep);
        exps.add(exp);
    }
    public static boolean isSep(Token token) {
        switch (token.getType()) {
            case MULT, DIV, MOD -> {
                return true;
            }
            default -> {
                return false;
            }
        }
    }
    @Override
    public String toString() {
        StringBuilder res = new StringBuilder();
        res.append(exps.get(0));
        res.append("<MulExp>\n");
        for (int i = 0; i < seps.size(); i++) {
            res.append(seps.get(i));
            res.append(exps.get(i + 1));
            res.append("<MulExp>\n");
        }
        return res.toString();
    }
}
