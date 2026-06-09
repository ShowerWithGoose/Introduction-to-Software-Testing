package AST;
import IO.*;

import java.io.IOException;

public class GetIntStmt extends ASTNode{

    ASTNodes type = ASTNodes.GETINT;
    LValNode LVal;
    public GetIntStmt(LValNode LVal) {
        this.LVal = LVal;
    }

    public LValNode getLVal() {
        return LVal;
    }

    public ASTNodes getType() {
        return type;
    }

    
    public void postOrderTraversal(IO io) throws IOException {
        LVal.postOrderTraversal(io);
        io.getParserWriter().write("ASSIGN =\n");
        io.getParserWriter().write("GETINTTK getint\n");
        io.getParserWriter().write("LPARENT (\n");
        io.getParserWriter().write("RPARENT )\n");
        io.getParserWriter().write("SEMICN ;\n");
    }

    
    public void postOrderNoPrint() {
        LVal.postOrderNoPrint();
    }
}
