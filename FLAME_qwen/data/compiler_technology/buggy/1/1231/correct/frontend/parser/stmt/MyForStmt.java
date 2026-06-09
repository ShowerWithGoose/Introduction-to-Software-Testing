package frontend.parser.stmt;

import java.util.ArrayList;

import frontend.TokenIterator;
import frontend.parser.exp.Cond;
import nodes.SyntaxNode;
import nodes.Token;
import nodes.TokenType;

// MyForStmt      ==>       'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt // h
public class MyForStmt implements StmtNode {

    private TokenIterator tokens;
    private ArrayList<SyntaxNode> children = new ArrayList<>();

    private ForStmt forStmt1 = null; // optional
    private Cond cond = null; // optional
    private ForStmt forStmt2 = null; // optional
    private Stmt stmt;

    public MyForStmt(TokenIterator tokens) {
        this.tokens = tokens;
    }

    @Override
    public String syntaxPrinter() {
        StringBuilder sb = new StringBuilder();
        children.forEach(child -> sb.append(child.syntaxPrinter()));
        return sb.toString();
    }

    @Override
    public boolean parse() {
        Token forToken = tokens.next();
        children.add(forToken);

        Token lParent = tokens.next();
        children.add(lParent);

        Token checkSemicon = tokens.next();
        if (checkSemicon.getType().equals(TokenType.SEMICN)) {
            tokens.stepBack(1);
        } else {
            tokens.stepBack(1);
            forStmt1 = new ForStmt(tokens);
            forStmt1.parse();
            children.add(forStmt1);
        }
        Token semicon1 = tokens.next();
        children.add(semicon1);

        checkSemicon = tokens.next();
        if (checkSemicon.getType().equals(TokenType.SEMICN)) {
            tokens.stepBack(1);
        } else {
            tokens.stepBack(1);
            cond = new Cond(tokens);
            cond.parse();
            children.add(cond);
        }
        Token semicon2 = tokens.next();
        children.add(semicon2);

        Token checkRParent = tokens.next();
        if (checkRParent.getType().equals(TokenType.RPARENT)) {
            tokens.stepBack(1);
        } else {
            tokens.stepBack(1);
            forStmt2 = new ForStmt(tokens);
            forStmt2.parse();
            children.add(forStmt2);
        }
        Token rParent = tokens.next();
        children.add(rParent);

        stmt = new Stmt(tokens);
        stmt.parse();
        children.add(stmt);

        return true;
    }
}
