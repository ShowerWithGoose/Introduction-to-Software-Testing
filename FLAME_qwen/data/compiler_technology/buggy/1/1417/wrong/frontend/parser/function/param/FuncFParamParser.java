package frontend.parser.function.param;

import frontend.error.Error;
import frontend.error.TokenError;
import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.declaration.BType;
import frontend.parser.declaration.BTypeParser;
import frontend.parser.terminal.Ident;
import frontend.parser.terminal.IdentParser;

import java.util.ArrayList;

public class FuncFParamParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public FuncFParamParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public FuncFParam parseFuncFParam() {
        BTypeParser bTypeParser = new BTypeParser(tokenList);
        BType bType = bTypeParser.parseBType();
        this.nodes.add(bType);
        IdentParser identParser = new IdentParser(tokenList);
        Ident ident = identParser.parseIdent();
        this.nodes.add(ident);
        Token token = tokenList.getNextToken();
        // 有[
        if (token.getType() == TokenType.LBRACK) {
            this.nodes.add(token);
            token = tokenList.getNextToken();
            Token rBrack = token;
            if (rBrack.getType() != TokenType.RBRACK) {
                Error error = new Error();
                tokenList.fallbackToken(2);
                Token token2 = tokenList.getNextToken();
                TokenError tokenError = new TokenError(token2.getLineNumber(), 'k');
                error.addTokenError(tokenError);
                rBrack = new Token(TokenType.RBRACK, "]", token2.getLineNumber());
            }
            this.nodes.add(rBrack);
        }
        // 无[
        else {
            tokenList.fallbackToken(1);
        }
        int startLine = this.nodes.get(0).getStarttLine();
        int endLine = this.nodes.get(nodes.size() - 1).getEndLine();
        FuncFParam funcFParam = new FuncFParam(startLine, endLine, "<FuncFParam>", this.nodes);
        return funcFParam;
    }
}
