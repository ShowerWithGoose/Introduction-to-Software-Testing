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
    private List<Decl> declList;
    private List<FuncDef> funcDefList;
    private MainFuncDef mainFuncDef;

    public CompUnit(List<Decl> declList,List<FuncDef> funcDefList,MainFuncDef mainFuncDef){
        this.declList=declList;
        this.funcDefList=funcDefList;
        this.mainFuncDef=mainFuncDef;
    }

    public void print(){
        for(Decl decl:declList){
            decl.print();
        }
        for(FuncDef funcDef:funcDefList){
            funcDef.print();
        }
        mainFuncDef.print();
        IO.parser_output(Parser.nodeTypes.get(NodeType.CompUnit));
    }

    public List<Decl> getdeclList() {
        return declList;
    }

    public List<FuncDef> getfuncDefList() {
        return funcDefList;
    }

    public MainFuncDef getMainFuncDef() {
        return mainFuncDef;
    }
}
