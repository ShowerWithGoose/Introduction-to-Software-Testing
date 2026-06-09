package frontend.parser.declaration;

import frontend.lexer.Token;
import frontend.parser.SyntaxNode;

public class BType implements SyntaxNode{
    public final String name="<BType>";
    public Token token;
    public BType(Token token) {
        this.token = token;
    }
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(token.syntaxOutput());
        /* not output BType according to assignment requirement */
        return sb.toString();
    }
    public int my_line_num(){
        return token.linenum;
    }

}
