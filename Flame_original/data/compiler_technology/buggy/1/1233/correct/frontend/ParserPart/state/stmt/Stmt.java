package frontend.ParserPart.state.stmt;

import frontend.ParserPart.state.blockitem.BlockItemInterface;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

public class Stmt implements BlockItemInterface {
    private String name = "<Stmt>";
    private TokenList tokenList;
    private StmtInterface stmtInterface;
    public Stmt(TokenList tokenList){
        this.tokenList = tokenList;
        stmtInterface = null;
    }
    public void parseStmt(){
        Token token = tokenList.peek();
        if (token.getType().equals(TokenType.IFTK)){
            //如果是if
            StmtCond stmtCond = new StmtCond(tokenList);
            stmtCond.parseStmtCond();
            stmtInterface = stmtCond;
        } else if (token.getType().equals(TokenType.FORTK)) {
            //如果是for
            StmtForStmt stmtForStmt = new StmtForStmt(tokenList);
            stmtForStmt.parseStmtForStmt();
            stmtInterface = stmtForStmt;
        } else if (token.getType().equals(TokenType.BREAKTK)) {
            //如果是break
            StmtBreak stmtBreak = new StmtBreak(tokenList);
            stmtBreak.parseStmtBreak();
            stmtInterface = stmtBreak;
        } else if (token.getType().equals(TokenType.CONTINUETK)) {
            //如果是continue
            StmtContinue stmtContinue = new StmtContinue(tokenList);
            stmtContinue.parseStmtContinue();
            stmtInterface = stmtContinue;
        } else if (token.getType().equals(TokenType.RETURNTK)) {
            //如果是return
            StmtReturn stmtReturn = new StmtReturn(tokenList);
            stmtReturn.parseStmtReturn();
            stmtInterface = stmtReturn;
        } else if (token.getType().equals(TokenType.PRINTFTK)) {
            //如果是printf
            StmtPrint stmtPrint = new StmtPrint(tokenList);
            stmtPrint.parseStmtPrint();
            stmtInterface = stmtPrint;
        } else if (token.getType().equals(TokenType.IDENFR)) {
            //如果是Ident开头
            //对应了三种LVal开头的情况还有可能是[exp]，需要细分
            divideLVal();
        } else if (token.getType().equals(TokenType.LBRACE)) {
            //如果是Block开头，也就是{开头
            StmtBlock stmtBlock = new StmtBlock(tokenList);
            stmtBlock.parseStmtBlock();
            stmtInterface = stmtBlock;
        } else if (token.getType().equals(TokenType.SEMICN)) {
            //如果是;开头，对应[exp];情况
            StmtExp2 stmtExp2 = new StmtExp2(tokenList);
            stmtExp2.parseStmtExp2();
            stmtInterface = stmtExp2;
        }else {
            //对应剩下的[exp];情况
            StmtExp2 stmtExp2 = new StmtExp2(tokenList);
            stmtExp2.parseStmtExp2();
            stmtInterface = stmtExp2;
        }
    }
    public void divideLVal(){
        //对应细分三种LVal开头情况和[exp];开头情况
        int num = 0;
        int mark1 = 0;//标记是LVal还是exp，通过=判断，1代表LVal，0代表exp
        int mark2 = 0;//标记哪种LVal，0是exp，1是getint，2是getchar
        Token token = tokenList.peek();
        while (!token.getType().equals(TokenType.SEMICN)){
            if (token.getType().equals(TokenType.ASSIGN)){
                mark1 = 1;
                //预读一个,看后面的是哪种
                Token tem = tokenList.preRead(num + 1);
                if (tem.getType().equals(TokenType.GETINTTK)){
                    mark2 = 1;
                }
                if (tem.getType().equals(TokenType.GETCHARTK)){
                    mark2 = 2;
                }
                break;
            }
            num++;
            token = tokenList.preRead(num);
        }
        if (mark1 == 0){
            //[exp];
            StmtExp2 stmtExp2 = new StmtExp2(tokenList);
            stmtExp2.parseStmtExp2();
            stmtInterface = stmtExp2;
        }else {
            //LVal开头
            if (mark2 == 1){
                //LVal = getint;
                StmtGetInt stmtGetInt = new StmtGetInt(tokenList);
                stmtGetInt.parseStmtGetInt();
                stmtInterface = stmtGetInt;
            } else if (mark2 == 2) {
                //LVal = getchar;
                StmtGetChar stmtGetChar = new StmtGetChar(tokenList);
                stmtGetChar.parseStmtGetChar();
                stmtInterface = stmtGetChar;
            }else {
                //LVal = exp;
                StmtExp1 stmtExp1 = new StmtExp1(tokenList);
                stmtExp1.parseStmtExp1();
                stmtInterface = stmtExp1;
            }
        }
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(stmtInterface.toString());
        sb.append(name);
        sb.append("\n");
        return sb.toString();
    }
}
