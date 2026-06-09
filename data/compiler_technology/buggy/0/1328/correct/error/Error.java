package error;

public class Error implements Comparable<Error> {
    private ErrorType type;
    private int lineNum;

    public Error(ErrorType type, int lineNum) {
        this.type = type;
        this.lineNum = lineNum;
    }

    /**
     * @param e 与当前Error对象比较的另一个Error对象
     * @return int
     * @Description 使Error对象按照行号进行排序
     * @date 2024/9/23 22:24
     * @version 1.0
     */
    public int compareTo(Error e) {
        if (lineNum > e.lineNum) {
            return 1;
        } else if (lineNum < e.lineNum) {
            return -1;
        }
        return 0;
    }

    /**
     * @return java.lang.String
     * @Description 错误信息输出格式
     * @date 2024/9/23 20:34
     * @version 1.0
     */
    public String toString() {
        return lineNum + " " + type.toString() + "\n";
    }
}
