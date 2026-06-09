package frontend;

import java.util.ArrayList;
import java.util.HashMap;

public class MulExp implements Node{
    private GiveTokener giveTokener = GiveTokener.getInstance();
    ArrayList<Node> nodes = new ArrayList<>();
    public Token parser(Token token){
        UnaryExp unaryExp = new UnaryExp();
        UnaryExp unaryExp1 = null;
        Token token1 = unaryExp.parser(token);
        nodes.add(unaryExp);
        while(token1.getTokenType() == TokenType.DIV||token1.getTokenType() == TokenType.MOD||token1.getTokenType() == TokenType.MULT){
            nodes.add(token1);
            Token token2 = getAToken();
            if(token2 == null){
                System.out.println("error!:in MulExp.parserMulExp in line 21");
                return null;
            }
            if(token2.getTokenType()== TokenType.LPARENT || token2.getTokenType() == TokenType.IDENFR || token2.getTokenType() ==TokenType.INTCON || token2.getTokenType() ==TokenType.CHRCON || token2.getTokenType() == TokenType.MINU||token2.getTokenType() == TokenType.PLUS|| token2.getTokenType() == TokenType.NOT){
                unaryExp1 = new UnaryExp();
                token1 = unaryExp1.parser(token2);
                nodes.add(unaryExp1);
            }else{
                System.out.println("error!:in MulExp.parserMulExp in line 29");
                return token2;
            }
        }
        return token1;
    }

    public void printToFile() {
        for(int i=0;i<nodes.size();i++){
            nodes.get(i).printToFile();
            if(i!=nodes.size()-1&& nodes.get(i) instanceof UnaryExp){
                WriteIntoF.getInstance().writeToFile(true, "" + "<MulExp>" + "\n");
            }
        }
        WriteIntoF.getInstance().writeToFile(true, "" + "<MulExp>" + "\n");
    }

    public Token getAToken(){
        return giveTokener.getAToken();
    }

    public void putBackAToken(Token token){
        giveTokener.putBackAToken(token);
    }
}
