package frontend;

import java.util.ArrayList;

public class FuncRParams implements Node{
    private GiveTokener giveTokener = GiveTokener.getInstance();

    private ArrayList<Node> nodes = new ArrayList<>();

    public Token parser(Token token){
        Exp exp = new Exp();
        Token token1 = exp.parser(token);
        nodes.add(exp);
        if(token1 == null){
            return null;
        }
        while(token1.getTokenType() == TokenType.COMMA){
            nodes.add(token1);
            token1 = getAToken();
            if(token1 == null){
                System.out.println("error!:in FuncRParams.parserFuncRParams in line 19");
                return null;
            }if(Exp.isFirstExp(token1)){
                Exp exp1 = new Exp();
                token1 = exp1.parser(token1);
                nodes.add(exp1);
            }else{
                System.out.println("error!:in FuncRParams.parserFuncRParams in line 26");
                return token1;
            }
        }
        return token1;
    }

    public void printToFile(){
        for(int i=0;i<nodes.size();i++){
            nodes.get(i).printToFile();
        }
        WriteIntoF.getInstance().writeToFile(true, "" + "<FuncRParams>" + "\n");
    }

    public static Boolean isFuncRParamsFirst(Token token){
        return Exp.isFirstExp(token);
    }

    public Token getAToken(){
        return giveTokener.getAToken();
    }

    public void putBackAToken(Token token){
        giveTokener.putBackAToken(token);
    }
}
