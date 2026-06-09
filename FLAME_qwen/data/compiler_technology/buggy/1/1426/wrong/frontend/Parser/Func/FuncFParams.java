package frontend.Parser.Func;

import frontend.Token;
import frontend.Parser.Output;

import java.util.ArrayList;

//函数形参表 FuncFParams → FuncFParam { ',' FuncFParam } // 1.花括号内重复0次 2.花括号内
//重复多次
public class FuncFParams implements Output {
    private final String name = "<FuncFParams>";
    private FuncFParam first;
    private ArrayList<Token> commas = new ArrayList<>();
    private ArrayList<FuncFParam> funcFParams = new ArrayList<>();

    public FuncFParams(FuncFParam first) {
        this.first = first;
    }
    public FuncFParams(FuncFParam first,ArrayList<Token> commas, ArrayList<FuncFParam> funcFParams) {
        this.first = first;
        this.commas = commas;
        this.funcFParams = funcFParams;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.first.Parser_Output());
        if(this.commas != null && this.funcFParams != null && this.commas.size() == this.funcFParams.size()) {
            for(int i = 0; i < this.funcFParams.size(); i++) {
                sb.append(this.commas.get(i).toString());
                sb.append(this.funcFParams.get(i).Parser_Output());
            }
        }
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
