package frontend.nodes;

import frontend.token;
import print.out;

import java.io.IOException;
import java.util.ArrayList;

/**
 * @author
 * @Description:
 * @date 2024/9/30 12:03
 */
public class ConstInitValNode {
    //ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
    ConstExpNode constExpNode;
    token lbraceToken;//{
    ArrayList<ConstExpNode> constExpNodes = new ArrayList<>();
    token rbraceToken;//}
    ArrayList<token> commas = new ArrayList<>();
    token stringConst;
    public ConstInitValNode(
            ConstExpNode constExpNode,
            token lbraceToken,
            ArrayList<ConstExpNode> constExpNodes,
            token rbraceToken,
            ArrayList<token> commas,
            token stringConst
    ){
        this.constExpNode=constExpNode;
        this.lbraceToken=lbraceToken;
        this.constExpNodes=constExpNodes;
        this.rbraceToken=rbraceToken;
        this.commas=commas;
        this.stringConst=stringConst;
    }

    public void output() throws IOException {
        if(lbraceToken!=null){
            out.write(lbraceToken.toString());
            if(constExpNodes.size()>0){
                constExpNodes.get(0).output();
                for (int i = 1; i < constExpNodes.size(); i++) {
                    out.write(commas.get(i - 1).toString());
                    constExpNodes.get(i).output();
                }
            }
            out.write(rbraceToken.toString());

        }else if(stringConst!=null){
            out.write(stringConst.toString());
        }else {
            constExpNode.output();
        }
        out.write("<ConstInitVal>");
    }
}
