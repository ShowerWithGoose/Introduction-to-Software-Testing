package ast;

import IO.IO;
import enum_package.NodeType;
import enum_package.StmtType;
import frontend.Token;
import frontend.Parser;

import java.util.List;

public class StmtNode {
    public StmtType type;

    public Token reserveWords;
    public Token reserveWords2;
    public LValNode lVal;
    public Token assign; // 指向 '=' 的叶节点
    public ExpNode exp;
    public Token semicolon;
    public Token semicolon2;
    public BlockNode block;
    public CondNode cond;
    public StmtNode stmt;
    public StmtNode stmt2;
    public Token lParent;
    public Token rParent;
    public ForStmtNode forStmt;
    public ForStmtNode forStmt2;
    // LVal '=' Exp ';'
    // [Exp] ';'
    // Block
    // 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
    // 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
    // 'break' ';'
    // 'continue' ';'
    // 'return' [Exp] ';'
    // LVal '=' 'getint' '(' ')' ';'
    // LVal '=' 'getchar' '(' ')' ';'
    // 'printf' '(' StringConst {',' Exp} ')' ';'
    public List<Token> comma; // printf语句','
    public List<ExpNode> exps; // printf语句的表达式列表

    // 构造函数
    // LVal '=' Exp ';'
    public StmtNode(StmtType type, LValNode lValStmt_lVal, Token assign, ExpNode exp, Token semicn) {
        if (type == StmtType.LVAL_STMT) {
            this.type = StmtType.LVAL_STMT; // 设置类型
            this.lVal = lValStmt_lVal;
            this.assign = assign;
            this.exp = exp;
            this.semicolon = semicn;
        }        
    }

    // [Exp] ';'
    // 'return' [Exp] ';'
    public StmtNode(StmtType type, ExpNode exp, Token semicolon) {
        if (type == StmtType.EXP_STMT) {
            this.type = StmtType.EXP_STMT; // 设置类型
            this.exp = exp;
            this.semicolon = semicolon; // 默认设置为 ';'
        }
    }

    // 'return' [Exp] ';'
    public StmtNode(StmtType type, Token returntk, ExpNode exp, Token semicolon) {
        if(type == StmtType.RETURN_STMT){
            this.type = StmtType.RETURN_STMT; // 设置类型
            this.reserveWords = returntk;
            this.exp = exp;
            this.semicolon = semicolon; // 默认设置为 ';'
        }
    }

    // Block
    public StmtNode(StmtType type, BlockNode block) {
        if (type == StmtType.BLOCK_STMT) {
            this.type = StmtType.BLOCK_STMT; // 设置类型
            this.block = block;
        }        
    }

    // 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
    public StmtNode(StmtType type, Token ifStmt_if, Token lParent, CondNode cond, Token rParent, StmtNode firstStmt, Token reserveWords2, StmtNode lastStmt ) {
        if (type == StmtType.IF_STMT) {
            this.type = StmtType.IF_STMT; // 设置类型
            this.reserveWords = ifStmt_if;
            this.lParent = lParent;
            this.cond = cond;
            this.rParent = rParent;
            this.stmt = firstStmt;
            this.reserveWords2 = reserveWords2; // 默认设置为 "else"
            this.stmt2 = lastStmt;
        }        
    }

    // 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
    public StmtNode(StmtType type, Token forStmt_for, Token forStmt_lParent,
                    ForStmtNode forStmt, Token forStmt_first_semicolon,
                    CondNode forStmt_cond, Token forStmt_last_semicolon, ForStmtNode forStmt2,
                    Token forStmt_rParent, StmtNode forStmt_stmt) {
        if (type == StmtType.FOR_STMT) {
            this.type = StmtType.FOR_STMT;
            this.reserveWords = forStmt_for;
            this.lParent = forStmt_lParent;
            this.forStmt = forStmt;
            this.semicolon  = forStmt_first_semicolon;
            this.cond = forStmt_cond;
            this.semicolon2 = forStmt_last_semicolon;
            this.forStmt2 = forStmt2;
            this.rParent = forStmt_rParent;
            this.stmt = forStmt_stmt;
        }
    }

    // 'break' ';'
    // 'continue' ';'
    public StmtNode(StmtType type, Token token, Token semicolon) {
        if (type == StmtType.BREAK_STMT) {
            this.type = StmtType.BREAK_STMT; // 设置类型
            this.reserveWords = token;
            this.semicolon = semicolon; // 默认设置为 ';'
        } else if (type == StmtType.CONTINUE_STMT) {
            this.type = StmtType.CONTINUE_STMT; // 设置类型
            this.reserveWords = token;
            this.semicolon = semicolon; // 默认设置为 ';'
        }
    }

