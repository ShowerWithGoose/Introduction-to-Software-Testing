package util.exception;


/**
 * 前端出现的异常，包括词法分析和语法分析部分
 */
public class SyntaxException extends Exception {
    public SyntaxException(String message) {
        super(message);
    }
}
