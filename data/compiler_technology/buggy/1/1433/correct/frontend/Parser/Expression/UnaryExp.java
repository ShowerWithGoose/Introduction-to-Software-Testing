package frontend.Parser.Expression;

import frontend.Parser.ASTNode;

public class UnaryExp implements ASTNode {
    private unaryExpEle unaryExpEle;

    public UnaryExp(unaryExpEle unaryExpEle) {
        this.unaryExpEle = unaryExpEle;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(unaryExpEle.printString());
        sb.append("<" + "UnaryExp" + ">\n");
        return sb.toString();
    }
}
