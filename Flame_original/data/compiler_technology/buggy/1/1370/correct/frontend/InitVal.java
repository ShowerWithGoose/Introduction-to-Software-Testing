package frontend;

import java.util.ArrayList;

public class InitVal implements Node{
    private GiveTokener giveTokener = GiveTokener.getInstance();
    private ArrayList<Node> nodes = new ArrayList<>();

    public Token parser(Token token){
        if(token.getTokenType() == TokenType.LBRACE){
            nodes.add(token);
            Token token1 = getAToken();
            if(token1 == null){
                System.out.println("error!:in InitVal.parserInitVal in line 13");
            }
            if(token1.getTokenType() == TokenType.LPARENT || token1.getTokenType() == TokenType.IDENFR || token1.getTokenType() == TokenType.INTCON || token1.getTokenType() == TokenType.CHRCON || token1.getTokenType() == TokenType.MINU || token1.getTokenType() == TokenType.PLUS|| token1.getTokenType() == TokenType.NOT){
                Exp exp = new Exp();
                nodes.add(exp);
                token = exp.parser(token1);
                if(token == null){
                    System.out.println("error!:in InitVal.parserInitVal in line 20");
                    return null;
                }
            }else{
                System.out.println("error!:in InitVal.parserInitVal in line 24");
                return token1;
            }
            while(token.getTokenType() == TokenType.COMMA){
                nodes.add(token);
                token1 = getAToken();
                if(token1 == null){
                    System.out.println("error!:in InitVal.parserInitVal in line 30");
                    return null;
                }
                if(token1.getTokenType() == TokenType.LPARENT || token1.getTokenType() == TokenType.IDENFR || token1.getTokenType() == TokenType.INTCON || token1.getTokenType() == TokenType.CHRCON || token1.getTokenType() == TokenType.MINU || token1.getTokenType() == TokenType.PLUS|| token1.getTokenType() == TokenType.NOT){
                    Exp exp = new Exp();
                    nodes.add(exp);
                    token = exp.parser(token1);
                    if(token == null){
                        System.out.println("error!:in InitVal.parserInitVal in line 38");
                        return null;
                    }
                }else{
                    System.out.println("error!:in InitVal.parserInitVal in line 42");
                    return token1;
                }
            }
            if(token.getTokenType()!=TokenType.RBRACE){
                System.out.println("error!:in InitVal.parserInitVal in line 47");
                return token;
            }
            nodes.add(token);
            return getAToken();
        }else if(token.getTokenType() == TokenType.STRCON){
            nodes.add(token);
            return getAToken();
        }else if(token.getTokenType() == TokenType.LPARENT || token.getTokenType() == TokenType.IDENFR || token.getTokenType() == TokenType.INTCON || token.getTokenType() == TokenType.CHRCON || token.getTokenType() == TokenType.MINU || token.getTokenType() == TokenType.PLUS|| token.getTokenType() == TokenType.NOT){
            Exp exp = new Exp();
            Token token1 = exp.parser(token);
            nodes.add(exp);
            return token1;
        }else{
            System.out.println("error!:in InitVal.parserInitVal in line 63");
            return token;
        }
    }

    public void printToFile(){
        for(int i=0;i<nodes.size();i++){
            nodes.get(i).printToFile();
        }
        WriteIntoF.getInstance().writeToFile(true, "" + "<InitVal>" + "\n");
    }

    public Token getAToken(){
        return giveTokener.getAToken();
    }

    public void putBackAToken(Token token){
        giveTokener.putBackAToken(token);
    }
}
