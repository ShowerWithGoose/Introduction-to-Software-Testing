package CompileErrors;

/**
 * @author
 * @Description:
 * @date 2024/9/29 13:45
 */
public class CompileError {
    public int errorLine;
    public char errorCode;

    public CompileError(int errorLine, char errorCode) {
        this.errorLine = errorLine;
        this.errorCode = errorCode;
    }
}
