package frontend.Parser.function;

import frontend.Error;
import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;
import frontend.MyErrorType;
import frontend.Parser.block.Block;
import frontend.Parser.block.ParserOfBlock;
import frontend.Parser.terminal.Ident;

import java.util.ArrayList;

public class ParserOfFuncDef {
    private TokenListManager tokenListManager;
    private FuncType funcType;
    private Ident ident;
    private Token lParent; // '('左括号
    private FuncFParams funcFParams; //函数形参表，可能有，可能没有
    private Token rParent;
    private Block block;
    private ArrayList<Error> errors;

    public ParserOfFuncDef(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }

    public FuncDef parseFuncDef() {
        this.funcFParams = null;
        this.errors = new ArrayList<>();
        ParserOfFuncType parserOfFuncType = new ParserOfFuncType(this.tokenListManager);
        this.funcType = parserOfFuncType.parseFuncType();
        Token token = this.tokenListManager.getTokenAndMove();
        if (token.getTokenType().equals(TokenType.IDENFR)) {
            this.ident = new Ident(token);
        } else {
            System.out.println("expected ident here!");
        }
        token = this.tokenListManager.getTokenAndMove();
        this.lParent = token;
        token = this.tokenListManager.getTokenAndMove();
        if (token.getTokenType().equals(TokenType.RPARENT)) {
            this.rParent = token;
        } else {
            if(token.getTokenType().equals(TokenType.LBRACE)){
                tokenListManager.lookBackToken(2);
                token = tokenListManager.getTokenAndMove();
                Error error = new Error(token.getLineNo(),MyErrorType.j);
                this.errors.add(error);
            }
            else {
                this.tokenListManager.lookBackToken(1);
                ParserOfFuncFParams parserOfFuncFParams = new ParserOfFuncFParams(this.tokenListManager);
                this.funcFParams = parserOfFuncFParams.parseFuncFParams();
                this.errors.addAll(parserOfFuncFParams.getErrors());
                token = this.tokenListManager.getTokenAndMove();
                if(token.getTokenType().equals(TokenType.RPARENT)) {
                    this.rParent = token;
                } else {
                    tokenListManager.lookBackToken(2);
                    token = tokenListManager.getTokenAndMove();
                    Error error = new Error(token.getLineNo(), MyErrorType.j);
                    this.errors.add(error);
                }
            }
        }
        ParserOfBlock parserOfBlock = new ParserOfBlock(this.tokenListManager);
        this.block = parserOfBlock.parseBlock();
        this.errors.addAll(parserOfBlock.getErrors());
        return new FuncDef(this.funcType, this.ident, this.lParent,
                this.funcFParams, this.rParent, this.block);
    }

    public ArrayList<Error> getErrors() {
        return this.errors;
    }
}
