package frontend;

import java.nio.channels.UnresolvedAddressException;
import java.util.ArrayList;

public class UnaryExp implements Node{
    private GiveTokener giveTokener = GiveTokener.getInstance();

    private ArrayList<Node> nodes = new ArrayList<>();
    private int errorline = 0;


    public Token parser(Token token){
        boolean flagf = false;
        Token tokenf = GiveTokener.getInstance().preReadAToken();
        if(tokenf.getTokenType() == TokenType.LPARENT){
            flagf = true;
        }
        GiveTokener.getInstance().putBackAToken(tokenf);
        if(PrimaryExp.isPrimaryExpFirst(token)&&!(flagf)){
            PrimaryExp primaryExp = new PrimaryExp();
            Token token1 = primaryExp.parser(token);
            nodes.add(primaryExp);
            return token1;
        }else if(token.getTokenType() == TokenType.IDENFR){
            nodes.add(token);
            Token token1 = getAToken();
            if(token1 == null){
                return null;
            }
            if(token1.getTokenType() != TokenType.LPARENT){
                return token1;
            }
            errorline = token1.getLineno();
            nodes.add(token1);
            token1 = getAToken();
            if(token1 == null){
                return null;
            }
            if(FuncRParams.isFuncRParamsFirst(token1)){
                FuncRParams funcRParams = new FuncRParams();
                errorline = token1.getLineno();
                Token token2 = funcRParams.parser(token1);
                nodes.add(funcRParams);
                if(token2.getTokenType()!=TokenType.RPARENT){
                    reportError(errorline);
                    return token2;
                }
                nodes.add(token2);
                return getAToken();
            }else if(token1.getTokenType() == TokenType.RPARENT){
                nodes.add(token1);
                return getAToken();
            } else{
                reportError(errorline);
                return token1;
            }
        }else if(token.getTokenType() == TokenType.PLUS||token.getTokenType() == TokenType.MINU||token.getTokenType() == TokenType.NOT){
            UnaryOp unaryOp = new UnaryOp();
            Token token1 = unaryOp.parser(token);
            nodes.add(unaryOp);
            if(token1 == null){
                return null;
            }if(UnaryExp.isUnaryExpFirst(token1)){
                UnaryExp unaryExp = new UnaryExp();
                Token token2 = unaryExp.parser(token1);
                nodes.add(unaryExp);
                return token2;
            }else{
                return token1;
            }
        }
        else{
            return token;
        }
    }



    public static Boolean isUnaryExpFirst(Token token){
        if(PrimaryExp.isPrimaryExpFirst(token)||token.getTokenType() == TokenType.IDENFR||token.getTokenType() == TokenType.PLUS||token.getTokenType() == TokenType.MINU||token.getTokenType() == TokenType.NOT){
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
        WriteIntoF.getInstance().writeToFile(true, "" + "<UnaryExp>" + "\n");
    }

    public Token getAToken(){
        return giveTokener.getAToken();
    }

    public void putBackAToken(Token token){
        giveTokener.putBackAToken(token);
    }
}
