package frontend.Parser;

import frontend.Token;
import frontend.TokenListReader;
import frontend.TokenType;

public class BtypeParser {
    public TokenListReader reader;

    public BtypeParser(TokenListReader reader) {
        this.reader = reader;
    }

    public Btype parseBtype() {
        Token first = this.reader.getnextToken();
        if(first.getType().equals(TokenType.INTTK) || first.getType().equals(TokenType.CHARTK)) {
            //
        }
        else
        {
            System.out.println("error: Btype");
            return null;
        }
        Btype btype = new Btype(first);
        return btype;
    }
}
