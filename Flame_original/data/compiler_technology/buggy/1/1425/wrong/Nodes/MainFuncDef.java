package Nodes;/**
 * @Description:
 * @author
 * @date 2024/9/28 18:58
 */
import java.util.*;
import Token.*;
import Utils.IO;
import frontend.*;
/**
 * @author:
 * TODO  
 * 2024/9/28 18:58
 */
public class MainFuncDef {
//    MainFuncDef â†’ 'int' 'main' '(' ')' Block
    private Token inttk;
    private Token maintk;
    private Token lparent;
    private Token rparent;
    private Block block;

    public MainFuncDef(Token inttk, Token maintk, Token lparent, Token rparent, Block block) {
        this.inttk = inttk;
        this.maintk = maintk;
        this.lparent = lparent;
        this.rparent = rparent;
        this.block = block;
    }

    public void print(){
        IO.parser_output(inttk.toString());
        IO.parser_output(maintk.toString());
        IO.parser_output(lparent.toString());
        IO.parser_output(rparent.toString());
        block.print();
        IO.parser_output(Parser.nodeTypes.get(NodeType.MainFuncDef));
    }

    public Token getInttk() {
        return inttk;
    }

    public Token getMaintk() {
        return maintk;
    }

    public Token getLparent() {
        return lparent;
    }

    public Token getRparent() {
        return rparent;
    }

    public Block getBlock() {
        return block;
    }
}
