package parser_part.statement;

import lexer_part.Token;
import lexer_part.TokenList;
import parser_part.block.BlockParser;
import parser_part.statement.StmtComponent.StmtAssignParser;
import parser_part.statement.StmtComponent.StmtBreakParser;
import parser_part.statement.StmtComponent.StmtComponent;
import parser_part.statement.StmtComponent.StmtContinueParser;
import parser_part.statement.StmtComponent.StmtExpParser;
import parser_part.statement.StmtComponent.StmtForParser;
import parser_part.statement.StmtComponent.StmtGetIntParser;
import parser_part.statement.StmtComponent.StmtIfParser;
import parser_part.statement.StmtComponent.StmtPrintfParser;
import parser_part.statement.StmtComponent.StmtReturnParser;
import parser_part.statement.StmtComponent.StmtSemicnParser;
import parser_part.statement.StmtComponent.StmtWhileParser;
import symbol_part.SymbolList;

public class StmtParser {
    private TokenList tokenList;
    private SymbolList symbolList;
    private boolean createNewList;

    public StmtParser(TokenList tokenList, SymbolList symbolList) {
        this.tokenList = tokenList;
        this.symbolList = symbolList;
        createNewList = false;
    }

    public void setNewSymbolList(boolean newSymbolList) {
        this.createNewList = newSymbolList;
    }

    public Stmt parseStmt() {
        Token token = tokenList.getNextToken();
        StmtComponent stmtComponent = null;
        tokenList.moveBack(1);
        if (token.getType() == Token.TokenType.IFTK) {
            StmtIfParser stmtIfParser = new StmtIfParser(tokenList, symbolList);
            stmtComponent = stmtIfParser.parseStmtIf();
        } else if (token.getType() == Token.TokenType.FORTK) {
            StmtForParser stmtForParser = new StmtForParser(tokenList, symbolList);
            stmtComponent = stmtForParser.parseStmtFor();
        } else if (token.getType() == Token.TokenType.WHILETK) {
            StmtWhileParser stmtWhileParser = new StmtWhileParser(tokenList, symbolList);
            stmtComponent = stmtWhileParser.parseStmtWhile();
        } else if (token.getType() == Token.TokenType.BREAKTK) {
            StmtBreakParser stmtBreakParser = new StmtBreakParser(tokenList, symbolList);
            stmtComponent = stmtBreakParser.parseStmtBreak();
        } else if (token.getType() == Token.TokenType.RETURNTK) {
            StmtReturnParser stmtReturnParser = new StmtReturnParser(tokenList, symbolList);
            stmtComponent = stmtReturnParser.parseStmtReturn();
        } else if (token.getType() == Token.TokenType.PRINTFTK) {
            StmtPrintfParser stmtPrintfParser = new StmtPrintfParser(tokenList, symbolList);
            stmtComponent = stmtPrintfParser.parseStmtPrintf();
        } else if (token.getType() == Token.TokenType.CONTINUETK) {
            StmtContinueParser stmtContinueParser = new StmtContinueParser(tokenList, symbolList);
            stmtComponent = stmtContinueParser.parseStmtContinue();
        } else if (token.getType() == Token.TokenType.LBRACE) {
            BlockParser blockParser = new BlockParser(tokenList, symbolList);
            blockParser.setFuncBlock(createNewList);
            stmtComponent = blockParser.parseBlock();
        } else if (token.getType() == Token.TokenType.SEMICN) {
            StmtSemicnParser stmtSemicnParser = new StmtSemicnParser(tokenList);
            stmtComponent = stmtSemicnParser.parseStmtSemicn();
        }
        // 系统能力大赛库函数 start
        /*else if (token.getIRType() == Token.TokenType.PUTINTTK) {
            StmtPutIntParser stmtPutIntParser = new StmtPutIntParser(tokenList, symbolList);
            stmtComponent = stmtPutIntParser.parseStmtPutInt();
        } else if (token.getIRType() == Token.TokenType.PUTCHTK) {
            StmtPutChParser stmtPutChParser = new StmtPutChParser(tokenList, symbolList);
            stmtComponent = stmtPutChParser.parseStmtPutCh();
        } else if (token.getIRType() == Token.TokenType.PUTARRAYTK) {
            StmtPutArrayParser stmtPutArrayParser = new StmtPutArrayParser(tokenList, symbolList);
            stmtComponent = stmtPutArrayParser.parseStmtPutArray();
        } else if (token.getIRType() == Token.TokenType.STARTTIME) {
            StmtStartTimeParser stmtStartTimeParser = new StmtStartTimeParser(tokenList);
            stmtComponent = stmtStartTimeParser.parseStmtStartTime();
        } else if (token.getIRType() == Token.TokenType.STOPTIME) {
            StmtStopTimeParser stmtStopTimeParser = new StmtStopTimeParser(tokenList);
            stmtComponent = stmtStopTimeParser.parseStmtStopTime();
        }*/
        // 系统能力大赛库函数 end
        else if (token.getType() == Token.TokenType.LPARENT ||
                token.getType() == Token.TokenType.INTCON ||
                token.getType() == Token.TokenType.PLUS ||
                token.getType() == Token.TokenType.MINU ||
                token.getType() == Token.TokenType.CHRCON) {
            StmtExpParser stmtExpParser = new StmtExpParser(tokenList, symbolList);
            stmtComponent = stmtExpParser.parseStmtExp();
        } else if (isFuncIdent(token)) {
            // judge the cases of
            // LVal '=' Exp ';'
            // [Exp] ';'
            // LVal '=' 'getint''('')'';'

            /* 系统能力大赛库函数 start */
            // LVal '=' 'getch''('')'';'
            // LVal '=' 'getarray''(' LVal ')'';'
            stmtComponent = judgeIdent(token);
        }
        return new Stmt(stmtComponent);
    }

    private StmtComponent judgeIdent(Token token) {
        boolean isLVal = false;
        boolean getIntChar = false;
        Token cur = token;
        int steps = 0;
        while (cur.getType() != Token.TokenType.SEMICN) {
            if (cur.isEndLine()){
                break;
            }
            cur = tokenList.getNextToken();
            steps++;
            if (cur.getType() == Token.TokenType.ASSIGN) {
                isLVal = true;
            }
            if (cur.getType() == Token.TokenType.GETINTTK || cur.getType() == Token.TokenType.GETCHARTK) {
                getIntChar = true;
                break;
            }
        }
        tokenList.moveBack(steps);
        if (isLVal) {
            if (getIntChar) {
                StmtGetIntParser stmtGetIntParser = new StmtGetIntParser(tokenList, symbolList);
                return stmtGetIntParser.parseStmtGetInt();
            }
            StmtAssignParser stmtAssignParser = new StmtAssignParser(tokenList, symbolList);
            return stmtAssignParser.parseStmtAssign();
        } else {
            StmtExpParser stmtExpParser = new StmtExpParser(tokenList, symbolList);
            return stmtExpParser.parseStmtExp();
        }
    }

    public boolean isFuncIdent(Token token) {
        return token.getType() == Token.TokenType.IDENFR ||
                token.getType() == Token.TokenType.GETINTTK ||
                token.getType() == Token.TokenType.GETCHARTK ||
                token.getType() == Token.TokenType.MAINTK;
    }
}
