package frontend.parser.ast;

import frontend.parser.ast.decl.MainFuncDef;
import frontend.parser.ast.decl.Decl;
import frontend.parser.ast.decl.FuncDef;

import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;

public class CompUnit {
    private String type = "<CompUnit>";
    private ArrayList<Decl> decls;
    private ArrayList<FuncDef> funcDefs;
    private MainFuncDef mainFuncDef;

    public CompUnit() {
        this.decls = new ArrayList<>();
        this.funcDefs = new ArrayList<>();
        this.mainFuncDef = null;
    }

    public void addDecl(Decl decl) {
        this.decls.add(decl);
    }

    public void addFuncDef(FuncDef funcDef) {
        this.funcDefs.add(funcDef);
    }

    public void setMainFuncDef(MainFuncDef mainFuncDef) {
        this.mainFuncDef = mainFuncDef;
    }

    public String getOutput() {
        StringBuilder out = new StringBuilder();
        for (Decl decl : this.decls) {
            out.append(decl.getOutput());
        }
        for (FuncDef funcDef : this.funcDefs) {
            out.append(funcDef.getOutput());
        }
        out.append(this.mainFuncDef.getOutput());
        out.append(type + "\n");

        return out.toString();
    }

    public String getError() {
        StringBuilder out = new StringBuilder();
        for (Decl decl : this.decls) {
            out.append(decl.getError());
        }
        for (FuncDef funcDef : this.funcDefs) {
            out.append(funcDef.getError());
        }
        out.append(this.mainFuncDef.getError());
        return out.toString();
    }

    public void output() throws FileNotFoundException{
        PrintStream ps = new PrintStream("parser.txt");
        System.setOut(ps);
        System.out.println(this.getOutput());
        ps.close();
    }

    public void errors() throws FileNotFoundException{
        PrintStream ps = new PrintStream("error.txt");
        System.setOut(ps);
        System.out.println(this.getError());
        ps.close();
    }
}
