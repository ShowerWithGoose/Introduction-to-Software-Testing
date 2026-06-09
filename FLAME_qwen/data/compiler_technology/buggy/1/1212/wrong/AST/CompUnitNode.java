package AST;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import IO.*;
public class CompUnitNode extends ASTNode {

    private ASTNodes type = ASTNodes.CompUnit;
    public List<DeclNode> Decls;

    public List<FuncDefNode> FuncDefs;

    MainFuncDef mainFuncDef;

    public CompUnitNode() {
        this.Decls = new ArrayList<>();
        this.FuncDefs = new ArrayList<>();
    }

    public ASTNodes getType() {
        return this.type;
    }

    public void addDecls(DeclNode decl) {
        Decls.add(decl);
    }

    public void addFuncDefs(FuncDefNode funcDef) {
        FuncDefs.add(funcDef);
    }

    public void setMainFuncDef(MainFuncDef mainFuncDef) {
        this.mainFuncDef = mainFuncDef;
    }

    public List<DeclNode> getDecls() {
        return Decls;
    }

    public List<FuncDefNode> getFuncDefs() {
        return FuncDefs;
    }

    public MainFuncDef getMainFuncDef() {
        return mainFuncDef;
    }


    public void postOrderTraversal(IO io) throws IOException {
        for(DeclNode decl : Decls) {
            decl.postOrderTraversal(io);
        }
        for(FuncDefNode funcDef : FuncDefs) {
            funcDef.postOrderTraversal(io);
        }
        mainFuncDef.postOrderTraversal(io);
        io.getParserWriter().write("<CompUnit>\n");
    }

    
    public void postOrderNoPrint() {
        for(DeclNode decl : Decls) {
            decl.postOrderNoPrint();
        }
        for(FuncDefNode funcDef : FuncDefs) {
            funcDef.postOrderNoPrint();
        }
        mainFuncDef.postOrderNoPrint();
    }
}