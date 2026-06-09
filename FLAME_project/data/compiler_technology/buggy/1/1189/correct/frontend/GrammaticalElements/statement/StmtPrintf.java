package frontend.GrammaticalElements.statement;

import frontend.GrammaticalElements.expression.Exp;
import frontend.Token;

import java.util.ArrayList;

public class StmtPrintf extends StmtEle{
    /*Token printf;
    Token leftParen;
    Token stringConst;
    vector<Token> commas;
    vector<Exp> exps;
    Token rightParen;
    Token semicolon;*/
    private Token printf;
    private Token leftParen;
    private Token stringConst;
    private ArrayList<Token> commas;
    private ArrayList<Exp> exps;
    private Token rightParen;
    private Token semicolon;

    public StmtPrintf(Token printf, Token leftParen, Token stringConst, ArrayList<Token> commas, ArrayList<Exp> exps, Token rightParen, Token semicolon) {
        this.printf = printf;
        this.leftParen = leftParen;
        this.stringConst = stringConst;
        this.commas = commas;
        this.exps = exps;
        this.rightParen = rightParen;
        this.semicolon = semicolon;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(printf.toString());
        sb.append(leftParen.toString());
        sb.append(stringConst.toString());
        int len = commas.size();
        for (int i = 0; i < len; i++) {
            sb.append(commas.get(i).toString());
            sb.append(exps.get(i).toString());
        }
        sb.append(rightParen.toString());
        sb.append(semicolon.toString());
        return sb.toString();
    }
}
