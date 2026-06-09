package frontend.nodes;

import frontend.token;
import print.out;

import java.io.IOException;
import java.util.ArrayList;

/**
 * @author
 * @Description:
 * @date 2024/10/10 8:15
 */
public class FuncFParamsNode {
    // FuncFParams → FuncFParam { ',' FuncFParam }
    ArrayList<FuncFParamNode> funcFParamNodes;
    ArrayList<token> commas;
    public FuncFParamsNode(ArrayList<FuncFParamNode> funcFParamNodes,ArrayList<token> commas){
        this.funcFParamNodes=funcFParamNodes;
        this.commas=commas;
    }

    public void output() throws IOException {
        funcFParamNodes.get(0).output();
        for(int i=1;i<funcFParamNodes.size();i++){
            out.write(commas.get(i-1).toString());
            funcFParamNodes.get(i).output();
        }
        out.write("<FuncFParams>");
    }
}
