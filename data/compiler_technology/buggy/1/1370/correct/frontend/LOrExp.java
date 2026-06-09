package frontend;

import java.util.ArrayList;

public class LOrExp implements Node{
    private GiveTokener giveTokener = GiveTokener.getInstance();

    private ArrayList<Node> nodes = new ArrayList<>();

    public Token parser(Token token){
        LandExp landExp = new LandExp();
        Token token1 = landExp.parser(token);
        nodes.add(landExp);
        if(token1==null){
            return null;
        }
        while(token1.getTokenType() == TokenType.OR ){
            nodes.add(token1);
            Token token2 = getAToken();
            if (token2 == null) {
                System.out.println("error!:in LOrExp.parserLOrExp in line 19");
                return null;
            }
            if(!(Exp.isFirstExp(token2))){
                System.out.println("error!:in LOrExp.parserLOrExp in line 23");
                return token2;
            }
            LandExp landExp1 = new LandExp();
            token1 = landExp1.parser(token2);
            nodes.add(landExp1);
        }
        return token1;
    }

    public void printToFile(){
        for(int i=0;i<nodes.size();i++){
            nodes.get(i).printToFile();
            if(i!=nodes.size()-1&& nodes.get(i) instanceof LandExp){
                WriteIntoF.getInstance().writeToFile(true, "" + "<LOrExp>" + "\n");
            }
        }
        WriteIntoF.getInstance().writeToFile(true, "" + "<LOrExp>" + "\n");
    }

    public Token getAToken(){
        return giveTokener.getAToken();
    }

    public void putBackAToken(Token token){
        giveTokener.putBackAToken(token);
    }
}
