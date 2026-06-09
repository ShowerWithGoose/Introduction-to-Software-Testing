package frontend.parser.expression.unaryexp;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.FuncRParams;
import frontend.parser.expression.FuncRParamsParser;
import frontend.parser.terminal.Ident;
import frontend.parser.terminal.IdentParser;

import java.util.ArrayList;

public class UnaryExpFuncParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    /* UnaryExpFunc Attributes */
    public Ident ident = null;
    public FuncRParams funcRParams = null;
    public Token leftParent; // '('
    public Token rightParent; // ')'
    public UnaryExpFunc unaryExpFunc = null;

    public UnaryExpFuncParser(TokenListIterator iterator, ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }

    public UnaryExpFunc parseUnaryFuncExp() {
        IdentParser identParser = new IdentParser(this.iterator,this.error_tokens);
        this.ident = identParser.parseIdent();
        this.leftParent = this.iterator.readNextToken();

        Token token =this.iterator.readNextToken();
        if (token.type.equals(TokenType.LPARENT) ||
                token.type.equals(TokenType.IDENFR) ||
                token.type.equals(TokenType.INTCON) ||
                token.type.equals(TokenType.CHRCON) ||
                token.type.equals(TokenType.PLUS) ||
                token.type.equals(TokenType.MINU) ||
                token.type.equals(TokenType.NOT)) {
            this.iterator.unReadToken(1);
            FuncRParamsParser funcRParamsParser = new FuncRParamsParser(this.iterator,this.error_tokens);
            this.funcRParams = funcRParamsParser.parseFuncRParams();
            Token token1 =this.iterator.readNextToken();
            if(!token1.type.equals(TokenType.RPARENT)) {
                this.iterator.unReadToken(1);
                this.rightParent = new Token(TokenType.RPARENT,this.funcRParams.my_line_num(),")");
                this.error_tokens.add(new Token(TokenType.RPARENT,this.funcRParams.my_line_num(),"j"));
            }else{
                this.rightParent=token1;
            }
            unaryExpFunc = new UnaryExpFunc(this.ident, this.funcRParams,
                    this.leftParent, this.rightParent);
        } else {
            if(!token.type.equals(TokenType.RPARENT)){
                this.iterator.unReadToken(1);
                this.rightParent = new Token(TokenType.RPARENT,this.leftParent.linenum,")");
                this.error_tokens.add(new Token(TokenType.RPARENT,this.leftParent.linenum,"j"));
            }else{
                this.rightParent= token;
            }
            unaryExpFunc = new UnaryExpFunc(this.ident, this.leftParent, this.rightParent);
        }
        return unaryExpFunc;
    }
}
