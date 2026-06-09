package err;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class ErrOutput {
    private static BufferedWriter fileErr = null;
    public static void open(String err) throws IOException {
        fileErr = new BufferedWriter(new FileWriter(err));
    }

    public static void thr(int lineNo, String str) throws IOException {
        String e = lineNo + " " + str + '\n';
//        System.out.print(e);
        fileErr.append(String.valueOf(lineNo)).append(" ").append(str).append(String.valueOf('\n'));
    }
    public static void close() throws IOException {
        fileErr.close();
    }
}
