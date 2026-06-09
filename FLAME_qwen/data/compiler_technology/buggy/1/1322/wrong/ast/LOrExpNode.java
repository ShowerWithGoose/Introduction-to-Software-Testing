package ast;

import IO.IO;
import enum_package.NodeType;
import frontend.Token;
import frontend.Parser;

public class LOrExpNode {
    // LOrExp â†’ LAndExp | LOrExp '||' LAndExp
    public LAndExpNode lAndExp;
    public LOrExpNode lOrExp;
    public Token op;

    public LOrExpNode(LAndExpNode lAndExp, LOrExpNode lOrExp, Token op) {
        this.lAndExp = lAndExp;
        this.lOrExp = lOrExp;
        this.op = op;
    }

    public void print() {
        lAndExp.print();
        IO.write(Parser.nodeTypeLabel.get(NodeType.LOrExp));
        if (op != null) {
            IO.write(op.toString());
            lOrExp.print();
        }
    }
}
