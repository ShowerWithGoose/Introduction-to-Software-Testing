package parser_part.expression.primaryExpression;

import error_part.Error;
import error_part.ErrorList;
import lexer_part.Token;
import lexer_part.TokenList;
import parser_part.expression.Exp;
import parser_part.expression.ExpParser;
import symbol_part.SymbolList;

public class ParentExpParser {
    private final TokenList tokenList;
    private SymbolList symbolList;

    public ParentExpParser(TokenList tokenList, SymbolList symbolList) {
        this.tokenList = tokenList;
        this.symbolList = symbolList;
    }

    public ParentExp parseParentExp() {
        Token leftParent = tokenList.getNextToken();
        ExpParser expParser = new ExpParser(tokenList, symbolList);
        Exp exp = expParser.parseExp();
        Token rightParent = tokenList.getNextToken();
        if (rightParent.getType() != Token.TokenType.RPARENT) {
            tokenList.moveBack(2);
            ErrorList.addError(new Error(tokenList.getNextToken().getLineIndex(), Error.ErrorType.LACK_RIGHT_PARENT));
        }
        return new ParentExp(leftParent, exp, rightParent);
    }
}
