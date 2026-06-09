package frontend;

import java.util.ArrayList;

public class PrimaryExp implements Node{
    private GiveTokener giveTokener = GiveTokener.getInstance();
    private ArrayList<Node> nodes = new ArrayList<>();
    private int errorline = 0;


    public Token parser(Token token2) {
        if(token2.getTokenType() == TokenType.LPARENT){
            nodes.add(token2);
            token2 = getAToken();
            if(token2 == null){
                return null;
            }
            if (token2.getTokenType() == TokenType.LPARENT || token2.getTokenType() == TokenType.IDENFR || token2.getTokenType() == TokenType.INTCON || token2.getTokenType() == TokenType.CHRCON || token2.getTokenType() == TokenType.MINU || token2.getTokenType() == TokenType.PLUS|| token2.getTokenType() == TokenType.NOT) {
                Exp exp = new Exp();
                errorline = token2.getLineno();
                Token token1 = exp.parser(token2);
                nodes.add(exp);
                if (token1 == null) {
                    return null;
                }
                if (token1.getTokenType() != TokenType.RPARENT) {
                    reportError(errorline);
                    return token1;
                }
                nodes.add(token1);
                return getAToken();
            }else {
                return token2;
            }
        }else if(token2.getTokenType() == TokenType.IDENFR){
            LVal lVal = new LVal();
            Token token = lVal.parser(token2);
            nodes.add(lVal);
            return token;
        }else if(token2.getTokenType() == TokenType.INTCON){
            Number number = new Number();
            Token token = number.parser(token2);
            nodes.add(number);
            return token;
        }else if(token2.getTokenType() == TokenType.CHRCON){
            MyCharacter myCharacter = new MyCharacter();
            Token token = myCharacter.parser(token2);
            nodes.add(myCharacter);
            return token;
        }else{
            return token2;
        }
    }

    public static Boolean isPrimaryExpFirst(Token token){
        if(token.getTokenType() == TokenType.LPARENT||token.getTokenType() == TokenType.IDENFR || token.getTokenType() ==TokenType.INTCON || token.getTokenType() ==TokenType.CHRCON){
            return true;
        }
        return false;
    }


    public void reportError(int lineno){
        WriteIntoF.getInstance().writeToFile(false,lineno+" "+ErrorType.j+"\n");
    }
    public void printToFile() {
        for(int i=0;i<nodes.size();i++){
            nodes.get(i).printToFile();
        }
        WriteIntoF.getInstance().writeToFile(true, "" + "<PrimaryExp>" + "\n");
    }

    public Token getAToken(){
        return giveTokener.getAToken();
    }

    public void putBackAToken(Token token){
        giveTokener.putBackAToken(token);
    }
}
