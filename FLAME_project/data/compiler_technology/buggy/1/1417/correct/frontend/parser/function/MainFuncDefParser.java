package frontend.parser.function;

import frontend.error.Error;
import frontend.error.TokenError;
import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.statement.Block;
import frontend.parser.statement.BlockParser;

import java.util.ArrayList;

public class MainFuncDefParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public MainFuncDefParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public MainFuncDef parseMainFuncDef() {
        Token intTk = tokenList.getNextToken();
        this.nodes.add(intTk);
        Token mainTk = tokenList.getNextToken();
        this.nodes.add(mainTk);
        Token lParent = tokenList.getNextToken();
        this.nodes.add(lParent);
        Token rParent = tokenList.getNextToken();
        if (rParent.getType() != TokenType.RPARENT) {
            Error error = new Error();
            tokenList.fallbackToken(2);
            Token token2 = tokenList.getNextToken();
            TokenError tokenError = new TokenError(token2.getLineNumber(), 'j');
            error.addTokenError(tokenError);
            rParent = new Token(TokenType.RPARENT, ")", token2.getLineNumber());
        }
        this.nodes.add(rParent);
        BlockParser blockParser = new BlockParser(tokenList);
        Block block = blockParser.parseBlock();
        this.nodes.add(block);
        int startLine = nodes.get(0).getStarttLine();
        int endLine = nodes.get(nodes.size() - 1).getEndLine();
        MainFuncDef mainFuncDef = new MainFuncDef(startLine, endLine, "<MainFuncDef>", this.nodes);
        return mainFuncDef;
    }
}
