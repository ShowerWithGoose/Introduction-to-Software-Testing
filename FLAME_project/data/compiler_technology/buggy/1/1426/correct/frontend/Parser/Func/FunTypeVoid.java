package frontend.Parser.Func;


import frontend.Token;

public class FunTypeVoid implements FuncTypeInf {
    private Token voidTk;

    public FunTypeVoid(Token voidTk) {
        this.voidTk = voidTk;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.voidTk.toString());
        return sb.toString();
    }
}
