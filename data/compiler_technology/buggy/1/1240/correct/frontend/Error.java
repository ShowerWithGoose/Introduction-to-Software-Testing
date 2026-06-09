package frontend;

import java.util.ArrayList;

public class Error {
    private ArrayList<oneError> errorList;

    public Error() {
        this.errorList = new ArrayList<>();
    }

    public void add(int errorLine, char errorChar) {
        errorList.add(new oneError(errorLine, errorChar));
    }

    public ArrayList<oneError> getErrorList() {
        return errorList;
    }

    public boolean isEmpty(){
        return errorList.isEmpty();
    }

    public void sort(){
        errorList.sort((o1, o2) -> o1.getErrorLine() - o2.getErrorLine());
    }

    public static class oneError{
        private final int errorLine;
        private final char errorChar;

        public oneError(int errorLine, char errorChar) {
            this.errorLine = errorLine;
            this.errorChar = errorChar;
        }

        public int getErrorLine() {
            return errorLine;
        }

        public char getErrorChar() {
            return errorChar;
        }
    }
}
