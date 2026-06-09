package fronted.Parser.SyntaxTree;

import java.util.ArrayList;

/**
 * @author
 * @Description:
 * @date 2024/10/11 16:48
 */
public class CompUnit implements SyntaxNode {
    private final String name = "<CompUnit>";
    private ArrayList<Decl> decls ; // MAY exist
    private ArrayList<FuncDef> funcDefs; // MAY exist
    private MainFuncDef mainFuncDef;

    public CompUnit(ArrayList<Decl> decls,
                    ArrayList<FuncDef> funcDefs,
                    MainFuncDef mainFuncDef) {
        this.mainFuncDef = mainFuncDef;
        this.decls = decls;
        this.funcDefs = funcDefs;
    }

    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        if (!this.decls.isEmpty()) {
            for (Decl decl : decls) {
                sb.append(decl.output()); // 假设 Decl 类中有 printDecl() 方法
            }
        }
        if (!this.funcDefs.isEmpty()) {
            for (FuncDef funcDef : funcDefs) {
                sb.append(funcDef.output()); // 假设 FuncDef 类中有 printFuncDef() 方法
            }
        }
        sb.append(this.mainFuncDef.output());
        sb.append(this.name + "\n");
        return sb.toString();
    }

    public void addDecl(Decl decl){
        this.decls.add(decl);
    }
    public void addFuncDef(FuncDef funcDef){
        this.funcDefs.add(funcDef);
    }

    public void setMainFuncDef(MainFuncDef mainFuncDef) {
        this.mainFuncDef = mainFuncDef;
    }
}
