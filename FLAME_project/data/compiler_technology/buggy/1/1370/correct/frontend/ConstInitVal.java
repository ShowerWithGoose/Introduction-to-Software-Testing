package frontend;

import java.util.ArrayList;

public class ConstInitVal implements Node{

    private GiveTokener giveTokener = GiveTokener.getInstance();
    private ArrayList<Node> nodes = new ArrayList<>();

    public Token parser(Token token){

        if(token.getTokenType() == TokenType.LBRACE){
            nodes.add(token);
            Token token1 = getAToken();
            if(token1 == null){
                System.out.println("error!:in ConstInitVal.parserConstInitVal in line 14");
            }
            if(token1.getTokenType() == TokenType.LPARENT || token1.getTokenType() == TokenType.IDENFR || token1.getTokenType() == TokenType.INTCON || token1.getTokenType() == TokenType.CHRCON || token1.getTokenType() == TokenType.MINU || token1.getTokenType() == TokenType.PLUS|| token1.getTokenType() == TokenType.NOT){
                ConstExp constExp = new ConstExp();
                nodes.add(constExp);
                token = constExp.parser(token1);
            }else if(token1.getTokenType()==TokenType.RBRACE){
                nodes.add(token1);
                return getAToken();
            } else{
                System.out.println("error!:in ConstInitVal.parserConstInitVal in line 21");
                return token1;
            }
            while(token.getTokenType() == TokenType.COMMA){
                nodes.add(token);
                token1 = getAToken();
                if (token1 == null){
                    System.out.println("error!:in ConstInitVal.parserConstInitVal in line 27");
                    return null;
                }
                if(token1.getTokenType() == TokenType.LPARENT || token1.getTokenType() == TokenType.IDENFR || token1.getTokenType() == TokenType.INTCON || token1.getTokenType() == TokenType.CHRCON || token1.getTokenType() == TokenType.MINU || token1.getTokenType() == TokenType.PLUS|| token1.getTokenType() == TokenType.NOT){
                    ConstExp constExp = new ConstExp();
                    nodes.add(constExp);
                    token = constExp.parser(token1);
                }else{
                    System.out.println("error!:in ConstInitVal.parserConstInitVal in line 35");
                    return token1;
                }
            }
            if(token.getTokenType()!=TokenType.RBRACE){
                System.out.println("error!:in ConstInitVal.parserConstInitVal in line 40");
            }
            nodes.add(token);
            return getAToken();
        }else if(token.getTokenType() == TokenType.STRCON){
            nodes.add(token);
            return getAToken();
        }else if(token.getTokenType() == TokenType.LPARENT || token.getTokenType() == TokenType.IDENFR || token.getTokenType() == TokenType.INTCON || token.getTokenType() == TokenType.CHRCON || token.getTokenType() == TokenType.MINU || token.getTokenType() == TokenType.PLUS|| token.getTokenType() == TokenType.NOT){
            ConstExp constExp = new ConstExp();
            nodes.add(constExp);
            Token token1 = constExp.parser(token);
            return token1;
        }else{
            System.out.println("error!:in ConstInitVal.parserConstInitVal in line 54");
            return token;
        }
    }

    public void printToFile(){
        for(int i=0;i<nodes.size();i++){
            nodes.get(i).printToFile();
        }
        WriteIntoF.getInstance().writeToFile(true, "" + "<ConstInitVal>" + "\n");
    }

    public Token getAToken(){
        return giveTokener.getAToken();
    }

    public void putBackAToken(Token token){
        giveTokener.putBackAToken(token);
    }
}
