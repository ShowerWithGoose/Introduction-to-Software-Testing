package frontend.parser.function.functype;

import frontend.lexer.Token;

public class FuncTypeChar implements FuncTypeEle{
    private Token charTk; // 'int'

    public FuncTypeChar(Token charTk) {
        this.charTk = charTk;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.charTk.syntaxOutput());
        return sb.toString();
    }
}
