package frontend.Parser.Class;

import java.util.ArrayList;

public class Number {
    private String number;
    public Number(String number, ArrayList<String> outputList){
        this.number=number;
        outputList.add("<Number>");
    }
}
