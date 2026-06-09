package frontend.parser.function;

import frontend.lexer.Token;
import frontend.parser.SyntaxNode;
import frontend.parser.function.functype.FuncType;
import frontend.parser.statement.Block;
import frontend.parser.terminal.Ident;

public class FuncDef implements SyntaxNode {
    public final String name="<FuncDef>";
    public FuncType funcType;
    public Ident ident;
    public Token leftParent; //‘(’
    public FuncFParams funcFParams = null;
    public Token rightParent;//')'
    public Block block;
    public FuncDef(FuncType funcType,
                   Ident ident,
                   Token leftParent,
                   Token rightParent,
                   Block block) {
        this.funcType = funcType;
        this.ident = ident;
        this.leftParent = leftParent;
        this.rightParent = rightParent;
        this.block = block;
    }
    public FuncDef(FuncType funcType,
                   Ident ident,
                   Token leftParent,
                   FuncFParams funcFParams,
                   Token rightParent,
                   Block block) {
        this.funcType = funcType;
        this.ident = ident;
        this.leftParent = leftParent;
        this.rightParent = rightParent;
        this.block = block;
        this.funcFParams = funcFParams;
    }
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.funcType.syntaxOutput());
        sb.append(this.ident.syntaxOutput());
        sb.append(this.leftParent.syntaxOutput());
        if (this.funcFParams != null) {
            sb.append(this.funcFParams.syntaxOutput());
        }
        sb.append(this.rightParent.syntaxOutput());
        sb.append(this.block.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
    public int my_line_num(){
        return block.my_line_num();
    }
}
