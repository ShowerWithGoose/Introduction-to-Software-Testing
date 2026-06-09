package node;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import static utils.IO.writeParser;

//编译单元 CompUnit → {Decl} {FuncDef} MainFuncDef
public class CompUnit {
    private String nodeName;
    private List<Decl> declList = new ArrayList<>();
    private List<FuncDef> funcDefList = new ArrayList<>();
    private MainFuncDef mainFuncDef;

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
