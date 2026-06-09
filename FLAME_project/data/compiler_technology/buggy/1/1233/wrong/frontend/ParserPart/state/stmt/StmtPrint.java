package frontend.ParserPart.state.stmt;

import frontend.ErrorPart.Error;
import frontend.ErrorPart.ErrorList;
import frontend.ErrorPart.ErrorType;
import frontend.ParserPart.expr.Exp;
import frontend.ParserPart.term.StringConst;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

import java.util.ArrayList;

public class StmtPrint implements StmtInterface{
    private TokenList tokenList;
    private Token printfToken;
    private Token leftPARENT;
    private StringConst stringConst;
    private ArrayList<Token> commas;//可能存在
    private ArrayList<Exp> expArrayList;//可能存在
    private Token rightPARENT;
    private Token secimn;
    public StmtPrint(TokenList tokenList){
        this.tokenList = tokenList;
        printfToken = new Token(TokenType.PRINTFTK,"printf");
        leftPARENT = new Token(TokenType.LPARENT,"(");
        stringConst = new StringConst(tokenList);
        commas = new ArrayList<>();
        expArrayList = new ArrayList<>();
        rightPARENT = new Token(TokenType.RPARENT,")");
        secimn = new Token(TokenType.SEMICN,";");
    }
    public void parseStmtPrint(){
        //指向printf
        tokenList.next();
        //指向(
        tokenList.next();
        stringConst.parseStringConst();
        while (tokenList.peek().getType().equals(TokenType.COMMA)){
            Token token = new Token(TokenType.COMMA,",");
            commas.add(token);
            tokenList.next();
            Exp tem = new Exp(tokenList);
            tem.parseExp();
            expArrayList.add(tem);
        }
        //指向)
        if (tokenList.peek().getType().equals(TokenType.RPARENT)){
            tokenList.next(); }
        else {
            Error error = new Error(ErrorType.j,tokenList.preRead(-1).getLineNum());
            ErrorList.addError(error);
        }
        //指向;
        if (tokenList.peek().getType().equals(TokenType.SEMICN)){
            tokenList.next(); }
        else {
            Error error = new Error(ErrorType.i,tokenList.preRead(-1).getLineNum());
            ErrorList.addError(error);
        }
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(printfToken.toString());
        sb.append(leftPARENT.toString());
        sb.append(stringConst.toString());
        for (int i = 0; i < commas.size(); i++) {
            sb.append(commas.get(i).toString());
            sb.append(expArrayList.get(i).toString());
        }
        sb.append(rightPARENT.toString());
        sb.append(secimn.toString());
        return sb.toString();
    }
}
