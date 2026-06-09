package ast;

import IO.IO;
import enum_package.EqExpType;
import enum_package.NodeType;
import frontend.Token;
import frontend.Parser;

public class EqExpNode {
    // EqExp â†’ RelExp | EqExp ('==' | '!=') RelExp
    public RelExpNode relExp;
    public EqExpNode eqExp;
    public Token op;

    public EqExpNode(RelExpNode relExp, EqExpNode eqExp, Token op) {
        this.relExp = relExp;
        this.eqExp = eqExp;
        this.op = op;
    }

    public void print() {
        relExp.print();
        IO.write(Parser.nodeTypeLabel.get(NodeType.EqExp));
        if (op != null) {
            IO.write(op.toString());
            eqExp.print();
        }
    }
}
