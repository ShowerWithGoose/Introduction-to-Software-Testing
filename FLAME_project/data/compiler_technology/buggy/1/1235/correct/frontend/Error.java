package frontend;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
public class Error {
    private String value;
    private String type;
    private int lineNum;

    public static List<Error> errors = new ArrayList<>();

    public Error(){

    }
    public Error(String value, String type, int lineNum){
        this.value = value;
        this.type = type;
        this.lineNum = lineNum;
    }

    public String getValue(){
        return value;
    }

    public String getType(){
        return type;
    }

    public int getLineNum(){
        return lineNum;
    }

    public void addErrors(Error error){
        errors.add(error);
    }

    public List<Error> getErrors(){
        return errors;
    }

    public void sortErrors(){
        errors.sort(Comparator.comparingInt(Error::getLineNum));
    }

    public String writeString(){
        return lineNum + " " + type;
    }
}
