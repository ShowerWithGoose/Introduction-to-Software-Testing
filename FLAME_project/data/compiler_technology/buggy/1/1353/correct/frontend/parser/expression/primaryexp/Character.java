package frontend.parser.expression.primaryexp;

import frontend.parser.terminal.CharConst;
import frontend.parser.terminal.IntConst;

/**
 * Character 字符类
 * Character -> CharConst
 */
public class Character implements PrimaryExpEle {

    private final String name = "<Character>";
    private CharConst charConst;

    public Character(CharConst charConst) {
        this.charConst = charConst;
    }

    public CharConst getCharConst() {
        return charConst;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(charConst.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }

    @Override
    public String toString() {
        return this.charConst.getChar();
    }
}
