package frontend.Parser.Exp;

import frontend.Parser.ErrorHandler;
import frontend.Token;
import frontend.TokenListReader;
import frontend.TokenType;
import frontend.Parser.Func.FuncRParams;
import frontend.Parser.Func.FuncRParamsParser;
import frontend.Parser.solid.Ident;
import frontend.Parser.solid.IdentParser;

//Ident '(' [FuncRParams] ')'
public class UnaryExpIdentParser {
    private TokenListReader reader;
    private Ident ident;
    private Token lparent;
    private FuncRParams params;
    private Token rparent;
    private UnaryExpIdent unaryExpIdent;

    public UnaryExpIdentParser(TokenListReader reader) {
        this.reader = reader;
    }

    public UnaryExpIdent parseUnaryExpIdent() {
        IdentParser parser = new IdentParser(this.reader);
        this.ident = parser.parseIdent();
        this.lparent = this.reader.getnextToken();
        this.rparent = this.reader.getnextToken();
        if(!this.rparent.getType().equals(TokenType.RPARENT))
        {
            this.reader.backward(1);
            FuncRParamsParser funcRParamsParser = new FuncRParamsParser(this.reader);
            this.params = funcRParamsParser.parseFuncRParams();
            if(this.params == null)
            {
                // error!
                ErrorHandler.getInstance().reportError(this.reader.getPreviousToken().getLine(),"j");
                this.reader.backward(1);
            }
            this.rparent = this.reader.getnextToken();
            unaryExpIdent = new UnaryExpIdent(this.ident, this.lparent, this.params, this.rparent);
        }
        else{
            unaryExpIdent = new UnaryExpIdent(this.ident, this.lparent, this.rparent);
        }
        return unaryExpIdent;
    }

}
