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
public class MulExp {
//    MulExp â†’ UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
//    MulExp -> UnaryExp { ('*' | '/' | '%') UnaryExp }
    private List<UnaryExp> unaryExpList;
    private List<Token> opList;

    public MulExp(List<UnaryExp> unaryExpList,List<Token> opList){
        this.unaryExpList=unaryExpList;
        this.opList=opList;
    }

    public void print(){
        unaryExpList.get(0).print();
        IO.parser_output(Parser.nodeTypes.get(NodeType.MulExp));
        for(int i=0;i<opList.size();i++){
            IO.parser_output(opList.get(i).toString());
            unaryExpList.get(i+1).print();
            IO.parser_output(Parser.nodeTypes.get(NodeType.MulExp));
        }
    }

    public List<UnaryExp> getUnaryExpList() {
        return unaryExpList;
    }

    public List<Token> getOpList() {
        return opList;
    }
}
