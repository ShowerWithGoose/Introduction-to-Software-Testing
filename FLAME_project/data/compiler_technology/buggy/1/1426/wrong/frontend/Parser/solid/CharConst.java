package frontend.Parser.solid;

import frontend.Token;
import frontend.TokenType;
import frontend.Parser.Output;

public class CharConst implements Output {
    private Token token;

    public CharConst(Token token) {
        this.token = token;
    }

    public CharConst(String str, int lineNum) {
        this.token = new Token(str, TokenType.CHRCON, lineNum);
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.token.toString());
        return sb.toString();
    }
}
