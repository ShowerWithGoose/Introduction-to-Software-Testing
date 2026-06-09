package frontend.ParserPart.func;

import frontend.Factor;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

import java.util.ArrayList;

public class FuncFParams implements Factor {
    private String name = "<FuncFParams>";
    private TokenList tokenList;
    private FuncFParam funcFParam;//代表开头第一个
    private ArrayList<Token> commas;//可能有一系列逗号
    private ArrayList<FuncFParam> funcFParamArrayList;//可能有一系列的funcfparam
    public FuncFParams(TokenList tokenList){
        this.tokenList = tokenList;
        funcFParam = new FuncFParam(tokenList);
        commas = new ArrayList<>();
        funcFParamArrayList = new ArrayList<>();
    }
    public void parseFuncParams(){
        funcFParam.parseFuncFParam();
        while (tokenList.peek().getType().equals(TokenType.COMMA)){
            //存在一系列可选项
            Token token = new Token(TokenType.COMMA,",");
            commas.add(token);
            tokenList.next();
            FuncFParam tem = new FuncFParam(tokenList);
            tem.parseFuncFParam();
            funcFParamArrayList.add(tem);
        }
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(funcFParam.toString());
        for (int i = 0; i < commas.size(); i++) {
            sb.append(commas.get(i).toString());
            sb.append(funcFParamArrayList.get(i).toString());
        }
        sb.append(name);
        sb.append("\n");
        return sb.toString();
    }
}
