import java.util.ArrayList;
import java.util.HashMap;

public class ErrorList {
    private HashMap<Integer, ArrayList<String>> errors;

    public ErrorList() {
        this.errors = new HashMap<>();
    }

    public void addError(int lineNum, String errorType) {
        if (!this.errors.containsKey(lineNum)) {
            this.errors.put(lineNum, new ArrayList<>());
        }
        this.errors.get(lineNum).add(String.valueOf(errorType));
    }

    public String toString() {
        String string = "";
        for (Integer line : this.errors.keySet()) {
            for (String errorType : this.errors.get(line)) {
                string += line + " " + errorType + "\n";
            }
        }
        return string;
    }
}
