package frontend.parser.node;

import frontend.error.ErrorProcess;
import frontend.lexer.LexType;
import frontend.lexer.Token;
import frontend.parser.Parser;
import frontend.parser.ParserType;
import frontend.parser.TreeNode;

import java.util.ArrayList;
import java.util.HashMap;

public class CompUnit extends TreeNode {
    private ArrayList<Decl> declArrayList = new ArrayList<>();
    private ArrayList<FuncDef> funcDefArrayList = new ArrayList<>();
    private ArrayList<MainFuncDef> mainFuncDefArrayList = new ArrayList<>();
    public CompUnit(ParserType parserType, Token token) {
        super(parserType, token);
    }

    public void setDeclArrayList(Decl decl) {
        this.declArrayList.add(decl);
    }

    public void setFuncDefArrayList(FuncDef funcDef) {
        this.funcDefArrayList.add(funcDef);
    }

    public void setMainFuncDefArrayList(MainFuncDef mainFuncDef) {
        this.mainFuncDefArrayList.add(mainFuncDef);
    }
}
