package frontend.treenode;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import static frontend.executor.Parser.writeParser;

//编译单元 CompUnit → {Decl} {FuncDef} MainFuncDef
public class CompUnit {
    public String nodeName;
    public List<Decl> declList = new ArrayList<>();
    public List<FuncDef> funcDefList = new ArrayList<>();
    public MainFuncDef mainFuncDef;

    public CompUnit(String nodeName, List<Decl> declList, List<FuncDef> funcDefList, MainFuncDef mainFuncDef) {
        this.nodeName = nodeName;
        this.declList = declList;
        this.funcDefList = funcDefList;
        this.mainFuncDef = mainFuncDef;
    }

    public void print() throws IOException {
        if (!declList.isEmpty()) {
            for (Decl decl : declList) {
                decl.print();
            }
        }
        if (!funcDefList.isEmpty()) {
            for (FuncDef funcDef : funcDefList) {
                funcDef.print();
            }
        }
        if (mainFuncDef != null) {
            mainFuncDef.print();
        }
        writeParser(nodeName);
    }
}
