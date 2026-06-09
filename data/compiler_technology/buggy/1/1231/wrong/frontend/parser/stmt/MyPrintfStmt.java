package frontend.parser.stmt;

import java.util.ArrayList;

import error.ErrorHandler;
import frontend.TokenIterator;
import frontend.parser.decl.StringConst;
import frontend.parser.exp.Exp;
import nodes.SyntaxNode;
import nodes.Token;
import nodes.TokenType;

// MyPrintfStmt      == > 'printf''('StringConst {','Exp}')'';' //i j l 
public class MyPrintfStmt implements StmtNode {
    private TokenIterator tokens;
    private ArrayList<SyntaxNode> children = new ArrayList<>();

    private StringConst stringConst;
    private ArrayList<Exp> exps = new ArrayList<>(); // optional

    public MyPrintfStmt(TokenIterator tokens) {
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
        Token token = tokens.next();
        // 'printf'
        children.add(token);

        // '('
        token = tokens.next();
        children.add(token);

        stringConst = new StringConst(tokens);
        stringConst.parse();
        children.add(stringConst);

        exps = new ArrayList<>();
        while (tokens.hasNext()) {
            token = tokens.next();
            if (token.getType().equals(TokenType.COMMA)) {
                children.add(token);

                Exp exp = new Exp(tokens);
                exp.parse();
                exps.add(exp);
                children.add(exp);
            } else {
                tokens.stepBack(1);
                break;
            }
        }

        ErrorHandler.handleJError(tokens, children);
        ErrorHandler.handleIError(tokens, children);

        return true;
    }

}
