package error_part;

public class Error implements Comparable {

    private int lineIndex;
    private ErrorType errorType;

    public Error(int lineIndex, ErrorType errorType) {
        this.lineIndex = lineIndex;
        this.errorType = errorType;
    }

    @Override
    public int compareTo(Object o) {
        return this.lineIndex - ((Error) o).lineIndex;
    }

    @Override
    public String toString() {
        return lineIndex + " " + errorType.errorCode + "\n";
    }

    public enum ErrorType {
        ILLEGAL_AND_OR("a"),
        REPEAT_DECLARE("b"),
        UNDECLARED_NAME("c"),
        WRONG_PARAM_CNT("d"),
        WRONG_PARAM_TYPE("e"),
        EXCESSIVE_RETURN("f"),
        LACK_RETURN("g"),
        MODIFY_CONST("h"),
        LACK_SEMICN("i"),
        LACK_RIGHT_PARENT("j"),
        LACK_RIGHT_BRACK("k"),
        PRINTF_LACK_EXP("l"),
        WRONG_BREAK_CONTINUE("m"),
        ;
        private String errorCode;

        ErrorType(String errorCode) {
            this.errorCode = errorCode;
        }

        public String getErrorCode() {
            return errorCode;
        }
    }
}
