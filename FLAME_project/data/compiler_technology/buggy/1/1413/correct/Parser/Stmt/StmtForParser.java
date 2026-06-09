package Parser.Stmt;

import Lexer.Token;
import Lexer.TokenListIterator;
import Parser.ErrorP;
import Parser.ErrorPList;
import Parser.Exp.Cond;
import Parser.Exp.CondParser;

/**
 * @Description:
 * @date 2024/10/13
 */
public class StmtForParser {
    private TokenListIterator iterator;
    private Token forTk; // 'for'
    private Token leftParent; // '('
    private ForStmt firstForStmt=null;
    private Token firstSemicolon;
    private Cond cond=null;
    private Token secondSemicolon;
    private ForStmt secondForStmt=null;
    private Token rightParent; // ')'
    private Stmt forStmt;
    private int errorLine;

    public StmtForParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }
    public StmtFor stmtForParse()
    {
        Token first=iterator.readNextToken();
        if(first.getValue().equals("for"))
        {
            this.forTk=first;
            this.errorLine=forTk.getLine();
            Token next=iterator.readNextToken();
            if(next.getValue().equals("("))
            {
                this.leftParent=next;
                next=iterator.readNextToken();
                if(next.getValue().equals(";"))
                {
                    this.firstSemicolon=next;
                    next=iterator.readNextToken();
                    if(next.getValue().equals(";"))
                    {
                        this.secondSemicolon=next;
                        next=iterator.readNextToken();
                        if(next.getValue().equals(")"))
                        {
                            this.rightParent=next;
                            StmtParser stmtParser=new StmtParser(iterator);
                            this.forStmt=stmtParser.parseStmt();
                        }else if(next.getType().equals("IDENFR"))
                        {
                            iterator.unReadToken(1);
                            ForStmtParser forStmtParser=new ForStmtParser(iterator);
                            this.secondForStmt=forStmtParser.forStmtParse();
                            next=iterator.readNextToken();
                            this.rightParent=next;
                            StmtParser stmtParser=new StmtParser(iterator);
                            this.forStmt=stmtParser.parseStmt();
                        }else {
                            iterator.unReadToken(1);
                            ErrorP errorP=new ErrorP("j",this.errorLine);
                            ErrorPList errorPList=ErrorPList.getInstance();
                            errorPList.addErrorP(errorP);
                        }
                    }else {
                        iterator.unReadToken(1);
                        CondParser condParser=new CondParser(iterator);
                        this.cond=condParser.parseCond();
                        next=iterator.readNextToken();
                        this.secondSemicolon=next;
                        next=iterator.readNextToken();
                        if(next.getValue().equals(")"))
                        {
                            this.rightParent=next;
                            StmtParser stmtParser=new StmtParser(iterator);
                            this.forStmt=stmtParser.parseStmt();
                        }else if(next.getType().equals("IDENFR"))
                        {
                            iterator.unReadToken(1);
                            ForStmtParser forStmtParser=new ForStmtParser(iterator);
                            this.secondForStmt=forStmtParser.forStmtParse();
                            next=iterator.readNextToken();
                            this.rightParent=next;
                            StmtParser stmtParser=new StmtParser(iterator);
                            this.forStmt=stmtParser.parseStmt();
                        }else {
                            iterator.unReadToken(1);
                            ErrorP errorP=new ErrorP("j",this.errorLine);
                            ErrorPList errorPList=ErrorPList.getInstance();
                            errorPList.addErrorP(errorP);
                        }
                    }
                }else {
                    iterator.unReadToken(1);
                    ForStmtParser forStmtParser=new ForStmtParser(iterator);
                    this.firstForStmt=forStmtParser.forStmtParse();
                    next=iterator.readNextToken();
                    this.firstSemicolon=next;
                    next=iterator.readNextToken();
                    if(next.getValue().equals(";"))
                    {

                            this.secondSemicolon=next;
                            next=iterator.readNextToken();
                            if(next.getValue().equals(")"))
                            {
                                this.rightParent=next;
                                StmtParser stmtParser=new StmtParser(iterator);
                                this.forStmt=stmtParser.parseStmt();
                            }else if(next.getType().equals("IDENFR"))
                            {
                                iterator.unReadToken(1);
                                ForStmtParser forStmtParser2=new ForStmtParser(iterator);
                                this.secondForStmt=forStmtParser.forStmtParse();
                                next=iterator.readNextToken();
                                this.rightParent=next;
                                StmtParser stmtParser=new StmtParser(iterator);
                                this.forStmt=stmtParser.parseStmt();
                            }else {
                                iterator.unReadToken(1);
                                ErrorP errorP=new ErrorP("j",this.errorLine);
                                ErrorPList errorPList=ErrorPList.getInstance();
                                errorPList.addErrorP(errorP);
                            }
                        }else {
                        iterator.unReadToken(1);
                        CondParser condParser = new CondParser(iterator);
                        this.cond = condParser.parseCond();
                        next = iterator.readNextToken();
                        this.secondSemicolon = next;
                        next = iterator.readNextToken();
                        if (next.getValue().equals(")")) {
                            this.rightParent = next;
                            StmtParser stmtParser = new StmtParser(iterator);
                            this.forStmt = stmtParser.parseStmt();
                        } else if (next.getType().equals("IDENFR")) {
                            iterator.unReadToken(1);
                            ForStmtParser forStmtParser1 = new ForStmtParser(iterator);
                            this.secondForStmt = forStmtParser.forStmtParse();
                            next = iterator.readNextToken();
                            this.rightParent = next;
                            StmtParser stmtParser = new StmtParser(iterator);
                            this.forStmt = stmtParser.parseStmt();
                        } else {
                            iterator.unReadToken(1);
                            ErrorP errorP=new ErrorP("j",this.errorLine);
                            ErrorPList errorPList=ErrorPList.getInstance();
                            errorPList.addErrorP(errorP);
                        }

                    }
                }
            }
            return new StmtFor(forTk,leftParent,firstForStmt,firstSemicolon,cond,secondSemicolon,secondForStmt,rightParent,forStmt);
        }else {
            System.out.println("stmtfor error");
            return null;
        }
    }
}
