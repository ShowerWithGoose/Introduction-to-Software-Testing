package src.errorHandle;

/**
 * 错误信息封装类，包含错误类型和所在行号
 */
public class Error {

    private ErrorType errorType; // 错误类型
    private int errorRow; // 错误行号（从0开始，输出时注意）
    private int errorCol; // 错误列号（从0开始，输出时注意）

    public Error(ErrorType errorType, int errorRow, int errorCol) {
        this.errorType = errorType;
        this.errorRow = errorRow;
        this.errorCol = errorCol;
    }

    public ErrorType getErrorType() {
        return errorType;
    }

    public void setErrorType(ErrorType errorType) {
        this.errorType = errorType;
    }

    public int getErrorRow() {
        return errorRow;
    }

    public void setErrorRow(int errorRow) {
        this.errorRow = errorRow;
    }

    public int getErrorCol() {
        return errorCol;
    }

    public void setErrorCol(int errorCol) {
        this.errorCol = errorCol;
    }
}
