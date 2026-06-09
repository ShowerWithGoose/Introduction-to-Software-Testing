package frontend.parser.terminal;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;

import java.util.ArrayList;

public class StringConstParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public StringConstParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public StringConst parseStringConst(){
        Token token = tokenList.getNextToken();
        if (token.getType() == TokenType.STRCON){
            this.nodes.add(token);
            int startLine = this.nodes.get(0).getStarttLine();
            int endLine = this.nodes.get(nodes.size() - 1).getEndLine();
            StringConst stringConst = new StringConst(startLine, endLine, "", this.nodes);
            return stringConst;
        }else {
            // TODO: something wrong
            return null;
        }
    }
}
