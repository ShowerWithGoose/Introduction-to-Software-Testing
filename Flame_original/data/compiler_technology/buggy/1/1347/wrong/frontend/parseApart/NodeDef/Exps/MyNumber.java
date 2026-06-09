package frontend.parseApart.NodeDef.Exps;

import frontend.Token;

public class MyNumber extends PrimaryExp {
    public String number;
    public int line;

    public MyNumber(Token token) {
        this.number = token.getName();
        this.line = token.getLine();
    }

    public String returnSymbolType() {
        String string = "<Number>";
        return string;
    }
}
