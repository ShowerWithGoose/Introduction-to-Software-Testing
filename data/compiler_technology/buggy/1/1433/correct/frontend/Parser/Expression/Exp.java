package frontend.Parser.Expression;

import frontend.Parser.ASTNode;
import frontend.Parser.Declaration.InitValEle;

public class Exp implements ASTNode, InitValEle {
    private AddExp addExp;

    public Exp(AddExp addExp) {
        this.addExp = addExp;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(addExp.printString());
        sb.append("<" + "Exp" + ">\n");
        return sb.toString();
    }
}
