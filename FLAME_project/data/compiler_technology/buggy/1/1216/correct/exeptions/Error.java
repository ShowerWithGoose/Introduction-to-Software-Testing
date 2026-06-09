package exeptions;
// 负责前端编译过程中的出错处理
public class Error {
    ErrorType errorType;
    int lineNum;
    public Error(ErrorType errorType, int lineNum) {
        this.lineNum = lineNum;
        this.errorType = errorType;
    }
    @Override
    public String toString() {
        return String.format("%d %s\n", lineNum, errorType);
    }
}
