package struct;

import token.Token;

/* MainFuncDef â†’ 'int' 'main' '(' ')' Block */
public class MainFuncDef {
    private final Token intToken;
    private final Token mainToken;
    private final Token lParentToken;
    private final Token rParentToken;
    private final Block block;

    public MainFuncDef(Token intToken, Token mainToken, Token lParentToken, Token rParentToken, Block block) {
        this.intToken = intToken;
        this.mainToken = mainToken;
        this.lParentToken = lParentToken;
        this.rParentToken = rParentToken;
        this.block = block;
    }

    public Token getIntToken() {
        return intToken;
    }

    public Token getMainToken() {
        return mainToken;
    }

    public Token getLParentToken() {
        return lParentToken;
    }

    public Token getRParentToken() {
        return rParentToken;
    }

    public Block getBlock() {
        return block;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(intToken.toString());
        sb.append(mainToken.toString());
        sb.append(lParentToken.toString());
        sb.append(rParentToken.toString());
        sb.append(block.toString());
        sb.append("<MainFuncDef>\n");
        return sb.toString();
    }
}
