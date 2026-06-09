package frontend.parser.function;

import frontend.lexer.Token;
import frontend.parser.statement.Block;

public class MainFuncDef {
    public final String name = "<MainFuncDef>";
    public Token intTk; // 'int'
    public Token mainTk; // 'main'
    public Token leftParent; // '('
    public Token rightParent; // ')'
    public Block block;
    public MainFuncDef(Token intTk,
                       Token mainTk,
                       Token leftParent,
                       Token rightParent,
                       Block block) {
        this.intTk = intTk;
        this.mainTk = mainTk;
        this.leftParent = leftParent;
        this.rightParent = rightParent;
        this.block = block;
    }
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.intTk.syntaxOutput());
        sb.append(this.mainTk.syntaxOutput());
        sb.append(this.leftParent.syntaxOutput());
        sb.append(this.rightParent.syntaxOutput());
        sb.append(this.block.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
    public int my_line_num(){
        return this.block.my_line_num();
    }




}
