package error;

import java.util.ArrayList;

public class ErrorList {
    public ArrayList<Error> errorList = new ArrayList<>();

    public void addError(Error error) {
        errorList.add(error);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Error error : errorList) {
            sb.append(error.toString() + '\n');
        }
        return sb.toString();
    }
}
