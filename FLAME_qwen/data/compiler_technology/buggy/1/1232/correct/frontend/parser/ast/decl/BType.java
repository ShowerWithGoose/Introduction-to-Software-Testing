package frontend.parser.ast.decl;

import frontend.lexer.Token;

public class BType {
    private String type = "<BType>";
    private Token token;

    public BType(Token token) {
        this.token = token;
    }

    public String getOutput() {
        return token.getOutput();
    }

}
