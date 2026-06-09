package struct;

import java.util.List;

/* CompUnit â†’ {Decl} {FuncDef} MainFuncDef */
public class CompUnit {
    private final List<Decl> decl;
    private final List<FuncDef> funcDef;
    private final MainFuncDef mainFuncDef;

    public CompUnit(List<Decl> decl, List<FuncDef> funcDef, MainFuncDef mainFuncDef) {
        this.decl = decl;
        this.funcDef = funcDef;
        this.mainFuncDef = mainFuncDef;
    }

    public List<Decl> getDecl() {
        return decl;
    }

    public List<FuncDef> getFuncDef() {
        return funcDef;
    }

    public MainFuncDef getMainFuncDef() {
        return mainFuncDef;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Decl decl : decl) {
            sb.append(decl.toString());
        }
        for (FuncDef funcDef : funcDef) {
            sb.append(funcDef.toString());
        }
        sb.append(mainFuncDef.toString());
        sb.append("<CompUnit>\n");
        return sb.toString();
    }
}
