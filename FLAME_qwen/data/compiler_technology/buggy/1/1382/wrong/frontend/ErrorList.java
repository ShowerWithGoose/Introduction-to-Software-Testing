package frontend;

import java.util.ArrayList;
import java.util.Comparator;

public class ErrorList {
    private final ArrayList<Error> errors;

    public ErrorList() {
        errors = new ArrayList<>();
    }

    public void addError(Error error) {
        errors.add(error);
    }

    private void errorsSort() {
        Comparator<Error> lineComp = (e1, e2) -> e1.getLineNum() - e2.getLineNum();
        errors.sort(lineComp);
    }

    public void popErrors() {
        errorsSort();
        errors.forEach(e -> e.toPrint());
    }
}
