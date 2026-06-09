package error;

import java.util.ArrayList;
import java.util.Comparator;

public class ErrorList {
    public ArrayList<Error> errors = new ArrayList<>();

    private ErrorList() {
    }

    private static final ErrorList instance = new ErrorList();

    public static ErrorList getInstance() {
        return instance;
    }

    public void print() {
        errors.sort(new Comparator<Error>() {
            @Override
            public int compare(Error o1, Error o2) {
                return o1.lineNumber - o2.lineNumber;
            }
        });
        for (Error error : errors)
        {
            System.out.println(error);
        }
    }
}
