package tree;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class CompUnit {
    private final ArrayList<Decl> decls = new ArrayList<>();
    private final ArrayList<FuncDef> funcDefs = new ArrayList<>();
    private MainFuncDef mainFuncDef;


    public void addDecl(Decl decl) {
        decls.add(decl);
    }

    public void addFuncDef(FuncDef funcDef) {
        funcDefs.add(funcDef);
    }

    public void setMainFuncDef(MainFuncDef mainFuncDef) {
        this.mainFuncDef = mainFuncDef;
    }

    public void output(FileWriter fileWriter) throws IOException {
        for (Decl decl : decls) {
            decl.output(fileWriter);
        }
        for (FuncDef funcDef : funcDefs) {
            funcDef.output(fileWriter);
        }
        mainFuncDef.output(fileWriter);
        fileWriter.write("<CompUnit>\n");
    }
}
