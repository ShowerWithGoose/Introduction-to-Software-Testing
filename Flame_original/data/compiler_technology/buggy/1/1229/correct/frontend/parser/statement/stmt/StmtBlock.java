package frontend.parser.statement.stmt;

import frontend.lexer.TokenList;
import frontend.parser.statement.Block;

public class StmtBlock implements StmtIFace{
    private Block block;
    private TokenList tokenList;

    public StmtBlock(TokenList tokenList) {
        this.tokenList = tokenList;
    }

    public void parseStmtBlock(){
        this.block = new Block(tokenList);
        this.block.parseBlock();
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.block.syntaxOutput());
        return sb.toString();
    }
}
