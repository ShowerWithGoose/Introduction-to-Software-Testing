package Parser.Func;

import Lexer.Token;
import Parser.TreeNode;

import java.util.ArrayList;
import java.util.concurrent.TransferQueue;

/**
 * @Description:
 * @date 2024/10/13
 */
public class FuncFParams implements TreeNode {
    private final String value="<FuncFParams>";
    private FuncFParam funcFParam;
    private ArrayList<Token> commmas;
    private ArrayList<FuncFParam> funcFParamArrayList;

    public FuncFParams(FuncFParam funcFParam, ArrayList<Token> commmas, ArrayList<FuncFParam> funcFParamArrayList) {
        this.funcFParam = funcFParam;
        this.commmas = commmas;
        this.funcFParamArrayList = funcFParamArrayList;
    }

    @Override
    public String print_tree() {
        StringBuilder sb=new StringBuilder();
        sb.append(this.funcFParam.print_tree());
        for(int i=0;i<commmas.size();i++){
            sb.append(this.commmas.get(i).toStringprint());
            sb.append(this.funcFParamArrayList.get(i).print_tree());
        }
        sb.append(this.value).append("\n");
        return sb.toString();
    }
}
