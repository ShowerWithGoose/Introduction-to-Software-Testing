package frontend.parser.function.functype;

import frontend.lexer.Token;

public class FuncTypeChar implements FuncTypeEle{
    public Token charTk; // 'int'

    public FuncTypeChar(Token charTk) {
        this.charTk = charTk;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.charTk.syntaxOutput());
        return sb.toString();
    }
    public int my_line_num() {
        return charTk.linenum;
    }
}
