package frontend.parseApart.NodeDef.Normal;

import java.util.ArrayList;

public class CompUnit {
    private ArrayList<Decl> decls = new ArrayList<>();
    private ArrayList<FuncDef> funcDefs = new ArrayList<>();
    private MainFuncDef mainFuncDef;

    public CompUnit() {}

    public void setDecl(Decl decl) {
        this.decls.add(decl);
    }

    public void setFuncDef(FuncDef funcDef) {
        this.funcDefs.add(funcDef);
    }

    public void setMainFuncDef(MainFuncDef mainFuncDef) {
        this.mainFuncDef = mainFuncDef;
    }

    public String returnSymbolType() {
        String string = "<CompUnit>";
        return string;
    }
}
