package frontend.Parser.Func;

import frontend.Token;
import frontend.Parser.Exp.Exp;
import frontend.Parser.Output;

import java.util.ArrayList;

//函数实参表 FuncRParams → Exp { ',' Exp } // 1.花括号内重复0次 2.花括号内重复多次 3.Exp需
//要覆盖数组传参和部分数组传参
public class FuncRParams implements Output {
    private final String name = "<FuncRParams>";
    private Exp first;
    private ArrayList<Token> commas = new ArrayList<>();
    private ArrayList<Exp> exps = new ArrayList<>();

    public FuncRParams(Exp first) {
        this.first = first;
    }
    public FuncRParams(Exp first, ArrayList<Token> commas, ArrayList<Exp> exps) {
        this.first = first;
        this.commas = commas;
        this.exps = exps;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.first.Parser_Output());
        if(this.commas != null && this.exps != null && this.commas.size() == this.exps.size()) {
            for(int i = 0; i < this.commas.size(); i++) {
                sb.append(this.commas.get(i).toString());
                sb.append(this.exps.get(i).Parser_Output());
            }
        }
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
