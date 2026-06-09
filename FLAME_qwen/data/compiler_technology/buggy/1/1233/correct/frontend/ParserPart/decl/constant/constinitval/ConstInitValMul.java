package frontend.ParserPart.decl.constant.constinitval;

import frontend.ParserPart.expr.ConstExp;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

import java.util.ArrayList;

public class ConstInitValMul implements ConstInitValInterface{
    private TokenList tokenList;
    private Token leftBRACE;
    private ConstExp constExp;//可能存在
    private ArrayList<Token> commas;//可能存在
    private ArrayList<ConstExp> constExpArrayList;//可能存在
    private Token rightBRACE;
    public ConstInitValMul(TokenList tokenList){
        this.tokenList = tokenList;
        leftBRACE = new Token(TokenType.LBRACE,"{");
        constExp = null;
        commas = new ArrayList<>();
        constExpArrayList = new ArrayList<>();
        rightBRACE = new Token(TokenType.RBRACE,"}");
    }
    public void parserConstExpMul(){
        //指向{
        tokenList.next();
        if (!tokenList.peek().getType().equals(TokenType.RBRACE)){
            constExp = new ConstExp(tokenList);
            constExp.parseConstExp();
            while (tokenList.peek().getType().equals(TokenType.COMMA)){
                //指向,
                Token token = new Token(TokenType.COMMA,",");
                commas.add(token);
                tokenList.next();
                ConstExp tem = new ConstExp(tokenList);
                tem.parseConstExp();
                constExpArrayList.add(tem);
            }
        }
        //指向}
        tokenList.next();
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(leftBRACE.toString());
        if (constExp != null){
            sb.append(constExp.toString());
            for (int i = 0; i < commas.size(); i++) {
                sb.append(commas.get(i).toString());
                sb.append(constExpArrayList.get(i).toString());
            }
        }
        sb.append(rightBRACE.toString());
        return sb.toString();
    }
}
