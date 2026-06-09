package frontend;

import java.util.ArrayList;

public class FuncFParams implements Node{
    private GiveTokener giveTokener = GiveTokener.getInstance();

    ArrayList<Node> nodes = new ArrayList<>();

    public Token parser(Token token){
        FuncFParam funcFParam = new FuncFParam();
        nodes.add(funcFParam);
        Token token1 = funcFParam.parser(token);
        if(token1 == null){
            return null;
        }
        while(token1.getTokenType() == TokenType.COMMA){
            nodes.add(token1);
            token1 = getAToken();
            if(token1 == null){
                System.out.println("error!:in FuncRParams.parserFuncRParams in line 19");
                return null;
            }if(token1.getTokenType()==TokenType.INTTK||token1.getTokenType()==TokenType.CHARTK){
                FuncFParam funcFParam1 = new FuncFParam();
                nodes.add(funcFParam1);
                token1 = funcFParam1.parser(token1);
            }else{
                System.out.println("error!:in FuncRParams.parserFuncRParams in line 26");
                return token1;
            }
        }
        return token1;
    }

    public void printToFile() {
        for(int i=0;i<nodes.size();i++){
            nodes.get(i).printToFile();
        }
        WriteIntoF.getInstance().writeToFile(true, "" + "<FuncFParams>" + "\n");
    }

    public static Boolean isFuncFParamsFirst(Token token){
        return (token.getTokenType()==TokenType.INTTK||token.getTokenType()==TokenType.CHARTK);
    }

    public Token getAToken(){
        return giveTokener.getAToken();
    }

    public void putBackAToken(Token token){
        giveTokener.putBackAToken(token);
    }
}
