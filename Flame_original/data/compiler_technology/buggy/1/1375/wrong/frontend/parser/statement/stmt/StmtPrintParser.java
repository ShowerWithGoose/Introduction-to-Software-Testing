package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.Exp;
import frontend.parser.expression.ExpParser;
import frontend.parser.terminal.FormatString;

import java.util.ArrayList;

public class StmtPrintParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    /* StmtPrint Attributes */
    public Token printf; // 'printf'
    public Token leftParent; // '('
    public FormatString formatString;
    public ArrayList<Token> commmas = new ArrayList<>(); // ','
    public ArrayList<Exp> exps = new ArrayList<>();
    public Token rightParent; // ')'
    public Token semicn; // ';'

    public StmtPrintParser(TokenListIterator iterator, ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }

    public StmtPrint parseStmtPrint() {
        this.commmas = new ArrayList<>();
        this.exps = new ArrayList<>();
        this.printf = this.iterator.readNextToken();
        this.leftParent = this.iterator.readNextToken();
        this.formatString = new FormatString(this.iterator.readNextToken());
        Token token = this.iterator.readNextToken();
        while (token.type.equals(TokenType.COMMA)) {
            this.commmas.add(token);
            ExpParser expParser = new ExpParser(this.iterator,this.error_tokens);
            this.exps.add(expParser.parseExp());
            token = this.iterator.readNextToken();
        }

        if(!token.type.equals(TokenType.RPARENT)){
            this.iterator.unReadToken(1);
            this.rightParent = new Token(TokenType.RPARENT,this.formatString.my_line_num(),")");
            this.error_tokens.add(new Token(TokenType.RPARENT,this.formatString.my_line_num(),"j"));
        }else{
            this.rightParent = token;
        }

        token = this.iterator.readNextToken();
        if(!token.type.equals(TokenType.SEMICN)){
            this.iterator.unReadToken(1);
            this.semicn = new Token(TokenType.SEMICN,this.formatString.my_line_num(),")");
            this.error_tokens.add(new Token(TokenType.SEMICN,this.formatString.my_line_num(),"i"));
        }else{
            this.semicn = token;
        }

        StmtPrint stmtPrint = new StmtPrint(this.printf, this.leftParent,
                this.formatString, this.commmas, this.exps, this.rightParent, this.semicn);
        return stmtPrint;
    }
}
