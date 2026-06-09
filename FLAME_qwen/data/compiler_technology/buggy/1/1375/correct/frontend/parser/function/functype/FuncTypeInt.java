package frontend.parser.function.functype;

import frontend.lexer.Token;

public class FuncTypeInt implements FuncTypeEle{
    public Token intTk; // 'int'

    public FuncTypeInt(Token intTk) {
        this.intTk = intTk;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.intTk.syntaxOutput());
        return sb.toString();
    }
    public int my_line_num() {
        return intTk.linenum;
    }
}
