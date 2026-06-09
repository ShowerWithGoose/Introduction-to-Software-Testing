package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.parser.expression.Exp;
import frontend.parser.expression.ExpParser;
import frontend.parser.expression.primaryexp.LVal;
import frontend.parser.expression.primaryexp.LValParser;

import java.util.ArrayList;

public class ForStmtParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    public LVal lval;
    public Token eq;
    public Exp exp;
    public ForStmt forStmt;
    public ForStmtParser(TokenListIterator iterator,ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }

    public ForStmt forStmtParser(){
        LValParser lValParser = new LValParser(this.iterator,this.error_tokens);
        this.lval = lValParser.parseLVal();
        this.eq = this.iterator.readNextToken();
        ExpParser expParser = new ExpParser(this.iterator,this.error_tokens);
        this.exp = expParser.parseExp();
        this.forStmt = new ForStmt(this.lval,this.eq,this.exp);
        return this.forStmt;
    }
}
