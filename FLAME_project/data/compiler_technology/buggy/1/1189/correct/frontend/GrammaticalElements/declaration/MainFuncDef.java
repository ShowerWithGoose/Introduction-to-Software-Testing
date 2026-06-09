package frontend.GrammaticalElements.declaration;

import frontend.GrammaticalElements.statement.Block;
import frontend.Token;

public class MainFuncDef {
    /*Token _int;
    Token _main;
    Token leftParent;
    Token rightParent;
    Block* block;*/
    private final String name = "<MainFuncDef>";
    private Token _int;
    private Token _main;
    private Token leftParent;
    private Token rightParent;
    private Block block;

    public MainFuncDef(Token _int, Token _main, Token leftParent, Token rightParent, Block block) {
        this._int = _int;
        this._main = _main;
        this.leftParent = leftParent;
        this.rightParent = rightParent;
        this.block = block;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(_int.toString());
        sb.append(_main.toString());
        sb.append(leftParent.toString());
        sb.append(rightParent.toString());
        sb.append(block.toString());
        sb.append(this.name).append('\n');
        return sb.toString();
    }
}
