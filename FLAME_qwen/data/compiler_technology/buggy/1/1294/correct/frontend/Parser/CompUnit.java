package frontend.Parser;

import frontend.Parser.declaration.Decl;
import frontend.Parser.function.FuncDef;
import frontend.Parser.function.MainFuncDef;

import java.util.ArrayList;

public class CompUnit {
    private ArrayList<Decl> decls = null;
    private ArrayList<FuncDef> funcDefs = null;
    private MainFuncDef mainFuncDef;
    private final String grammarName = "<CompUnit>";

    public CompUnit(MainFuncDef mainFuncDef) {
        this.mainFuncDef = mainFuncDef;
    }

    public CompUnit(ArrayList<Decl> decls, ArrayList<FuncDef> funcDefs,MainFuncDef mainFuncDef) {
        this.decls = decls;
        this.funcDefs = funcDefs;
        this.mainFuncDef = mainFuncDef;
    }

    public String grammarOutput(){
        StringBuilder sb = new StringBuilder();
        if(decls != null){
            for(Decl d : decls){
                sb.append(d.grammarOutput());
            }
        }
        if(funcDefs != null){
            for(FuncDef f : funcDefs){
                sb.append(f.grammarOutput());
            }
        }
        sb.append(mainFuncDef.grammarOutput());
        sb.append(this.grammarName);
        sb.append('\n');
        return sb.toString();
    }

}
