package frontend;

import java.util.ArrayList;

public class RelExp implements Node{
    private GiveTokener giveTokener = GiveTokener.getInstance();

    private ArrayList<Node> nodes = new ArrayList<>();

    public Token parser(Token token){
        AddExp addExp = new AddExp();
        Token token1 = addExp.parser(token);
        nodes.add(addExp);
        if(token1==null){
            return null;
        }
        while(token1.getTokenType() == TokenType.GRE||token1.getTokenType() == TokenType.LSS || token1.getTokenType()==TokenType.GEQ||token1.getTokenType() == TokenType.LEQ){
            nodes.add(token1);
            Token token2 = getAToken();
            if (token2 == null) {
                System.out.println("error:in RelExp.parserRelExp in line 21");
                return null;
            }
            if(!(Exp.isFirstExp(token2))){
                System.out.println("error:in RelExp.parserRelExp in line 25");
                return token2;
            }
            AddExp addExp1 = new AddExp();
            token1 = addExp1.parser(token2);
            nodes.add(addExp1);
        }
        return token1;
    }

    public void printToFile(){
        for(int i=0;i<nodes.size();i++){
            nodes.get(i).printToFile();
            if(i!=nodes.size()-1&& nodes.get(i) instanceof AddExp){
                WriteIntoF.getInstance().writeToFile(true, "" + "<RelExp>" + "\n");
            }
        }
        WriteIntoF.getInstance().writeToFile(true, "" + "<RelExp>" + "\n");
    }

    public Token getAToken(){
        return giveTokener.getAToken();
    }

    public void putBackAToken(Token token){
        giveTokener.putBackAToken(token);
    }
}
