package frontend.Parser.Val;

import frontend.Parser.Output;

//常量初值 ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' |
//StringConst // 1.常表达式初值 2.一维数组初值
public class ConstInitVal implements Output {
    private final String name = "<ConstInitVal>";
    private ConstInitValInf constInitValInf;

    public ConstInitVal(ConstInitValInf constInitValInf) {
        this.constInitValInf = constInitValInf;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(constInitValInf.Parser_Output());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
