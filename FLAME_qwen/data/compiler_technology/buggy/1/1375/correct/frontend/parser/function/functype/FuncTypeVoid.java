package frontend.parser.function.functype;

import frontend.lexer.Token;

public class FuncTypeVoid implements FuncTypeEle{
    public Token voidTk; // 'void'

    public FuncTypeVoid(Token voidTk) {
        this.voidTk = voidTk;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.voidTk.syntaxOutput());
        return sb.toString();
    }
    public int my_line_num() {
        return voidTk.linenum;
    }
}
