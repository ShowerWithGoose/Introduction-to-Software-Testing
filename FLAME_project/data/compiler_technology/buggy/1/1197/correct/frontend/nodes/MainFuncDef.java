package frontend.nodes;

import frontend.ErrorType;
import frontend.LexType;
import frontend.NodeRegistry;
import frontend.NodeType;

public class MainFuncDef extends Node {
    public MainFuncDef() {
        super(NodeType.MAIN_FUNC_DEF);
    }

    public static Node parse() {
        MainFuncDef mainFuncDef = new MainFuncDef();
        mainFuncDef.terminalCheck(LexType.INTTK);
        mainFuncDef.terminalCheck(LexType.MAINTK);
        mainFuncDef.terminalCheck(LexType.LPARENT);
        mainFuncDef.terminalCheck(LexType.RPARENT, ErrorType.j);
        mainFuncDef.parseAndAdd(NodeRegistry.BLOCK);
        return mainFuncDef;
    }
}
