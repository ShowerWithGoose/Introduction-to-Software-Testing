package frontend.parser.expr.types;

import frontend.lexer.Token;

import java.util.ArrayList;

public class RelExp {
    private final ArrayList<AddExp> exps = new ArrayList<>();
    private final ArrayList<Token> seps = new ArrayList<>();
    public RelExp(AddExp firstExp) {
        this.exps.add(firstExp);
    }

    public static boolean isSep(Token token) {
        switch (token.getType()) {
            case LSS, LEQ, GRE, GEQ -> {
                return true;
            }
            default -> {
                return false;
            }
        }
    }

    public void appendAddExp(Token sep, AddExp exp) {
        seps.add(sep);
        exps.add(exp);
    }

    @Override
    public String toString() {
        StringBuilder res = new StringBuilder();
        res.append(exps.get(0));
        res.append("<RelExp>\n");
        for (int i = 0; i < seps.size(); i++) {
            res.append(seps.get(i));
            res.append(exps.get(i + 1));
            res.append("<RelExp>\n");
        }
        return res.toString();
    }
}
