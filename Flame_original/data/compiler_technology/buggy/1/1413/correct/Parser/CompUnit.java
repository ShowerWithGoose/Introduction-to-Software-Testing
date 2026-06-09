package Parser;

import Parser.Func.FuncDef;

import java.util.ArrayList;

/**
 * @Description:
 * @date 2024/10/7
 */
public class CompUnit implements TreeNode {
    private final String value= "<CompUnit>";
    private ArrayList<Decl> decls=new ArrayList<>();
    private ArrayList<FuncDef> funcDefs=new ArrayList<>();
    private MainFuncDef mainFuncDef;
    public CompUnit(ArrayList<Decl> decls,ArrayList<FuncDef> funcDefs,MainFuncDef mainFuncDef)
    {
        this.decls=decls;
        this.funcDefs=funcDefs;
        this.mainFuncDef=mainFuncDef;
    }

    @Override
    public String print_tree() {
        StringBuilder sb = new StringBuilder();
        if (!this.decls.isEmpty()) {
            for (Decl decl : this.decls) {
                sb.append(decl.print_tree());
            }
        }
        if (!this.funcDefs.isEmpty()) {
            for (FuncDef funcDef : this.funcDefs) {
                sb.append(funcDef.print_tree());
            }
        }
        sb.append(this.mainFuncDef.print_tree());
        sb.append(this.value).append("\n");
        return sb.toString();
    }
}
