package Nodes;/**
 * @Description:
 * @author
 * @date 2024/9/28 19:01
 */

import Utils.IO;
import frontend.Parser;

/**
 * @author:
 * TODO  
 * 2024/9/28 19:01
 */
public class ConstExp {
//    ConstExp â†’ AddExp
    private AddExp addExp;

    public ConstExp(AddExp addExp){
        this.addExp=addExp;
    }

    public void print(){
        addExp.print();
        IO.parser_output(Parser.nodeTypes.get(NodeType.ConstExp));
    }

    public AddExp getAddExp() {
        return addExp;
    }
}
