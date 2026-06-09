package frontend.DataStructure.ASTNodes;

import frontend.DataStructure.*;

public class ENode extends ASTNode {
    public ErrorIndex errorInfo;

    public ENode(ErrorIndex errorInfo, String name) {
        super(name);
        this.errorInfo = errorInfo;
    }
}