package frontend.Parser.solid;

import frontend.Token;
import frontend.TokenType;
import frontend.Parser.Val.ConstInitValInf;
import frontend.Parser.Val.InitValInf;

public class StringConst implements ConstInitValInf, InitValInf {
    private Token token;
    public StringConst(Token token) {
        this.token = token;
    }

    public StringConst(String str, int lineNum) {
        this.token = new Token(str, TokenType.STRCON, lineNum);
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.token.toString());
        return sb.toString();
    }
}
