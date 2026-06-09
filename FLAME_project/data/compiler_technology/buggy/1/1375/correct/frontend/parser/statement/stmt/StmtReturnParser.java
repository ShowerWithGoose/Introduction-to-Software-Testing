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
    public Exp exp=null;
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
        Token token = this.iterator.readNextToken();
        if (!token.type.equals(TokenType.SEMICN)){
            this.iterator.unReadToken(1);
            if(token.type.equals(TokenType.LPARENT) ||
                    token.type.equals(TokenType.IDENFR) ||
                    token.type.equals(TokenType.INTCON) ||
                    token.type.equals(TokenType.CHRCON) ||
                    token.type.equals(TokenType.PLUS) ||
                    token.type.equals(TokenType.MINU) ||
                    token.type.equals(TokenType.NOT)){

                ExpParser expParser = new ExpParser(iterator, error_tokens);
                this.exp=expParser.parseExp();
                token = this.iterator.readNextToken();
                if(token.type.equals(TokenType.SEMICN)){
                    this.semicn=token;
                }else{
                    this.iterator.unReadToken(1);
                    this.semicn = new Token(TokenType.SEMICN,this.returnTk.linenum,";");
                    this.error_tokens.add(new Token(TokenType.SEMICN,this.returnTk.linenum,"i"));
                }
            }else{
                this.semicn = new Token(TokenType.SEMICN,this.returnTk.linenum,";");
                this.error_tokens.add(new Token(TokenType.SEMICN,this.returnTk.linenum,"i"));
            }
            stmtReturn = new StmtReturn(this.returnTk, this.exp, this.semicn);

        } else {
            this.semicn=token;
            stmtReturn = new StmtReturn(this.returnTk, this.semicn);
        }
        return stmtReturn;
    }
}
