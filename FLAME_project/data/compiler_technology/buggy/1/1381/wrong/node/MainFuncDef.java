package node;

import frontend.Parser;
import frontend.Token;

public class MainFuncDef extends FuncDef {
    private Parser.SyntaxType nodeType = Parser.SyntaxType.MainFuncDef;

    public MainFuncDef(Block block) {
        super(
                new FuncType(Token.TokenType.INTTK),
                new Ident("main", Ident.Type.FUNC),
                null,
                block
        );
    }

    public String toString() {
        StringBuilder ret = new StringBuilder("<" + nodeType + ">");
        ret.append("\n").append(getBlock());
        ret.append("\n<").append(nodeType).append("> <END>");
        return ret.toString();
    }
}
