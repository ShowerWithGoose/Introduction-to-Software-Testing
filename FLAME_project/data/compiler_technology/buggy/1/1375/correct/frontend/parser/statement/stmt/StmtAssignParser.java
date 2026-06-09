package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.Exp;
import frontend.parser.expression.ExpParser;
import frontend.parser.expression.primaryexp.LVal;
import frontend.parser.expression.primaryexp.LValParser;

import java.util.ArrayList;

public class StmtAssignParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    /* StmtAssign Attributes */
    public LVal lval = null;
    public Token eq; // '='
    public Exp exp;
    public Token semicn; // ';'

    public StmtAssignParser(TokenListIterator iterator,ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }

    public StmtAssign parseStmtAssign() {
        LValParser lvalParser = new LValParser(this.iterator,this.error_tokens);
        this.lval = lvalParser.parseLVal();
        this.eq = this.iterator.readNextToken();
        ExpParser expParser = new ExpParser(this.iterator,this.error_tokens);
        this.exp = expParser.parseExp();
        Token token = this.iterator.readNextToken();
        if(!token.type.equals(TokenType.SEMICN))
        {
            this.iterator.unReadToken(1);
            this.semicn = new Token(TokenType.SEMICN,exp.my_line_num(),";");
            this.error_tokens.add(new Token(TokenType.SEMICN, exp.my_line_num(), "i"));
        }
        else {
            this.semicn = token;
        }
        StmtAssign stmtAssign = new StmtAssign(this.lval, this.eq, this.exp, this.semicn);
        return stmtAssign;
    }
}
