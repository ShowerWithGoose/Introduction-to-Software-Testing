package frontend.Parser.function;

import frontend.Parser.GrammarNode;
import frontend.Lexer.Token;
import frontend.Parser.block.Block;

public class MainFuncDef implements GrammarNode {
    private final String grammarName = "<MainFuncDef>";
    private Token intTk;
    private Token mainTk;
    private Token lParent;
    private Token rParent;
    private Block block;

    public MainFuncDef(Token intTk, Token mainTk, Token lParent, Token rParent, Block block) {
        this.intTk = intTk;
        this.mainTk = mainTk;
        this.lParent = lParent;
        this.rParent = rParent;
        this.block = block;
    }

    public String grammarOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.intTk.grammarOutput());
        sb.append(this.mainTk.grammarOutput());
        sb.append(this.lParent.grammarOutput());
        sb.append(this.rParent.grammarOutput());
        sb.append(this.block.grammarOutput());
        sb.append(this.grammarName).append("\n");
        return sb.toString();
    }
}
