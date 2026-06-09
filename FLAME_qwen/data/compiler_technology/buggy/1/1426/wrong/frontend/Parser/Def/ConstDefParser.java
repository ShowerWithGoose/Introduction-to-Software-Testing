package frontend.Parser.Def;

import frontend.Parser.ErrorHandler;
import frontend.Token;
import frontend.TokenListReader;
import frontend.TokenType;
import frontend.Parser.Exp.ConstExp;
import frontend.Parser.Exp.ConstExpParser;
import frontend.Parser.Val.ConstInitVal;
import frontend.Parser.Val.ConstInitValParser;
import frontend.Parser.solid.Ident;
import frontend.Parser.solid.IdentParser;

import java.util.ArrayList;

//ConstDef â†’ Ident [ '[' ConstExp ']' ] '=' ConstInitVal
public class ConstDefParser {
    private TokenListReader reader;
    private Ident ident;
    private ArrayList<Token> lbracks = new ArrayList<>();
    private ArrayList<ConstExp> constExps = new ArrayList<>();
    private ArrayList<Token> rbracks = new ArrayList<>();
    private Token equal;
    private ConstInitVal constInitVal;

    public ConstDefParser(TokenListReader reader) {
        this.reader = reader;
    }

    public ConstDef parseConstDef() {
        this.lbracks = new ArrayList<>();
        this.constExps = new ArrayList<>();
        this.rbracks = new ArrayList<>();
        IdentParser identParser = new IdentParser(this.reader);
        ident = identParser.parseIdent();
        Token token = reader.getnextToken();
        while (token.getType().equals(TokenType.LBRACK)) {
            this.lbracks.add(token);
            ConstExpParser constExpParser = new ConstExpParser(this.reader);
            ConstExp constExp = constExpParser.parseConstExp();
            this.constExps.add(constExp);
            token = this.reader.getnextToken();
            // error!
            if (!token.getType().equals(TokenType.RBRACK)) {
                ErrorHandler.getInstance().reportError(this.reader.getPreviousToken().getLine(),"k");
                this.reader.backward(1);
            }
            this.rbracks.add(token);
            token = this.reader.getnextToken();
        }
        if(!token.getType().equals(TokenType.ASSIGN))
        {
            System.out.println("error: invalid ConstDef, assign");
        }
        this.equal = token;
        ConstInitValParser constInitValParser = new ConstInitValParser(this.reader);
        this.constInitVal = constInitValParser.parseConstInitVal();
        ConstDef constDef = new ConstDef(this.ident, this.lbracks, this.constExps,
                this.rbracks, this.equal, this.constInitVal);
        return constDef;

    }

}
