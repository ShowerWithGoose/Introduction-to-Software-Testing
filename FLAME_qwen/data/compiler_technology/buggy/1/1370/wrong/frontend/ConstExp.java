package frontend;

import java.util.ArrayList;

public class ConstExp implements Node{

    private GiveTokener giveTokener = GiveTokener.getInstance();
    private ArrayList<Node> nodes = new ArrayList<>();

    public Token parser(Token token){
        AddExp addExp = new AddExp();
        Token token1 = addExp.parser(token);
        nodes.add(addExp);
        return token1;
    }

    public void printToFile(){
        for(int i=0;i<nodes.size();i++){
            nodes.get(i).printToFile();
        }
        WriteIntoF.getInstance().writeToFile(true, "" + "<ConstExp>" + "\n");
    }

    public Token getAToken(){
        return giveTokener.getAToken();
    }

    public void putBackAToken(Token token){
        giveTokener.putBackAToken(token);
    }
}
