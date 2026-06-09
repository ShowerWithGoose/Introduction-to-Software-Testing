package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.statement.Block;
import frontend.parser.statement.BlockParser;

import java.util.ArrayList;

public class StmtParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public StmtParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public Stmt parseStmt() {
        Token token = tokenList.getNextToken();
        // 1 Stmt -> LVal '=' Exp ';'
        // 2 Stmt -> LVal '=' 'getInt' '(' ')' ';'
        // 3 Stmt -> LVal '=' 'getChar' '(' ')' ';'
        // 4 Stmt -> Exp ';' -> LVal ';'
        if (token.getType() == TokenType.IDENFR) {
            if (lValJudge() == 1) {
                tokenList.fallbackToken(1);
                StmtAssginParser stmtAssginParser = new StmtAssginParser(tokenList);
                StmtAssign stmtAssign = stmtAssginParser.parseStmtAssgin();
                this.nodes.add(stmtAssign);
            } else if (lValJudge() == 2) {
                tokenList.fallbackToken(1);
                StmtGetIntParser stmtGetIntParser = new StmtGetIntParser(tokenList);
                StmtGetInt stmtGetInt = stmtGetIntParser.parseStmtGetInt();
                this.nodes.add(stmtGetInt);
            } else if (lValJudge() == 3) {
                tokenList.fallbackToken(1);
                StmtGetCharParser stmtGetCharParser = new StmtGetCharParser(tokenList);
                StmtGetChar stmtGetChar = stmtGetCharParser.parseStmtGetChar();
                this.nodes.add(stmtGetChar);
            } else {
                tokenList.fallbackToken(1);
                StmtExpParser stmtExpParser = new StmtExpParser(tokenList);
                StmtExp stmtExp = stmtExpParser.parseStmtExp();
                this.nodes.add(stmtExp);
            }
        }
        // Stmt -> ';'
        // Stmt -> Exp ';'
        else if (token.getType() == TokenType.SEMICN || token.getType() == TokenType.LPARENT || token.getType() == TokenType.INTCON || token.getType() == TokenType.CHRCON || token.getType() == TokenType.PLUS || token.getType() == TokenType.MINU || token.getType() == TokenType.NOT) {
            tokenList.fallbackToken(1);
            StmtExpParser stmtExpParser = new StmtExpParser(tokenList);
            StmtExp stmtExp = stmtExpParser.parseStmtExp();
            this.nodes.add(stmtExp);
        }
        // Stmt -> Block -> '{' BlockItem '}'
        else if (token.getType() == TokenType.LBRACE) {
            tokenList.fallbackToken(1);
            BlockParser blockParser = new BlockParser(tokenList);
            Block block = blockParser.parseBlock();
            this.nodes.add(block);
        }
        // Stmt -> 'if' '(' Cond ')' ...
        else if (token.getType() == TokenType.IFTK) {
            tokenList.fallbackToken(1);
            StmtIfParser stmtIfParser = new StmtIfParser(tokenList);
            StmtIf stmtIf = stmtIfParser.parseStmtIf();
            this.nodes.add(stmtIf);
        }
        // Stmt -> 'for' '(' ...
        else if (token.getType() == TokenType.FORTK) {
            tokenList.fallbackToken(1);
            StmtForParser stmtForParser = new StmtForParser(tokenList);
            StmtFor stmtFor = stmtForParser.parseStmtFor();
            this.nodes.add(stmtFor);
        }
        // Stmt -> 'break' ';'
        else if (token.getType() == TokenType.BREAKTK) {
            tokenList.fallbackToken(1);
            StmtBreakParser stmtBreakParser = new StmtBreakParser(tokenList);
            StmtBreak stmtBreak = stmtBreakParser.parseStmtBreak();
            this.nodes.add(stmtBreak);
        }
        // Stmt -> 'continue' ';'
        else if (token.getType() == TokenType.CONTINUETK) {
            tokenList.fallbackToken(1);
            StmtContinueParser stmtContinueParser = new StmtContinueParser(tokenList);
            StmtContinue stmtContinue = stmtContinueParser.parseStmtContinue();
            this.nodes.add(stmtContinue);
        }
        // Stmt -> 'return' [Exp] ';'
        else if (token.getType() == TokenType.RETURNTK) {
            tokenList.fallbackToken(1);
            StmtReturnParser stmtReturnParser = new StmtReturnParser(tokenList);
            StmtReturn stmtReturn = stmtReturnParser.parseStmtReturn();
            this.nodes.add(stmtReturn);
        }
        // Stmt -> 'printf' '(' StringConst ...
        else if (token.getType() == TokenType.PRINTFTK) {
            tokenList.fallbackToken(1);
            StmtPrintfParser stmtPrintfParser = new StmtPrintfParser(tokenList);
            StmtPrintf stmtPrintf = stmtPrintfParser.parseStmtPrintf();
            this.nodes.add(stmtPrintf);
        }
        int startLine = this.nodes.get(0).getStarttLine();
        int endLine = this.nodes.get(nodes.size() - 1).getEndLine();
        Stmt stmt = new Stmt(startLine, endLine, "<Stmt>", this.nodes);
        return stmt;
    }

    // 1 Stmt -> LVal '=' Exp ';'
    // 2 Stmt -> LVal '=' 'getInt' ...
    // 3 Stmt -> LVal '=' 'getChar' ...
    // 4 Stmt -> LVal ';' 或 Stmt -> Exp ';' -> Ident '(' [FuncRParams] ')' ';'
    public int lValJudge() {
        tokenList.fallbackToken(1);
        Token ident = tokenList.getNextToken();
        Token token = tokenList.getNextToken();
        int cnt = 1;
        boolean hasAssign = false;
        // 如果 ';' 缺失则会读完全部内容，然后在fallback到LVal之前
        int preLine = ident.getLineNumber();
        int curLine = token.getLineNumber();
        // 考虑换行问题
        while (token.getType() != TokenType.SEMICN && tokenList.hasNext() && preLine == curLine) {
            if (token.getType() == TokenType.GETINTTK) {
                tokenList.fallbackToken(cnt);
                return 2;
            } else if (token.getType() == TokenType.GETCHARTK) {
                tokenList.fallbackToken(cnt);
                return 3;
            } else if (hasAssign) {
                tokenList.fallbackToken(cnt);
                return 1;
            }
            if (token.getType() == TokenType.ASSIGN) {
                hasAssign = true;
            }
            preLine = curLine;
            token = tokenList.getNextToken();
            curLine = token.getLineNumber();
            cnt++;
        }
        tokenList.fallbackToken(cnt);
        // 说明是Stmt -> Exp ';' -> LVal ';'
        return 4;
    }

}
