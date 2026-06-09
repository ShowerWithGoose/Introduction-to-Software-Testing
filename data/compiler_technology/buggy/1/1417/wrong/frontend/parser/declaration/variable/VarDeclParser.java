package frontend.parser.declaration.variable;

import frontend.error.Error;
import frontend.error.TokenError;
import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.declaration.BType;
import frontend.parser.declaration.BTypeParser;

import java.util.ArrayList;

// VarDecl -> BType VarDef { ',' VarDef } ';'
public class VarDeclParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public VarDeclParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public VarDecl parserVarDecl() {
        BTypeParser bTypeParser = new BTypeParser(tokenList);
        BType bType = bTypeParser.parseBType();
        this.nodes.add(bType);
        VarDefParser varDefParser = new VarDefParser(tokenList);
        VarDef first = varDefParser.parseVarDef();
        this.nodes.add(first);
        Token token = tokenList.getNextToken();
        // VarDecl -> BType VarDef ',' VarDef ',' VarDef ... ';'
        if (token.getType() == TokenType.COMMA) {
            while (token.getType() == TokenType.COMMA) {
                this.nodes.add(token);
                VarDefParser varDefParser2 = new VarDefParser(tokenList);
                VarDef varDef = varDefParser2.parseVarDef();
                this.nodes.add(varDef);
                token = tokenList.getNextToken();
            }
        }
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
        int endLine = nodes.get(nodes.size() - 1).getEndLine();
        VarDecl varDecl = new VarDecl(startLine, endLine, "<VarDecl>", this.nodes);
        return varDecl;
    }
}
