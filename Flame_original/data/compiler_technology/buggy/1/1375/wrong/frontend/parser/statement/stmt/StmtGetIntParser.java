package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.primaryexp.LVal;
import frontend.parser.expression.primaryexp.LValParser;

import java.util.ArrayList;

public class StmtGetIntParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    /* StmtGetint Attributes */
    public LVal lval = null;
    public Token eq = null; // '='
    public Token getint = null; // 'getint'
    public Token leftParent = null; // '('
    public Token rightParent = null; // ')'
    public Token semicn = null; // ';'

    public StmtGetIntParser(TokenListIterator iterator, ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }

    public StmtGetint parseStmtGetInt() {
        LValParser lvalParser = new LValParser(this.iterator,this.error_tokens);
        this.lval = lvalParser.parseLVal();
        this.eq = this.iterator.readNextToken();
        this.getint = this.iterator.readNextToken();
        this.leftParent = this.iterator.readNextToken();

        Token token = this.iterator.readNextToken();
        this.iterator.unReadToken(1);
        if (!token.type.equals(TokenType.RPARENT)) {
            this.rightParent = new Token(TokenType.RPARENT,this.leftParent.linenum,")");
            this.error_tokens.add(new Token(TokenType.RPARENT,this.leftParent.linenum,"j"));
        }else{
            this.rightParent = this.iterator.readNextToken();
        }



        Token token2 = this.iterator.readNextToken();
        this.iterator.unReadToken(1);
        if (!token2.type.equals(TokenType.SEMICN)) {
            this.semicn = new Token(TokenType.SEMICN,this.leftParent.linenum,";");
            this.error_tokens.add(new Token(TokenType.SEMICN,this.leftParent.linenum,"i"));
        }else{
            this.semicn = this.iterator.readNextToken();
        }




        StmtGetint stmtGetint = new StmtGetint(this.lval, this.eq, this.getint,
                this.leftParent, this.rightParent, this.semicn);
        return stmtGetint;
    }
}
