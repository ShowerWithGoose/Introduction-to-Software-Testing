package frontend.Parser.SyntaxNode;

import frontend.Lexer.Token.Token;

public class MainFuncDef implements SyntaxNode {
    private final String name = "<MainFuncDef>";
    private Token inttk;
    private Token maintk;
    private Token lparent;
    private Token rparent;
    private Block block;

    public MainFuncDef(Token inttk, Token maintk, Token lparent, Token rparent, Block block) {
        this.inttk = inttk;
        this.maintk = maintk;
        this.lparent = lparent;
        this.rparent = rparent;
        this.block = block;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(inttk);
        sb.append(maintk);
        sb.append(lparent);
        sb.append(rparent);
        sb.append(block);
        sb.append(name + "\n");
        return sb.toString();
    }
}
