package frontend.parser.function.param;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.expression.Exp;
import frontend.parser.expression.ExpParser;
import frontend.parser.function.param.FuncRParams;

import java.util.ArrayList;

public class FuncRParamsParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public FuncRParamsParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public FuncRParams parseFuncRParams() {
        ExpParser expParser = new ExpParser(tokenList);
        Exp first = expParser.parseExp();
        this.nodes.add(first);
        Token token = tokenList.getNextToken();
        // 有 ','
        if (token.getType() == TokenType.COMMA) {
            while (token.getType() == TokenType.COMMA) {
                this.nodes.add(token);
                ExpParser expParser2 = new ExpParser(tokenList);
                Exp exp = expParser2.parseExp();
                this.nodes.add(exp);
                token = tokenList.getNextToken();
            }
            tokenList.fallbackToken(1);
        }
        // 没有 ','
        else {
            tokenList.fallbackToken(1);
        }
        int startLine = nodes.get(0).getStarttLine();
        int endLine = nodes.get(nodes.size() - 1).getEndLine();
        FuncRParams funcRParams = new FuncRParams(startLine, endLine, "<FuncRParams>", this.nodes);
        return funcRParams;
    }
}
