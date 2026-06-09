package parser_part.block;

import lexer_part.Token;
import lexer_part.TokenList;
import parser_part.declaration.DeclParser;
import parser_part.statement.StmtParser;
import symbol_part.SymbolList;

public class BlockItemParser {
    private TokenList tokenList;
    private SymbolList symbolList;

    public BlockItemParser(TokenList tokenList, SymbolList symbolList) {
        this.tokenList = tokenList;
        this.symbolList = symbolList;
    }

    public BlockItem parseBlockItem() {
        Token token = tokenList.getNextToken();
        tokenList.moveBack(1);
        if (token.getType() == Token.TokenType.CONSTTK ||
                token.getType() == Token.TokenType.INTTK ||
                token.getType() == Token.TokenType.FLOATTK ||
                token.getType() == Token.TokenType.CHARTK) {
            DeclParser declParser = new DeclParser(tokenList, symbolList);
            return new BlockItem(declParser.parseDecl());
        } else {
            StmtParser stmtParser = new StmtParser(tokenList, symbolList);
            return new BlockItem(stmtParser.parseStmt());
        }
    }
}
