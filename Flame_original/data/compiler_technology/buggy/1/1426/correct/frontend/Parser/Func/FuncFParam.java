package frontend.Parser.Func;

import frontend.Token;
import frontend.Parser.Btype;
import frontend.Parser.Output;
import frontend.Parser.solid.Ident;

//函数形参 FuncFParam → BType Ident ['[' ']'] // 1.普通变量2.一维数组变量
public class FuncFParam implements Output {
    private final String name = "<FuncFParam>";
    private Btype btype;
    private Ident ident;
    private Token lbrace;
    private Token rbrace;

    public FuncFParam(Btype btype, Ident ident) {
        this.btype = btype;
        this.ident = ident;
    }
    public FuncFParam(Btype btype, Ident ident, Token lbrace, Token rbrace) {
        this.btype = btype;
        this.ident = ident;
        this.lbrace = lbrace;
        this.rbrace = rbrace;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(btype.Parser_Output());
        sb.append(ident.Parser_Output());
        if(lbrace != null && rbrace != null) {
            sb.append(lbrace);
            sb.append(rbrace);
        }
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
