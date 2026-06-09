package frontend.parser;

import frontend.parser.decl.types.Decl;
import frontend.parser.func.types.FuncDef;

import java.util.ArrayList;

public class CompUnit {
    private final ArrayList<Decl> globalDecls = new ArrayList<>();
    private final ArrayList<FuncDef> functions = new ArrayList<>();
    private FuncDef mainFuncDef = null;
    public void addDecl(Decl newDecl) {
        this.globalDecls.add(newDecl);
    }
    public void addFunc(FuncDef newFunc) {
        this.functions.add(newFunc);
    }
    public void setMainFunc(FuncDef mainFunc) {
        this.functions.add(mainFunc);
        this.mainFuncDef = mainFunc;
    }
    public ArrayList<Decl> getGlobalDecls() {
        return this.globalDecls;
    }
    public ArrayList<FuncDef> getFunctions() {
        return this.functions;
    }
    public FuncDef getMainFuncDef() {
        return this.mainFuncDef;
    }
    @Override
    public String toString() {
        StringBuilder res = new StringBuilder();
        for (Decl decl: globalDecls) {
            res.append(decl);
        }
        for (FuncDef func: functions) {
            res.append(func);
        }
        res.append(mainFuncDef);
        res.append("<CompUnit>\n");
        return res.toString();
    }
}
