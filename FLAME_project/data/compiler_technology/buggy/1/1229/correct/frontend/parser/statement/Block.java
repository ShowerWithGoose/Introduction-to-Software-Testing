package frontend.parser.statement;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.statement.blockitem.BlockItem;

import java.util.ArrayList;

public class Block implements Node {
    private final String name = "<Block>";
    private Token leftBrace; // '{'
    private ArrayList<BlockItem> blockItems;
    private Token rightBrace; // '}'

    private TokenList tokenList;

    public Block(TokenList tokenList) {
        this.tokenList = tokenList;
        this.blockItems = new ArrayList<>();
    }
    public void parseBlock(){
        this.leftBrace = tokenList.getNextToken();
        Token token = tokenList.seeAfterToken(0);
        while (!token.getType().equals(TokenType.RBRACE)){
            BlockItem blockItem = new BlockItem(tokenList);
            blockItem.parseBlockItem();
            this.blockItems.add(blockItem);
            token = tokenList.seeAfterToken(0);
        }
        this.rightBrace = tokenList.getNextToken();
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.leftBrace.syntaxOutput());
        if (blockItems != null && blockItems.size() != 0) {
            int len = blockItems.size();
            for (int i = 0; i < len; i++) {
                sb.append(this.blockItems.get(i).syntaxOutput());
            }
        }
        sb.append(this.rightBrace.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
