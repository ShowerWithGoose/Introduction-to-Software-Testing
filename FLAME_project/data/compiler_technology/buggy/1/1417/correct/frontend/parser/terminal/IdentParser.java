package frontend.parser.terminal;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;

import java.util.ArrayList;

public class IdentParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public IdentParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public Ident parseIdent(){
        Token token = tokenList.getNextToken();
        if (token.getType() == TokenType.IDENFR){
            int startLine = token.getStarttLine();
            int endLine = token.getEndLine();
            this.nodes.add(token);
            Ident ident = new Ident(startLine, endLine, "", this.nodes);
            return ident;
        }else {
            // TODO: something wrong
            return null;
        }
    }
}
