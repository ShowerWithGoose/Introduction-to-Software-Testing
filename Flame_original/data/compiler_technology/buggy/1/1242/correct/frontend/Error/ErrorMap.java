package frontend.Error;

import frontend.Lexer.Lexer;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;

public class ErrorMap {

    private static HashMap<Integer,ArrayList<Error>> errorMap = new HashMap<>();

    public static void AddError(Error error) {
        if (errorMap.containsKey(error.GetLine())) {
            errorMap.get(error.GetLine()).add(error);
        } else {
            ArrayList<Error> errorList = new ArrayList<>();
            errorList.add(error);
            errorMap.put(error.GetLine(),errorList);
        }
    }

    public static void Print() {
        try {
            BufferedWriter error = new BufferedWriter(new FileWriter("error.txt"));
            for (int i = 0;i < Lexer.GetLineth();i++) {
                if (errorMap.containsKey(i)) {
                    ArrayList<Error> errorList = errorMap.get(i);
                    for (int j = 0;j < errorList.size();j++) {
                        error.write(errorList.get(j).toString() + "\n");
                    }
                }
            }
            error.flush();
        } catch (IOException e) {
            System.out.println("error.txt does not exist");
        }
    }
}
