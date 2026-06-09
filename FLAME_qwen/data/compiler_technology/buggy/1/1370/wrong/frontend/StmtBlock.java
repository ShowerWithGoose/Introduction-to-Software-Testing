package frontend;

import java.util.ArrayList;

public class StmtBlock implements Node{
    private ArrayList<Node> nodes = new ArrayList<>();

    public Token parser(Token token){
        Block block = new Block();
        block.parser(token);
        nodes.add(block);
        return getAToken();
    }
    public void printToFile(){
        for(int i=0;i<nodes.size();i++){
            nodes.get(i).printToFile();
        }
        WriteIntoF.getInstance().writeToFile(true, "" + "<Stmt>" + "\n");
    }
    public void reportErrori(int lineno){
        WriteIntoF.getInstance().writeToFile(false,ErrorType.i+" "+lineno+"\n");
    }
    public Token getAToken(){
        return GiveTokener.getInstance().getAToken();
    }

    public void putBackAToken(Token token){
        GiveTokener.getInstance().putBackAToken(token);
    }
}
