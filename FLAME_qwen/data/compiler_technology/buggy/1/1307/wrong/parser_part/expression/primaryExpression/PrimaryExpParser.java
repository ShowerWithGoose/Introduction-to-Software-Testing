package parser_part.expression.primaryExpression;

import lexer_part.Token;
import lexer_part.TokenList;
import symbol_part.SymbolList;

public class PrimaryExpParser {
    private TokenList tokenList;
    private SymbolList symbolList;

    public PrimaryExpParser(TokenList tokenList, SymbolList symbolList) {
        this.tokenList = tokenList;
        this.symbolList = symbolList;
    }

    public PrimaryExp parsePrimaryExp() {
        Token token = tokenList.getNextToken();
        PrimaryExpComponent primaryExpComponent = null;
        if (token.getType() == Token.TokenType.LPARENT) {
            tokenList.moveBack(1);
            ParentExpParser parentExpParser = new ParentExpParser(tokenList, symbolList);
            primaryExpComponent = parentExpParser.parseParentExp();
        }
        else if (token.getType() == Token.TokenType.INTCON || token.getType() == Token.TokenType.FLOATCON) {
            tokenList.moveBack(1);
            NumberParser numberParser = new NumberParser(tokenList);
            primaryExpComponent = numberParser.parseNumber();
        }
        else if (token.getType() == Token.TokenType.CHRCON){
            tokenList.moveBack(1);
            CharacterParser characterParser = new CharacterParser(tokenList);
            primaryExpComponent = characterParser.parseCharacter();
        }
        else if (isFuncIdent(token)) {
            tokenList.moveBack(1);
            LValParser lValParser = new LValParser(tokenList, symbolList);
            primaryExpComponent = lValParser.parseLVal();
        }
        return new PrimaryExp(primaryExpComponent);
    }

    public boolean isFuncIdent(Token token) {
        return token.getType() == Token.TokenType.IDENFR ||
                token.getType() == Token.TokenType.GETINTTK ||
                token.getType() == Token.TokenType.GETCHARTK ||
                token.getType() == Token.TokenType.MAINTK;
    }
}
