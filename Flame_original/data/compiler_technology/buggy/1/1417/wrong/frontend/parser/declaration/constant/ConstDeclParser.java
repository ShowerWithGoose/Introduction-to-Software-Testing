package frontend.parser.declaration.constant;

import frontend.error.Error;
import frontend.error.TokenError;
import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.declaration.BType;
import frontend.parser.declaration.BTypeParser;

import java.util.ArrayList;

// ConstDecl -> 'const' BType ConstDef { ',' ConstDef }

public class ConstDeclParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public ConstDeclParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public ConstDecl parseConstDecl() {
        Token token = tokenList.getNextToken();
        if (token.getType() == TokenType.CONSTTK) {
            Token constTk = token;
            this.nodes.add(constTk);
        } else {
            // TODO: something wrong
        }
        BTypeParser bTypeParser = new BTypeParser(tokenList);
        BType bType = bTypeParser.parseBType();
        this.nodes.add(bType);
        ConstDefParser constDefParser = new ConstDefParser(tokenList);
        ConstDef first = constDefParser.parseConstDef();
        this.nodes.add(first);
        token = tokenList.getNextToken();
        while(token.getType() == TokenType.COMMA){
            this.nodes.add(token);
            ConstDefParser constDefParser2 = new ConstDefParser(tokenList);
            ConstDef constDef = constDefParser2.parseConstDef();
            this.nodes.add(constDef);
            token = tokenList.getNextToken();
        }
        // 读取ConstDecl结尾的 ';'
        Token semicn = token;
        if (semicn.getType() != TokenType.SEMICN) {
            Error error = new Error();
            tokenList.fallbackToken(2);
            Token token2 = tokenList.getNextToken();
            TokenError tokenError = new TokenError(token2.getLineNumber(), 'i');
            error.addTokenError(tokenError);
            semicn = new Token(TokenType.SEMICN, ";", token2.getLineNumber());
        }
        this.nodes.add(semicn);
        int startLine = nodes.get(0).getStarttLine();
        int endLine = nodes.get(nodes.size()-1).getEndLine();
        ConstDecl constDecl = new ConstDecl(startLine, endLine, "<ConstDecl>", nodes);
        return constDecl;
    }
}
