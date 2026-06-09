package frontend.parser.node;

import frontend.lexer.Token;
import frontend.parser.ParserType;
import frontend.parser.TreeNode;

import java.util.ArrayList;

public class FuncFParams extends TreeNode {
    private ArrayList<FuncFParam> funcFParams = new ArrayList<>();
    private ArrayList<Token> commas = new ArrayList<>();

    public void setFuncFParams(FuncFParam funcFParam) {
        this.funcFParams.add(funcFParam);
    }

    public void setCommas(Token token) {
        this.commas.add(token);
    }

    public FuncFParams(ParserType parserType, Token token) {
        super(parserType, token);
    }
}
