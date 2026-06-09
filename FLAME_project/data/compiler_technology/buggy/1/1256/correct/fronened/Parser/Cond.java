package fronened.Parser;

import fronened.Lexer.TokenIterator;

public class Cond {
    private LOrExp lOrExp;

    public Cond(LOrExp lOrExp) {
        this.lOrExp = lOrExp;
    }

    public String print() {
        StringBuilder sb = new StringBuilder();
        sb.append(lOrExp.print());
        sb.append("<Cond>\n");
        return sb.toString();
    }

    public static Cond parse(TokenIterator iterator) {
        LOrExp lOrExp = LOrExp.parse(iterator);
        return new Cond(lOrExp);
    }
}
