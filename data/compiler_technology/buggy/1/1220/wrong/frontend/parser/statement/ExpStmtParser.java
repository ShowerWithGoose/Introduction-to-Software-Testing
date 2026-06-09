package frontend.parser.statement;

import frontend.error.Error;
import frontend.error.ErrorList;
import frontend.lexer.Token;
import frontend.lexer.TokenIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.Exp;
import frontend.parser.expression.ExpParser;

public class ExpStmtParser {
    TokenIterator iterator;

    public ExpStmtParser(TokenIterator iterator) {
        this.iterator = iterator;
    }

    public ExpStmt parseExpStmt() {
        //stmt-> LVal '=' (Exp';'|getint();|getchar();)
        Token semicn = iterator.getNextToken();
        Exp exp;
        if (semicn.getType() != TokenType.SEMICN) {
            semicn = null;
            ExpParser parser = new ExpParser(iterator);
            exp = parser.parseExp();
            semicn = iterator.getNextToken();
            if (semicn.getType() != TokenType.SEMICN) {
                semicn = null;
                iterator.ungetToken(2);
                Error error = new Error(iterator.getNextToken().getLineNum(), "i");
                ErrorList.addErrorList(error);
            }
        } else {
            exp = null;
        }
        return new ExpStmt(exp, semicn);

    }
}
