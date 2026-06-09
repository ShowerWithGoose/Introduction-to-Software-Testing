package frontend.function.functype;

import frontend.Token;
import frontend.function.functype.FuncTypeEle;

public class FuncTypeVoid implements FuncTypeEle {
    private Token voidTk; // 'void'

    public FuncTypeVoid(Token voidTk) {
        this.voidTk = voidTk;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.voidTk.syntaxOutput());
        return sb.toString();
    }
}
