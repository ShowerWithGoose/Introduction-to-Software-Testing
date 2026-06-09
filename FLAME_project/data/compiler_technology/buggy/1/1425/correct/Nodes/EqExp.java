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
    private List<Token> options;
    private List<RelExp> relExpList;

    public EqExp(List<RelExp> relExpList,List<Token> options){
        this.options=options;
        this.relExpList=relExpList;
    }

    public void print(){
        relExpList.get(0).print();
        IO.parser_output(Parser.nodeTypes.get(NodeType.EqExp));
        for(int i=1;i<relExpList.size();i++){
            IO.parser_output(options.get(i-1).toString());
            relExpList.get(i).print();
            IO.parser_output(Parser.nodeTypes.get(NodeType.EqExp));
        }
    }

    public List<Token> getoptions() {
        return options;
    }

    public List<RelExp> getRelExpList() {
        return relExpList;
    }
}
