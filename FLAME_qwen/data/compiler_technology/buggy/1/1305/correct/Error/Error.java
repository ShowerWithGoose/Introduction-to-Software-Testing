package Error;

import java.util.ArrayList;
import java.util.List;

public class Error implements Comparable<Error>{
    public int line;
    public char type;
    public static List<Error> errors = new ArrayList<>();
    public Error(int line, char type){
        this.line = line;
        this.type = type;
    }
    public String toString() {
        return line + " " + type + "\n";
    }
    public int compareTo(Error o){
        if(this.line != o.line){
            return this.line - o.line;
        }
        else {
            return this.type - o.type;
        }
    }
}
