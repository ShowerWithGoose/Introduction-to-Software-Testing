package frontend.node;

import frontend.token.Token;
import utils.Tools;

import java.util.ArrayList;
import java.util.Objects;

//<EqExp> ::= <RelExp> | <EqExp> ('==' | '!=') <RelExp>
public class EqExpNode extends Node {
    private EqExpNode eqExpNode;
    private Token eqToken;
    private RelExpNode relExpNode;

    public EqExpNode(EqExpNode eqExpNode, Token eqToken, RelExpNode relExpNode) {
        super(NodeType.EQ_EXP);
        this.eqExpNode = eqExpNode;
        this.eqToken = eqToken;
        this.relExpNode = relExpNode;
    }

    @Override
    public String toString() {
        return Objects.toString(eqExpNode, "") +
                Objects.toString(eqToken, "") + relExpNode + nodeType;
    }
}
