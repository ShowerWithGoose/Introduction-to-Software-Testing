package fault;

/**
 * 错误信息类
 */
public class FaultInfo {
    /**
     * 错误码
     */
    char code;
    /**
     * 错误行数
     */
    int line;

    /**
     * 错误信息构造方法
     * @param code 错误码
     * @param line 行数
     */
    public FaultInfo(char code, int line) {
        this.code = code;
        this.line = line;
    }

    /**
     * 重写 toString 方法
     * @return 一行错误信息的输出
     */
    @Override
    public String toString() {
        return line + " " + code;
    }
}
