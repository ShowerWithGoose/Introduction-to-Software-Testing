package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.Exp;
import frontend.parser.expression.ExpParser;

import java.util.ArrayList;

public class StmtReturnParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    /* StmtPrint Attributes */
    public Token returnTk; // 'return'
    public Exp exp;
    public Token semicn; // ';'
    public StmtReturn stmtReturn = null;

    public StmtReturnParser(TokenListIterator iterator, ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }

    public StmtReturn parseStmtReturn() {
        this.returnTk = this.iterator.readNextToken();
        if (!this.returnTk.type.equals(TokenType.RETURNTK)) {
            System.out.println("EXPECT RETURNTK IN STMTRETURNPARSER");
        }
        ExpParser expParser = new ExpParser(this.iterator,this.error_tokens);
        this.semicn = this.iterator.readNextToken();
        if (!this.semicn.type.equals(TokenType.SEMICN)) {
            this.iterator.unReadToken(1);
            this.exp = expParser.parseExp();
            this.semicn = this.iterator.readNextToken();
            stmtReturn = new StmtReturn(this.returnTk, this.exp, this.semicn);
        } else {
            stmtReturn = new StmtReturn(this.returnTk, this.semicn);
        }
        return stmtReturn;
    }
}
