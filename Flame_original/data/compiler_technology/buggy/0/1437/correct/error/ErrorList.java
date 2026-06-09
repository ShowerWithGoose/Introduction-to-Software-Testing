package error;

import java.util.ArrayList;
import java.util.List;

public class ErrorList {
    public static List<Error> errors = new ArrayList<>();

    public static void addError(Error error) {
        errors.add(error);
    }

}
