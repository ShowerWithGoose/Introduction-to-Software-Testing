package frontend.Parser.Exp;

import frontend.Parser.Output;

//一元表达式 UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp // j
public class UnaryExp implements Output {
    private final String name = "<UnaryExp>";
    private UnaryExpInf unaryExpInf;

    public UnaryExp(UnaryExpInf unaryExpInf) {
        this.unaryExpInf = unaryExpInf;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.unaryExpInf.Parser_Output());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
