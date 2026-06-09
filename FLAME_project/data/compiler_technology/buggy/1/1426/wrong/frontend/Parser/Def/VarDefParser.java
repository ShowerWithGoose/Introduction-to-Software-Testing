package frontend.Parser.Def;

import frontend.Token;
import frontend.TokenListReader;
import frontend.TokenType;
import frontend.Parser.ErrorHandler;
import frontend.Parser.Exp.ConstExp;
import frontend.Parser.Exp.ConstExpParser;
import frontend.Parser.Val.InitVal;
import frontend.Parser.Val.InitValParser;
import frontend.Parser.solid.Ident;
import frontend.Parser.solid.IdentParser;

import java.util.ArrayList;

//VarDef â†’ Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '='
//InitVal
public class VarDefParser {
    private TokenListReader reader;
    private Ident ident = null;
    private ArrayList<Token> lbracks = new ArrayList<>();
    private ArrayList<ConstExp> constExps = new ArrayList<>();
    private ArrayList<Token> rbracks = new ArrayList<>();
    private Token equal = null;
    private InitVal initVal = null;
    private VarDefInf varDefInf = null;

    public VarDefParser(TokenListReader reader) {
        this.reader = reader;
    }

    public VarDef parseVarDef() {
        this.rbracks = new ArrayList<>();
        this.constExps = new ArrayList<>();
        this.lbracks = new ArrayList<>();
        IdentParser identParser = new IdentParser(this.reader);
        this.ident = identParser.parseIdent();
        Token token = this.reader.getnextToken();
        while (token.getType().equals(TokenType.LBRACK)) {
            this.lbracks.add(token);
            ConstExpParser expParser = new ConstExpParser(this.reader);
            this.constExps.add(expParser.parseConstExp());
            token = this.reader.getnextToken();
            if(!token.getType().equals(TokenType.RBRACK)) {
                ErrorHandler.getInstance().reportError(this.reader.getPreviousToken().getLine() , "k");
                this.reader.backward(1);
            }
            else {
                this.rbracks.add(token);
            }
            token = this.reader.getnextToken();
        }
        if (token.getType().equals(TokenType.ASSIGN)) {
            this.equal = token;
            InitValParser initValParser = new InitValParser(this.reader);
            this.initVal = initValParser.parseInitVal();
            this.varDefInf = new VarDefInit(this.ident, this.lbracks, this.constExps, this.rbracks, this.equal, this.initVal);
        } else {
            this.reader.backward(1);
            this.varDefInf = new VarDefVoid(this.ident, this.lbracks,
                    this.constExps, this.rbracks);
        }
        VarDef varDef = new VarDef(this.varDefInf);
        return varDef;
    }
}
