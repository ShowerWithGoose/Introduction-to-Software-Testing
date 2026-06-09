package frontend.parser.declaration;

import frontend.lexer.Token;
import frontend.parser.SyntaxUnit;

public class BType implements SyntaxUnit {
    private final String name = "<BType>";
    private Token btype;

    public BType(Token btype) {
        this.btype = btype;
    }

    @Override
    public String syntaxPrint() {
        //不输出名字
        StringBuilder sb = new StringBuilder();
        sb.append(btype.syntaxPrint());
        return sb.toString();
    }
}
