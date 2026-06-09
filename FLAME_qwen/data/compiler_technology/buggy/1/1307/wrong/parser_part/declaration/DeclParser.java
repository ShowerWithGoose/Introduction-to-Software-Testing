package parser_part.declaration;

import lexer_part.Token;
import lexer_part.TokenList;
import parser_part.declaration.constance.ConstDeclParser;
import parser_part.declaration.var.VarDeclParser;
import symbol_part.SymbolList;

public class DeclParser {
    private TokenList tokenList;
    private SymbolList symbolList;

    public DeclParser(TokenList tokenList, SymbolList symbolList) {
        this.tokenList = tokenList;
        this.symbolList = symbolList;
    }

    public Decl parseDecl() {
        Token token = tokenList.getNextToken();
        tokenList.moveBack(1);
        if (token.getType() == Token.TokenType.CONSTTK) {
            ConstDeclParser constDeclParser = new ConstDeclParser(tokenList,symbolList);
            return new Decl(constDeclParser.parseConstDecl());
        } else if (token.getType() == Token.TokenType.INTTK || token.getType() == Token.TokenType.FLOATTK || token.getType() == Token.TokenType.CHARTK) {
            VarDeclParser varDeclParser = new VarDeclParser(tokenList,symbolList);
            return new Decl(varDeclParser.parseVarDecl());
        } else {
            System.err.println("No match type for Declare");
            return null;
        }
    }
}
