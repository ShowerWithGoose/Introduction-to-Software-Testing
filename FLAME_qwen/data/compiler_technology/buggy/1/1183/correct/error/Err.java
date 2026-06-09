package error;
public class Err {
    private Integer lineNum;
    private String code;

    public Err(Integer lineNum,String code) {
        this.lineNum = lineNum;
        this.code = code;
    }

    public Integer getLineNum() {
        return lineNum;
    }

    public String getCode() {
        return code;
    }
}
