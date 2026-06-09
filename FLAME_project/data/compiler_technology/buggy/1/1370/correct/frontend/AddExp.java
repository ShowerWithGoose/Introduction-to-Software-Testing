package frontend;

import java.util.ArrayList;
import java.util.HashMap;

public class AddExp implements Node{
    private GiveTokener giveTokener = GiveTokener.getInstance();

    ArrayList<Node> nodes = new ArrayList<>();

    public Token parser(Token token){
        MulExp mulExp = new MulExp();
        MulExp mulExp1 = null;
        Token token1 = mulExp.parser(token);
        nodes.add(mulExp);
        if(token1 == null){
            System.out.println("error!:in AddExp.parserAddExp in line 21");
            return null;
        }
        while(token1.getTokenType() == TokenType.PLUS||token1.getTokenType() == TokenType.MINU){
            nodes.add(token1);
            Token token2 = getAToken();
            if(token2 == null){
                System.out.println("error!:in AddExp.parserAddExp in line 21");
                return null;
            }
            if(token2.getTokenType()== TokenType.LPARENT || token2.getTokenType() == TokenType.IDENFR || token2.getTokenType() ==TokenType.INTCON || token2.getTokenType() ==TokenType.CHRCON || token2.getTokenType() == TokenType.MINU||token2.getTokenType() == TokenType.PLUS||token2.getTokenType() == TokenType.NOT){
                mulExp1 = new MulExp();
                nodes.add(mulExp1);
                token1 = mulExp1.parser(token2);
            }else{
                System.out.println("error!:in AddExp.parserAddExp in line 33");
                return token2;
            }
        }
        return token1;
    }
    public void printToFile() {
        for(int i=0;i<nodes.size();i++){
            nodes.get(i).printToFile();
            if(i!=nodes.size()-1&& nodes.get(i) instanceof MulExp){
                WriteIntoF.getInstance().writeToFile(true, "" + "<AddExp>" + "\n");
            }
        }
        WriteIntoF.getInstance().writeToFile(true, "" + "<AddExp>" + "\n");
    }

    public Token getAToken(){
        return giveTokener.getAToken();
    }

    public void putBackAToken(Token token){
        giveTokener.putBackAToken(token);
    }
}
