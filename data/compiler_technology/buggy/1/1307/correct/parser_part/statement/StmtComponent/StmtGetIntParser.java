package parser_part.statement.StmtComponent;

import error_part.Error;
import error_part.ErrorList;
import lexer_part.Token;
import lexer_part.TokenList;
import parser_part.expression.primaryExpression.LVal;
import parser_part.expression.primaryExpression.LValParser;
import symbol_part.SymbolList;

public class StmtGetIntParser {
    private TokenList tokenList;
    private SymbolList symbolList;

    public StmtGetIntParser(TokenList tokenList,SymbolList symbolList) {
        this.tokenList = tokenList;
        this.symbolList = symbolList;
    }

    public StmtGetInt parseStmtGetInt() {
        LValParser lValParser = new LValParser(tokenList,symbolList);
        LVal lVal = lValParser.parseLVal();
        // check h error
        if (lVal.isConstVar()) {
            ErrorList.addError(new Error(lVal.getLineIndex(), Error.ErrorType.MODIFY_CONST));
        }
        Token assign = tokenList.getNextToken();
        if (assign.getType() != Token.TokenType.ASSIGN) {
            System.err.println("expect assign in parseStmtGetInt");
        }
        Token getInt = tokenList.getNextToken();
        if (getInt.getType() != Token.TokenType.GETINTTK && getInt.getType() != Token.TokenType.GETCHARTK) {
            System.err.println("expect getin getchar in parseStmtGetInt");
        }
        Token leftParent = tokenList.getNextToken();
        if (leftParent.getType() != Token.TokenType.LPARENT) {
            //System.err.println("expect left parent in parseStmtGetInt");
        }
        Token rightParent = tokenList.getNextToken();
        if (rightParent.getType() != Token.TokenType.RPARENT) {
            tokenList.moveBack(2);
            //System.err.println("expect r parent in parseStmtGetInt");
            Token token = tokenList.getNextToken();
            ErrorList.addError(new Error(token.getLineIndex(), Error.ErrorType.LACK_RIGHT_PARENT));
        }
        Token semicn = tokenList.getNextToken();
        //check i error
        if (semicn.getType() != Token.TokenType.SEMICN) {
            tokenList.moveBack(2);
            //System.err.println("expect semicn in parseStmtGetInt");
            Token token = tokenList.getNextToken();
            ErrorList.addError(new Error(token.getLineIndex(), Error.ErrorType.LACK_SEMICN));
        }
        return new StmtGetInt(lVal, assign, getInt, leftParent, rightParent, semicn);
    }
}
