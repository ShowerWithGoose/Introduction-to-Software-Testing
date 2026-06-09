package Nodes;/**
 * @Description:
 * @author
 * @date 2024/9/28 19:01
 */

import java.util.List;

import Config.Config;
import Token.Token;
import Utils.IO;
import frontend.*;
/**
 * @author:
 * TODO  
 * 2024/9/28 19:01
 */
public class LAndExp {
//    LAndExp â†’ EqExp | LAndExp '&&' EqExp
//    LAndExp -> EqExp { '&&' EqExp }
    private List<EqExp> eqExpList;
    private List<Token> andList;

    public LAndExp(List<EqExp> eqExpList,List<Token> andList){
        this.eqExpList=eqExpList;
        this.andList=andList;
    }

    public void print(){
        eqExpList.get(0).print();
        IO.parser_output(Parser.nodeTypes.get(NodeType.LAndExp));
        for(int i=1;i<eqExpList.size();i++){
            IO.parser_output(andList.get(i-1).toString());
            eqExpList.get(i).print();
            IO.parser_output(Parser.nodeTypes.get(NodeType.LAndExp));
        }
    }

    public List<EqExp> getEqExpList() {
        return eqExpList;
    }

    public List<Token> getAndList() {
        return andList;
    }
}
