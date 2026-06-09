import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class ERRORS extends Father {
    private static ArrayList<ERROR> errors = new ArrayList<>();

    public static void addError(ERROR error) {
        errors.add(error);
    }

    public static boolean isEmpty() {
        return errors.isEmpty();
    }

    public static void Print() throws IOException {
        errors.sort(Comparator.comparingInt(ERROR::getNum));
        FileWriter fileWriter = new FileWriter("error.txt", true);
        BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
        for (ERROR e : errors) {
            bufferedWriter.write( e.getNum()+ " " + e.getType());
            bufferedWriter.newLine();
        }
        bufferedWriter.flush();
        bufferedWriter.close();
    }
}
