package frontend.parser.expr.types;

import frontend.lexer.Token;

public class Cond {
    private final LOrExp lOrExp;

    public Cond(LOrExp lOrExp) {
        this.lOrExp = lOrExp;
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
        return lOrExp.toString() + "<Cond>\n";
    }
}
