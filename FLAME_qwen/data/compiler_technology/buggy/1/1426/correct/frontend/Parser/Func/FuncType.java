package frontend.Parser.Func;

import frontend.Parser.Output;

public class FuncType implements Output {
    private final String name = "<FuncType>";
    private FuncTypeInf funcTypeInf;

    public FuncType(FuncTypeInf funcTypeInf) {
        this.funcTypeInf = funcTypeInf;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.funcTypeInf.Parser_Output());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
