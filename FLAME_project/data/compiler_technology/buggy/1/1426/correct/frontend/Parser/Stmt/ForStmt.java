package frontend.Parser.Stmt;

import frontend.Token;
import frontend.Parser.Exp.Exp;
import frontend.Parser.Output;
import frontend.Parser.PriExp.LVal;

//语句 ForStmt → LVal '=' Exp // 存在即可
public class ForStmt implements Output {
    private final String name = "<ForStmt>";
    private LVal lVal;
    private Token equal;
    private Exp exp;

    public ForStmt(LVal lVal, Token equal, Exp exp) {
        this.lVal = lVal;
        this.equal = equal;
        this.exp = exp;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(lVal.Parser_Output());
        sb.append(equal.toString());
        sb.append(exp.Parser_Output());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
