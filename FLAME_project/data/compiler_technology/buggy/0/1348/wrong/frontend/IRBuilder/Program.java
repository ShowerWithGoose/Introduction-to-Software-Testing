package frontend.IRBuilder;

import frontend.IRBuilder.structure.Function;
import frontend.IRBuilder.structure.GlobalVar;
import frontend.IRBuilder.structure.SymTab;
import frontend.syntax.Ast;

import java.util.ArrayList;

public class Program {
    public SymTab curSymTab = new SymTab();
    public ArrayList<GlobalVar> globalVarList = new ArrayList<>();
    public final ArrayList<Function> functionList = new ArrayList<>();

    public Program(Ast ast) {
        for (Ast.CompUnit compUnit : ast.nodes) {
            if (compUnit instanceof Ast.FuncDef) {
                functionList.add(new Function((Ast.FuncDef) compUnit, curSymTab));
            } else if (compUnit instanceof Ast.Decl) {
                curSymTab.parseSymbolsForDecl((Ast.Decl) compUnit);
            } else {
                throw new RuntimeException("未定义的编译单元");
            }
        }
    }
}