package frontend.parser.declaration.constant.constinitval;

import frontend.lexer.Token;
import frontend.lexer.TokenType;

public class ConstInitValString implements ConstInitValEle{
    public Token token;
    public ConstInitValString(Token token) {
        this.token = token;
    }
    public ConstInitValString(Token token, String name, int lineNum) {
        this.token = new Token(TokenType.STRCON,lineNum,name);
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
