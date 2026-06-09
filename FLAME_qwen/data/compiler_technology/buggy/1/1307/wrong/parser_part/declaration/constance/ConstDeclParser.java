package parser_part.declaration.constance;

import error_part.Debug;
import error_part.Error;
import error_part.ErrorList;
import lexer_part.Token;
import lexer_part.TokenList;
import parser_part.declaration.BType;
import parser_part.declaration.BTypeParser;
import parser_part.declaration.Def;
import symbol_part.SymbolList;

import java.util.ArrayList;

public class ConstDeclParser {
    private TokenList tokenList;
    private SymbolList symbolList;

    public ConstDeclParser(TokenList tokenList,SymbolList symbolList) {
        this.tokenList = tokenList;
        this.symbolList = symbolList;
    }

    public ConstDecl parseConstDecl() {
        Token constToken = tokenList.getNextToken();
        if (constToken.getType() != Token.TokenType.CONSTTK) {
            System.err.println("expect constToken in parseConstDecl");
        }
        BTypeParser bTypeParser = new BTypeParser(tokenList);
        BType bType = bTypeParser.parseBType();
        ConstDefParser constDefParser = new ConstDefParser(tokenList,symbolList,bType);
        ConstDef constDef = constDefParser.parseConstDef();
        Token token = tokenList.getNextToken();
        ArrayList<Token> commas = new ArrayList<>();
        ArrayList<Def> constDefs = new ArrayList<>();
        while (token.getType() == Token.TokenType.COMMA) {
            ConstDefParser constDefParser1 = new ConstDefParser(tokenList,symbolList,bType);
            commas.add(token);
            constDefs.add(constDefParser1.parseConstDef());
            token = tokenList.getNextToken();
        }
        Token semicn = token;
        if (semicn.getType() != Token.TokenType.SEMICN && Debug.status) {
            //System.err.println("expect semicn in parseConstDecl");
            tokenList.moveBack(2);
            ErrorList.addError(new Error(tokenList.getNextToken().getLineIndex(), Error.ErrorType.LACK_SEMICN));
        }
        return new ConstDecl(constToken, bType, constDef, commas, constDefs, semicn);
    }
}
