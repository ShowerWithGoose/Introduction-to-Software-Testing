package frontend;

import java.util.ArrayList;

public class MyCharacter implements Node{
    private GiveTokener giveTokener = GiveTokener.getInstance();
    ArrayList<Node> nodes = new ArrayList<>();
    public Token parser(Token token){
        nodes.add(token);
        return getAToken();
    }

    public void printToFile() {
        for(int i=0;i<nodes.size();i++){
            nodes.get(i).printToFile();
        }
        WriteIntoF.getInstance().writeToFile(true, "" + "<Character>" + "\n");
    }

    public Token getAToken(){
        return giveTokener.getAToken();
    }

    public void putBackAToken(Token token){
        giveTokener.putBackAToken(token);
    }
}
