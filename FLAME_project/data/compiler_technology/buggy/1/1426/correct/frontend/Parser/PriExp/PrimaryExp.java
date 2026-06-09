package frontend.Parser.PriExp;

import frontend.Parser.Exp.UnaryExpInf;

//基本表达式 PrimaryExp → '(' Exp ')' | LVal | Number | Character// 四种情况均需覆盖
public class PrimaryExp implements UnaryExpInf {
    private final String name = "<PrimaryExp>";
    private PrimaryExpInf primaryExpInf;

    public PrimaryExp(PrimaryExpInf primaryExpInf) {
        this.primaryExpInf = primaryExpInf;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.primaryExpInf.Parser_Output());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
