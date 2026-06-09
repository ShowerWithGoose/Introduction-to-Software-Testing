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
public class FuncFParam {
//     FuncFParam â†’ BType Ident ['[' ']']
    private BType bType;
    private Token ident;
    private Token lbrack;
    private Token rbrack;

    public FuncFParam(BType bType, Token ident, Token lbrack, Token rbrack) {
        this.bType = bType;
        this.ident = ident;
        this.lbrack = lbrack;
        this.rbrack = rbrack;
    }

    public void print(){
        bType.print();
        IO.parser_output(ident.toString());
        if(lbrack!=null){
            IO.parser_output(lbrack.toString());
            IO.parser_output(rbrack.toString());
        }
        IO.parser_output(Parser.nodeTypes.get(NodeType.FuncFParam));
    }
}
