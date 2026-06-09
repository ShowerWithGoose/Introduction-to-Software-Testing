package frontend.parser.expression.primaryexp;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.Exp;
import frontend.parser.expression.ExpParser;

import java.util.ArrayList;

public class PrimaryExpExpParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    /* PrimaryExpExp Attribute */
    public Token leftParent = null; // '('
    public Exp exp = null;
    public Token rightParent = null; // ')'

    public PrimaryExpExpParser(TokenListIterator iterator,ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }

    public PrimaryExpExp parsePrimaryExpExp() {
        this.leftParent = this.iterator.readNextToken();
        ExpParser expParser = new ExpParser(this.iterator,this.error_tokens);
        this.exp = expParser.parseExp();

        Token token = this.iterator.readNextToken(); // ']'
        if(!token.type.equals(TokenType.RPARENT)) {
            this.iterator.unReadToken(1);
            this.rightParent = new Token(TokenType.RPARENT,this.exp.my_line_num(),")");
            this.error_tokens.add(new Token(TokenType.RPARENT,this.exp.my_line_num(),"j"));
        }else{
            this.rightParent = token;
        }


        PrimaryExpExp primaryExpExp = new
                PrimaryExpExp(this.leftParent, this.exp, this.rightParent);
        return primaryExpExp;
    }
}
