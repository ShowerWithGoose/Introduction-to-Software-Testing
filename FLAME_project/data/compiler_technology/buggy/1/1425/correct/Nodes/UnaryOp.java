package Nodes;/**
 * @Description:
 * @author
 * @date 2024/9/28 19:01
 */
import java.util.*;
import Token.*;
import Utils.IO;
import frontend.*;
/**
 * @author:
 * TODO  
 * 2024/9/28 19:01
 */

public class UnaryOp {
//    UnaryOp → '+' | '−' | '!'
    private Token option;

    public UnaryOp(Token option){
        this.option=option;
    }

    public void print(){
        IO.parser_output(option.toString());
        IO.parser_output(Parser.nodeTypes.get(NodeType.UnaryOp));
    }

    public Token getOption() {
        return option;
    }
}
