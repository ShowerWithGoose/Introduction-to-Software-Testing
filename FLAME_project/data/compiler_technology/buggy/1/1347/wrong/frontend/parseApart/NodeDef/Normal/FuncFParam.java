package frontend.parseApart.NodeDef.Normal;

import frontend.LexType;
import frontend.Token;

public class FuncFParam {
    private LexType lexType;

    private String name;
    private int line;

    private int type = 0;

    public FuncFParam() {}

    public void setLexType(Token token) {
        this.lexType = token.getLexType();
    }

    public void setNameAndLine(Token token) {
        this.name = token.getName();
        this.line = token.getLine();
    }

    public void setType() {
        this.type = 1;
    }

    public String returnSymbolType() {
        String string = "<FuncFParam>";
        return string;
    }
}
