package FrontEnd.ASDTree;

import java.io.FileNotFoundException;
import java.util.ArrayList;

public class MainFuncDef implements ASDNode{
    private Block block;
    private ArrayList<ASDNode> ASDNodeList=new ArrayList<>();;
    public MainFuncDef(Block block)
    {
        this.block=block;
        this.ASDNodeList.add(block);
    }
    @Override
    public void printInfo() throws FileNotFoundException {
        System.out.println("INTTK int");
        System.out.println("MAINTK main");
        System.out.println("LPARENT (");
        System.out.println("RPARENT )");
        this.block.printInfo();
        System.out.println("<MainFuncDef>");
    }

    @Override
    public ArrayList<ASDNode> getChild() {
        return null;
    }
}
