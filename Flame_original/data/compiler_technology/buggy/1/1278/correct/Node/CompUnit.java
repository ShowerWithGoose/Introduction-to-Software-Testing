package Node;
import Tools.Token;
import Tools.WriteFile;
import java.util.ArrayList;
public class CompUnit extends Node {
    ArrayList<Decl> decls;
    ArrayList<FuncDef> funcDefs;
    MainFuncDef mainFuncDef;

    public CompUnit(int lineno, ArrayList<Decl> decls, ArrayList<FuncDef> funcDefs, MainFuncDef mainFuncDef) {
        super(lineno);
        this.decls = decls;
        this.funcDefs = funcDefs;
        this.mainFuncDef = mainFuncDef;
    }

    public void checkOut() {
        for (Decl decl : decls) {
            decl.checkOut();
        }
        for (FuncDef funcDef : funcDefs) {
            funcDef.checkOut();
        }
        mainFuncDef.checkOut();
        WriteFile.MakeFile("<CompUnit>\n");
    }
}
