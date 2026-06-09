package frontend.parser.node;

import frontend.lexer.Token;
import frontend.parser.ParserType;
import frontend.parser.TreeNode;

import java.util.ArrayList;

public class FuncRParams extends TreeNode {
    private ArrayList<Exp> exps = new ArrayList<>();
    private ArrayList<Token> commas = new ArrayList<>();

    public void setExps(Exp exp) {
        this.exps.add(exp);
    }

    public void setCommas(Token token) {
        this.commas.add(token);
    }

    public FuncRParams(ParserType parserType, Token token) {
        super(parserType, token);
    }
}
