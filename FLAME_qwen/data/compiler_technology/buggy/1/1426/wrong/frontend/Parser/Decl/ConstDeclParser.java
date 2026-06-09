package frontend.Parser.Decl;

import frontend.Parser.ErrorHandler;
import frontend.Token;
import frontend.TokenListReader;
import frontend.TokenType;
import frontend.Parser.Btype;
import frontend.Parser.BtypeParser;
import frontend.Parser.Def.ConstDef;
import frontend.Parser.Def.ConstDefParser;

import java.util.ArrayList;

//ConstDecl â†’ 'const' BType ConstDef { ',' ConstDef } ';'
public class ConstDeclParser {
    private TokenListReader reader;
    private Token constTk;
    private Btype btype;
    private ConstDef first;
    private ArrayList<Token> commas = new ArrayList<>();
    private ArrayList<ConstDef> constDefs = new ArrayList<>();
    private Token semicn;

    public ConstDeclParser(TokenListReader reader) {
        this.reader = reader;
    }

    public ConstDecl parseConstDecl(){
        this.commas = new ArrayList<>();
        this.constDefs = new ArrayList<>();
        Token token = this.reader.getnextToken();
        if (token.getType().equals(TokenType.CONSTTK)) {
            constTk = token;
        } else {
            System.out.println("error: invalid ConstDecl");
        }
        BtypeParser btypeParser = new BtypeParser(this.reader);
        btype = btypeParser.parseBtype();
        ConstDefParser constDefParser = new ConstDefParser(this.reader);
        first = constDefParser.parseConstDef();
        token = this.reader.getnextToken();
        while (token.getType().equals(TokenType.COMMA)) {
            this.commas.add(token);
            this.constDefs.add(constDefParser.parseConstDef());
            token = this.reader.getnextToken();
        }
        this.semicn = token;
        // error!
        if(!token.getType().equals(TokenType.SEMICN))
        {
            ErrorHandler.getInstance().reportError(this.reader.getPreviousToken().getLine(),"i");
            this.reader.backward(1);
        }
        ConstDecl constDecl = new ConstDecl(this.constTk, this.btype,
                this.first, this.commas, this.constDefs, this.semicn);
        return constDecl;
    }

}
