package frontend.ParserPart.state.stmt;

import frontend.ParserPart.state.Block;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

public class StmtBlock implements StmtInterface{
    private TokenList tokenList;
    private Block block;
    public StmtBlock(TokenList tokenList){
        this.tokenList = tokenList;
        block = new Block(tokenList);
    }
    public void parseStmtBlock(){
        block.parseBlock();
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(block.toString());
        return sb.toString();
    }
}
