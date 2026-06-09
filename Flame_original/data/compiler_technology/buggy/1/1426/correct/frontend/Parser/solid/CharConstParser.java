package frontend.Parser.solid;

import frontend.Token;
import frontend.TokenListReader;
import frontend.TokenType;

public class CharConstParser {
    private TokenListReader reader;
    private Token token = null;

    public CharConstParser(TokenListReader reader) {
        this.reader = reader;
    }

    public CharConst parseCharConst() {
        this.token = this.reader.getnextToken();
        if(!this.token.getType().equals(TokenType.CHRCON))
        {
            System.out.println("error: invalid CharConst");
        }
        CharConst charConst = new CharConst(this.token);
        return charConst;
    }
}
