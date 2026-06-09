package frontend.Parser.declaration.constant;

import frontend.Error;
import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;
import frontend.MyErrorType;
import frontend.Parser.declaration.BType;

import java.util.ArrayList;

public class ParserOfConstDecl {
    private Token constTk;
    private BType bType;
    private ConstDef firConstDef;
    private ArrayList<ConstDef> constDefs;
    private ArrayList<Token> commas;
    private Token semicn;
    private TokenListManager tokenListManager;
    private ArrayList<Error> errors;
    public ParserOfConstDecl(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }

    public ConstDecl parseConstDel() {
        this.constDefs = new ArrayList<>();
        this.commas = new ArrayList<>();
        this.errors = new ArrayList<>();
        Token fir = tokenListManager.getTokenAndMove();
        if(fir.getTokenType().equals(TokenType.CONSTTK)){
            constTk = fir;
        } else {
            System.out.println("ConstDel's first is not 'const'!");
        }
        Token sec = tokenListManager.getTokenAndMove();
        if(sec.getTokenType().equals(TokenType.CHARTK) || sec.getTokenType().equals(TokenType.INTTK)){
            bType = new BType(sec);
        } else{
            System.out.println("ConstDel's sec is not char or int!");
        }
        ParserOfConstDef parserOfConstDef = new ParserOfConstDef(tokenListManager);
        firConstDef = parserOfConstDef.parserConstDef();
        this.errors.addAll(parserOfConstDef.getErrors());
        Token nextToken = tokenListManager.getTokenAndMove();
        while(nextToken.getTokenType().equals(TokenType.COMMA)){
            commas.add(nextToken);
            constDefs.add(parserOfConstDef.parserConstDef());
            this.errors.addAll(parserOfConstDef.getErrors());
            nextToken = tokenListManager.getTokenAndMove();
        }
        if(nextToken.getTokenType().equals(TokenType.SEMICN)){
            semicn = nextToken;
        } else {
            tokenListManager.lookBackToken(2);
            nextToken = tokenListManager.getTokenAndMove();
            Error error = new Error(nextToken.getLineNo(), MyErrorType.i);
            this.errors.add(error);
        }
        ConstDecl constDecl = new ConstDecl(constTk, bType, firConstDef, semicn, constDefs, commas);
        return constDecl;
    }

    public ArrayList<Error> getErrors() {
        return errors;
    }
}
