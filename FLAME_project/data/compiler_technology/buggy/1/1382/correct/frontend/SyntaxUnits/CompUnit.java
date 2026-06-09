package frontend.SyntaxUnits;

import java.util.ArrayList;

public class CompUnit implements SyntaxUnit{

    private ArrayList<Decl> decls;
    private ArrayList<FuncDef> funcDefs;
    private MainFuncDef mainFuncDef;

    public CompUnit(ArrayList<Decl> decls,
                    ArrayList<FuncDef> funcDefs,
                    MainFuncDef mainFuncDef) {
        this.decls = decls;
        this.funcDefs = funcDefs;
        this.mainFuncDef = mainFuncDef;
    }

    public String toPrint() {
        StringBuilder stringBuilder = new StringBuilder();

        for (Decl decl : decls) {
            stringBuilder.append(decl.toPrint());
        }
        for (FuncDef funcDef : funcDefs) {
            stringBuilder.append(funcDef.toPrint());
        }
        stringBuilder.append(mainFuncDef.toPrint());
        stringBuilder.append("<CompUnit>\n");
        return stringBuilder.toString();
    }
}