    // LVal '=' 'getint' '(' ')' ';'
    // LVal '=' 'getchar' '(' ')' ';'
    public StmtNode(StmtType type, LValNode lValStmt_lVal, Token assign, Token get, Token lParent, Token rParent, Token semicn) {
        if (type == StmtType.GETINT_STMT) {
            this.type = StmtType.GETINT_STMT; // 设置类型
            this.lVal = lValStmt_lVal;
            this.assign = assign;
            this.reserveWords = get;
            this.lParent = lParent;
            this.rParent = rParent;
            this.semicolon = semicn;
        } else if (type == StmtType.GETCHAR_STMT) {
            this.type = StmtType.GETCHAR_STMT; // 设置类型
            this.lVal = lValStmt_lVal;
            this.assign = assign;
            this.reserveWords = get;
            this.lParent = lParent;
            this.rParent = rParent;
            this.semicolon = semicn;
        }        
    }

    // 'printf' '(' StringConst {',' Exp} ')' ';'
    public StmtNode(StmtType type, Token printf, Token lParent, Token strcon, List<Token> commas, List<ExpNode> exps, Token rParent, Token semicn) {
        if (type == StmtType.PRINTF_STMT) {
            this.type = StmtType.PRINTF_STMT; // 设置类型
            this.reserveWords = printf;
            this.lParent = lParent;
            this.reserveWords2 = strcon;
            this.comma = commas;
            this.exps = exps;
            this.rParent = rParent;
            this.semicolon = semicn;
        }        
    }

    public StmtNode () {
    }

//    public void print() {
//        IO.write(Parser.nodeTypeLabel.get(NodeType.Stmt));
//    }

    public void print() {
        switch (type) {
            case LVAL_STMT:
                lVal.print();
                IO.write(assign.toString());
                exp.print();
                IO.write(semicolon.toString());
                break;
            case EXP_STMT:
                if (exp != null) {
                    exp.print();
                }
                IO.write(semicolon.toString());
                break;
            case BLOCK_STMT:
                block.print();
                break;
            case IF_STMT:
                IO.write(reserveWords.toString());
                IO.write(lParent.toString());
                cond.print();
                IO.write(rParent.toString());
                stmt.print();
                if (reserveWords2 != null) {
                    IO.write(reserveWords2.toString());
                    stmt2.print();
                }
                break;
            case FOR_STMT:
                IO.write(reserveWords.toString());
                IO.write(lParent.toString());
                if (forStmt != null) {
                    forStmt.print();
                }
                IO.write(semicolon.toString());
                if (cond != null) {
                    cond.print();
                }
                IO.write(semicolon2.toString());
                if (forStmt2 != null) {
                    forStmt2.print();
                }
                IO.write(rParent.toString());
                stmt.print();
                break;
            case BREAK_STMT:
                IO.write(reserveWords.toString());
                IO.write(semicolon.toString());
                break;
            case CONTINUE_STMT:
                IO.write(reserveWords.toString());
                IO.write(semicolon.toString());
                break;
            case RETURN_STMT:
                IO.write(reserveWords.toString());
                if (exp != null) {
                    exp.print();
                }
                IO.write(semicolon.toString());
                break;
            case GETINT_STMT:
                lVal.print();
                IO.write(assign.toString());
                IO.write(reserveWords.toString());
                IO.write(lParent.toString());
                IO.write(rParent.toString());
                IO.write(semicolon.toString());
                break;
            case GETCHAR_STMT:
                lVal.print();
                IO.write(assign.toString());
                IO.write(reserveWords.toString());
                IO.write(lParent.toString());
                IO.write(rParent.toString());
                IO.write(semicolon.toString());
                break;
            case PRINTF_STMT:
                IO.write(reserveWords.toString());
                IO.write(lParent.toString());
                IO.write(reserveWords2.toString());
                for(int i = 0; i< exps.size(); i++) {
                    IO.write(comma.get(i).toString());
                    exps.get(i).print();
                }
                IO.write(rParent.toString());
                IO.write(semicolon.toString());
                break;
        }
        IO.write(Parser.nodeTypeLabel.get(NodeType.Stmt));
    }
}
