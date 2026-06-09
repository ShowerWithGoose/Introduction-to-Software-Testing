package frontend;

import java.util.ArrayList;

public class Stmt {
    private static GiveTokener giveTokener = GiveTokener.getInstance();
    public static Node parserStmt(Token tnow0){
        TokenType type = tnow0.getTokenType();
        if(type == TokenType.SEMICN){
            return new StmtExp();
        } else if(type == TokenType.IFTK){
            return new StmtIf();
        }else if(type == TokenType.FORTK){
            return new StmtFor();
        }else if(type == TokenType.BREAKTK){
            return new StmtBreak();
        }else if(type == TokenType.CONTINUETK){
            return new StmtContinue();
        }
        else if(type == TokenType.RETURNTK){
            return new StmtReturn();
        }else if(type == TokenType.PRINTFTK){
            return new StmtPrintf();
        }else if(type == TokenType.LBRACE){
            return new StmtBlock();
        }else if(type == TokenType.IDENFR){
            Token token = GiveTokener.getInstance().preReadAToken();
            if(token.getTokenType() == TokenType.ASSIGN){
                GiveTokener.getInstance().putBackAToken(token);
                return new StmtAssign();
            }else if(token.getTokenType() == TokenType.LBRACK){
                boolean isAssign = false;
                int lineno = token.getLineno();
                int line = lineno;
                ArrayList<Token> tokens = new ArrayList<>();
                while(line == lineno){
                    Token token1 = GiveTokener.getInstance().preReadAToken();
                    tokens.add(token1);
                    line = token1.getLineno();
                    if(token1.getTokenType()==TokenType.ASSIGN){
                        isAssign = true;
                        break;
                    }
                }
                for(int i=((tokens.size()>0)?tokens.size()-1:0);i>=0;i--){
                    putBackAToken(tokens.get(i));
                }
                GiveTokener.getInstance().putBackAToken(token);
                if(isAssign){
                    return new StmtAssign();
                }else{
                    return new StmtExp();
                }
            }else{
                GiveTokener.getInstance().putBackAToken(token);
                return new StmtExp();
            }
        }else if (type == TokenType.IDENFR||type == TokenType.PLUS||type == TokenType.MINU||type == TokenType.LPARENT||type == TokenType.INTCON||type == TokenType.CHRCON|| type == TokenType.NOT){
            return new StmtExp();
        }else{
            System.out.println("ERROR!!!Stmt type divide");
            return null;
        }
    }


    public static Boolean isStmtFirst(Token token){
        TokenType type = token.getTokenType();
        if(type == TokenType.SEMICN||type == TokenType.LPARENT||type == TokenType.IDENFR||type == TokenType.CHRCON||type == TokenType.INTCON||type == TokenType.LBRACE||type == TokenType.IFTK||type == TokenType.FORTK||type == TokenType.BREAKTK||type == TokenType.CONTINUETK||type == TokenType.RETURNTK||type == TokenType.PRINTFTK||Exp.isFirstExp(token)){
            return true;
        }
        return false;
    }

    public Token getAToken(){
        return giveTokener.getAToken();
    }

    public static void putBackAToken(Token token){
        giveTokener.putBackAToken(token);
    }
}
