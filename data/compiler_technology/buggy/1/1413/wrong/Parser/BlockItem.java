package Parser;

import Parser.Stmt.Stmt;

/**
 * @Description:
 * @date 2024/10/13
 */
public class BlockItem implements TreeNode{
    private int flag;
    private Decl decl;
    private Stmt stmt;

    public BlockItem(int flag, Decl decl, Stmt stmt) {
        this.flag = flag;
        this.decl = decl;
        this.stmt = stmt;
    }

    @Override
    public String print_tree() {
        StringBuilder sb=new StringBuilder();
        if(this.flag==1){
            sb.append(this.decl.print_tree());
        }else if(flag==2){
            sb.append(this.stmt.print_tree());
        }
        return sb.toString();
    }
}
