package frontend.Parser.function;

import frontend.Lexer.Token;
import frontend.Parser.GrammarNode;

import java.util.ArrayList;

public class FuncFParams implements GrammarNode {
    private final String grammarName = "<FuncFParams>";
    private FuncFParam firstParam;
    private ArrayList<Token> commas;
    private ArrayList<FuncFParam> funcParams;

    public FuncFParams(FuncFParam firstParam) {
        this.firstParam = firstParam;
    }

    public FuncFParams(FuncFParam firstParam, ArrayList<Token> commas, ArrayList<FuncFParam> funcParams) {
        this(firstParam);
        this.commas = commas;
        this.funcParams = funcParams;
    }

    @Override
    public String grammarOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(firstParam.grammarOutput());
        if (commas != null && funcParams != null && commas.size() == funcParams.size()) {
            for (int i = 0; i < commas.size(); i++) {
                sb.append(commas.get(i).grammarOutput());
                sb.append(funcParams.get(i).grammarOutput());
            }
        }
        sb.append(this.grammarName).append("\n");
        return sb.toString();
    }
}
