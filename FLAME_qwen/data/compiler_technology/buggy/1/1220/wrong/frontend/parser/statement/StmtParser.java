package frontend.parser.statement;

import frontend.error.Error;
import frontend.error.ErrorList;
import frontend.lexer.Token;
import frontend.lexer.TokenIterator;
import frontend.lexer.TokenType;
import frontend.parser.block.BlockParser;
import frontend.parser.expression.Exp;
import frontend.parser.expression.ExpParser;
import frontend.parser.expression.primaryExp.LVal;
import frontend.parser.expression.primaryExp.LValParser;

public class StmtParser {
    private TokenIterator iterator;
    private StmtUnit stmtUnit;

    public StmtParser(TokenIterator iterator) {
        this.iterator = iterator;
    }

    public Stmt parseStmt() {
        Token t1 = iterator.getNextToken();
        switch (t1.getType()) {
            case LBRACE: //  Block -> '{' { BlockItem } '}'
                iterator.ungetToken(1);
                BlockParser parser = new BlockParser(iterator);
                stmtUnit = parser.parseBlock();
                break;
            case IFTK:
                // 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
                iterator.ungetToken(1);
                IfElseStmtParser parser1 = new IfElseStmtParser(iterator);
                stmtUnit = parser1.parseIfElseStmt();
                break;
            case FORTK:
                //'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
                iterator.ungetToken(1);
                ForCondStmtParser parser2 = new ForCondStmtParser(iterator);
                stmtUnit = parser2.parseForCondStmt();
                break;
            case BREAKTK:
                Token t2 = iterator.getNextToken();
                if (t2.getType() == TokenType.SEMICN) {
                    stmtUnit = new BreakStmt(t1, t2);
                } else {
                    //缺少分号
                    Error error = new Error(t1.getLineNum(), "i");
                    ErrorList.addErrorList(error);
                    stmtUnit = new BreakStmt(t1, null);
                    iterator.ungetToken(1);
                }
                break;
            case CONTINUETK:
                Token t3 = iterator.getNextToken();
                if (t3.getType() == TokenType.SEMICN) {
                    stmtUnit = new ContinueStmt(t1, t3);
                } else {
                    //缺少分号
                    Error error = new Error(t1.getLineNum(), "i");
                    ErrorList.addErrorList(error);
                    stmtUnit = new ContinueStmt(t1, null);
                    iterator.ungetToken(1);
                }
                break;
            case RETURNTK:
                // 'return' [Exp] ';'
                iterator.ungetToken(1);
                ReturnStmtParser parser3 = new ReturnStmtParser(iterator);
                stmtUnit = parser3.parseReturnStmt();
                break;
            case PRINTFTK:
                iterator.ungetToken(1);
                PrintfStmtParser parser4 = new PrintfStmtParser(iterator);
                stmtUnit = parser4.parsePrintfStmt();
                break;
            case IDENFR:
                //1. stmt-> LVal '=' (Exp';'|getint();|getchar();)
                // LVal → Ident ['[' Exp ']']
                /*---------------------怎么区分？------------------*/
                //2. stmt -> [Exp];
                //Exp -> AddExp -> MulExp -> UnaryExp ->PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
                //PrimaryExp → '(' Exp ')' | LVal | Number | Character/
                //LVal和Ident '(' [FuncRParams] ')'都以Ident开头

                /*------------------------------------*/
                Token t4 = iterator.getNextToken();
                if (t4.getType() == TokenType.LPARENT) {
                    //说明是[Exp];->Ident'('[FuncRParams]')'';'
                    iterator.ungetToken(2);
                    ExpParser expParser = new ExpParser(iterator);
                    Exp e = expParser.parseExp();
                    Token semicn = iterator.getNextToken();
                    if (semicn.getType() != TokenType.SEMICN) {
                        iterator.ungetToken(2);
                        Error error = new Error(iterator.getNextToken().getLineNum(), "i");
                        ErrorList.addErrorList(error);
                        semicn = null;
                    }
                    stmtUnit = new ExpStmt(e, semicn);
                } else {
                    //说明是LVal
                    //todo:解析LVal
                    iterator.ungetToken(2);
                    int markedPosition = iterator.nextIndex();
                    //开始位置
                    LValParser parser5 = new LValParser(iterator);
                    LVal lVal = parser5.parseLVal();
                    //nextToken，假如是‘=’，那么为LVal '=' (Exp';'|getint();|getchar();)
                    Token t5 = iterator.getNextToken();
                    if (t5.getType() == TokenType.ASSIGN) {
                        Token assign = t5;
                        Token t6 = iterator.getNextToken();
                        if (t6.getType() == TokenType.GETINTTK) {
                            iterator.ungetToken(1);
                            GetIntParser parser6 = new GetIntParser(iterator);
                            stmtUnit = parser6.parseGetIntStmt(lVal, assign);
                        } else if (t6.getType() == TokenType.GETCHARTK) {
                            iterator.ungetToken(1);
                            GetCharParser parser6 = new GetCharParser(iterator);
                            stmtUnit = parser6.parseGetCharStmt(lVal, assign);
                        } else {
                            //LVal '=' Exp';'------LValExpStmt
                            iterator.ungetToken(1);
                            ExpParser expParser = new ExpParser(iterator);
                            Exp exp = expParser.parseExp();
                            Token semicn = iterator.getNextToken();
                            if (semicn.getType() != TokenType.SEMICN) {
                                iterator.ungetToken(2);
                                Error error = new Error(iterator.getNextToken().getLineNum(), "i");
                                ErrorList.addErrorList(error);
                            }
                            stmtUnit = new LValExpStmt(lVal, assign, exp, semicn);
                        }

                    }
                    //假如不是，说明是ExpStmt----- [Exp] ';',且Exp->..->LVal开头
                    else {
                        //退回Exp开始的位置，解析[Exp]';'
                        iterator.ungetToken(1);
                        int nowPosition = iterator.nextIndex();
                        iterator.ungetToken(nowPosition - markedPosition);
                        Token semicn = iterator.getNextToken();
                        Exp exp;
                        if (semicn.getType() != TokenType.SEMICN) {
                            semicn = null;
                            iterator.ungetToken(1);
                            ExpParser expParser = new ExpParser(iterator);
                            exp = expParser.parseExp();
                            semicn = iterator.getNextToken();
                            if (semicn.getType() != TokenType.SEMICN) {
                                semicn = null;
                                iterator.ungetToken(2);
                                Error error = new Error(iterator.getNextToken().getLineNum(), "i");
                                ErrorList.addErrorList(error);
                            }
                        } else {
                            exp = null;
                        }
                        stmtUnit = new ExpStmt(exp, semicn);
                    }
                }
                break;
                /*---------------------------------------*/
            default:
                iterator.ungetToken(1);
                Token semicn1 = iterator.getNextToken();
                Exp exp;
                if (semicn1.getType() != TokenType.SEMICN) {
                    semicn1 = null;
                    iterator.ungetToken(1);
                    ExpParser expParser = new ExpParser(iterator);
                    exp = expParser.parseExp();
                    semicn1 = iterator.getNextToken();
                    if (semicn1.getType() != TokenType.SEMICN) {
                        semicn1 = null;
                        iterator.ungetToken(2);
                        Error error = new Error(iterator.getNextToken().getLineNum(), "i");
                        ErrorList.addErrorList(error);
                    }
                } else {
                    exp = null;
                }
                stmtUnit = new ExpStmt(exp, semicn1);
        }
        return new Stmt(stmtUnit);
    }
}
