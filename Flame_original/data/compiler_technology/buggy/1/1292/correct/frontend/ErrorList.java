package frontend;

import java.io.FileWriter;
import java.io.IOException;
import java.util.Comparator;
import java.util.PriorityQueue;

public class ErrorList {
    static Comparator<Error> cmp = new Comparator<Error>() {
        @Override
        public int compare(Error o1, Error o2) {
            if (o1.getLineNum() == o2.getLineNum()) {
                return o1.getTypenum() > o2.getTypenum() ? 1 : -1;
            }
            return o1.getLineNum() > o2.getLineNum() ? 1 : -1;
        }
    };
    private static PriorityQueue<Error> errorList = new PriorityQueue<>(cmp);

    public static void add(Error error) {
        errorList.add(error);
    }

    public static void printOut() {
        while(!errorList.isEmpty()) {
            Error error = errorList.poll();
            FileWriter fileWriter = null;
            try {
                fileWriter = new FileWriter("error.txt", true);
                fileWriter.write((error.getLineNum()) + " " + error.getType() + "\n");
                fileWriter.close();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
