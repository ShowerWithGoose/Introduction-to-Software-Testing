package frontend.parser.expression.unaryexp;

import frontend.error.Error;
import frontend.error.TokenError;
import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.function.param.FuncRParams;
import frontend.parser.function.param.FuncRParamsParser;
import frontend.parser.terminal.Ident;
import frontend.parser.terminal.IdentParser;

import java.util.ArrayList;

// UnaryExpFunc -> Ident '(' [FuncRParams] ')'
public class UnaryExpFuncParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public UnaryExpFuncParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public UnaryExpFunc parseUnaryExpFunc() {
        IdentParser identParser = new IdentParser(tokenList);
        Ident ident = identParser.parseIdent();
        this.nodes.add(ident);
        // 需要判断是否存在FuncRParams
        Token first = tokenList.getNextToken();
        Token second = tokenList.getNextToken();
        Token rParent = null;
        // 没有FuncRParams
        if (second.getType() == TokenType.RPARENT) {
            this.nodes.add(first);
            rParent = second;
        }
        // f(;  缺少右括号的错误
        else if (second.getType() == TokenType.SEMICN){
            Error error = new Error();
            tokenList.fallbackToken(2);
            Token token2 = tokenList.getNextToken();
            TokenError tokenError = new TokenError(token2.getLineNumber(), 'j');
            error.addTokenError(tokenError);
            rParent = new Token(TokenType.RPARENT, ")", token2.getLineNumber());
        }
        // 有FuncRParams
        else {
            this.nodes.add(first);
            tokenList.fallbackToken(1);
            FuncRParamsParser funcRParamsParser = new FuncRParamsParser(tokenList);
            FuncRParams funcRParams = funcRParamsParser.parseFuncRParams();
            this.nodes.add(funcRParams);
            rParent = tokenList.getNextToken();
        }

        if (rParent.getType() != TokenType.RPARENT){
            Error error = new Error();
            tokenList.fallbackToken(2);
            Token token2 = tokenList.getNextToken();
            TokenError tokenError = new TokenError(token2.getLineNumber(), 'j');
            error.addTokenError(tokenError);
            rParent = new Token(TokenType.RPARENT, ")", token2.getLineNumber());
        }
        this.nodes.add(rParent);
        int startLine = nodes.get(0).getStarttLine();
        int endLine = nodes.get(nodes.size() - 1).getEndLine();
        UnaryExpFunc unaryExpFunc = new UnaryExpFunc(startLine, endLine, "", this.nodes);
        return unaryExpFunc;
    }
}
