package frontend.nodes;

import frontend.LexType;
import frontend.Lexer;
import frontend.NodeRegistry;
import frontend.NodeType;

public class FuncRParams extends Node {
    public FuncRParams() {
        super(NodeType.FUNC_R_PARAMS);
    }

    public static Node parse() {
        FuncRParams funcRParams = new FuncRParams();
        funcRParams.parseAndAdd(NodeRegistry.EXP);
        while (Lexer.INSTANCE.getLexType() == LexType.COMMA) {
            funcRParams.parseAndAdd(NodeRegistry.TERMINAL);
            funcRParams.parseAndAdd(NodeRegistry.EXP);
        }
        return funcRParams;
    }
}
