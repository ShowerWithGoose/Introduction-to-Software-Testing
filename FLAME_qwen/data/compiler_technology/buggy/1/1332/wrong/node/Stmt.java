package node;

import token.Token;
import token.TokenType;

import java.util.List;

/**
 * ClassName: Stmt
 * Package: node
 * Description:
 *
 * @Author
 * @Create 2024/10/4 16:03
 * @Version 1.0
 */
public class Stmt extends Node {
    // Stmt =>
    // LVal '=' Exp ';'
    // | LVal '=' 'getint' '(' ')' ';'
    // | LVal '=' 'getchar' '(' ')' ';'
    // | [Exp] ';'
    // | Block
    // | 'if' '(' Cond ')' Stmt ['else' Stmt]
    // | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
    // | 'break' ';' | 'continue' ';' | 'return' [Exp] ';'
    // | 'printf' '(' StringConst { ',' Exp} ')' ';'

    // while ? todo?
    public StmtType type;
    public LVal lVal;
    public Token assign;
    public List<Exp> exps;

    public Block block;

    public Token ifToken;
    public Token lparent;
    public Cond cond;
    public Token rparent;
    public Stmt ifStmt;
    public Stmt stmt;
    public Token elseToken;
    public Stmt elseStmt;
    public Token forToken;
    public ForStmt forStmt1;
    public ForStmt forStmt2;
    public Token breakToken;
    public Token continueToken;
    public Token returnToken;
    public Token getIntToken;
    public Token getCharToken;
    public Token printfToken;
    public Token stringConstToken;
    public List<Token> commas;
    public List<Token> semicns;

    public Stmt() {

    }


    // PrintStmt
    public Stmt(Token printfToken, Token lparent, Token stringConstToken,
                List<Token> commas, List<Exp> exps, Token rparent, List<Token> semicns) {
        this.printfToken = printfToken;
        this.lparent = lparent;
        this.rparent = rparent;
        this.stringConstToken = stringConstToken;
        this.commas = commas;
        this.exps = exps;
        this.semicns = semicns;
        this.type = StmtType.PrintStmt;
        setLineNo(printfToken);
    }

    public Stmt(Token breakOrContinueToken, List<Token> semicns) {
        this.semicns = semicns;
        if (breakOrContinueToken.type == TokenType.BREAKTK) {
            this.breakToken = breakOrContinueToken;
            this.type = StmtType.BreakStmt;
        } else {
            this.continueToken = breakOrContinueToken;
            this.type = StmtType.ContinueStmt;
        }
        setLineNo(breakOrContinueToken);
    }

    public Stmt(Token returnToken, List<Token> semicns, List<Exp> exps) {
        this.semicns = semicns;
        this.returnToken = returnToken;
        this.exps = exps;
        this.type = StmtType.ReturnStmt;
        setLineNo(returnToken);
    }


    public Stmt(Block block) {
        this.block = block;
        this.type = StmtType.BlockStmt;
        setLineNo(block);
    }

    public Stmt(Token ifToken, Token lparent, Cond cond, Token rparent, Stmt ifStmt, Token elseToken, Stmt elseStmt) {
        this.ifToken = ifToken;
        this.lparent = lparent;
        this.cond = cond;
        this.rparent = rparent;
        this.ifStmt = ifStmt;
        this.elseToken = elseToken;
        this.elseStmt = elseStmt;
        this.type = StmtType.IfStmt;
        setLineNo(ifToken);
    }

    public Stmt(Token forToken, Token lparent, ForStmt forStmt1, List<Token> semicns,
                Cond cond, ForStmt forStmt2, Token rparent, Stmt stmt) {
        this.forToken = forToken;
        this.lparent = lparent;
        this.forStmt1 = forStmt1;
        this.semicns = semicns;
        this.cond = cond;
        this.forStmt2 = forStmt2;
        this.rparent = rparent;
        this.stmt = stmt;
        this.type = StmtType.ForStmt;
        setLineNo(forToken);
    }

    public StringBuilder getPrintInfo() {
        StringBuilder info = new StringBuilder();
        switch (type) {
            case BlockStmt:
                info.append(block.getPrintInfo());
                break;
            case IfStmt:
                info.append(ifToken.getPrintInfo());
                info.append(lparent.getPrintInfo());
                info.append(cond.getPrintInfo());
                info.append(rparent.getPrintInfo());
                info.append(ifStmt.getPrintInfo());
                if (elseToken != null) {
                    info.append(elseToken.getPrintInfo());
                    info.append(elseStmt.getPrintInfo());
                }
                break;
            case ForStmt:
                info.append(forToken.getPrintInfo());
                info.append(lparent.getPrintInfo());
                if (forStmt1 != null) {
                    info.append(forStmt1.getPrintInfo());
                }
                info.append(semicns.get(0).getPrintInfo());
                if (cond != null) {
                    info.append(cond.getPrintInfo());
                }
                info.append(semicns.get(1).getPrintInfo());
                if (forStmt2 != null) {
                    info.append(forStmt2.getPrintInfo());
                }
                info.append(rparent.getPrintInfo());
                info.append(stmt.getPrintInfo());
                break;
            case BreakStmt:
                info.append(breakToken.getPrintInfo());
                info.append(semicns.get(0).getPrintInfo());
                break;
            case ContinueStmt:
                info.append(continueToken.getPrintInfo());
                info.append(semicns.get(0).getPrintInfo());
                break;
            case ReturnStmt:
                info.append(returnToken.getPrintInfo());
                if (exps.size() > 0 && exps.get(0) != null) {
                    info.append(exps.get(0).getPrintInfo());
                }
                info.append(semicns.get(0).getPrintInfo());
                break;
            case PrintStmt:
                info.append(printfToken.getPrintInfo());
                info.append(lparent.getPrintInfo());
                info.append(stringConstToken.getPrintInfo());
                for (int i = 0; i < commas.size(); i++) {
                    info.append(commas.get(i).getPrintInfo());
                    info.append(exps.get(i).getPrintInfo());
                }
                info.append(rparent.getPrintInfo());
                info.append(semicns.get(0).getPrintInfo());
                break;
            case LValExpStmt:
                info.append(lVal.getPrintInfo());
                info.append(assign.getPrintInfo());
                info.append(exps.get(0).getPrintInfo());
                info.append(semicns.get(0).getPrintInfo());
                break;
            case GetIntStmt:
                info.append(lVal.getPrintInfo());
                info.append(assign.getPrintInfo());
                info.append(getIntToken.getPrintInfo());
                info.append(lparent.getPrintInfo());
                info.append(rparent.getPrintInfo());
                info.append(semicns.get(0).getPrintInfo());
                break;
            case GetCharStmt:
                info.append(lVal.getPrintInfo());
                info.append(assign.getPrintInfo());
                info.append(getCharToken.getPrintInfo());
                info.append(lparent.getPrintInfo());
                info.append(rparent.getPrintInfo());
                info.append(semicns.get(0).getPrintInfo());
                break;
            case ExpStmt:
                if (exps.size() > 0) {
                    info.append(exps.get(0).getPrintInfo());
                }
                info.append(semicns.get(0).getPrintInfo());
                break;
        }
        info.append("<Stmt>\n");
        return info;
    }
}
