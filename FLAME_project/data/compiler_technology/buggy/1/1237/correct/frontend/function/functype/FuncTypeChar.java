package frontend.function.functype;

import frontend.Token;
import frontend.function.functype.FuncTypeEle;

public class FuncTypeChar implements FuncTypeEle {
    private final Token charTk; // 'char'

    public FuncTypeChar(Token charTk) {
        if (charTk == null) {
            throw new IllegalArgumentException("Token for char cannot be null");
        }
        this.charTk = charTk;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.charTk.syntaxOutput());
        return sb.toString();
    }
}
