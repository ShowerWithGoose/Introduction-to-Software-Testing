package frontend.parser.expression.primaryexp;

import frontend.parser.terminal.IntConst;

public class Number implements PrimaryExpEle{
    public final String name = "<Number>";
    public IntConst intConst;

    public Number(IntConst intConst) {
        this.intConst = intConst;
    }

    public IntConst getIntConst() {
        return intConst;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(intConst.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }

    @Override
    public String toString() {
        return String.valueOf(this.intConst.getNum());
    }
    public int my_line_num() {
        return this.intConst.my_line_num();
    }
    
}
