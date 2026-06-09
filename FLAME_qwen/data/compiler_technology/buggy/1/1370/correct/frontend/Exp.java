package frontend;

import java.util.ArrayList;

public class Exp implements Node{
    private GiveTokener giveTokener = GiveTokener.getInstance();
    private ArrayList<Node> nodes = new ArrayList<>();

    public Token parser(Token token){
        AddExp addExp = new AddExp();
        Token token1 = addExp.parser(token);
        nodes.add(addExp);
        return token1;
    }

    public void printToFile() {
        for(int i=0;i<nodes.size();i++){
            nodes.get(i).printToFile();
        }
        WriteIntoF.getInstance().writeToFile(true, "" + "<Exp>" + "\n");
    }
    public static Boolean isFirstExp(Token token2){
        if(token2.getTokenType()== TokenType.LPARENT || token2.getTokenType() == TokenType.IDENFR || token2.getTokenType() ==TokenType.INTCON || token2.getTokenType() ==TokenType.CHRCON || token2.getTokenType() == TokenType.MINU||token2.getTokenType() == TokenType.PLUS||token2.getTokenType() == TokenType.NOT){
            return true;
        }
        return false;
    }

    public Token getAToken(){
        return giveTokener.getAToken();
    }

    public void putBackAToken(Token token){
        giveTokener.putBackAToken(token);
    }

}
