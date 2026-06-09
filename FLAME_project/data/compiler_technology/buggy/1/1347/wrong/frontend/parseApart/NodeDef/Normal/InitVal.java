package frontend.parseApart.NodeDef.Normal;

import frontend.Token;
import frontend.parseApart.NodeDef.Exps.Exp;

import java.util.ArrayList;

public class InitVal {

    private int type; // 1,2,3
    private int line;

    private ArrayList<Exp> exps = new ArrayList<>();

    private String string;
    public InitVal() {}

    public void setType(int type) {
        this.type = type;
    }

    public void setExps(Exp exp) {
        this.exps.add(exp);
    }

    public void setStringAndLine(Token token) {
        this.string = token.getName();
        this.line = token.getLine();
    }


    public String returnSymbolType() {
        String string = "<InitVal>";
        return string;
    }
}
