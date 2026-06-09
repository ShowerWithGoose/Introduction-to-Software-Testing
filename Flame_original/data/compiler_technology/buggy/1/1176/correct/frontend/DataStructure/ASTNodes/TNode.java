package frontend.DataStructure.ASTNodes;

import frontend.DataStructure.*;
public class TNode extends ASTNode {
    public Lex lexInfo;
    public TNode(Lex lexInfo, String name) {
        super(name);
        this.lexInfo = lexInfo;
    }
}