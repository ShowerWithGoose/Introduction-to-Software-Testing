package frontend.Nodes;

import java.util.ArrayList;
import java.util.List;

public class CompUnit implements Node {
    private final List<Decl> declList;
    private final List<FuncDef> funDefList;
    private MainFuncDef mainFuncDef;

    public CompUnit() {
        this.declList = new ArrayList<>();
        this.funDefList = new ArrayList<>();
        this.mainFuncDef = null;
    }

    public void addDecl(Decl decl) {
        declList.add(decl);
    }

    public void addFuncDef(FuncDef funcDef) {
        funDefList.add(funcDef);
    }

    public void addMainFuncDef(MainFuncDef mainFuncDef) {
        this.mainFuncDef = mainFuncDef;
    }

    @Override
    public String error() {
        StringBuilder sb = new StringBuilder();
        for (Decl decl : declList) {
            sb.append(decl.error());
        }
        for (FuncDef funcDef : funDefList) {
            sb.append(funcDef.error());
        }
        if (mainFuncDef != null) {
            sb.append(mainFuncDef.error());
        }
        return sb.toString();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Decl decl : declList) {
            sb.append(decl.toString());
        }
        for (FuncDef funcDef : funDefList) {
            sb.append(funcDef.toString());
        }
        if (mainFuncDef != null) {
            sb.append(mainFuncDef.toString());
        }
        sb.append("<CompUnit>\n");
        return sb.toString();
    }
}
