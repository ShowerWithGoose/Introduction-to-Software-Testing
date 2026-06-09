package frontend.parseApart.NodeDef.Normal;

import frontend.Token;
import frontend.parseApart.NodeDef.Exps.ConstExp;

import java.util.ArrayList;

public class ConstInitVal {
    private int type;
    private int line;

    private ArrayList<ConstExp> constExps = new ArrayList<>();

    private String string;
    public ConstInitVal() {}

    public void setType(int type) {
        this.type = type;
    }

    public void setConstExps(ConstExp constExp) {
        this.constExps.add(constExp);
    }

    public void setStringAndLine(Token token) {
        this.string = token.getName();
        this.line = token.getLine();
    }

    public String returnSymbolType() {
        String string = "<ConstInitVal>";
        return string;
    }
}
