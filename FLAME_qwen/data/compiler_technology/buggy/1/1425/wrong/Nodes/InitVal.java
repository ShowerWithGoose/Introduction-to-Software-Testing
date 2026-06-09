package Nodes;/**
 * @Description:
 * @author
 * @date 2024/9/28 18:58
 */
import java.util.*;
import Token.*;
import Utils.IO;
import frontend.*;
/**
 * @author:
 * TODO  
 * 2024/9/28 18:58
 */
public class InitVal {
//    InitVal â†’ Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
    private List<Exp> expList;
    private Token lbrace;
    private List<Token> commaList;
    private Token rbrace;
    private Token strcon;

    public InitVal(List<Exp> expList, Token lbrace, List<Token> commaList, Token rbrace, Token strcon) {
        this.expList = expList;
        this.lbrace = lbrace;
        this.commaList = commaList;
        this.rbrace = rbrace;
        this.strcon=strcon;
    }

    public void print(){
        if(lbrace!=null){
            IO.parser_output(lbrace.toString());
            if(!expList.isEmpty()){
                expList.get(0).print();
                for(int i=0;i<commaList.size();i++){
                    IO.parser_output(commaList.get(i).toString());
                    expList.get(i+1).print();
                }
            }
            IO.parser_output(rbrace.toString());
        }
        else if(strcon!=null){
            IO.parser_output(strcon.toString());
        }
        else{
            expList.get(0).print();
        }
        IO.parser_output(Parser.nodeTypes.get(NodeType.InitVal));
    }

    public List<Exp> getExpList() {
        return expList;
    }

    public Token getLbrace() {
        return lbrace;
    }

    public List<Token> getCommaList() {
        return commaList;
    }

    public Token getRbrace() {
        return rbrace;
    }

    public Token getStrcon() {
        return strcon;
    }
}
