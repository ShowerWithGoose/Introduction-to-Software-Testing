package frontend.Parser;

import frontend.Parser.Decl.Decl;

import java.util.ArrayList;

//编译单元 CompUnit → {Decl} {FuncDef} MainFuncDef
public class CompUnit implements Output{
    private final String name = "<CompUnit>";
    private ArrayList<Decl> decls = null; // MAY exist
    private ArrayList<FuncDef> funcDefs = null; // MAY exist
    private MainFuncDef mainFuncDef;

    public CompUnit(MainFuncDef mainFuncDef) {
        this.mainFuncDef = mainFuncDef;
    }

    public CompUnit(ArrayList<Decl> decls, ArrayList<FuncDef> funcDefs, MainFuncDef mainFuncDef) {
        this.mainFuncDef = mainFuncDef;
        this.decls = decls;
        this.funcDefs = funcDefs;
    }


    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        if(this.decls != null) {
            for(int i = 0; i < this.decls.size(); i++) {
                sb.append(this.decls.get(i).Parser_Output());
            }
        }
        if(this.funcDefs != null) {
            for(int i = 0; i < this.funcDefs.size(); i++) {
                sb.append(this.funcDefs.get(i).Parser_Output());
            }
        }
        sb.append(this.mainFuncDef.Parser_Output());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
