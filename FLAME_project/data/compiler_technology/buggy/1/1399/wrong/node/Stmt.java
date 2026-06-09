/********************************************************************************
 * @FileName     : Stmt.java
 * @Author       :
 * @Description  : 语句
 * @Notice       :     // Stmt -> LVal '=' Exp ';'
 *                     	| [Exp] ';'
 *                     	| Block
 *                     	| 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
 *                     	| 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
 *                     	| 'break' ';' | 'continue' ';'
 *                     	| 'return' [Exp] ';'
 *                     	| LVal '=' 'getint' '(' ')' ';'
 *                      | LVal '=' 'getchar''('')'';'
 *                     	| 'printf' '(' FormatString { ',' Exp } ')' ';'
 * @Time         : 2024-10-03 19:51
 * @Version      : 0.0
 ********************************************************************************/

package node;

import frontend.Token;
import type.ASTNodeType;
import utils.IOTools;

import java.util.List;

public class Stmt implements ASTNode {
    public enum StmtType {
        Assign, Exp, Block, ifBranch, forBranch, breakStmt, continueStmt, returnStmt, inputInt, intputChar, print, None
    }

    private StmtType type;
    private LVal lVal;
    private Token assignToken;
    private Exp exp;
    private Token semicnToken;
    private Block block;
    private Token ifToken;
    private Token leftParentToken;
    private Cond cond;
    private Token rightParentToken;
    private List<Stmt> stmts;
    private Token elseToken;
    private Token forToken;
    private Token breakOrContinueToken;
    private Token returnToken;
    private Token getintToken;
    private Token printfToken;
    private Token formatString;
    private List<Token> commas;
    private List<Exp> exps;
    private ForStmt forStmt1;
    private ForStmt forStmt2;
    private List<Token> semicnList;

    public Stmt(StmtType type, LVal lVal, Token assignToken, Exp exp, Token semicnToken) {
        // LVal '=' Exp ';'
        this.type = type;
        this.lVal = lVal;
        this.assignToken = assignToken;
        this.exp = exp;
        this.semicnToken = semicnToken;
    }

    public Stmt(StmtType type, Exp exp, Token semicnToken) {
        // [Exp] ';'
        this.type = type;
        this.exp = exp;
        this.semicnToken = semicnToken;
    }

    public Stmt(StmtType type, Block block) {
        // Block
        this.type = type;
        this.block = block;
    }

    public Stmt(StmtType type, Token ifToken, Token leftParentToken, Cond cond, Token rightParentToken, List<Stmt> stmts, Token elseToken) {
        // 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
        this.type = type;
        this.ifToken = ifToken;
        this.leftParentToken = leftParentToken;
        this.cond = cond;
        this.rightParentToken = rightParentToken;
        this.stmts = stmts;
        this.elseToken = elseToken;
    }

    public Stmt(StmtType type, Token forToken, Token leftParentToken, ForStmt forStmt1, Cond cond, ForStmt forStmt2, Token rightParentToken, List<Stmt> stmts, List<Token> semicnList) {
        // 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
        this.type = type;
        this.forToken = forToken;
        this.leftParentToken = leftParentToken;
        this.forStmt1 = forStmt1;
        this.cond = cond;
        this.forStmt2 = forStmt2;
        this.rightParentToken = rightParentToken;
        this.stmts = stmts;
        this.semicnList = semicnList;
    }

    public Stmt(StmtType type, Token breakOrContinueToken, Token semicnToken) {
        // 'break' ';'
        this.type = type;
        this.breakOrContinueToken = breakOrContinueToken;
        this.semicnToken = semicnToken;
    }

    public Stmt(StmtType type, Token returnToken, Exp exp, Token semicnToken) {
        // 'return' [Exp] ';'
        this.type = type;
        this.returnToken = returnToken;
        this.exp = exp;
        this.semicnToken = semicnToken;
    }

    public Stmt(StmtType type, LVal lVal, Token assignToken, Token getintToken, Token leftParentToken, Token rightParentToken, Token semicnToken) {
        // LVal '=' 'getint' '(' ')' ';'
        this.type = type;
        this.lVal = lVal;
        this.assignToken = assignToken;
        this.getintToken = getintToken;
        this.leftParentToken = leftParentToken;
        this.rightParentToken = rightParentToken;
        this.semicnToken = semicnToken;
    }

