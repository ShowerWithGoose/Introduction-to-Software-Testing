package Nodes;
/**
 * @Description:
 * @author
 * @date 2024/9/28 19:01
 */
import java.util.*;
import Token.Token;
import Utils.IO;
import frontend.*;
/**
 * @author:
 * TODO  
 * 2024/9/28 19:01
 */
public class EqExp {
//    EqExp â†’ RelExp | EqExp ('==' | '!=') RelExp
//    EqExp -> RelExp { ('==' | '!=') RelExp }
    private List<Token> opList;
    private List<RelExp> relExpList;

    public EqExp(List<RelExp> relExpList,List<Token> opList){
        this.opList=opList;
        this.relExpList=relExpList;
    }

    public void print(){
        relExpList.get(0).print();
        IO.parser_output(Parser.nodeTypes.get(NodeType.EqExp));
        for(int i=0;i<opList.size();i++){
            IO.parser_output(opList.get(i).toString());
            relExpList.get(i+1).print();
            IO.parser_output(Parser.nodeTypes.get(NodeType.EqExp));
        }
    }

    public List<Token> getOpList() {
        return opList;
    }

    public List<RelExp> getRelExpList() {
        return relExpList;
    }
}
