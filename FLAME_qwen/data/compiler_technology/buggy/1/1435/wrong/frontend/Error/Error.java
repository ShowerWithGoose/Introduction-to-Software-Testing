package frontend.Error;

/**
 * @author
 * @Description:
 * @date 2024/10/15 23:23
 */
public class Error {
    private int lineNum;
    private String type;
    public Error(int lineNum, String type){
        this.lineNum = lineNum;
        this.type = type;
    }

    public int getLineNum() {
        return lineNum;
    }

    public String getType(){
        return type;
    }
}
