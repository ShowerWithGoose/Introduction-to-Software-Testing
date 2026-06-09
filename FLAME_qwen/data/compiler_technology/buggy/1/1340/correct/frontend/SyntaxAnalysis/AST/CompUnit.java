package frontend.SyntaxAnalysis.AST;

import frontend.LexicalAnalysis.Word;

import java.util.ArrayList;

public class CompUnit {
    public ArrayList<Decl> declList;
    public ArrayList<FuncDef> funcDefList;
    public MainFuncDef mainFuncDef;

//    public void analyse() {
//        for (Decl decl : this.declList) {
//            decl.analyse();
//        }
//        for (FuncDef funcDef : this.funcDefList) {
//            funcDef.analyse();
//        }
//        this.mainFuncDef.analyse();
//    }
    public CompUnit(){
        declList = new ArrayList<>();
        funcDefList = new ArrayList<>();
    }
}
