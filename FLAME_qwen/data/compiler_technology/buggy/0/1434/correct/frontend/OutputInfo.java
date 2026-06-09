package frontend;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;

public class OutputInfo {
    private OutputInfo() {
    }

    private static final boolean print = true;

    public static void print(String s) throws IOException {
        if (print) {
            File file = new File("lexer.txt");
            file.createNewFile();
            FileOutputStream output = new FileOutputStream(file, true);
            byte[] bytes = s.getBytes();
            output.write(bytes);
            output.write('\n');
            output.close();
        } else {
            System.out.println(s);
        }
    }

    public static void error(String s) throws IOException {
        if (print) {
            File file = new File("error.txt");
            if (!file.exists()) {
                file.createNewFile();
            }
            FileOutputStream output = new FileOutputStream(file, true);
            byte[] bytes = s.getBytes();
            output.write(bytes);
            output.write('\n');
            output.close();
        } else {
            System.out.println(s);
        }
    }

}
