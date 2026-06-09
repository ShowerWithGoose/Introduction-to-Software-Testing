package frontend;

import java.util.ArrayList;

public class LandExp implements Node{
    private GiveTokener giveTokener = GiveTokener.getInstance();

    private ArrayList<Node> nodes = new ArrayList<>();

    public Token parser(Token token){
        EqExp eqExp = new EqExp();
        Token token1 = eqExp.parser(token);
        nodes.add(eqExp);
        if(token1==null){
            return null;
        }
        while(token1.getTokenType() == TokenType.AND){
            nodes.add(token1);
            Token token2 = getAToken();
            if (token2 == null) {
                System.out.println("error!:in LandExp.parserLandExp in line 19");
                return null;
            }
            if(!(Exp.isFirstExp(token2))){
                System.out.println("error!:in LandExp.parserLandExp in line 23");
                return token2;
            }
            EqExp eqExp1 = new EqExp();
            token1 = eqExp1.parser(token2);
            nodes.add(eqExp1);
        }
        return token1;
    }

    public void printToFile(){
        for(int i=0;i<nodes.size();i++){
            nodes.get(i).printToFile();
            if(i!=nodes.size()-1&& nodes.get(i) instanceof EqExp){
                WriteIntoF.getInstance().writeToFile(true, "" + "<LAndExp>" + "\n");
            }
        }
        WriteIntoF.getInstance().writeToFile(true, "" + "<LAndExp>" + "\n");
    }


    public Token getAToken(){
        return giveTokener.getAToken();
    }

    public void putBackAToken(Token token){
        giveTokener.putBackAToken(token);
    }
}
