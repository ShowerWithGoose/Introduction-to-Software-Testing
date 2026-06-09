package frontend.parser.expr.types;

import frontend.lexer.Token;

public class Exp {
    private final AddExp addExp;
    private final boolean isConst;

    public Exp(AddExp addExp, boolean isConst) {
        this.addExp = addExp;
        this.isConst = isConst;
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
        return addExp.toString() + (isConst?"<ConstExp>\n":"<Exp>\n");
    }
}
