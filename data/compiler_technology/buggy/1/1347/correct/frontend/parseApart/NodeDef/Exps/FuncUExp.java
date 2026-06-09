package frontend.parseApart.NodeDef.Exps;

import frontend.Token;

public class FuncUExp extends UnaryExp {
    private String name;
    private int nameLine;
    private FuncRParams params = null;
    public FuncUExp(Token token) {
        this.name = token.getName();
        this.nameLine = token.getLine();
    }

    public FuncUExp(Token token, FuncRParams params) {
        this.name = token.getName();
        this.nameLine = token.getLine();
        this.params = params;
    }

    public String returnSymbolType() {
        String string = "<UnaryExp>";
        return string;
    }
}
