package frontend.parser.Block;

import frontend.lexer.LexType;
import frontend.lexer.Token;
import frontend.lexer.TokenList;

public class Stmt implements BlockItem {
    private StmtElement stmtElement; //11 cases
    private TokenList tokens;
    private int errorNum;
    private String nonTerminalName = "Stmt";

    public Stmt(TokenList tokens) {
        this.stmtElement = null;
        this.tokens = tokens;
        this.errorNum = 0;
    }

    public int parse() { //return error num
        Token first = tokens.nextToken();
        if (first.equals(LexType.IFTK)) { //if语句
            tokens.rollBack(1);
            stmtElement = new StmtIf(tokens);
            errorNum += stmtElement.parse();
        } else if (first.equals(LexType.FORTK)) { //for语句
            tokens.rollBack(1);
            stmtElement = new StmtFor(tokens);
            errorNum += stmtElement.parse();
        } else if (first.equals(LexType.BREAKTK)) { //break语句
            tokens.rollBack(1);
            stmtElement = new StmtBreak(tokens);
            errorNum += stmtElement.parse();
        } else if (first.equals(LexType.CONTINUETK)) { //continue语句
            tokens.rollBack(1);
            stmtElement = new StmtContinue(tokens);
            errorNum += stmtElement.parse();
        } else if (first.equals(LexType.RETURNTK)) { //return语句
            tokens.rollBack(1);
            stmtElement = new StmtReturn(tokens);
            errorNum += stmtElement.parse();
        } else if (first.equals(LexType.PRINTFTK)) { //printf语句
            tokens.rollBack(1);
            stmtElement = new StmtPrintf(tokens);
            errorNum += stmtElement.parse();
        } else if (first.equals(LexType.LBRACE)) { //block
            tokens.rollBack(1);
            stmtElement = new Block(tokens);
            errorNum += stmtElement.parse();
        } else if (first.equals(LexType.SEMICN)) { //单;
            tokens.rollBack(1);
            stmtElement = new StmtSemicn(tokens);
            errorNum += stmtElement.parse();
        } else if (!first.equals(LexType.IDENFR)) { //不以ident开头必为Exp
            tokens.rollBack(1);
            stmtElement = new StmtExp(tokens);
            errorNum += stmtElement.parse();
        } else { //以ident开头的4种情况：assign Exp（部分） getInt getChar
            startWithIdent(first);
        }
        return errorNum;
    }

    private void startWithIdent(Token first) {
        int tokenNum = 1; //first已经读了一个单词
        int lineNum = first.getLineNum(); //该行行号
        Token token = tokens.nextToken();
        tokenNum++;
        //0:未识别到任何 1:识别到= 2:识别到=和getint 3:识别到=和getchar
        int stmtCase = 0;
        while (!token.equals(LexType.SEMICN)) { //循环直到句末分号;
            int newLineNum = token.getLineNum();
            if (newLineNum > lineNum) { //读到新的一行了，停止循环
                break;
            }
            //有限状态机
            if (stmtCase == 0 && token.equals(LexType.ASSIGN)) {
                stmtCase = 1;
            }
            if (stmtCase == 1 && token.equals(LexType.GETINTTK)) {
                stmtCase = 2;
            }
            if (stmtCase == 1 && token.equals(LexType.GETCHARTK)) {
                stmtCase = 3;
            }
            token = tokens.nextToken();
            tokenNum++;
        }
        tokens.rollBack(tokenNum);
        if (stmtCase == 0) { //Exp
            stmtElement = new StmtExp(tokens);
            errorNum += stmtElement.parse();
        } else if (stmtCase == 1) { //assign
            stmtElement = new StmtAssign(tokens);
            errorNum += stmtElement.parse();
        } else if (stmtCase == 2) { //getint
            stmtElement = new StmtGetInt(tokens);
            errorNum += stmtElement.parse();
        } else if (stmtCase == 3) { //getchar
            stmtElement = new StmtGetChar(tokens);
            errorNum += stmtElement.parse();
        }
    }

    public String toSyntaxTree() {
        StringBuilder sb = new StringBuilder();
        sb.append(stmtElement.toSyntaxTree());
        sb.append('<').append(this.nonTerminalName).append('>').append('\n');
        return sb.toString();
    }
}
