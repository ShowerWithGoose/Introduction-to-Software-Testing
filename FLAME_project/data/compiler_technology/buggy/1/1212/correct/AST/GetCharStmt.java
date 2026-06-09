package AST;
import IO.*;

import java.io.IOException;

public class GetCharStmt extends ASTNode{

    ASTNodes type = ASTNodes.GETCHAR;
    LValNode LVal;
    public GetCharStmt(LValNode LVal) {
        this.LVal = LVal;
    }

    public ASTNodes getType() {
        return type;
    }

    public LValNode getLVal() {
        return LVal;
    }

    
    public void postOrderTraversal(IO io) throws IOException {
        LVal.postOrderTraversal(io);
        io.getParserWriter().write("ASSIGN =\n");
        io.getParserWriter().write("GETCHARTK getchar\n");
        io.getParserWriter().write("LPARENT (\n");
        io.getParserWriter().write("RPARENT )\n");
        io.getParserWriter().write("SEMICN ;\n");
    }

    
    public void postOrderNoPrint() {
        LVal.postOrderNoPrint();
    }
}
