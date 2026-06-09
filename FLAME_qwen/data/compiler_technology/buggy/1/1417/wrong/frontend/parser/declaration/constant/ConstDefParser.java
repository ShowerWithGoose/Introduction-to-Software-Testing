package frontend.parser.declaration.constant;

import frontend.error.Error;
import frontend.error.TokenError;
import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.declaration.constant.constinitval.ConstInitVal;
import frontend.parser.declaration.constant.constinitval.ConstInitValParser;
import frontend.parser.expression.ConstExp;
import frontend.parser.expression.ConstExpParser;
import frontend.parser.terminal.Ident;
import frontend.parser.terminal.IdentParser;

import java.util.ArrayList;

// ConstDef -> Ident [ '[' ConstExp ']' ] '=' ConstInitVal
public class ConstDefParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public ConstDefParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public ConstDef parseConstDef() {
        // 先解析Ident
        IdentParser identParser = new IdentParser(this.tokenList);
        Ident ident = identParser.parseIdent();
        this.nodes.add(ident);
        Token token = tokenList.getNextToken();
        while (token.getType() == TokenType.LBRACK) {
            // 解析'['
            this.nodes.add(token);
            // 解析ConstExp
            ConstExpParser constExpParser = new ConstExpParser(tokenList);
            ConstExp constExp = constExpParser.parseConstExp();
            this.nodes.add(constExp);
            // 解析']'
            token = tokenList.getNextToken();
            if (token.getType() != TokenType.RBRACK) {
                Error error = new Error();
                tokenList.fallbackToken(2);
                Token token2 = tokenList.getNextToken();
                TokenError tokenError = new TokenError(token2.getLineNumber(), 'k');
                error.addTokenError(tokenError);
                token = new Token(TokenType.RBRACK, "]", token2.getLineNumber());
            }
            this.nodes.add(token);
            token = tokenList.getNextToken();
        }
        // 解析'='
        this.nodes.add(token);
        ConstInitValParser constInitValParser = new ConstInitValParser(tokenList);
        ConstInitVal constInitVal = constInitValParser.parseConstInitVal();
        this.nodes.add(constInitVal);
        int startLine = this.nodes.get(0).getStarttLine();
        int endLine = this.nodes.get(nodes.size() - 1).getEndLine();
        ConstDef constDef = new ConstDef(startLine, endLine, "<ConstDef>", this.nodes);
        return constDef;
    }

}
