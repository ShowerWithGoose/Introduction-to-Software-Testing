package frontend.SyntaxUnits;

import frontend.Token;

public class FuncDef implements SyntaxUnit{
    private final FuncType funcType;
    private final Token ident;
    private final FuncFParams funcFParams;
    private final Block block;

    public FuncDef(FuncType funcType, Token ident, FuncFParams funcFParams, Block block) {
        this.funcType = funcType;
        this.ident = ident;
        this.funcFParams = funcFParams;
        this.block = block;
    }

    public FuncDef(FuncType funcType, Token ident, Block block) {
        this.funcType = funcType;
        this.ident = ident;
        this.funcFParams = null;
        this.block = block;
    }

    public String toPrint() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(funcType.toPrint());
        stringBuilder.append(ident.toPrint());
        stringBuilder.append("LPARENT" + " (" +  "\n");
        if (funcFParams != null) {
            stringBuilder.append(funcFParams.toPrint());
        }
        stringBuilder.append("RPARENT" + " )" +  "\n");
        stringBuilder.append(block.toPrint());
        stringBuilder.append("<FuncDef>\n");
        return stringBuilder.toString();
    }
}
