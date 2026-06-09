package parser_part.declaration.var;

import error_part.Debug;
import error_part.Error;
import error_part.ErrorList;
import lexer_part.Token;
import lexer_part.TokenList;
import parser_part.declaration.BType;
import parser_part.declaration.BTypeParser;
import parser_part.declaration.Def;
import parser_part.declaration.var.varDef.VarDef;
import parser_part.declaration.var.varDef.VarDefParser;
import symbol_part.SymbolList;

import java.util.ArrayList;

public class VarDeclParser {
    private TokenList tokenList;
    private SymbolList symbolList;

    public VarDeclParser(TokenList tokenList,SymbolList symbolList) {
        this.tokenList = tokenList;
        this.symbolList = symbolList;
    }

    public VarDecl parseVarDecl() {
        BTypeParser bTypeParser = new BTypeParser(tokenList);
        BType bType = bTypeParser.parseBType();
        VarDefParser varDefParser = new VarDefParser(tokenList,symbolList,bType);
        VarDef varDef = varDefParser.parseVarDef();
        ArrayList<Token> commas = new ArrayList<>();
        ArrayList<Def> varDefs = new ArrayList<>();
        Token semicn;
        Token token = tokenList.getNextToken();
        while (token != null && token.getType() == Token.TokenType.COMMA) {
            commas.add(token);
            VarDefParser varDefParser1 = new VarDefParser(tokenList,symbolList,bType);
            varDefs.add(varDefParser1.parseVarDef());
            token = tokenList.getNextToken();
        }
        semicn = token;
        if (semicn.getType() != Token.TokenType.SEMICN && Debug.status) {
            //System.err.println("expect semicn in parseVarDecl");
            tokenList.moveBack(2);
            ErrorList.addError(new Error(tokenList.getNextToken().getLineIndex(), Error.ErrorType.LACK_SEMICN));
        }
        return new VarDecl(bType, varDef, commas, varDefs, semicn);
    }

}
