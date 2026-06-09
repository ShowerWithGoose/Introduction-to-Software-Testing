package ast;

import IO.IO;
import enum_package.NodeType;
import frontend.Token;
import frontend.Parser;

public class LAndExpNode {
    // LAndExp â†’ EqExp | LAndExp '&&' EqExp
    public EqExpNode eqExp;
    public LAndExpNode lAndExp;
    public Token op;

    public LAndExpNode(EqExpNode eqExp, LAndExpNode lAndExp, Token op) {
        this.eqExp = eqExp;
        this.lAndExp = lAndExp;
        this.op = op;
    }

    public void print() {
        eqExp.print();
        IO.write(Parser.nodeTypeLabel.get(NodeType.LAndExp));
        if (op != null){
            IO.write(op.toString());
            lAndExp.print();
        }
    }
}
