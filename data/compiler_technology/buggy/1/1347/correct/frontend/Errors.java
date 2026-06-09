package frontend;

import java.util.ArrayList;

public class Errors {
    private ArrayList<MyError> errors = new ArrayList<>();


    public Errors() {

    }

    public void setErrors(MyError error) {
        this.errors.add(error);
    }

    public ArrayList<MyError> getErrors() {
        return errors;
    }
}
