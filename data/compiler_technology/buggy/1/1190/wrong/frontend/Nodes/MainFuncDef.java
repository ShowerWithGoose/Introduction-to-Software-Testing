package frontend.Nodes;

import frontend.Token;

public class MainFuncDef implements Node {
    private Token intToken;
    private Token mainToken;
    private Token lParent;
    private Token rParent;
    private Block block;

    public MainFuncDef() {
        this.intToken = null;
        this.mainToken = null;
        this.lParent = null;
        this.rParent = null;
        this.block = null;
    }

    public void addInt(Token intToken) {
        this.intToken = intToken;
    }

    public void addMain(Token mainToken) {
        this.mainToken = mainToken;
    }

    public void addLParent(Token lParent) {
        this.lParent = lParent;
    }

    public void addRParent(Token rParent) {
        this.rParent = rParent;
    }

    public void addBlock(Block block) {
        this.block = block;
    }

    @Override
    public String error() {
        StringBuilder sb = new StringBuilder();
        if (intToken != null) {
            sb.append(intToken.error());
        }
        if (mainToken != null) {
            sb.append(mainToken.error());
        }
        if (lParent != null) {
            sb.append(lParent.error());
        }
        if (rParent != null) {
            sb.append(rParent.error());
        }
        if (block != null) {
            sb.append(block.error());
        }
        return sb.toString();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        if (intToken != null) {
            sb.append(intToken.toString());
        }
        if (mainToken != null) {
            sb.append(mainToken.toString());
        }
        if (lParent != null) {
            sb.append(lParent.toString());
        }
        if (rParent != null) {
            sb.append(rParent.toString());
        }
        if (block != null) {
            sb.append(block.toString());
        }
        sb.append("<MainFuncDef>\n");
        return sb.toString();
    }
}
