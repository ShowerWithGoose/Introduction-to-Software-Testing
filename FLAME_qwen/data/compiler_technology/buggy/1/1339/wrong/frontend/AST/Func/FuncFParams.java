package frontend.AST.Func;

import frontend.AST.AST;
import frontend.AST.SyntaxNode;
import frontend.TokenType;

import java.util.ArrayList;

//FuncFParams â†’ FuncFParam { ',' FuncFParam }
public class FuncFParams implements SyntaxNode {
    private ArrayList<FuncFParam> funcFParams;

    public FuncFParams(ArrayList<FuncFParam> funcFParams) {
        this.funcFParams = funcFParams;
    }

    @Override
    public void print() {
        funcFParams.get(0).print();
        for(int i= 1; i < funcFParams.size(); i++){
            AST.ast.addLine(TokenType.COMMA + " ,");
            funcFParams.get(i).print();
        }
        AST.ast.addLine(getName());
    }

    @Override
    public String getName() {
        return "<FuncFParams>";
    }
}
