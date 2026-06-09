package AST;
import IO.*;

import java.io.IOException;
import java.util.ArrayList;

public class InitVal extends ASTNode{
    ASTNodes type = ASTNodes.Initval;

    ArrayList<ExprNode> exps;

    StringConst string;

    int t;

    boolean isStringConst;

    public InitVal(ArrayList<ExprNode> exps, int t) {
        this.exps = exps;
        this.t = t;
        this.isStringConst = false;
    }

    public InitVal(StringConst string) {
        this.string = string;
        this.isStringConst = true;
        this.t = 3;
    }

    public int getT() {
        return t;
    }

    public ASTNodes getType() {
        return type;
    }

    public ArrayList<ExprNode> getExps() {
        return exps;
    }

    public boolean isStringConst() {
        return isStringConst;
    }

    public StringConst getString() {
        return string;
    }

    
    public void postOrderTraversal(IO io) throws IOException {
        if (isStringConst) {
            string.postOrderTraversal(io);
        } else if (t == 1){
            io.getParserWriter().write("LBRACE {\n");
            if (exps.isEmpty()) {
                io.getParserWriter().write("}\n");
            } else {
                for (ExprNode exp : exps) {
                    exp.postOrderTraversal(io);
                    if (exps.indexOf(exp) != exps.size() - 1) {
                        io.getParserWriter().write("COMMA ,\n");
                    }
                }
                io.getParserWriter().write("RBRACE }\n");
            }
        } else if (t == 2) {
            for (ExprNode exp : exps) {
                exp.postOrderTraversal(io);
            }
        }
        io.getParserWriter().write("<InitVal>\n");
    }

    
    public void postOrderNoPrint() {
        if (isStringConst) {
            string.postOrderNoPrint();
        } else if (t == 1){

            if (exps.isEmpty()) {

            } else {
                for (ExprNode exp : exps) {
                    exp.postOrderNoPrint();
                    if (exps.indexOf(exp) != exps.size() - 1) {

                    }
                }

            }
        } else if (t == 2) {
            for (ExprNode exp : exps) {
                exp.postOrderNoPrint();
            }
        }
    }
}
