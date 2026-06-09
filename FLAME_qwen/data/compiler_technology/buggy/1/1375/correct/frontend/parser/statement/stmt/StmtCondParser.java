package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.Cond;
import frontend.parser.expression.CondParser;

import java.util.ArrayList;

public class StmtCondParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    /* StmtCond Attributes */
    public Token ifTK = null; // 'if'
    public Token leftParent = null; // '('
    public Cond cond = null;
    public Token rightParent = null; // ')'
    public Stmt ifStmt = null;
    public Token elseTk = null; // MAY exist 'else'
    public Stmt elseStmt = null; // MAY exist else statement
    public StmtCond stmtCond = null;

    public StmtCondParser(TokenListIterator iterator, ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }

    public StmtCond parseStmtCond() {
        this.ifTK = this.iterator.readNextToken();
        this.leftParent = this.iterator.readNextToken();
        CondParser condParser = new CondParser(this.iterator,this.error_tokens);
        this.cond = condParser.parseCond();
        Token token = this.iterator.readNextToken();
        this.iterator.unReadToken(1);
        if (!token.type.equals(TokenType.RPARENT)) {
            this.rightParent=new Token(TokenType.RPARENT,this.cond.my_line_num(),")");
            this.error_tokens.add(new Token(TokenType.RPARENT,this.cond.my_line_num(),"j"));
        }else{
            this.rightParent=this.iterator.readNextToken();
        }
        StmtParser stmtParser = new StmtParser(this.iterator,this.error_tokens);
        this.ifStmt = stmtParser.parseStmt();
        this.elseTk = this.iterator.readNextToken();
        if (this.elseTk.type.equals(TokenType.ELSETK)) {
            this.elseStmt = stmtParser.parseStmt();
            this.stmtCond = new StmtCond(this.ifTK, this.leftParent,
                    this.cond, this.rightParent, this.ifStmt, this.elseTk, this.elseStmt);
        } else {
            this.iterator.unReadToken(1);
            this.stmtCond = new StmtCond(this.ifTK, this.leftParent,
                    this.cond, this.rightParent, this.ifStmt);
        }
        return this.stmtCond;
    }
}
