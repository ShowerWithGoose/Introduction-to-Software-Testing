package frontend.error;

public class Error {
    private String type;
    private int lineNum;

    public Error(String type, int lineNum) {
        this.type = type;
        this.lineNum = lineNum;
    }

    public String getType() {
        return type;
    }

    public int getLineNum() {
        return lineNum;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Error at line " + lineNum + " " + type + ":");
        switch (type) {
            case "a": sb.append("非法符号"); break;
            case "b": sb.append("名字重定义"); break;
            case "c": sb.append("未定义的名字"); break;
            case "d": sb.append("函数参数个数不匹配"); break;
            case "e": sb.append("函数参数类型不匹配"); break;
            case "f": sb.append("无返回值的函数存在不匹配的return语句"); break;
            case "g": sb.append("有返回值的函数缺少return语句"); break;
            case "h": sb.append("不能改变常量的值"); break;
            case "i": sb.append("缺少分号"); break;
            case "j": sb.append("缺少右小括号\')\'"); break;
            case "k": sb.append("缺少右中括号\']\'"); break;
            case "l": sb.append("printf中格式字符与表达式个数不匹配"); break;
            case "m": sb.append("在非循环块中使用break和continue语句"); break;
            default: sb.append("未知错误"); break;
        }
        return sb.toString();
    }
}
