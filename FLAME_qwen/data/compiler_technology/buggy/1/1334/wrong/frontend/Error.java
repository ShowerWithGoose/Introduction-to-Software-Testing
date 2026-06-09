package frontend;

/**
 * @author
 * @Description
 * @date 2024/10/4 23:18
 */
public class Error{
    private Integer lineno;
    private char errorType;

    public Error(Integer lineno, char errorType){
        this.lineno=lineno;
        this.errorType = errorType;
    }

    public Integer getLineno(){
        return this.lineno;
    }

    @Override
    public String toString() {
        return lineno + " " + errorType;
    }
}
