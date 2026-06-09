package frontend.Parser.Func;

import frontend.Token;

public class FunTypeInt implements FuncTypeInf {
    private Token intTk;

    public FunTypeInt(Token intTk) {
        this.intTk = intTk;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.intTk.toString());
        return sb.toString();
    }
}
