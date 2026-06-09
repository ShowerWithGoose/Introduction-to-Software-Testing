package frontend;

import java.util.ArrayList;

public class Block implements Node{
    private GiveTokener giveTokener = GiveTokener.getInstance();
    private ArrayList<Node> nodes = new ArrayList<>();

    public Token parser(Token token){
        nodes.add(token);
        Token tnow0 = getAToken();
        if(tnow0 == null){
            System.out.println("error!:in Block.parserBlock in line 10");
            return null;
        }
        TokenType type = tnow0.getTokenType();
        while(type!=TokenType.RBRACE){
            if(type == TokenType.CONSTTK ){
                ConstDecl constDecl = new ConstDecl();
                nodes.add(constDecl);
                tnow0 = constDecl.parser(tnow0);
                if(tnow0 == null){
                    System.out.println("error!:in Block.parserBlock in line 19");
                    return null;
                }
                type = tnow0.getTokenType();
            }else if(type == TokenType.INTTK || type == TokenType.CHARTK){
                VarDecl varDecl = new VarDecl();
                nodes.add(varDecl);
                tnow0 = varDecl.parser(tnow0);
                if(tnow0 == null){
                    System.out.println("error!:in Block.parserBlock in line 29");
                    return null;
                }
                type = tnow0.getTokenType();
            }
            else if(type == TokenType.SEMICN||type == TokenType.LPARENT||type == TokenType.IDENFR||type == TokenType.CHRCON||type == TokenType.INTCON||type == TokenType.LBRACE||type == TokenType.IFTK||type == TokenType.FORTK||type == TokenType.BREAKTK||type == TokenType.CONTINUETK||type == TokenType.RETURNTK||type == TokenType.PRINTFTK||Exp.isFirstExp(tnow0)){
                Node node= Stmt.parserStmt(tnow0);
                tnow0 = node.parser(tnow0);
                if(tnow0 == null){
                    System.out.println("error!:in Block.parserBlock in line 29");
                    return null;
                }
                nodes.add(node);
                type = tnow0.getTokenType();
            }
            else{
                tnow0 = getAToken();
                if(tnow0 == null){
                    return null;
                }
                type = tnow0.getTokenType();
                System.out.println("error!:in Block.parserBlock in line 40"+GiveTokener.getInstance().getMaxlineno()+"with token "+tnow0.toString());
            }
        }
        nodes.add(tnow0);
        return null;
    }


    public void printToFile(){
        for(int i=0;i<nodes.size();i++){
            nodes.get(i).printToFile();
        }
        WriteIntoF.getInstance().writeToFile(true, "" + "<Block>" + "\n");
    }


    public Token getAToken(){
        return giveTokener.getAToken();
    }

    public void putBackAToken(Token token){
        giveTokener.putBackAToken(token);
    }
}
