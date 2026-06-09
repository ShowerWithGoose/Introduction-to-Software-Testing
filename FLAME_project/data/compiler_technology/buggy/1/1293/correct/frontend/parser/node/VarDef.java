package frontend.parser.node;

import frontend.error.ErrorProcess;
import frontend.lexer.Token;
import frontend.parser.Parser;
import frontend.parser.ParserType;
import frontend.parser.TreeNode;

import java.util.HashMap;

public class VarDef extends TreeNode {
    private Token identToken = null;
    private Token lToken = null;
    private Token rToken = null;
    private Token assignToken = null;
    private ConstExp constExp = null;
    private InitVal initVal = null;

    public void setIdentToken(Token identToken) {
        this.identToken = identToken;
    }

    public void setlToken(Token lToken) {
        this.lToken = lToken;
    }

    public void setrToken(Token rToken) {
        this.rToken = rToken;
    }

    public void setAssignToken(Token assignToken) {
        this.assignToken = assignToken;
    }

    public void setConstExp(ConstExp constExp) {
        this.constExp = constExp;
    }

    public void setInitVal(InitVal initVal) {
        this.initVal = initVal;
    }

    public VarDef(ParserType parserType, Token token) {
        super(parserType, token);
    }
}
