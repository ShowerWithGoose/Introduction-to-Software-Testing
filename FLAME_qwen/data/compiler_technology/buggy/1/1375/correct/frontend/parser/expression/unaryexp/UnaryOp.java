package frontend.parser.expression.unaryexp;

import frontend.lexer.Token;
import frontend.parser.SyntaxNode;

public class UnaryOp implements SyntaxNode {
    public final String name = "<UnaryOp>";
    public Token token;

    public UnaryOp(Token token) {
        this.token = token;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(token.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
    public int my_line_num(){
        return token.linenum;
    }
}
