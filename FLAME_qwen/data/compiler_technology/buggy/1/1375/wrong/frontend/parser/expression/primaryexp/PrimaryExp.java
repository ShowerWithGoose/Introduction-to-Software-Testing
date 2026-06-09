package frontend.parser.expression.primaryexp;

import frontend.parser.expression.unaryexp.UnaryExpEle;

public class PrimaryExp implements UnaryExpEle {
    public final String name = "<PrimaryExp>";
    public PrimaryExpEle primaryExpEle;

    public PrimaryExp(PrimaryExpEle primaryExpEle) {
        this.primaryExpEle = primaryExpEle;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.primaryExpEle.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
    public int my_line_num() {
        return this.primaryExpEle.my_line_num();
    }
}
