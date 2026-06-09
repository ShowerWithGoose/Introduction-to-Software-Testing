package frontend.Parser.declaration;

import frontend.Error;
import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;
import frontend.Parser.declaration.constant.ConstDecl;
import frontend.Parser.declaration.constant.ParserOfConstDecl;
import frontend.Parser.declaration.variable.ParserOfVarDecl;
import frontend.Parser.declaration.variable.VarDecl;

import java.util.ArrayList;

public class ParserOfDecl {
    private TokenListManager tokenListManager;
    private ArrayList<Error> errors;
    public ParserOfDecl(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
        this.errors = new ArrayList<>();
    }

    public Decl parseDecl(){
        Token fir = tokenListManager.getTokenAndMove();
        tokenListManager.lookBackToken(1);
        Decl decl = null;
        if(fir.getTokenType().equals(TokenType.CONSTTK)){
            ParserOfConstDecl parserOfConstDecl = new ParserOfConstDecl(tokenListManager);
            ConstDecl constDecl = parserOfConstDecl.parseConstDel();
            this.errors.addAll(parserOfConstDecl.getErrors());
            decl = new Decl(constDecl);
        } else if(fir.getTokenType().equals(TokenType.INTTK) || fir.getTokenType().equals(TokenType.CHARTK)){
            ParserOfVarDecl parserOfVarDecl = new ParserOfVarDecl(tokenListManager);
            VarDecl varDecl = parserOfVarDecl.parseVarDel();
            this.errors.addAll(parserOfVarDecl.getErrors());
            decl = new Decl(varDecl);
        } else {
            System.out.println("illegal declaration");
        }
        return decl;
    }

    public ArrayList<Error> getErrors() {
        return errors;
    }
}
