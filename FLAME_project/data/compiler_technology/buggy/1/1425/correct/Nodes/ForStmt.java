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
public class ForStmt {
//    ForStmt â†’ LVal '=' Exp
    private LVal lVal;
    private Token assign;
    private Exp exp;

    public ForStmt(LVal lVal, Token assign, Exp exp) {
        this.lVal = lVal;
        this.assign = assign;
        this.exp = exp;
    }

    public void print(){
        lVal.print();
        IO.parser_output(assign.toString());
        exp.print();
        IO.parser_output(Parser.nodeTypes.get(NodeType.ForStmt));
    }

    public LVal getlVal() {
        return lVal;
    }

    public Token getAssign() {
        return assign;
    }

    public Exp getExp() {
        return exp;
    }
}
