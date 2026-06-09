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
public class ConstInitVal {
//    ConstInitVal â†’ ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
    private List<ConstExp> constExpList;
    private Token lbrace;
    private List<Token> commaList;
    private Token rbrace;
    private Token strcon;

    public ConstInitVal(List<ConstExp> constExpList, Token lbrace, List<Token> commaList, Token rbrace, Token strcon) {
        this.constExpList = constExpList;
        this.lbrace = lbrace;
        this.commaList = commaList;
        this.rbrace = rbrace;
        this.strcon = strcon;
    }

    public void print(){
        if(lbrace!=null){
            IO.parser_output(lbrace.toString());
            if(!constExpList.isEmpty()){
                constExpList.get(0).print();
                for(int i=1;i<constExpList.size();i++){
                    IO.parser_output(commaList.get(i-1).toString());
                    constExpList.get(i).print();
                }
            }
            IO.parser_output(rbrace.toString());
        }
        else if(strcon!=null){
            IO.parser_output(strcon.toString());
        }
        else{
            constExpList.get(0).print();
        }
        IO.parser_output(Parser.nodeTypes.get(NodeType.ConstInitVal));
    }

    public List<ConstExp> getConstExpList() {
        return constExpList;
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
