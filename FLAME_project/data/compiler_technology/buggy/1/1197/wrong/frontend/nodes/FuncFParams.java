package frontend.nodes;

import frontend.LexType;
import frontend.Lexer;
import frontend.NodeRegistry;
import frontend.NodeType;

public class FuncFParams extends Node {
    public FuncFParams() {
        super(NodeType.FUNC_F_PARAMS);
    }

    public static Node parse() {
        FuncFParams funcFParams = new FuncFParams();
        funcFParams.parseAndAdd(NodeRegistry.FUNC_F_PARAM);
        while (Lexer.INSTANCE.getLexType() == LexType.COMMA) {
            funcFParams.parseAndAdd(NodeRegistry.TERMINAL);
            funcFParams.parseAndAdd(NodeRegistry.FUNC_F_PARAM);
        }
        return funcFParams;
    }
}
