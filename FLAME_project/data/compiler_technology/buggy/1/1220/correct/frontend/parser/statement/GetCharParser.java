package frontend.parser.statement;

import frontend.error.Error;
import frontend.error.ErrorList;
import frontend.lexer.Token;
import frontend.lexer.TokenIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.primaryExp.LVal;

public class GetCharParser {
    private TokenIterator iterator;

    public GetCharParser(TokenIterator iterator) {
        this.iterator = iterator;
    }

    public GetCharStmt parseGetCharStmt(LVal lVal, Token assign) {
        //LVal '=' (Exp';'|getint();|getchar();)
        Token getChar = iterator.getNextToken();
        Token leftParent = iterator.getNextToken();
        Token rightParent = iterator.getNextToken();
        if (rightParent.getType() != TokenType.RPARENT) {
            rightParent = null;
            iterator.ungetToken(2);
            Error error = new Error(iterator.getNextToken().getLineNum(), "j");
            ErrorList.addErrorList(error);
        }
        Token semicn = iterator.getNextToken();
        if (semicn.getType() != TokenType.SEMICN) {
            semicn = null;
            iterator.ungetToken(2);
            Error error = new Error(iterator.getNextToken().getLineNum(), "i");
            ErrorList.addErrorList(error);
        }
        return new GetCharStmt(lVal, assign, getChar, leftParent, rightParent, semicn);
    }
}
