package frontend.parser.declaration.variable.initval;

import frontend.lexer.Token;

public class InitValString implements InitValEle{
    public Token token;
    public InitValString(Token token) {
        this.token = token;
    }
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.token.syntaxOutput());
        return sb.toString();
    }
    public int my_line_num() {
        return this.token.linenum;
    }
}
