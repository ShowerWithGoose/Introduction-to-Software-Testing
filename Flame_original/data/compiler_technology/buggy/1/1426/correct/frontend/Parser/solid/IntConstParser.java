package frontend.Parser.solid;

import frontend.Token;
import frontend.TokenListReader;
import frontend.TokenType;

public class IntConstParser {
    private TokenListReader reader;
    private Token token = null;

    public IntConstParser(TokenListReader reader) {
        this.reader = reader;
    }

    public IntConst parseIntConst() {
        this.token = this.reader.getnextToken();
        if(!this.token.getType().equals(TokenType.INTCON))
        {
            System.out.println("error: invalid IntConst");
        }
        IntConst intConst = new IntConst(this.token);
        return intConst;
    }
}
