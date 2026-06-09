package frontend.Parser.Declaration;

import frontend.Parser.ASTNode;
import frontend.Parser.Statement.BlockItemEle;

public class Decl implements ASTNode, BlockItemEle {
    private declEle declEle;

    public Decl (declEle declEle) {
        this.declEle = declEle;
    }

    @Override
    public String printString() {
        if (declEle != null) {
            return declEle.printString();
        } else {
            return "";
        }
    }
}
