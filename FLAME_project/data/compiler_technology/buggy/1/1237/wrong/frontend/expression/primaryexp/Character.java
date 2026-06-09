package frontend.expression.primaryexp;

import frontend.terminal.CharConst;

public class Character implements PrimaryExpEle {
    private final String name = "<Character>";
    private final CharConst charConst;

    public Character(CharConst charConst) {
        this.charConst = charConst;
    }

    public CharConst getCharConst() {
        return charConst;
    }

    @Override
    public String syntaxOutput() {
        return new StringBuilder()
                .append(charConst.syntaxOutput())  // 输出字符常量的语法
                .append(name)
                .append("\n")
                .toString();
    }

    @Override
    public String toString() {
        return String.valueOf(charConst.getChar());
    }
}
