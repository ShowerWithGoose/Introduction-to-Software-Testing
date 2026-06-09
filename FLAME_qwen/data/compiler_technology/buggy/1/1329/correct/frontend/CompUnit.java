package frontend;
import java.util.ArrayList;

public class CompUnit {
    //{Decl} {FuncDef} MainFuncDef
    private ArrayList<Decl> decls = new ArrayList<>();
    private ArrayList<FuncDef> funcDefs = new ArrayList<>();
    private MainFuncDef mainFuncDef;

    public CompUnit() {
        this.decls = new ArrayList<>();
        this.funcDefs = new ArrayList<>();
    }

    public void addDecl(Decl decl) {
        decls.add(decl);
    }

    public void addFuncDef(FuncDef funcDef) {
        funcDefs.add(funcDef);
    }

    public void setMainFuncDef(MainFuncDef mainFuncDef) {
        this.mainFuncDef = mainFuncDef;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Decl it : decls) {
            sb.append(it.toString());
        }
        for (FuncDef it : funcDefs) {
            sb.append(it.toString());
        }
        sb.append(mainFuncDef.toString());
        sb.append("<CompUnit>");
        sb.append("\n");
        return sb.toString();
    }
}
