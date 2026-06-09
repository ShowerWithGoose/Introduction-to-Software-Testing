package fronted.Parser.SyntaxTree;

import fronted.Lexer.Token;

import java.util.ArrayList;

/**
 * @author
 * @Description:
 * @date 2024/10/13 10:45
 */
public class FuncFParams implements SyntaxNode{
    private final String name = "<FuncFParams>";
    private FuncFParam necFuncFParam;
    private ArrayList<Token> commas = null; // ','may
    private ArrayList<FuncFParam> funcFParams = null; // may

    public FuncFParams(FuncFParam necFuncFParam, ArrayList<Token> commas, ArrayList<FuncFParam> funcFParams) {
        this.necFuncFParam = necFuncFParam;
        this.commas = commas;
        this.funcFParams = funcFParams;
    }

    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.necFuncFParam.output());
        if (!this.commas.isEmpty() && !this.funcFParams.isEmpty() && this.commas.size() == this.funcFParams.size()) {
            int len = this.commas.size();
            for (int i = 0; i < len; i++) {
                sb.append(this.commas.get(i).output());
                sb.append(this.funcFParams.get(i).output());
            }
        }
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
