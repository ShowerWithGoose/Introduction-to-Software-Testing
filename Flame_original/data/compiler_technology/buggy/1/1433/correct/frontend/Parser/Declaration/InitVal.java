package frontend.Parser.Declaration;

import frontend.Parser.ASTNode;

public class InitVal implements ASTNode {
    private InitValEle initValEle;

    public InitVal(InitValEle initValEle) {
        this.initValEle = initValEle;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(initValEle.printString());
        sb.append("<" + "InitVal" + ">\n");
        return sb.toString();
    }
}
