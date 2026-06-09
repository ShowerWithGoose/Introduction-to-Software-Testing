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
    private List<Token> options;

    public RelExp(List<AddExp> addExpList,List<Token> options){
        this.addExpList=addExpList;
        this.options=options;
    }

    public void print(){
        addExpList.get(0).print();
        IO.parser_output(Parser.nodeTypes.get(NodeType.RelExp));
        for(int i=1;i<addExpList.size();i++){
            IO.parser_output(options.get(i-1).toString());
            addExpList.get(i).print();
            IO.parser_output(Parser.nodeTypes.get(NodeType.RelExp));
        }
    }

    public List<AddExp> getAddExpList() {
        return addExpList;
    }

    public List<Token> getOpList() {
        return options;
    }
}
