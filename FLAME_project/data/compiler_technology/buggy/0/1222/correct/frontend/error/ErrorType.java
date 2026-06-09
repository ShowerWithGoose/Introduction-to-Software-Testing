package frontend.error;

public enum ErrorType {
    A("非法符号", "a"),
    B("名字重定义", "b"),
    C("未定义的名字", "c"),
    D("函数参数个数不匹配", "d"),
    E("函数参数类型不匹配", "e"),
    F("无返回值的函数存在不匹配的 return 语句", "f"),
    G("有返回值的函数缺少 return 语句", "g"),
    H("不能改变常量的值", "h"),
    I("缺少分号", "i"),
    J("缺少右小括号 ')'", "j"),
    K("缺少右中括号 '']'", "k"),
    L("printf 中格式字符与表达式个数不匹配", "l"),
    M("在非循环块中使用 break 和 continue 语句", "m"),
    N("未知的其他错误","n");


    private String nameString;
    private String kindString;

    ErrorType(String nameString, String kindString) {
        this.nameString = nameString;
        this.kindString = kindString;

    }
    
    public String getKindString() {
        return kindString;
    }

    public String getNameString() {
        return nameString;
    }

    public void setKindString(String kindString) {
        this.kindString = kindString;
    }

    public void setNameString(String nameString) {
        this.nameString = nameString;
    }
}
