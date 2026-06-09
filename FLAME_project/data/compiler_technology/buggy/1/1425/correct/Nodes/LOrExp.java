package Nodes;
import Config.Config;
import Token.Token;
import Utils.IO;
/**
 * @Description:
 * @author
 * @date 2024/9/28 19:01
 */

import java.util.List;
import frontend.*;

/**
 * @author:
 * TODO  
 * 2024/9/28 19:01
 */
public class LOrExp {
//     LOrExp â†’ LAndExp | LOrExp '||' LAndExp
//    LOrExp -> LAndExp { '||' LAndExp }
    private List<Token> orList;
    private List<LAndExp> lAndExpList;

    public LOrExp(List<LAndExp> lAndExpList, List<Token> orList){
        this.orList=orList;
        this.lAndExpList=lAndExpList;
    }

    public void print(){
        lAndExpList.get(0).print();
        IO.parser_output(Parser.nodeTypes.get(NodeType.LOrExp));
        for(int i=1;i<lAndExpList.size();i++){
            IO.parser_output(orList.get(i-1).toString());
            lAndExpList.get(i).print();
            IO.parser_output(Parser.nodeTypes.get(NodeType.LOrExp));
        }
    }
    public List<Token> getOrList() {
        return orList;
    }

    public List<LAndExp> getlAndExpList() {
        return lAndExpList;
    }
}
