package frontend.ParserPart.expr.primaryexp;

import frontend.Factor;
import frontend.ParserPart.expr.unaryexp.UnaryExpInterface;
import frontend.ParserPart.term.IntConst;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

public class PrimaryExp implements UnaryExpInterface {
    private String name = "<PrimaryExp>";
    private TokenList tokenList;
    private PrimaryExpInterface primaryExpInterface;
    public PrimaryExp(TokenList tokenList){
        this.tokenList = tokenList;
        primaryExpInterface = null;
    }
    public void parsePrimaryExp(){
        Token token = tokenList.peek();
        if (token.getType().equals(TokenType.LPARENT)){
            //(开头
            PrimaryExpMul primaryExpMul = new PrimaryExpMul(tokenList);
            primaryExpMul.parsePrimaryExpMul();
            primaryExpInterface = primaryExpMul;
        } else if (token.getType().equals(TokenType.IDENFR)) {
            //Ident开头，LVal情况
            LVal lVal = new LVal(tokenList);
            lVal.parseLVal();
            primaryExpInterface = lVal;
        } else if (token.getType().equals(TokenType.INTCON)) {
            //intConst开头，对应Number情况
            Number number = new Number(tokenList);
            number.parseNumber();
            primaryExpInterface = number;
        }else {
            //Character情况
            Character character = new Character(tokenList);
            character.parseCharacter();
            primaryExpInterface = character;
        }
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(primaryExpInterface.toString());
        sb.append(name);
        sb.append("\n");
        return sb.toString();
    }
}
