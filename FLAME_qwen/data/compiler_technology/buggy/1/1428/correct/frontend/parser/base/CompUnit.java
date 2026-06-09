package frontend.parser.base;

import frontend.parser.func.FuncDef;
import frontend.parser.func.MainFuncDef;
import frontend.parser.stmt.DeclStmt;

import java.util.ArrayList;

public class CompUnit {
    private ArrayList<DeclStmt> declStmts;
    private ArrayList<FuncDef> funcDefs;
    private MainFuncDef mainFuncDef;

    public CompUnit(ArrayList<DeclStmt> declStmts, ArrayList<FuncDef> funcDefs, MainFuncDef mainFuncDef) {
        this.declStmts = declStmts;
        this.funcDefs = funcDefs;
        this.mainFuncDef = mainFuncDef;
    }

    @Override
    public String toString() {
        String string = "";
        for (DeclStmt declStmt : this.declStmts) {
            string += declStmt.toString();
        }
        for (FuncDef funcDef : this.funcDefs) {
            string += funcDef.toString();
        }
        string += mainFuncDef.toString();
        string += "<CompUnit>";
        return string;
    }
}
