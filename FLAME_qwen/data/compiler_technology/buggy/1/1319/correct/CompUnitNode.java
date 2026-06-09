import java.io.IOException;
import java.util.List;

public class CompUnitNode extends ASTNode {
    List<DeclNode> decls;
    List<FuncDefNode> funcDefs;
    MainFuncDefNode mainFuncDef;

    public CompUnitNode(List<DeclNode> decls, List<FuncDefNode> funcDefs, MainFuncDefNode mainFuncDef) {
        this.decls = decls;
        this.funcDefs = funcDefs;
        this.mainFuncDef = mainFuncDef;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitCompUnit(this);
    }
}