package Error;

import java.io.BufferedWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Comparator;

import IO.*;

public class errorMessage {
    private static ArrayList<error> errorList;

    private final BufferedWriter errorLog;
    public errorMessage(IO io) {
        errorList = new ArrayList<>();
        errorLog = io.getErrorWriter();
    }

    public static void addError(error error) {
        errorList.add(error);
    }

    public ArrayList<error> getErrors() {
        return errorList;
    }

    public static void addError(ArrayList<error> errors) {
        errorList.addAll(errors);
    }

    public void sortErrorsByLineNumber() {
        errorList.sort(Comparator.comparingInt(error::getErrorLineNumber));
    }

    public void printErrors() throws IOException {
        sortErrorsByLineNumber();
        for (error error : errorList) {
            errorLog.write(error.toString());
//            System.out.print(error.toString());
        }
        errorLog.flush();
        errorLog.close();
    }

}
