package ErrorsModule;

import java.util.ArrayList;
import java.util.Comparator;

public class ErrorCollect {
    private static final ArrayList<ErrorData> errorDataArrayList = new ArrayList<>();

    public static void addErrorData(ErrorData data) {
        errorDataArrayList.add(data);
    }

    public static boolean isError() {
        return !errorDataArrayList.isEmpty();
    }

    public static void printError() {
        errorDataArrayList.sort(new Comparator<ErrorData>() {
            @Override
            public int compare(ErrorData o1, ErrorData o2) {
                return -1 * Integer.compare(o2.getLineNumber(), o1.getLineNumber());
            }
        });
        for (ErrorData data : errorDataArrayList) {
            System.err.println(data);
        }
    }

}
