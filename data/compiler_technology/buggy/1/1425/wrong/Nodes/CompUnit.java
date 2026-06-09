package Nodes;/**
 * @Description:
 * @author
 * @date 2024/9/28 18:57
 */

import Utils.IO;
import frontend.Parser;

import java.util.List;

/**
 * @author:
 * TODO  
 * 2024/9/28 18:57
 */
public class CompUnit {
//    CompUnit -> {Decl} {FuncDef} MainFuncDef
    private List<Decl> decls;
    private List<FuncDef> funcDefs;
    private MainFuncDef mainFuncDef;

    public CompUnit(List<Decl> decls,List<FuncDef> funcDefs,MainFuncDef mainFuncDef){
        this.decls=decls;
        this.funcDefs=funcDefs;
        this.mainFuncDef=mainFuncDef;
    }

    public void print(){
        for(Decl decl:decls){
            decl.print();
        }
        for(FuncDef funcDef:funcDefs){
            funcDef.print();
        }
        mainFuncDef.print();
        IO.parser_output(Parser.nodeTypes.get(NodeType.CompUnit));
    }

    public List<Decl> getDecls() {
        return decls;
    }

    public List<FuncDef> getFuncDefs() {
        return funcDefs;
    }

    public MainFuncDef getMainFuncDef() {
        return mainFuncDef;
    }
}
