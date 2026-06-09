package frontend.Parser.solid;

import frontend.Token;
import frontend.TokenType;
import frontend.Parser.Output;

public class IntConst implements Output {
    private Token token;

    public IntConst(Token token) {
        this.token = token;
    }

    public IntConst(String str, int lineNum) {
        this.token = new Token(str, TokenType.INTCON, lineNum);
    }

    public int getNum() {
        return Integer.valueOf(this.token.getValue());
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.token.toString());
        return sb.toString();
    }
}
