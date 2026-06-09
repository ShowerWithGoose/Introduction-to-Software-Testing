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
    public Exp exp;

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
    public Token semicn;

    public Stmt() {

    }


    // PrintStmt
    //  'printf' '(' StringConst { ',' Exp} ')' ';'
    public Stmt(Token printfToken, Token lparent, Token stringConstToken,
                List<Token> commas, List<Exp> exps, Token rparent, Token semicn) {
        this.printfToken = printfToken;
        this.lparent = lparent;
        this.rparent = rparent;
        this.stringConstToken = stringConstToken;
        this.commas = commas;
        this.exps = exps;
        this.semicn = semicn;
        this.type = StmtType.PrintStmt;
        setLineNo(printfToken);
    }

    // | 'break' ';' | 'continue' ';'
    public Stmt(Token breakOrContinueToken, Token semicn) {
        this.semicn = semicn;
        if (breakOrContinueToken.type == TokenType.BREAKTK) {
            this.breakToken = breakOrContinueToken;
            this.type = StmtType.BreakStmt;
        } else {
            this.continueToken = breakOrContinueToken;
            this.type = StmtType.ContinueStmt;
        }
        setLineNo(breakOrContinueToken);
    }

    // 'return' [Exp] ';'
    public Stmt(Token returnToken, Token semicn, Exp exp) {
        this.semicn = semicn;
        this.returnToken = returnToken;
        this.exp = exp;
        this.type = StmtType.ReturnStmt;
        setLineNo(returnToken);
    }


    // Block
    public Stmt(Block block) {
        this.block = block;
        this.type = StmtType.BlockStmt;
        setLineNo(block);
    }

    //  'if' '(' Cond ')' Stmt ['else' Stmt]
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

    //  'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
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
            //  'if' '(' Cond ')' Stmt ['else' Stmt]
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
            //  'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
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
                info.append(semicn.getPrintInfo());
                break;
            case ContinueStmt:
                info.append(continueToken.getPrintInfo());
                info.append(semicn.getPrintInfo());
                break;
            // 'return' [Exp] ';'
            case ReturnStmt:
                info.append(returnToken.getPrintInfo());
                if(exp != null){
                    info.append(exp.getPrintInfo());
                }
                info.append(semicn.getPrintInfo());
                break;
            // 'printf' '(' StringConst { ',' Exp} ')' ';'
            case PrintStmt:
                info.append(printfToken.getPrintInfo());
                info.append(lparent.getPrintInfo());
                info.append(stringConstToken.getPrintInfo());
                if(commas != null){
                    for (int i = 0; i < commas.size(); i++) {
                        info.append(commas.get(i).getPrintInfo());
                        info.append(exps.get(i).getPrintInfo());
                    }
                }
                info.append(rparent.getPrintInfo());
                info.append(semicn.getPrintInfo());
                break;
            // LVal '=' Exp ';'
            case LValExpStmt:
                info.append(lVal.getPrintInfo());
                info.append(assign.getPrintInfo());
                info.append(exp.getPrintInfo());
                info.append(semicn.getPrintInfo());
                break;
            // | LVal '=' 'getint' '(' ')' ';'
            case GetIntStmt:
                info.append(lVal.getPrintInfo());
                info.append(assign.getPrintInfo());
                info.append(getIntToken.getPrintInfo());
                info.append(lparent.getPrintInfo());
                info.append(rparent.getPrintInfo());
                info.append(semicn.getPrintInfo());
                break;
            // | LVal '=' 'getchar' '(' ')' ';'
            case GetCharStmt:
                info.append(lVal.getPrintInfo());
                info.append(assign.getPrintInfo());
                info.append(getCharToken.getPrintInfo());
                info.append(lparent.getPrintInfo());
                info.append(rparent.getPrintInfo());
                info.append(semicn.getPrintInfo());
                break;
            // | [Exp] ';'
            case ExpStmt:
                if(exp != null){
                    info.append(exp.getPrintInfo());
                }
                info.append(semicn.getPrintInfo());
                break;
        }
        info.append("<Stmt>\n");
        return info;
    }
}
