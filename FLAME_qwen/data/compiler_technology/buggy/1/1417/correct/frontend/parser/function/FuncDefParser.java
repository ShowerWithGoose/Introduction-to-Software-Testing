package frontend.parser.function;

import frontend.error.Error;
import frontend.error.TokenError;
import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.function.functype.FuncType;
import frontend.parser.function.functype.FuncTypeParser;
import frontend.parser.function.param.FuncFParams;
import frontend.parser.function.param.FuncFParamsParser;
import frontend.parser.statement.Block;
import frontend.parser.statement.BlockParser;
import frontend.parser.terminal.Ident;
import frontend.parser.terminal.IdentParser;

import java.util.ArrayList;

public class FuncDefParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public FuncDefParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public FuncDef parseFuncDef() {
        FuncTypeParser funcTypeParser = new FuncTypeParser(tokenList);
        FuncType funcType = funcTypeParser.parseFuncType();
        this.nodes.add(funcType);
        IdentParser identParser = new IdentParser(tokenList);
        Ident ident = identParser.parseIdent();
        this.nodes.add(ident);
        Token lParent = tokenList.getNextToken();
        this.nodes.add(lParent);

        Token token = tokenList.getNextToken();
        // 没有FuncFParams
        if (token.getType() == TokenType.RPARENT) {
            this.nodes.add(token);
        }
        // 有FuncFParams
        else {
            if (token.getType() == TokenType.LBRACE) {
                Error error = new Error();
                tokenList.fallbackToken(2);
                Token token2 = tokenList.getNextToken();
                TokenError tokenError = new TokenError(token2.getLineNumber(), 'j');
                error.addTokenError(tokenError);
                Token rParent = new Token(TokenType.SEMICN, ")", token2.getLineNumber());
                this.nodes.add(rParent);
            } else {
                tokenList.fallbackToken(1);
                FuncFParamsParser funcFParamsParser = new FuncFParamsParser(tokenList);
                FuncFParams funcFParams = funcFParamsParser.parseFuncFParams();
                this.nodes.add(funcFParams);
                Token rParent = tokenList.getNextToken();
                if (rParent.getType() != TokenType.RPARENT){
                    Error error = new Error();
                    tokenList.fallbackToken(2);
                    Token token2 = tokenList.getNextToken();
                    TokenError tokenError = new TokenError(token2.getLineNumber(), 'j');
                    error.addTokenError(tokenError);
                    rParent = new Token(TokenType.RPARENT, ")", token2.getLineNumber());
                }
                this.nodes.add(rParent);
            }
        }

        BlockParser blockParser = new BlockParser(tokenList);
        Block block = blockParser.parseBlock();
        this.nodes.add(block);
        int startLine = this.nodes.get(0).getStarttLine();
        int endLine = this.nodes.get(nodes.size() - 1).getEndLine();
        FuncDef funcDef = new FuncDef(startLine, endLine, "<FuncDef>", this.nodes);
        return funcDef;
    }
}
