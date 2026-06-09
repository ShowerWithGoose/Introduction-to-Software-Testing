package node;

/**
 * ClassName: BlockItem
 * Package: node
 * Description:
 *
 * @Author
 * @Create 2024/10/4 16:03
 * @Version 1.0
 */
public class BlockItem extends Node{
    // BlockItem => Decl | Stmt
    public Decl decl;
    public Stmt stmt;

    public BlockItem(Decl decl) {
        this.decl = decl;
        setLineNo(decl);
    }

    public BlockItem(Stmt stmt) {
        this.stmt = stmt;
        setLineNo(stmt);
    }

    public StringBuilder getPrintInfo(){
        StringBuilder info = new StringBuilder();
        if(decl != null){
            info.append(decl.getPrintInfo());
        }else{
            info.append(stmt.getPrintInfo());
        }
        return info;
    }
}
