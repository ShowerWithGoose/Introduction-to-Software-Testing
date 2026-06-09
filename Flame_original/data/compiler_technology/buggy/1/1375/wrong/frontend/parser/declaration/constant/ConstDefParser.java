package frontend.parser.declaration.constant;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.declaration.BType;
import frontend.parser.declaration.constant.constinitval.ConstInitVal;
import frontend.parser.declaration.constant.constinitval.ConstInitValParser;
import frontend.parser.expression.ConstExp;
import frontend.parser.expression.ConstExpParser;
import frontend.parser.terminal.Ident;
import frontend.parser.terminal.IdentParser;

import java.util.ArrayList;

public class ConstDefParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    /* ConstDef Attributes */
    public Ident ident;
    public Token leftBrackets = null;
    public ConstExp constExps = null;
    public Token rightBrackets = null;
    public Token eq; // =
    public ConstInitVal constInitVal;
    public ConstDefParser(TokenListIterator iterator,ArrayList<Token> error_tokens) {
        this.iterator = iterator;
        this.error_tokens = error_tokens;
    }
    public ConstDef parseConstDef(){
        IdentParser identParser = new IdentParser(this.iterator,this.error_tokens);
        ident = identParser.parseIdent();
        Token token = iterator.readNextToken();
        if (token.type.equals(TokenType.LBRACK)) {
            /* '[' */
            this.leftBrackets = token;
            /* ConstExp */
            ConstExpParser constExpParser = new ConstExpParser(this.iterator,this.error_tokens);
            ConstExp constExp = constExpParser.parseConstExp();
            this.constExps = constExp;
            token = this.iterator.readNextToken();
            /* ']' */
            if (!token.type.equals(TokenType.RBRACK)) {
                this.rightBrackets = new Token(TokenType.RBRACK, token.linenum, "]");
                this.error_tokens.add(new Token(TokenType.RBRACK,constExp.my_line_num(),"k"));
                this.iterator.unReadToken(1);
            } else {
                this.rightBrackets = token;
            }
            this.eq=this.iterator.readNextToken();
        } else {
            this.eq = token;
        }

        ConstInitValParser constInitValParser = new ConstInitValParser(this.iterator,this.error_tokens);
        this.constInitVal = constInitValParser.parseConstInitVal();
        ConstDef constDef = new ConstDef(this.ident, this.leftBrackets, this.constExps,
                this.rightBrackets, this.eq, this.constInitVal);
        return constDef;
    }

}
