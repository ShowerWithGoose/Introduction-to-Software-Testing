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
public class AddExp {
//    AddExp → MulExp | AddExp ('+' | '−') MulExp
//    AddExp -> MulExp { ('+' | '−') MulExp }
    private List<MulExp> mulExpList;
    private List<Token> optionList;

    public AddExp(List<MulExp> mulExpList,List<Token> optionList){
        this.mulExpList=mulExpList;
        this.optionList=optionList;
    }

    public void print(){
        mulExpList.get(0).print();
        IO.parser_output(Parser.nodeTypes.get(NodeType.AddExp));
        for(int i=0;i<optionList.size();i++){
            IO.parser_output(optionList.get(i).toString());
            mulExpList.get(i+1).print();
            IO.parser_output(Parser.nodeTypes.get(NodeType.AddExp));
        }
    }

    public List<MulExp> getMulExpList() {
        return mulExpList;
    }

    public List<Token> getoptionList() {
        return optionList;
    }
}
