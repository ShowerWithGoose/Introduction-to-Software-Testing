package frontend.Parser.Func;

import frontend.Token;

public class FuncTypeChar implements FuncTypeInf {
    private Token charTk;

    public FuncTypeChar(Token charTk) {
        this.charTk = charTk;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.charTk.toString());
        return sb.toString();
    }
}
