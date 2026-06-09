package Node;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import Token.*;
import Utils.OutputUtils;
public class BlockItemNode {
    public DeclNode declNode = null;
    public StmtNode stmtNode = null;
    public BlockItemNode(DeclNode declNode){
        this.declNode = declNode;
    }
    public BlockItemNode(StmtNode stmtNode){
        this.stmtNode = stmtNode;
    }
    public void print() throws IOException {
        if(declNode != null){
            declNode.print();
        }
        else {
            stmtNode.print();
        }
    }
}
