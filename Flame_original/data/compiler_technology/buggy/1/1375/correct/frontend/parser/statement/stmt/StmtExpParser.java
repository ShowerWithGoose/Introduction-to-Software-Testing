package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.Exp;
import frontend.parser.expression.ExpParser;

import java.util.ArrayList;

public class StmtExpParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    /* StmtExp Attributes */
    public Exp exp = null;
    public Token semicn = null; // ';'

    public StmtExpParser(TokenListIterator iterator, ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }

    public StmtExp parseStmtExp() {
        ExpParser expParser = new ExpParser(this.iterator,this.error_tokens);
        this.exp = expParser.parseExp();
        Token token = this.iterator.readNextToken();
        this.iterator.unReadToken(1);
        if(token.type.equals(TokenType.SEMICN)){
            this.semicn=this.iterator.readNextToken();
        }else{
            this.semicn=new Token(TokenType.SEMICN,exp.my_line_num(),";");
            this.error_tokens.add(new Token(TokenType.SEMICN,exp.my_line_num(),"i"));
        }
        StmtExp stmtExp = new StmtExp(this.exp, this.semicn);
        return stmtExp;
    }

}
