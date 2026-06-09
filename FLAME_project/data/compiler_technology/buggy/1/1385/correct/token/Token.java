package token;

import java.io.IOException;

public class Token {
    private String type;
    private RetrainToken retrainToken;
    private String value;
    private int rowNumber;
    private String error;
    
    public Token(String value, String type, int rowNumber){
        this.error = null;
        this.value = value;
        this.type = type;
        this.rowNumber = rowNumber;
        if (type.equals("IDENFR")){
            retrainToken = RetrainToken.queryRetrainToken(value);
            if (retrainToken!=null){
                this.type = retrainToken.toString();
            }
        }
    }
    
    public String getValue() {
        return value;
    }
    
    public String getType() {
        return type;
    }
    
    public void setError(String s){
        error = s;
    }
    
    public int getRowNumber() {
        return rowNumber;
    }
    
    public void print() throws IOException {
        Io.Text.printWord(type + " " + value);
    }
}
