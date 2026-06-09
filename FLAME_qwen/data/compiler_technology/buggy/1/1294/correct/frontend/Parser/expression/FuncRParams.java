package frontend.Parser.expression;

import frontend.Lexer.Token;
import frontend.Parser.GrammarNode;

import java.util.ArrayList;

//函数实参表
public class FuncRParams implements GrammarNode {
    private final String grammarName = "<FuncRParams>";
    private Exp firstExp;
    private ArrayList<Token> commas;
    private ArrayList<Exp> expList;

    public FuncRParams(Exp firstExp, ArrayList<Token> commas, ArrayList<Exp> expList) {
        this.firstExp = firstExp;
        this.commas = commas;
        this.expList = expList;
    }
    @Override
    public String grammarOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(firstExp.grammarOutput());
        if(commas != null && expList != null && commas.size() == expList.size()){
            for(int i = 0; i<commas.size(); i++){
                sb.append(commas.get(i).grammarOutput());
                sb.append(expList.get(i).grammarOutput());
            }
        }
        sb.append(this.grammarName).append("\n");
        return sb.toString();
    }
}
