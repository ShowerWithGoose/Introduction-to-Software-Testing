package frontend.nodes;

import frontend.*;

public class FuncFParam extends Node {
    public FuncFParam() {
        super(NodeType.FUNC_F_PARAM);
    }

    public static Node parse() {
        FuncFParam funcFParam = new FuncFParam();
        funcFParam.parseAndAdd(NodeRegistry.B_TYPE);
        funcFParam.terminalCheck(LexType.IDENFR);
        if (Lexer.INSTANCE.getLexType() == LexType.LBRACK) {
            funcFParam.parseAndAdd(NodeRegistry.TERMINAL);
            funcFParam.terminalCheck(LexType.RBRACK, ErrorType.k);
        }
        return funcFParam;
    }
}
