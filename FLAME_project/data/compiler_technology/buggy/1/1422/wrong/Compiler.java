import java.io.BufferedWriter;
import java.io.FileWriter;

public class Compiler {
    public static void main(String[] args) {
        try {
            BufferedWriter out = new BufferedWriter(new FileWriter("parser.txt"));
            Parser parser = new Parser("testfile.txt", out);
            parser.parse();
            out.close();
            Error.writeErrorsToFile();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
}
