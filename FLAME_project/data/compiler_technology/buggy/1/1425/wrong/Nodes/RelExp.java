package Nodes;/**
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
public class RelExp {
//    RelExp â†’ AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
//    RelExp -> AddExp { ('<' | '>' | '<=' | '>=') AddExp }
    private List<AddExp> addExpList;
    private List<Token> opList;

    public RelExp(List<AddExp> addExpList,List<Token> opList){
        this.addExpList=addExpList;
        this.opList=opList;
    }

    public void print(){
        addExpList.get(0).print();
        IO.parser_output(Parser.nodeTypes.get(NodeType.RelExp));
        for(int i=0;i<opList.size();i++){
            IO.parser_output(opList.get(i).toString());
            addExpList.get(i+1).print();
            IO.parser_output(Parser.nodeTypes.get(NodeType.RelExp));
        }
    }

    public List<AddExp> getAddExpList() {
        return addExpList;
    }

    public List<Token> getOpList() {
        return opList;
    }
}
