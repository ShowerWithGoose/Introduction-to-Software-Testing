package frontend.Parser.block;

import frontend.Error;
import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;

import java.util.ArrayList;

public class ParserOfBlock {
    private TokenListManager tokenListManager;
    private Token lBrace;
    private ArrayList<BlockItem> blockItems;
    private Token rBrace;
    private ArrayList<Error> errors;
    public ParserOfBlock(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }
    public Block parseBlock() {
        this.errors = new ArrayList<>();
        this.blockItems = new ArrayList<>();
        Token token = tokenListManager.getTokenAndMove();
        if(token.getTokenType().equals(TokenType.LBRACE)){
            this.lBrace = token;
        } else{
            System.out.println("expected lBrace in parseBlock");
        }
        Token next = tokenListManager.getTokenAndMove();
        while(!next.getTokenType().equals(TokenType.RBRACE)){
            tokenListManager.lookBackToken(1);
            ParserOfBlockItem parserOfBlockItem = new ParserOfBlockItem(tokenListManager);
            BlockItem blockItem = parserOfBlockItem.parseBlockItem();
            this.blockItems.add(blockItem);
            this.errors.addAll(parserOfBlockItem.getErrors());
            next = tokenListManager.getTokenAndMove();
        }
        this.rBrace = next;
        return new Block(this.lBrace, this.blockItems, this.rBrace);
    }
    public ArrayList<Error> getErrors() {
        return errors;
    }
}
