package frontend.Parser.Stmt;

import frontend.Token;

import java.util.ArrayList;

//语句块 Block → '{' { BlockItem } '}' // 1.花括号内重复0次 2.花括号内重复多次
public class Block implements BlockItemInf,StmtInf {
    private final String name = "<Block>";
    private Token lbrace;
    private ArrayList<BlockItem> blockItems = new ArrayList<>();
    private Token rbrace;

    public Block(Token lbrace, ArrayList<BlockItem> blockItems, Token rbrace) {
        this.lbrace = lbrace;
        this.blockItems = blockItems;
        this.rbrace = rbrace;
    }
    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.lbrace.toString());
        if(this.blockItems != null) {
            for(int i = 0; i < this.blockItems.size(); i++) {
                sb.append(this.blockItems.get(i).Parser_Output());
            }
        }
        sb.append(this.rbrace.toString());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
