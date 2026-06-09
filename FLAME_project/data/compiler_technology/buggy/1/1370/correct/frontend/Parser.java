package frontend;

import java.util.ArrayList;
import java.util.Deque;
import java.util.ArrayDeque;


public class Parser {

    private CompUnit compUnit;

    public void parser(){
        compUnit = new CompUnit();
        compUnit.parser(null);
        compUnit.printToFile();
    }






}

