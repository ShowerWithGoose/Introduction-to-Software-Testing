package frontend.Parser.function;

import frontend.Lexer.Token;
import frontend.Parser.GrammarNode;
import frontend.Parser.block.Block;
import frontend.Parser.terminal.Ident;

public class FuncDef implements GrammarNode {
    private final String grammarName = "<FuncDef>";
    private FuncType funcType;
    private Ident ident;
    private Token lParent; // '('左括号
    private FuncFParams funcFParams; //函数形参表，可能有，可能没有
    private Token rParent;
    private Block block;
    public FuncDef(FuncType funcType, Ident ident, Token lParent,FuncFParams funcFParams,
                   Token rParent, Block b) {
        this.funcType = funcType;
        this.ident = ident;
        this.lParent = lParent;
        this.funcFParams = funcFParams;
        this.rParent = rParent;
        this.block = b;
    }

    public String grammarOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.funcType.grammarOutput());
        sb.append(this.ident.getToken().grammarOutput());
        sb.append(this.lParent.grammarOutput());
        if(this.funcFParams != null) {
            sb.append(this.funcFParams.grammarOutput());
        }
        sb.append(this.rParent.grammarOutput());
        sb.append(this.block.grammarOutput());
        sb.append(this.grammarName).append("\n");
        return sb.toString();
    }
}
