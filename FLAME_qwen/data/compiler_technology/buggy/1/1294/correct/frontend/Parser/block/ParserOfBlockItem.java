package frontend.Parser.block;

import frontend.Error;
import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;
import frontend.Parser.declaration.Decl;
import frontend.Parser.declaration.ParserOfDecl;
import frontend.Parser.statement.ParserOfStmt;
import frontend.Parser.statement.Stmt;

import java.util.ArrayList;

public class ParserOfBlockItem {
    private TokenListManager tokenListManager;
    private ArrayList<Error> errors;
    public ParserOfBlockItem(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }
    public BlockItem parseBlockItem() {
        this.errors = new ArrayList<>();
        Token fir = tokenListManager.getTokenAndMove();
        if(fir.getTokenType().equals(TokenType.CONSTTK) ||
           fir.getTokenType().equals(TokenType.INTTK)   ||
           fir.getTokenType().equals(TokenType.CHARTK)){
            tokenListManager.lookBackToken(1);
            ParserOfDecl parserOfDecl = new ParserOfDecl(tokenListManager);
            Decl decl = parserOfDecl.parseDecl();
            this.errors.addAll(parserOfDecl.getErrors());
            return new BlockItem(decl);
        } else {
            tokenListManager.lookBackToken(1);
            ParserOfStmt parserOfStmt = new ParserOfStmt(tokenListManager);
            Stmt stmt = parserOfStmt.parseStmt();
            this.errors.addAll(parserOfStmt.getErrors());
            return new BlockItem(stmt);
        }
    }
    public ArrayList<Error> getErrors() {
        return errors;
    }
}
