package frontend.GrammaticalElements.declaration;

import frontend.GrammaticalElements.function.FuncFParams;
import frontend.GrammaticalElements.function.FuncType;
import frontend.GrammaticalElements.statement.Block;
import frontend.Token;

public class FuncDef {
    /*FuncType* funcType;
    Token ident;
    Token leftParent;
    FuncFParams* funcFParams{};
    Token rightParent;
    Block* block;*/
    private final String name = "<FuncDef>";
    private FuncType funcType;
    private Token ident;
    private Token leftParent;
    private FuncFParams funcFParams;
    private Token rightParent;
    private Block block;

    public FuncDef(FuncType funcType, Token ident, Token leftParent, Token rightParent, Block block) {
        this.funcType = funcType;
        this.ident = ident;
        this.leftParent = leftParent;
        this.rightParent = rightParent;
        this.block = block;
    }

    public FuncDef(FuncType funcType, Token ident, Token leftParent, FuncFParams funcFParams, Token rightParent, Block block) {
        this.funcType = funcType;
        this.ident = ident;
        this.leftParent = leftParent;
        this.funcFParams = funcFParams;
        this.rightParent = rightParent;
        this.block = block;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(funcType.toString());
        sb.append(ident.toString());
        sb.append(leftParent.toString());
        if (funcFParams != null) {
            sb.append(funcFParams.toString());
        }
        sb.append(rightParent.toString());
        sb.append(block.toString());
        sb.append(this.name).append('\n');
        return sb.toString();
    }
}
