package frontend.parser.declaration.variable;

import frontend.error.Error;
import frontend.error.TokenError;
import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.declaration.variable.initval.InitVal;
import frontend.parser.declaration.variable.initval.InitValParser;
import frontend.parser.expression.ConstExp;
import frontend.parser.expression.ConstExpParser;
import frontend.parser.terminal.Ident;
import frontend.parser.terminal.IdentParser;

import java.util.ArrayList;

// VarDef -> Ident [ '[' ConstExp ']' ] [ '=' InitVal ]
public class VarDefParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public VarDefParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public VarDef parseVarDef() {
        IdentParser identParser = new IdentParser(tokenList);
        Ident ident = identParser.parseIdent();
        this.nodes.add(ident);
        Token token = tokenList.getNextToken();
        // VarDef -> Ident '[' ConstExp ']' [ '=' InitVal ]
        if (token.getType() == TokenType.LBRACK) {
            this.nodes.add(token);
            ConstExpParser constExpParser = new ConstExpParser(tokenList);
            ConstExp constExp = constExpParser.parseConstExp();
            this.nodes.add(constExp);
            Token rBrack = tokenList.getNextToken();
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
        // VarDef -> Ident [ '=' InitVal ]
        else {
            tokenList.fallbackToken(1);
        }

        token = tokenList.getNextToken();
        // VarDef -> Ident '=' InitVal
        if (token.getType() == TokenType.ASSIGN) {
            this.nodes.add(token);
            InitValParser initValParser = new InitValParser(tokenList);
            InitVal initVal = initValParser.parseInitVal();
            this.nodes.add(initVal);
        }
        // VarDef -> Ident
        else {
            tokenList.fallbackToken(1);
        }
        int startLine = nodes.get(0).getStarttLine();
        int endLine = nodes.get(nodes.size() - 1).getEndLine();
        VarDef varDef = new VarDef(startLine, endLine, "<VarDef>", this.nodes);
        return varDef;
    }
}
