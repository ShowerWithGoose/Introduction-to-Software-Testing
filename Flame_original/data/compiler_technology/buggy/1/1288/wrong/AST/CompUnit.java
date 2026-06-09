package AST;

import java.util.ArrayList;

public class CompUnit {
    private ArrayList<Decl> decls = new ArrayList<>();
    private ArrayList<FuncDef> funcDefs = new ArrayList<>();
    private MainFuncDef mainFunc;
    public CompUnit(ArrayList<Decl> decls, ArrayList<FuncDef> funcDefs, MainFuncDef mainFunc){
        this.decls=(decls);
        this.funcDefs=(funcDefs);
        this.mainFunc = mainFunc;
    }

}
