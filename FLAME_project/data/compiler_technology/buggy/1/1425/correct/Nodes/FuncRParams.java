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
public class FuncRParams {
//    FuncRParams â†’ Exp { ',' Exp }
    private List<Exp> expList;
    private List<Token> commaList;

    public FuncRParams(List<Exp> expList,List<Token> commaList){
        this.expList=expList;
        this.commaList=commaList;
    }

    public void print(){
        expList.get(0).print();
        for(int i=1;i<expList.size();i++){
            IO.parser_output(commaList.get(i-1).toString());
            expList.get(i).print();
        }
        IO.parser_output(Parser.nodeTypes.get(NodeType.FuncRParams));
    }

    public List<Exp> getExpList() {
        return expList;
    }

    public List<Token> getCommaList() {
        return commaList;
    }
}
