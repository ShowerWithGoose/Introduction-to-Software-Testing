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
public class Block {
//    Block â†’ '{' { BlockItem } '}'
    private Token lbrace;
    private Token rbrace;
    private List<BlockItem> blockItemList;

    public Block(Token lbrace, List<BlockItem> blockItemList, Token rbrace) {
        this.lbrace = lbrace;
        this.rbrace = rbrace;
        this.blockItemList = blockItemList;
    }

    public void print(){
        IO.parser_output(lbrace.toString());
        if(!blockItemList.isEmpty()){
            for(int i=0;i<blockItemList.size();i++){
                blockItemList.get(i).print();
            }
        }
        IO.parser_output(rbrace.toString());
        IO.parser_output(Parser.nodeTypes.get(NodeType.Block));
    }
}
