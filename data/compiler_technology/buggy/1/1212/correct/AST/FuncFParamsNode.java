package AST;

import java.io.IOException;
import java.util.ArrayList;
import IO.*;
public class FuncFParamsNode extends ASTNode{

    ASTNodes type = ASTNodes.FuncRParams;
    ArrayList<FuncFParamNode> fparams;

    public FuncFParamsNode(ArrayList<FuncFParamNode> fparams) {
        this.fparams = fparams;
    }

    public ASTNodes getType() {
        return type;
    }

    public ArrayList<FuncFParamNode> getFparams() {
        return fparams;
    }


    
    public void postOrderTraversal(IO io) throws IOException {
        for (FuncFParamNode fparam : fparams) {
            fparam.postOrderTraversal(io);
            if (fparams.indexOf(fparam) != fparams.size() -1) {
                io.getParserWriter().write("COMMA ,\n");
            }
        }
        io.getParserWriter().write("<FuncFParams>\n");
    }

    
    public void postOrderNoPrint() {
        for (FuncFParamNode fparam : fparams) {
            fparam.postOrderNoPrint();
            if (fparams.indexOf(fparam) != fparams.size() -1) {

            }
        }
    }
}
