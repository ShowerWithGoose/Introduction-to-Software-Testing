package frontend.ParserPart.decl.variable;

import frontend.ErrorPart.Error;
import frontend.ErrorPart.ErrorList;
import frontend.ErrorPart.ErrorType;
import frontend.Factor;
import frontend.ParserPart.decl.variable.varinitval.InitVal;
import frontend.ParserPart.expr.ConstExp;
import frontend.ParserPart.term.Ident;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

public class VarDef implements Factor {
    private String name = "<VarDef>";
    private TokenList tokenList;
    private Ident ident;
    private Token leftBRACK;//可能存在
    private ConstExp constExp;//可能存在
    private Token rightBRACK;//可能存在
    private Token equal;//分情况存在
    private InitVal initVal;//分情况存在
    public VarDef(TokenList tokenList){
        this.tokenList = tokenList;
        ident = new Ident(tokenList);
        leftBRACK = null;
        constExp = null;
        rightBRACK = null;
        equal = null;
        initVal = null;
    }
    public void parseVarDef(){
        ident.parseIdent();
        if (tokenList.peek().getType().equals(TokenType.LBRACK)){
            //如果有可选部分
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
        if (tokenList.peek().getType().equals(TokenType.ASSIGN)){
            equal = new Token(TokenType.ASSIGN,"=");
            tokenList.next();
            initVal = new InitVal(tokenList);
            initVal.parseInitVal();
        }
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
        if (equal != null){
            sb.append(equal.toString());
            sb.append(initVal.toString());
        }
        sb.append(name);
        sb.append("\n");
        return sb.toString();
    }
}
