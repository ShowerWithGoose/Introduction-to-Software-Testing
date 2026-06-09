package frontend.parser.init;

import frontend.lexer.Token;

public class StringConst implements ConstInitValUnit, InitValUnit{
    private String name = "<StringConst>";
    private Token content;

    public StringConst(Token content) {
        this.content = content;
    }

    @Override
    public String syntaxPrint() {
        StringBuilder sb = new StringBuilder();
        sb.append(content.syntaxPrint());
        return sb.toString();
    }
}
