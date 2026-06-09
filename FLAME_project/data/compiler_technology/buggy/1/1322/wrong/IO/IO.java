package IO;

import java.io.File;
import java.io.FileWriter;

public class IO {
    public static String outputFile = "parser.txt";
    public static void write(String content) {
        File outputFile = new File(IO.outputFile);
        try (FileWriter writer = new FileWriter("parser.txt", true)) {
            writer.write(content);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void writeSymbol(String content) {
        File outputFile = new File(IO.outputFile);
        try (FileWriter writer = new FileWriter("symbol.txt", true)) {
            writer.write(content);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
