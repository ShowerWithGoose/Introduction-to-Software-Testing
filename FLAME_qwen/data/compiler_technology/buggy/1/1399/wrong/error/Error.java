/********************************************************************************
 * @FileName     : Error.java
 * @Author       :
 * @Description  : 异常类
 * @Notice       : None
 * @Time         : 2024-10-03 21:30
 * @Version      : 0.0
 ********************************************************************************/

package error;

public class Error extends RuntimeException {
    public ErrorType errorType;
    public int lineNumber;

    public Error(ErrorType type, int lineNumber) {
        this.errorType = type;
        this.lineNumber = lineNumber;
    }

    @Override
    public String toString() {
        return lineNumber + " " + errorType.toString();
    }

    /**
     * 获取
     *
     * @return errorType
     */
    public ErrorType getErrorType() {
        return errorType;
    }

    /**
     * 设置
     *
     * @param errorType 错误类型
     */
    public void setErrorType(ErrorType errorType) {
        this.errorType = errorType;
    }

    /**
     * 获取
     *
     * @return lineNumber
     */
    public int getLineNumber() {
        return lineNumber;
    }

    /**
     * 设置
     *
     * @param lineNumber 行号
     */
    public void setLineNumber(int lineNumber) {
        this.lineNumber = lineNumber;
    }
}
