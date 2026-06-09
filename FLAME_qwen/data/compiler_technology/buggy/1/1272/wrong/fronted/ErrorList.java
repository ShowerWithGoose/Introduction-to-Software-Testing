package fronted;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.util.HashMap;

public class ErrorList {

    private static final HashMap<Integer,MyError> errorList = new HashMap<>();

    public HashMap<Integer, MyError> getErrorList() {
        return errorList;
    }

    public static boolean isEmpty() {
        return errorList.isEmpty();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Integer pos : errorList.keySet()) {
            sb.append(errorList.get(pos).toString());
        }
        return sb.toString();
    }

    public static void print(){
        StringBuilder sb = new StringBuilder();
        int max = 0;
        for (Integer i : errorList.keySet()) {
            if (i > max) {
                max = i;
            }
        }
        for (int i = 0; i <= max; i = i +1) {
            if (errorList.containsKey(i)) {
                sb.append(errorList.get(i).toString());
            }
        }
         /*System.out.println(sb.toString());*/
        String outputFile = "error.txt";
        try {
            OutputStream outputStream = new FileOutputStream(outputFile);
            try {
                outputStream.write(sb.toString().getBytes());
            } catch (IOException e) {
                System.err.println("Can not Write it!");
            }
        } catch (FileNotFoundException e) {
            System.err.println("Can not Open!");
        }
    }

    public static void addError(int line, char err) {
        MyError error = new MyError(line,err);
        errorList.put(line,error);
    }

}
