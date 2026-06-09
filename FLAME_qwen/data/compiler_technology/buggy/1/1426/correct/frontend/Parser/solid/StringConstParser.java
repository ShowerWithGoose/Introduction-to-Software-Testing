package frontend.Parser.solid;

import frontend.Token;
import frontend.TokenListReader;
import frontend.TokenType;

public class StringConstParser {
    private TokenListReader reader;
    private Token token = null;

    public StringConstParser(TokenListReader reader) {
        this.reader = reader;
    }

    public StringConst parseStringConst() {
        this.token = this.reader.getnextToken();
        if(!this.token.getType().equals(TokenType.STRCON))
        {
            System.out.println("error: invalid StringConst");
        }
        StringConst stringConst = new StringConst(this.token);
        return stringConst;
    }
}
