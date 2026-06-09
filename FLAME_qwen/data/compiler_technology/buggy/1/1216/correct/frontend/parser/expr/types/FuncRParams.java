package frontend.parser.expr.types;

import frontend.lexer.Token;

import java.util.ArrayList;

public class FuncRParams {
    private final Exp firstExp;
    private final ArrayList<Exp> exps = new ArrayList<>();
    private final ArrayList<Token> seps = new ArrayList<>();

    public FuncRParams(Exp firstExp) {
        this.firstExp = firstExp;
    }
    public void addExp(Token sep, Exp exp) {
        exps.add(exp);
        seps.add(sep);
    }
    public static boolean inFirst(Token token) {
        switch (token.getType()) {
            case LPARENT, IDENFR, INTCON, CHRCON, PLUS, MINU, NOT -> {
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
        res.append(firstExp);
        for (int i = 0; i < exps.size(); i++) {
            res.append(seps.get(i));
            res.append(exps.get(i));
        }
        res.append("<FuncRParams>\n");
        return res.toString();
    }
}
