package middle.error;

public class Error implements Comparable<Error>{
    private String errorType;
    //虽然，类别码都是单个字符，我这里还是用string，不是为了
    //更好的扩展性，而是，parse里我写了Character类了，再引用官方这个类
    //之后写着写着我都不知道自己写的是啥类了
    // 所属错误类别
    private int lineNum; // 从1开始

    public Error(int lineNum, String type) {
        this.lineNum = lineNum;
        this.errorType = type;
    }

    public String getErrorType() {
        return errorType;
    }

    public int getLineNum() {
        return lineNum;
    }

    @Override
    public int compareTo(Error o) {
        return Integer.compare(this.lineNum, o.getLineNum());
    }

    public String output() {
        String s = new String(this.lineNum + " " + this.errorType + "\n");
        return s;
    }
}
