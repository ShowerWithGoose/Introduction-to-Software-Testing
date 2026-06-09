package frontend;

import java.util.ArrayList;

public class UnaryOp implements Node{

    private GiveTokener giveTokener = GiveTokener.getInstance();

    private ArrayList<Node> nodes = new ArrayList<>();

    public Token parser(Token token){
        if(token.getTokenType() == TokenType.PLUS||token.getTokenType() == TokenType.MINU||token.getTokenType() == TokenType.NOT){
            //DONE!!!
            nodes.add(token);
        }
        //error!!!
        return getAToken();
    }

    public void printToFile() {
        for(int i=0;i<nodes.size();i++){
            nodes.get(i).printToFile();
        }
        WriteIntoF.getInstance().writeToFile(true, "" + "<UnaryOp>" + "\n");
    }


    public Token getAToken(){
        return giveTokener.getAToken();
    }

    public void putBackAToken(Token token){
        giveTokener.putBackAToken(token);
    }
}
