package frontend.parser.expression.primaryexp;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.Exp;
import frontend.parser.expression.ExpParser;
import frontend.parser.terminal.Ident;
import frontend.parser.terminal.IdentParser;

import java.util.ArrayList;

public class LValParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    /* LVal Attributes */
    public Ident ident = null;
    public Token leftBrackets = null; // '['
    public Exp exps = null;
    public Token rightBrackets = null;

    public LValParser(TokenListIterator iterator,ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }

    public LVal parseLVal() {
        IdentParser identParser = new IdentParser(this.iterator,this.error_tokens);
        this.ident = identParser.parseIdent();
        Token token = this.iterator.readNextToken();
        LVal lval = null;
        if(token.type.equals(TokenType.LBRACK)) { // '['
            this.leftBrackets = token;
            ExpParser expParser = new ExpParser(this.iterator,this.error_tokens);
            this.exps = expParser.parseExp();


            token = this.iterator.readNextToken(); // ']'
            if(!token.type.equals(TokenType.RBRACK)) {
                this.iterator.unReadToken(1);
                this.rightBrackets = new Token(TokenType.RBRACK,this.exps.my_line_num(),"]");
                this.error_tokens.add(new Token(TokenType.RBRACK,this.exps.my_line_num(),"k"));
            }else{
                this.rightBrackets = token;
            }






            lval = new LVal(this.ident, this.leftBrackets, this.exps, this.rightBrackets);
        } else{
            this.iterator.unReadToken(1);
            lval = new LVal(this.ident);
        }
        return lval;
    }
}
