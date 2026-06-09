package exeptions;

import java.util.ArrayList;
import java.util.Comparator;

public class ErrorList {
    private final ArrayList<Error> errors = new ArrayList<>();
    public void add(Error error) {
        this.errors.add(error);
    }
    public Error get(int index) {
        return errors.get(index);
    }
    public int getSize() {
        return errors.size();
    }
    public void clear() {
        this.errors.clear();
    }
    public boolean isEmpty() {
        return errors.isEmpty();
    }
    public void appendErrorList(ErrorList errorList) {
        this.errors.addAll(errorList.errors);
    }
    public ErrorList sortUpOrder() {
        this.errors.sort(new Comparator<Error>() {
            @Override
            public int compare(Error o1, Error o2) {
                return o1.lineNum - o2.lineNum;
            }
        });
        return this;
    }
    @Override
    public String toString() {
        StringBuilder result = new StringBuilder();
        for (Error error: errors) {
            result.append(error);
        }
        return result.toString();
    }
}
