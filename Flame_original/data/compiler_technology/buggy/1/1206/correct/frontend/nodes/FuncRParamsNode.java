package frontend.nodes;

import frontend.token;
import print.out;

import java.io.IOException;
import java.util.ArrayList;

/**
 * @author
 * @Description:
 * @date 2024/10/10 8:22
 */
public class FuncRParamsNode {
    // FuncRParams → Exp { ',' Exp }
    ArrayList<ExpNode> expNodes;
    ArrayList<token> commas;
    public FuncRParamsNode(ArrayList<ExpNode> expNodes, ArrayList<token> commas){
        this.commas=commas;
        this.expNodes=expNodes;
    }

    public void output() throws IOException {
        expNodes.get(0).output();
        for(int i=1;i<expNodes.size();i++){
            out.write(commas.get(i-1).toString());
            expNodes.get(i).output();
        }
        out.write("<FuncRParams>");
    }
}
