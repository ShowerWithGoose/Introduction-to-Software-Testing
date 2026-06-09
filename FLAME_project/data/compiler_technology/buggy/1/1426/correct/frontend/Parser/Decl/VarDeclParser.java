package frontend.Parser.Decl;

import frontend.Parser.ErrorHandler;
import frontend.Token;
import frontend.TokenListReader;
import frontend.TokenType;
import frontend.Parser.Btype;
import frontend.Parser.BtypeParser;
import frontend.Parser.Def.VarDef;
import frontend.Parser.Def.VarDefParser;

import java.util.ArrayList;

//变量声明 VarDecl → BType VarDef { ',' VarDef } ';'
public class VarDeclParser {
    private TokenListReader reader;
    private Btype btype;
    private VarDef first;
    private ArrayList<Token> commas = new ArrayList<>();
    private ArrayList<VarDef> varDefs = new ArrayList<>();
    private Token semicn;

    public VarDeclParser(TokenListReader reader) {
        this.reader = reader;
    }

    public VarDecl parseVarDecl() {
        BtypeParser btypeparser = new BtypeParser(this.reader);
        this.btype = btypeparser.parseBtype();
        VarDefParser varDefParser = new VarDefParser(this.reader);
        this.first = varDefParser.parseVarDef();
        Token token = this.reader.getnextToken();
        while (token.getType().equals(TokenType.COMMA)) {
            this.commas.add(token);
            this.varDefs.add(varDefParser.parseVarDef());
            token = this.reader.getnextToken();
        }
        this.semicn = token;
        if(!token.getType().equals(TokenType.SEMICN))
        {
            ErrorHandler.getInstance().reportError(this.reader.getPreviousToken().getLine(),"i");
            this.reader.backward(1);
        }
        VarDecl varDecl = new VarDecl(this.btype, this.first, this.commas, this.varDefs, this.semicn);
        return varDecl;
    }


}
