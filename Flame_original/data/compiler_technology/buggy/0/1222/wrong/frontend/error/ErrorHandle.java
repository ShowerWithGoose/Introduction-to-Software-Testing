package frontend.error;

public class ErrorHandle {
    private int lineno;
    private ErrorType errorType;
    private String content;

    public ErrorHandle(int lineno, ErrorType errorType, String content) {
        this.lineno = lineno;
        this.errorType = errorType;
        this.content = content;
    }

    public ErrorHandle(int lineno, ErrorType errorType) {
        this.lineno = lineno;
        this.errorType = errorType;
    }

    public ErrorHandle(ErrorType errorType) {
        this.errorType = errorType;
    }

    public int getLineno() {
        return lineno;
    }

    public ErrorType getErrorType() {
        return errorType;
    }

    public String getContent() {
        return content;
    }

    public void setLineno(int lineno) {
        this.lineno = lineno;
    }

    public void setErrorType(ErrorType errorType) {
        this.errorType = errorType;
    }

    public void setContent(String content) {
        this.content = content;
    }
}
