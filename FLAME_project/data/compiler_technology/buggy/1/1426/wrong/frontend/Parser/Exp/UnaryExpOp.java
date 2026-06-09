package frontend.Parser.Exp;

//一元表达式 UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp // j
public class UnaryExpOp implements UnaryExpInf{
    private UnaryOp unaryOp;
    private UnaryExp unaryExp;

    public UnaryExpOp(UnaryOp unaryOp, UnaryExp unaryExp) {
        this.unaryOp = unaryOp;
        this.unaryExp = unaryExp;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(unaryOp.Parser_Output());
        sb.append(unaryExp.Parser_Output());
        return sb.toString();
    }
}
