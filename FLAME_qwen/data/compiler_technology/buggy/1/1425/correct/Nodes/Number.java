package Nodes;/**
 * @Description:
 * @author
 * @date 2024/9/28 19:00
 */
import java.util.*;
import Token.*;
import Utils.IO;
import frontend.*;
/**
 * @author:
 * TODO  
 * 2024/9/28 19:00
 */
public class Number {
//    Number â†’ IntConst
    private Token intcon;

    public Number(Token intcon) {
        this.intcon = intcon;
    }

    public void print(){
        IO.parser_output(intcon.toString());
        IO.parser_output(Parser.nodeTypes.get(NodeType.Number));
    }

    public Token getIntcon() {
        return intcon;
    }
}
