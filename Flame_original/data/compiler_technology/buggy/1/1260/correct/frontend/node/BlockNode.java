package frontend.node;

import frontend.Token;

import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class BlockNode {
    private Token l;
    private List<BlockItemNode> blockItemNodeList;
    private Token r;
    public BlockNode(Token l, List<BlockItemNode> blockItemNodeList, Token r){
        this.l = l;
        this.blockItemNodeList = blockItemNodeList;
        this.r = r;
    }
    public void print(){
        l.print();
        for(BlockItemNode blockItemNode: blockItemNodeList){
            blockItemNode.print();
        }
        r.print();
        try (FileWriter fw = new FileWriter("parser.txt", true)){
            fw.write("<Block>\n");
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
}
