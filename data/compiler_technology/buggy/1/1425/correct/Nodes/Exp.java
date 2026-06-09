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
public class Exp {
//    Exp â†’ AddExp
    private AddExp addExp;

    public Exp(AddExp addExp) {
        this.addExp = addExp;
    }

    public void print(){
        addExp.print();
        IO.parser_output(Parser.nodeTypes.get(NodeType.Exp));
    }

    public AddExp getAddExp() {
        return addExp;
    }
}
