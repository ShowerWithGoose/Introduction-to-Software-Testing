package frontend.Parser.PriExp;

import frontend.Parser.ErrorHandler;
import frontend.Token;
import frontend.TokenListReader;
import frontend.TokenType;
import frontend.Parser.Exp.Exp;
import frontend.Parser.Exp.ExpParser;
import frontend.Parser.solid.Ident;
import frontend.Parser.solid.IdentParser;

import java.util.ArrayList;

//LVal â†’ Ident ['[' Exp ']']
public class LValParser {
    private TokenListReader reader;
    private Ident ident;
    private ArrayList<Token> lbrack = new ArrayList<>();
    private ArrayList<Exp> exps = new ArrayList<>();
    private ArrayList<Token> rbrack = new ArrayList<>();

    public LValParser(TokenListReader reader) {
        this.reader = reader;
    }

    public LVal parseLVal(){
        IdentParser identParser = new IdentParser(this.reader);
        this.ident = identParser.parseIdent();
        Token token = this.reader.getnextToken();
        while(token.getType().equals(TokenType.LBRACK))
        {
            this.lbrack.add(token);
            ExpParser expParser = new ExpParser(this.reader);
            this.exps.add(expParser.parseExp());
            token = this.reader.getnextToken();
            this.rbrack.add(token);
            if(!token.getType().equals(TokenType.RBRACK))
            {
                // error!
                ErrorHandler.getInstance().reportError(this.reader.getPreviousToken().getLine(),"k");
                this.reader.backward(1);
            }
            token = this.reader.getnextToken();
        }
        this.reader.backward(1);
        LVal lVal = new LVal(this.ident, this.lbrack, this.exps, this.rbrack);
        return lVal;
    }

}
