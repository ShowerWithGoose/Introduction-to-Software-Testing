package FrontEnd.ASDTree;

import java.io.FileNotFoundException;
import java.util.ArrayList;

public class Block implements ASDNode{
    private ArrayList<BlockItem> blockItemArrayList;
    public Block(ArrayList<BlockItem> blockItemArrayList){
        this.blockItemArrayList=blockItemArrayList;
    }
    @Override
    public void printInfo() throws FileNotFoundException {
        System.out.println("LBRACE {");
        for(BlockItem blockItem:blockItemArrayList)
        {
            blockItem.printInfo();
        }
        System.out.println("RBRACE }");
        System.out.println("<Block>");
    }

    @Override
    public ArrayList<ASDNode> getChild() {
        return null;
    }
}
