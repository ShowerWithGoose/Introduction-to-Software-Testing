package frontend.ParserPart.decl.variable.varinitval;

import frontend.ParserPart.expr.Exp;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

import java.util.ArrayList;

public class InitValMul implements InitValInterface{
    private TokenList tokenList;
    private Token leftBRACE;
    private Exp exp;//可能存在
    private ArrayList<Token> commas;//可能存在一系列逗号
    private ArrayList<Exp> expArrayList;//可能存在一系列的Exp
    private Token rightBRACE;

    public InitValMul(TokenList tokenList){
        this.tokenList = tokenList;
        leftBRACE = new Token(TokenType.LBRACE,"{");
        exp = null;
        commas = new ArrayList<>();
        expArrayList = new ArrayList<>();
        rightBRACE = new Token(TokenType.RBRACE,"}");
    }
    public void parseInitValMul(){
        //指向{符号
        tokenList.next();
        if (!tokenList.peek().getType().equals(TokenType.RBRACE)){
            //说明有可选项
            exp = new Exp(tokenList);
            exp.parseExp();
            while (tokenList.peek().getType().equals(TokenType.COMMA)){
                //说明有重复项
                Token token = new Token(TokenType.COMMA,",");
                commas.add(token);
                tokenList.next();
                Exp tem = new Exp(tokenList);
                tem.parseExp();
                expArrayList.add(tem);
            }
        }
        //指向}符号
        tokenList.next();
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(leftBRACE.toString());
        if (exp != null){
            sb.append(exp.toString());
            for (int i = 0; i < commas.size(); i++) {
                sb.append(commas.get(i).toString());
                sb.append(expArrayList.get(i).toString());
            }
        }
        sb.append(rightBRACE.toString());
        return sb.toString();
    }
}
