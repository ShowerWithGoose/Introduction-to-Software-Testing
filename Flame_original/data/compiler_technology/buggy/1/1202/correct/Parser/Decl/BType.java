package Parser.Decl;

import Parser.Lexer.Token;
import Parser.Syntax;

public class BType implements Syntax {

    private String name;
    private Token BToken;

    public BType(Token BToken) {
        this.name = getName();
        this.BToken = BToken;
    }

    @Override
    public String getName() {
        return "<BType>";
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(BToken.syntaxOutput());
        return sb.toString();
    }
}
