package frontend.ParserPart.decl.constant;

import frontend.ErrorPart.Error;
import frontend.ErrorPart.ErrorList;
import frontend.ErrorPart.ErrorType;
import frontend.Factor;
import frontend.ParserPart.decl.constant.constinitval.ConstInitval;
import frontend.ParserPart.expr.ConstExp;
import frontend.ParserPart.term.Ident;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

public class ConstDef implements Factor {
    private String name = "<ConstDef>";
    private TokenList tokenList;
    private Ident ident;
    private Token leftBRACK;//可能没有
    private ConstExp constExp;//可能没有
    private Token rightBRACK;//可能没有
    private Token equal;//代表=
    private ConstInitval constInitval;
    public ConstDef(TokenList tokenList){
        this.tokenList = tokenList;
        ident = new Ident(tokenList);
        leftBRACK = null;
        constExp = null;
        rightBRACK = null;
        equal = new Token(TokenType.ASSIGN,"=");
        constInitval = new ConstInitval(tokenList);
    }

    public void parserConstDef(){
        ident.parseIdent();
        if (tokenList.peek().getType().equals(TokenType.LBRACK)){
            leftBRACK = new Token(TokenType.LBRACK,"[");
            tokenList.next();
            constExp = new ConstExp(tokenList);
            constExp.parseConstExp();
            if (tokenList.peek().getType().equals(TokenType.RBRACK)){
            rightBRACK = new Token(TokenType.RBRACK,"]");
            tokenList.next(); }
            else {
                Error error = new Error(ErrorType.k,tokenList.preRead(-1).getLineNum());
                ErrorList.addError(error);
            }
        }
        //指向=号
        tokenList.next();
        constInitval.parserConstInitval();
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(ident.toString());
        if (leftBRACK != null){
            sb.append(leftBRACK.toString());
            sb.append(constExp.toString());
            sb.append(rightBRACK.toString());
        }
        sb.append(equal.toString());
        sb.append(constInitval.toString());
        sb.append(name);
        sb.append("\n");
        return sb.toString();
    }
}