    public Stmt(StmtType type, Token printfToken, Token leftParentToken, Token formatString, List<Token> commas, List<Exp> exps, Token rightParentToken, Token semicnToken) {
        // 'printf' '(' FormatString { ',' Exp } ')' ';'
        this.type = type;
        this.printfToken = printfToken;
        this.leftParentToken = leftParentToken;
        this.formatString = formatString;
        this.commas = commas;
        this.exps = exps;
        this.rightParentToken = rightParentToken;
        this.semicnToken = semicnToken;
    }

    @Override
    public void printInfo() {
        switch (type) {
            case Assign:
                // LVal '=' Exp ';'
                lVal.printInfo();
                IOTools.parserOutput(assignToken.toString());
                exp.printInfo();
                IOTools.parserOutput(semicnToken.toString());
                break;
            case Exp:
                // [Exp] ';'
                if (exp != null) exp.printInfo();
                IOTools.parserOutput(semicnToken.toString());
                break;
            case Block:
                // Block
                block.printInfo();
                break;
            case ifBranch:
                // 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
                IOTools.parserOutput(ifToken.toString());
                IOTools.parserOutput(leftParentToken.toString());
                cond.printInfo();
                IOTools.parserOutput(rightParentToken.toString());
                stmts.get(0).printInfo();
                if (elseToken != null) {
                    IOTools.parserOutput(elseToken.toString());
                    stmts.get(1).printInfo();
                }
                break;
            case forBranch:
                // 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
                IOTools.parserOutput(forToken.toString());
                IOTools.parserOutput(leftParentToken.toString());
                if (forStmt1 != null)
                    forStmt1.printInfo();
                IOTools.parserOutput(semicnList.get(0).toString());
                if (cond != null)
                    cond.printInfo();
                IOTools.parserOutput(semicnList.get(1).toString());
                if (forStmt2 != null)
                    forStmt2.printInfo();
                IOTools.parserOutput(rightParentToken.toString());
                stmts.get(0).printInfo();
                break;
            case breakStmt:
                // 'break' ';'
            case continueStmt:
                // 'continue' ';'
                IOTools.parserOutput(breakOrContinueToken.toString());
                IOTools.parserOutput(semicnToken.toString());
                break;
            case returnStmt:
                // 'return' [Exp] ';'
                IOTools.parserOutput(returnToken.toString());
                if (exp != null) {
                    exp.printInfo();
                }
                IOTools.parserOutput(semicnToken.toString());
                break;
            case inputInt:
                // LVal '=' 'getint' '(' ')' ';'
                lVal.printInfo();
                IOTools.parserOutput(assignToken.toString());
                IOTools.parserOutput(getintToken.toString());
                IOTools.parserOutput(leftParentToken.toString());
                IOTools.parserOutput(rightParentToken.toString());
                IOTools.parserOutput(semicnToken.toString());
                break;
            case intputChar:
                // LVal '=' 'getchar' '(' ')' ';'
                lVal.printInfo();
                IOTools.parserOutput(assignToken.toString());
                IOTools.parserOutput(getintToken.toString());
                IOTools.parserOutput(leftParentToken.toString());
                IOTools.parserOutput(rightParentToken.toString());
                IOTools.parserOutput(semicnToken.toString());
                break;
            case print:
                // 'printf' '(' FormatString { ',' Exp } ')' ';'
                IOTools.parserOutput(printfToken.toString());
                IOTools.parserOutput(leftParentToken.toString());
                IOTools.parserOutput(formatString.toString());
                for (int i = 0; i < commas.size(); i++) {
                    IOTools.parserOutput(commas.get(i).toString());
                    exps.get(i).printInfo();
                }
                IOTools.parserOutput(rightParentToken.toString());
                IOTools.parserOutput(semicnToken.toString());
                break;
        }
        IOTools.parserOutput(ASTNodeType.Stmt.toString());
    }
}
