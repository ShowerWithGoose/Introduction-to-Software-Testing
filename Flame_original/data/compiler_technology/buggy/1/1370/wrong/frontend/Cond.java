package frontend;

import java.util.ArrayList;

public class Cond implements Node{

    private ArrayList<Node> nodes = new ArrayList<>();
    public Token parser(Token token){
        LOrExp lOrExp = new LOrExp();
        Token token1=lOrExp.parser(token);
        nodes.add(lOrExp);
        return token1;
    }

    public void printToFile(){
        for(int i=0;i<nodes.size();i++){
            nodes.get(i).printToFile();
        }
        WriteIntoF.getInstance().writeToFile(true, "" + "<Cond>" + "\n");
    }

    public static Boolean isCondFirst(Token token){
        return Exp.isFirstExp(token);
    }
}
