package frontend.Parser.Func;

import frontend.Parser.ErrorHandler;
import frontend.Token;
import frontend.TokenListReader;
import frontend.TokenType;
import frontend.Parser.Btype;
import frontend.Parser.BtypeParser;
import frontend.Parser.solid.Ident;
import frontend.Parser.solid.IdentParser;

// FuncFParam â†’ BType Ident ['[' ']']
public class FuncFParamParser {
    private TokenListReader reader;
    private Btype btype;
    private Ident ident;
    private Token first;
    private Token second;


    public FuncFParamParser(TokenListReader reader) {
        this.reader = reader;
    }

    public FuncFParam parseFuncFParam(){
        FuncFParams funcFParam = null;
        BtypeParser btypeParser = new BtypeParser(this.reader);
        btype = btypeParser.parseBtype();
        if(btype == null)
        {
            return null;
        }
        IdentParser identParser = new IdentParser(this.reader);
        ident = identParser.parseIdent();
        if(ident == null)
        {
            return null;
        }
        first = this.reader.getnextToken();
        second = this.reader.getnextToken();
        if(first.getType().equals(TokenType.LBRACK)) {
            if (!second.getType().equals(TokenType.RBRACK)) {
                // error!
                ErrorHandler.getInstance().reportError(this.reader.getPreviousToken().getLine(),"k");
                this.reader.backward(1);
            }
            return new FuncFParam(this.btype, this.ident, this.first, this.second);
        }
        else{
            this.reader.backward(2);
            return new FuncFParam(this.btype, this.ident);
        }

    }

}
