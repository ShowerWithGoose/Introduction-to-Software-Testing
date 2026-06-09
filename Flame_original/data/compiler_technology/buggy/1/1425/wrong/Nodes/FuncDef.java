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
public class FuncDef {
//     FuncDef â†’ FuncType Ident '(' [FuncFParams] ')' Block
    private FuncType funcType;
    private Token ident;
    private Token lparent;
    private FuncFParams funcFParams;
    private Token rparent;
    private Block block;

    public FuncDef(FuncType funcType, Token ident, Token lparent, FuncFParams funcFParams, Token rparent, Block block) {
        this.funcType = funcType;
        this.ident = ident;
        this.lparent = lparent;
        this.funcFParams = funcFParams;
        this.rparent = rparent;
        this.block = block;
    }

    public void print(){
        funcType.print();
        IO.parser_output(ident.toString());
        IO.parser_output(lparent.toString());
        if(funcFParams!=null){
            funcFParams.print();
        }
        IO.parser_output(rparent.toString());
        block.print();
        IO.parser_output(Parser.nodeTypes.get(NodeType.FuncDef));
    }
}
