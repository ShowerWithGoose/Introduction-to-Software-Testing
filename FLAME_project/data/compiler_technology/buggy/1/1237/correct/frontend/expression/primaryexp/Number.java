package frontend.expression.primaryexp;

import frontend.terminal.IntConst;

public class Number implements PrimaryExpEle {
    private final String name = "<Number>";
    private final IntConst intConst;

    public Number(IntConst intConst) {
        this.intConst = intConst;
    }

    public IntConst getIntConst() {
        return intConst;
    }

    @Override
    public String syntaxOutput() {
        return new StringBuilder()
                .append(intConst.syntaxOutput())
                .append(name)
                .append("\n")
                .toString();
    }

    @Override
    public String toString() {
        return String.valueOf(intConst.getNum());
    }
}
