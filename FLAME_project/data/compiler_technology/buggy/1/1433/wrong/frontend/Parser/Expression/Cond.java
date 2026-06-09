package frontend.Parser.Expression;

import frontend.Parser.ASTNode;

public class Cond implements ASTNode {
    private LOrExp lOrExp;

    public Cond(LOrExp lOrExp) {
        this.lOrExp = lOrExp;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(lOrExp.printString());
        sb.append("<" + "Cond" + ">\n");
        return sb.toString();
    }
}
