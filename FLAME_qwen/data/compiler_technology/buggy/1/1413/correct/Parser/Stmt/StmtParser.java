package Parser.Stmt;


import Lexer.Token;
import Lexer.TokenListIterator;

public class StmtParser {
    private TokenListIterator iterator;
    /* Stmt Attributes */
    private StmtEle stmtEle = null;

    public StmtParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public Stmt parseStmt() {
        Token first = this.iterator.readNextToken();
        switch (first.getType()) {
            case "IFTK": // 'if'
                this.iterator.unReadToken(1);
                StmtCondParser stmtCondParser = new StmtCondParser(this.iterator);
                this.stmtEle = stmtCondParser.parseStmtCond();
                break;
            case "FORTK": // 'for'
                this.iterator.unReadToken(1);
                StmtForParser stmtForParser=new StmtForParser(iterator);
                this.stmtEle = stmtForParser.stmtForParse();
                break;
            case "BREAKTK": // 'break'
                this.iterator.unReadToken(1);
                StmtBreakParser stmtBreakParser = new StmtBreakParser(this.iterator);
                this.stmtEle = stmtBreakParser.parseStmtBreak();
                break;
            case "CONTINUETK": // 'continue'
                this.iterator.unReadToken(1);
                StmtContinueParser stmtContinueParser = new StmtContinueParser(this.iterator);
                this.stmtEle = stmtContinueParser.parseStmtContinue();
                break;
            case "RETURNTK": // 'return'
                this.iterator.unReadToken(1);
                StmtReturnParser stmtReturnParser = new StmtReturnParser(this.iterator);
                this.stmtEle = stmtReturnParser.stmtReturnParse();
                break;
            case "PRINTFTK": // 'printf'
                this.iterator.unReadToken(1);
                StmtPrintParser stmtPrintParser = new StmtPrintParser(this.iterator);
                this.stmtEle = stmtPrintParser.parseStmtPrint();
                break;
            case "SEMICN": // ';'
                this.iterator.unReadToken(1);
                StmtNullParser stmtNullParser = new StmtNullParser(this.iterator);
                this.stmtEle = stmtNullParser.pasreStmtNull();
                break;
                /* TODO : handle exp and lval*/
            case "IDENFR":
                caseIdenfr(first);
                break;
            case "LBRACE": // '{'
                this.iterator.unReadToken(1);
                StmtBlockParser stmtBlockParser=new StmtBlockParser(iterator);
                this.stmtEle = stmtBlockParser.stmtBlockParse();
                break;
            case "LPARENT": case "INTCON": case "CHRCON": case "PLUS": case "MINU": case "NOT":
                this.iterator.unReadToken(1);
                StmtExpParser stmtExpParser = new StmtExpParser(this.iterator);
                this.stmtEle = stmtExpParser.parseStmtExp();
                break;
            default:
                System.out.println("ARRIVE UNEXPECTED DEFAULT BRANCH");
        }
        Stmt stmt = new Stmt(this.stmtEle);
        return stmt;
    }

    private void caseIdenfr(Token first) {
        /* need to distinguish LVal = Exp, LVal = getint ,LVal = getchar and [Exp] */
        int cnt = 1;
        int mode = 0; // 0:assign 1:input
        boolean flag = false; // LVal = Exp; || LVal = getint();,LVal = getchar
        Token token = first;
        while (!token.getType().equals("SEMICN")) {
            token = this.iterator.readNextToken();
            cnt += 1;
            if (token.getType().equals("ASSIGN")) {
                flag = true;
            }
            if (token.getType().equals("GETINTTK")) {
                mode = 1;
            }
            if (token.getType().equals("GETCHARTK")) {
                mode = 2;
            }
        }
        this.iterator.unReadToken(cnt);
        if (flag) {
            if (mode == 0) {
                StmtAssignParser stmtAssignParser = new StmtAssignParser(this.iterator);
                this.stmtEle = stmtAssignParser.parseStmtAssign();
            } else if (mode == 1) {
                StmtGetIntParser stmtGetIntParser = new StmtGetIntParser(this.iterator);
                this.stmtEle = stmtGetIntParser.parseStmtGetInt();
            } else if (mode == 2) {
                StmtGetcharParser stmtGetcharParser=new StmtGetcharParser(iterator);
                this.stmtEle = stmtGetcharParser.parseStmtGetInt();
            }else {
                System.out.println("REACHED UNEXPECTED BRANCH");
            }
        } else {
            StmtExpParser stmtExpParser = new StmtExpParser(this.iterator);
            this.stmtEle = stmtExpParser.parseStmtExp();
        }
    }
}
