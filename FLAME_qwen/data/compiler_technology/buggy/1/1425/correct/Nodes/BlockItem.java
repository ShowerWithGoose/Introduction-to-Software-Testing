package Nodes;/**
 * @Description:
 * @author
 * @date 2024/9/28 18:59
 */
import java.util.*;
import Token.*;
import Utils.IO;
import frontend.*;
/**
 * @author:
 * TODO  
 * 2024/9/28 18:59
 */
public class BlockItem {
//    BlockItem â†’ Decl | Stmt
    private Decl decl;
    private Stmt stmt;

    public BlockItem(Decl decl, Stmt stmt) {
        this.decl = decl;
        this.stmt = stmt;
    }

    public void print(){
        if(decl!=null){
            decl.print();
        }
        else if(stmt!=null){
            stmt.print();
        }

    }
}
