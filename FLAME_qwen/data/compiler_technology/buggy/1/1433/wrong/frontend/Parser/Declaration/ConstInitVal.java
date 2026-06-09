package frontend.Parser.Declaration;

import frontend.Parser.ASTNode;

public class ConstInitVal implements ASTNode {
    private ConstInitValEle constInitValEle;

    public ConstInitVal(ConstInitValEle constInitValEle) {
        this.constInitValEle = constInitValEle;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(constInitValEle.printString());
        sb.append("<" + "ConstInitVal" + ">\n");
        return sb.toString();
    }
}
