package frontend.parser.declaration.variable.initval;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.expression.Exp;
import frontend.parser.expression.ExpParser;

import java.util.ArrayList;

// InitValMulti -> '{' [ Exp { ',' Exp } '}'
public class InitValMultiParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public InitValMultiParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public InitValMulti parseInitValMulti() {
        Token lBrace = tokenList.getNextToken();
        this.nodes.add(lBrace);
        Token token = tokenList.getNextToken();
        // InitValMulti -> '{' '}'
        if (token.getType() == TokenType.RBRACE) {
            this.nodes.add(token);
        } else {
            tokenList.fallbackToken(1);
            ExpParser expParser = new ExpParser(tokenList);
            Exp first = expParser.parseExp();
            this.nodes.add(first);
            token = tokenList.getNextToken();
            // InitValMulti -> '{' Exp ',' Exp ',' Exp ... '}'
            if (token.getType() == TokenType.COMMA) {
                while (token.getType() == TokenType.COMMA) {
                    this.nodes.add(token);
                    ExpParser expParser2 = new ExpParser(tokenList);
                    Exp exp = expParser2.parseExp();
                    this.nodes.add(exp);
                    token = tokenList.getNextToken();
                }
                this.nodes.add(token);
            }
            // InitValMulti -> '{' Exp '}'
            else {
                this.nodes.add(token);
            }
        }
        int startLine = this.nodes.get(0).getStarttLine();
        int endLine = this.nodes.get(nodes.size() - 1).getEndLine();
        InitValMulti initValMulti = new InitValMulti(startLine, endLine, "", this.nodes);
        return initValMulti;
    }
}
