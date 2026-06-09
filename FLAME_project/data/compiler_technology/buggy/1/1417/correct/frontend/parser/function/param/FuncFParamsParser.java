package frontend.parser.function.param;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;

import java.util.ArrayList;

public class FuncFParamsParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public FuncFParamsParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public FuncFParams parseFuncFParams() {
        FuncFParamParser funcFParamParser = new FuncFParamParser(tokenList);
        FuncFParam first = funcFParamParser.parseFuncFParam();
        this.nodes.add(first);
        Token token = tokenList.getNextToken();
        // 有 ','
        if (token.getType() == TokenType.COMMA) {
            while (token.getType() == TokenType.COMMA) {
                this.nodes.add(token);
                FuncFParamParser funcFParamParser2 = new FuncFParamParser(tokenList);
                FuncFParam funcFParam = funcFParamParser2.parseFuncFParam();
                this.nodes.add(funcFParam);
                token = tokenList.getNextToken();
            }
            tokenList.fallbackToken(1);
        }
        // 无 ','
        else {
            tokenList.fallbackToken(1);
        }
        int startLine = this.nodes.get(0).getStarttLine();
        int endLine = this.nodes.get(nodes.size() - 1).getEndLine();
        FuncFParams funcFParams1 = new FuncFParams(startLine, endLine, "<FuncFParams>", this.nodes);
        return funcFParams1;
    }

}
