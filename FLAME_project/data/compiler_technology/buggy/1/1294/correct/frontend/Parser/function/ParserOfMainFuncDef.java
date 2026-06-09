package frontend.Parser.function;

import frontend.Error;
import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;
import frontend.MyErrorType;
import frontend.Parser.block.Block;
import frontend.Parser.block.ParserOfBlock;

import java.util.ArrayList;

public class ParserOfMainFuncDef {
    private TokenListManager tokenListManager;
    private Token intTk;
    private Token mainTk;
    private Token lParent;
    private Token rParent;
    private Block block;
    private ArrayList<Error> errors;

    public ParserOfMainFuncDef(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }

    public MainFuncDef parseMainFuncDef() {
        this.errors = new ArrayList<>();
        Token token = this.tokenListManager.getTokenAndMove();
        if (token.getTokenType().equals(TokenType.INTTK)) {
            this.intTk = token;
        } else {
            System.out.println("expected int here");
        }
        token = this.tokenListManager.getTokenAndMove();
        if (token.getTokenType().equals(TokenType.MAINTK)) {
            this.mainTk = token;
        } else {
            System.out.println("expected main here");
        }
        token = this.tokenListManager.getTokenAndMove();
        if (token.getTokenType().equals(TokenType.LPARENT)) {
            this.lParent = token;
        } else {
            System.out.println("expected leftParent here");
        }
        token = this.tokenListManager.getTokenAndMove();
        if (token.getTokenType().equals(TokenType.RPARENT)) {
            this.rParent = token;
        } else {
            tokenListManager.lookBackToken(2);
            token = tokenListManager.getTokenAndMove();
            Error error = new Error(token.getLineNo(), MyErrorType.j);
            this.errors.add(error);
            System.out.println("expected rightParent here");
        }
        ParserOfBlock parserOfBlock = new ParserOfBlock(tokenListManager);
        this.block = parserOfBlock.parseBlock();
        this.errors.addAll(parserOfBlock.getErrors());
        return new MainFuncDef(this.intTk, this.mainTk, this.lParent, this.rParent, this.block);
    }
    public ArrayList<Error> getErrors() {
        return this.errors;
    }
}
