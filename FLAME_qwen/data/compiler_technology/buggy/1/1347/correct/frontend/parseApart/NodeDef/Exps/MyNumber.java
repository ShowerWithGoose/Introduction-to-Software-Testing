package frontend.parseApart.NodeDef.Exps;

import frontend.Token;

public class MyNumber extends PrimaryExp {
    public int number;
    public int line;

    public MyNumber(Token token) {
        this.number = Integer.parseInt(token.getName());
        this.line = token.getLine();
    }

    public String returnSymbolType() {
        String string = "<Number>";
        return string;
    }
}
