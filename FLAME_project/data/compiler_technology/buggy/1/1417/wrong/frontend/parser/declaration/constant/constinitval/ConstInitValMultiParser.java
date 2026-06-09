package frontend.parser.declaration.constant.constinitval;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.expression.ConstExp;
import frontend.parser.expression.ConstExpParser;

import java.util.ArrayList;

// ConstInitVal -> '{' [ ConstExp { ',' ConstExp } ] '}'
public class ConstInitValMultiParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public ConstInitValMultiParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public ConstInitValMulti parseConstInitValMulti() {
        // 解析'{'
        Token token = tokenList.getNextToken();
        this.nodes.add(token);
        token = tokenList.getNextToken();
        // {}
        if (token.getType() == TokenType.RBRACE) {
            this.nodes.add(token);
        }
        // { ConstExp, ConstExp, ... }
        else {
            tokenList.fallbackToken(1);
            ConstExpParser constExpParser = new ConstExpParser(tokenList);
            ConstExp first = constExpParser.parseConstExp();
            this.nodes.add(first);
            token = tokenList.getNextToken();
            while (token.getType() == TokenType.COMMA) {
                this.nodes.add(token);
                ConstExpParser constExpParser2 = new ConstExpParser(tokenList);
                ConstExp constExp = constExpParser2.parseConstExp();
                this.nodes.add(constExp);
                token = tokenList.getNextToken();
            }
            this.nodes.add(token);
        }
        int startLine = this.nodes.get(0).getStarttLine();
        int endLine = this.nodes.get(nodes.size() - 1).getEndLine();
        ConstInitValMulti constInitValMulti = new ConstInitValMulti(startLine, endLine, "", this.nodes);
        return constInitValMulti;
    }
}
