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
public class Cond {
//    Cond â†’ LOrExp
    private LOrExp lOrExp;

    public Cond(LOrExp lOrExp) {
        this.lOrExp = lOrExp;
    }

    public void print(){
        lOrExp.print();
        IO.parser_output(Parser.nodeTypes.get(NodeType.Cond));
    }

    public LOrExp getlOrExp() {
        return lOrExp;
    }
}
