package frontend.Parser.solid;

import frontend.Token;
import frontend.TokenListReader;
import frontend.TokenType;

public class IdentParser {
    private TokenListReader reader;
    private Token token;

    public IdentParser(TokenListReader reader) {
        this.reader = reader;
    }

    public Ident parseIdent(){
        this.token = this.reader.getnextToken();
        if(!this.token.getType().equals(TokenType.IDENFR))
        {
            System.out.println("error: invalid Ident");
            return null;
        }
        Ident ident = new Ident(this.token);
        return ident;
    }
}
