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
    private List<Token> options;

    public MulExp(List<UnaryExp> unaryExpList,List<Token> options){
        this.unaryExpList=unaryExpList;
        this.options=options;
    }

    public void print(){
        unaryExpList.get(0).print();
        IO.parser_output(Parser.nodeTypes.get(NodeType.MulExp));
        for(int i=1;i<unaryExpList.size();i++){
            IO.parser_output(options.get(i-1).toString());
            unaryExpList.get(i).print();
            IO.parser_output(Parser.nodeTypes.get(NodeType.MulExp));
        }
    }

    public List<UnaryExp> getUnaryExpList() {
        return unaryExpList;
    }

    public List<Token> getOpList() {
        return options;
    }
}
