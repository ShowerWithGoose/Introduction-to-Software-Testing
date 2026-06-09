package frontend;

import java.util.ArrayList;

public class EqExp implements Node{
    private GiveTokener giveTokener = GiveTokener.getInstance();
    private ArrayList<Node> nodes = new ArrayList<>();

    public Token parser(Token token){
        RelExp relExp = new RelExp();
        Token token1 = relExp.parser(token);
        nodes.add(relExp);
        if(token1==null){
            return null;
        }
        while(token1.getTokenType() == TokenType.EQL||token1.getTokenType() == TokenType.NEQ){
            nodes.add(token1);
            Token token2 = getAToken();
            if (token2 == null) {
                System.out.println("error!:in EqExp.parserEqExp in line 19");
                return null;
            }
            if(!(Exp.isFirstExp(token2))){
                System.out.println("error!:in EqExp.parserEqExp in line 23");
                return token2;
            }
            RelExp relExp1 = new RelExp();
            token1 = relExp1.parser(token2);
            nodes.add(relExp1);
        }
        return token1;
    }

    public void printToFile(){
        for(int i=0;i<nodes.size();i++){
            nodes.get(i).printToFile();
            if(i!=nodes.size()-1&& nodes.get(i) instanceof RelExp){
                WriteIntoF.getInstance().writeToFile(true, "" + "<EqExp>" + "\n");
            }
        }
        WriteIntoF.getInstance().writeToFile(true, "" + "<EqExp>" + "\n");
    }

    public Token getAToken(){
        return giveTokener.getAToken();
    }

    public void putBackAToken(Token token){
        giveTokener.putBackAToken(token);
    }
}
