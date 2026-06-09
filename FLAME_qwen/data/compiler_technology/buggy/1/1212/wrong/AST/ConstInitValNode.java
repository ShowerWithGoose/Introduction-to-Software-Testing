package AST;

import java.io.IOException;
import java.util.ArrayList;

import IO.*;

//常量初值 ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' |
//StringConst // 1.常表达式初值 2.一维数组初值
public class ConstInitValNode extends ASTNode{

    ASTNodes type = ASTNodes.ConstInitVal;
    ArrayList<ConstExpNode> constExpNodes;

    StringConst stringConst;

    int t;

    public ConstInitValNode(ArrayList<ConstExpNode> constExpNodes, int t) {
        this.constExpNodes = constExpNodes;
        this.t = t;
    }

    public ConstInitValNode(StringConst stringConst) {
        this.stringConst = stringConst;
        this.t = 3;
    }

    public int getT() {
        return t;
    }

    public ASTNodes getType() {
        return type;
    }

    public ArrayList<ConstExpNode> getConstExpNodes() {
        return constExpNodes;
    }

    public StringConst getStringConst() {
        return stringConst;
    }

    
    public void postOrderTraversal(IO io) throws IOException {
        if (this.t == 1) {
            ConstExpNode constExpNode = constExpNodes.get(0);
            constExpNode.postOrderTraversal(io);
        } else if (this.t == 2) {
            io.getParserWriter().write("LBRACE {\n");
            if (constExpNodes.isEmpty()) {
                io.getParserWriter().write("RBRACE }\n");
            } else {
                for (ConstExpNode constExpNode: this.constExpNodes) {
                    constExpNode.postOrderTraversal(io);
                    if (this.constExpNodes.indexOf(constExpNode)!= this.constExpNodes.size() - 1) {
                        io.getParserWriter().write("COMMA ,\n");
                    }
                }
                io.getParserWriter().write("RBRACE }\n");
            }
        } else if (this.t == 3) {
            stringConst.postOrderTraversal(io);
        }
        io.getParserWriter().write("<ConstInitVal>\n");
    }

    
    public void postOrderNoPrint() {
        if (this.t == 1) {
            ConstExpNode constExpNode = constExpNodes.get(0);
            constExpNode.postOrderNoPrint();
        } else if (this.t == 2) {
            if (constExpNodes.isEmpty()) {

            } else {
                for (ConstExpNode constExpNode: this.constExpNodes) {
                    constExpNode.postOrderNoPrint();
                    if (this.constExpNodes.indexOf(constExpNode)!= this.constExpNodes.size() - 1) {

                    }
                }
            }
        } else if (this.t == 3) {
            stringConst.postOrderNoPrint();
        }
    }
}
