package frontend.Parser;

import frontend.Token;
import frontend.Parser.Stmt.Block;

//主函数定义 MainFuncDef → 'int' 'main' '(' ')' Block // 存在main函数
public class MainFuncDef implements Output{
    private final String name = "<MainFuncDef>";
    private Token intTk; // 'int'
    private Token mainTk; // 'main'
    private Token lparent; // '('
    private Token rparent; // ')'
    private Block block;

    public MainFuncDef(Token intTk, Token mainTk, Token lparent, Token rparent, Block block) {
        this.intTk = intTk;
        this.mainTk = mainTk;
        this.lparent = lparent;
        this.rparent = rparent;
        this.block = block;
    }


    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.intTk.toString());
        sb.append(this.mainTk.toString());
        sb.append(this.lparent.toString());
        sb.append(this.rparent.toString());
        sb.append(this.block.Parser_Output());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
