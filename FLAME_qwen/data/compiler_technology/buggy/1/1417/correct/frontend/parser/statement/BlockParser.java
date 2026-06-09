package frontend.parser.statement;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.statement.blockitem.BlockItem;
import frontend.parser.statement.blockitem.BlockItemParser;

import java.util.ArrayList;

// Block -> '{' {BlockItem} '}'
public class BlockParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public BlockParser(TokenList tokenList){
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public Block parseBlock(){
        Token lBrace = tokenList.getNextToken();
        this.nodes.add(lBrace);
        Token token = tokenList.getNextToken();
        while(token.getType() != TokenType.RBRACE){
            tokenList.fallbackToken(1);
            BlockItemParser blockItemParser = new BlockItemParser(tokenList);
            BlockItem blockItem = blockItemParser.parseBlockItem();
            this.nodes.add(blockItem);
            token = tokenList.getNextToken();
        }
        Token rBrace = token;
        this.nodes.add(rBrace);
        int startLine = this.nodes.get(0).getStarttLine();
        int endLine = this.nodes.get(nodes.size() - 1).getEndLine();
        Block block = new Block(startLine, endLine, "<Block>", this.nodes);
        return block;
    }
}
