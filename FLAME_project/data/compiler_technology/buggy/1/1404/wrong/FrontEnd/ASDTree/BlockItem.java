package FrontEnd.ASDTree;

import java.io.FileNotFoundException;
import java.util.ArrayList;

public class BlockItem implements ASDNode{
    private Decl decl=null;
    private Stmt stmt=null;
    public BlockItem(Decl decl)
    {
        this.decl=decl;
    }
    public BlockItem(Stmt stmt)
    {
        this.stmt=stmt;
    }

    @Override
    public void printInfo() throws FileNotFoundException {
        if(this.decl!=null)
        {
            this.decl.printInfo();
        }
        else {
            this.stmt.printInfo();
        }
//        System.out.println("BlockItem");
    }

    @Override
    public ArrayList<ASDNode> getChild() {
        return null;
    }
}
