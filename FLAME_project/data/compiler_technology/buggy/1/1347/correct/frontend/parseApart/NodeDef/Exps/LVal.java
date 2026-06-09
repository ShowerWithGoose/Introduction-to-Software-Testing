package frontend.parseApart.NodeDef.Exps;

import frontend.Token;

public class LVal {
    private String name;

    private Exp exp;

    public LVal() {

    }

    public void setName(Token token) {
        this.name = token.getName();
    }

    public void setExp(Exp exp) {
        this.exp = exp;
    }

    public String returnSymbolType() {
        String string = "<LVal>";
        return string;
    }
}
