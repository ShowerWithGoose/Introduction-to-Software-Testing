package frontend.parser.function;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.declaration.BType;
import frontend.parser.declaration.BTypeParser;
import frontend.parser.expression.ConstExpParser;
import frontend.parser.terminal.Ident;
import frontend.parser.terminal.IdentParser;

import java.util.ArrayList;

public class FuncFParamParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    /* FuncFParam Attributes */
    public BType btype = null;
    public Ident ident = null;
    public Token leftBracket = null;
    public Token rightBracket = null;
    public FuncFParam funcFParam = null;

    public FuncFParamParser(TokenListIterator iterator, ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }

    public FuncFParam parseFuncFParam() {
        BTypeParser btypeParser = new BTypeParser(this.iterator,this.error_tokens);
        this.btype = btypeParser.parseBtype();
        IdentParser identParser = new IdentParser(this.iterator,this.error_tokens);
        this.ident = identParser.parseIdent();
        this.leftBracket = this.iterator.readNextToken();
        if (this.leftBracket.type.equals(TokenType.LBRACK)) {
            Token token = this.iterator.readNextToken();
            this.iterator.unReadToken(1);
            if(token.type.equals(TokenType.RBRACK)){
                this.rightBracket = this.iterator.readNextToken();
            }else{
                this.rightBracket=new Token(TokenType.RBRACK,this.leftBracket.linenum,"]");
                this.error_tokens.add(new Token(TokenType.RBRACK,this.rightBracket.linenum,"k"));
            }
            this.funcFParam = new FuncFParam(this.btype, this.ident, this.leftBracket,
                    this.rightBracket);
        } else {
            this.iterator.unReadToken(1);
            this.funcFParam = new FuncFParam(this.btype, this.ident);
        }
        return this.funcFParam;
    }
}
