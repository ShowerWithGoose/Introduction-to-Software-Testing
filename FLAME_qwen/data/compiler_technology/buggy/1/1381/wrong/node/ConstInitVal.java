package node;

import frontend.Parser;

import java.util.ArrayList;

public class ConstInitVal {
    private Parser.SyntaxType nodeType = Parser.SyntaxType.ConstInitVal;
    private ConstExp constExp;

    // 或者是一个字符串常量
    private String stringConst;

    // 或者是一个花括号内的常量表达式列表
    private ArrayList<ConstExp> initList;

    // 构造函数，用于常量表达式的情况
    public ConstInitVal(ConstExp constExp) {
        this.constExp = constExp;
        this.stringConst = null;
        this.initList = null;
    }

    // 构造函数，用于字符串常量的情况
    public ConstInitVal(String stringConst) {
        this.stringConst = stringConst;
        this.constExp = null;
        this.initList = null;
    }

    // 构造函数，用于花括号内的常量表达式列表的情况
    public ConstInitVal(ArrayList<ConstExp> initList) {
        this.initList = initList;
        this.stringConst = null;
        this.constExp = null;
    }

    public ConstExp getConstExp() {
        return constExp;
    }

    public String getStringConst() {
        return stringConst;
    }

    public ArrayList<ConstExp> getInitList() {
        return initList;
    }

    public String toString() {
        StringBuilder ret = new StringBuilder("<" + nodeType + ">");
        if (constExp != null) {
            ret.append("\n").append(constExp);
        } else if (stringConst != null) {
            ret.append("\n").append(stringConst);
        } else if (initList != null) {
            for (ConstExp exp : initList) {
                ret.append("\n").append(exp);
            }
        }
        ret.append("\n<").append(nodeType).append("> <END>");
        return ret.toString();
    }
}