package frontend.Parser.declaration.variable;

import frontend.Error;
import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;
import frontend.MyErrorType;
import frontend.Parser.declaration.BType;

import java.util.ArrayList;

public class ParserOfVarDecl {
    private TokenListManager tokenListManager;
    private BType bType;
    private VarDef firstVarDef;
    private ArrayList<Token> commas;
    private ArrayList<VarDef> varDefs;
    private Token semicn; // ';'
    private ArrayList<Error> errors;

    public ParserOfVarDecl(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }

    public VarDecl parseVarDel() {
        this.commas = new ArrayList<>();
        this.varDefs = new ArrayList<>();
        this.errors = new ArrayList<>();
        Token first = tokenListManager.getTokenAndMove();
        if (first.getTokenType().equals(TokenType.INTTK) || first.getTokenType().equals(TokenType.CHARTK)) {
            this.bType = new BType(first);
        } else {
            System.out.println("VarDecl 's first is not bType");
        }
        ParserOfVarDef parserOfVarDef = new ParserOfVarDef(tokenListManager);
        VarDef firstVarDef = parserOfVarDef.parseVarDef();
        this.firstVarDef = firstVarDef;
        this.errors.addAll(parserOfVarDef.getErrors());
        Token next = tokenListManager.getTokenAndMove();
        while (next.getTokenType().equals(TokenType.COMMA)) {
            this.commas.add(next);
            VarDef varDef = parserOfVarDef.parseVarDef();
            this.varDefs.add(varDef);
            this.errors.addAll(parserOfVarDef.getErrors());
            next = tokenListManager.getTokenAndMove();
        }
        if(next.getTokenType().equals(TokenType.SEMICN)){
            this.semicn = next;
        } else {
            tokenListManager.lookBackToken(2);
            next = tokenListManager.getTokenAndMove();
            Error error = new Error(next.getLineNo(), MyErrorType.i);
            this.errors.add(error);
        }
        VarDecl varDecl = new VarDecl(this.bType, this.firstVarDef,
                this.commas, this.varDefs, this.semicn);
        return varDecl;
    }
    public ArrayList<Error> getErrors() {
        return errors;
    }
}
