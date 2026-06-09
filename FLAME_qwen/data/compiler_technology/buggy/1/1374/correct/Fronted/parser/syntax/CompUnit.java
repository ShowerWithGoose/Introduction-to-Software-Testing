package Fronted.parser.syntax;

import java.util.ArrayList;

// CompUnit â†’ {Decl} {FuncDef} MainFuncDef
public class CompUnit {
    private static final CompUnit compUnit = new CompUnit();

    private static final String name = "<CompUnit>";

    private ArrayList<Decl> declList;

    private ArrayList<FuncDef> funcDefList;

    private MainFuncDef mainFuncDef;

    public CompUnit() {
        this.declList = new ArrayList<>();
        this.funcDefList = new ArrayList<>();
        this.mainFuncDef = null;
    }

    public static CompUnit getCompUnit(){
        return compUnit;
    }

    public String toString(){
        StringBuilder out=new StringBuilder();
        for(Decl decl : declList) out.append(decl);
        for(FuncDef funcDef : funcDefList) out.append(funcDef);
        out.append(mainFuncDef);
        out.append(name);
        return out.toString();
    }

    public ArrayList<Decl> getDeclList(){
        return declList;
    }

    public ArrayList<FuncDef> getFuncDefList(){
        return funcDefList;
    }

    public MainFuncDef getMainFuncDef(){
        return mainFuncDef;
    }

    public void setDeclList(ArrayList<Decl> declList){
        this.declList = declList;
    }

    public void setFuncDefList(ArrayList<FuncDef> funcDefList){
        this.funcDefList = funcDefList;
    }

    public void setMainFuncDef(MainFuncDef mainFuncDef){
        this.mainFuncDef = mainFuncDef;
    }
}
