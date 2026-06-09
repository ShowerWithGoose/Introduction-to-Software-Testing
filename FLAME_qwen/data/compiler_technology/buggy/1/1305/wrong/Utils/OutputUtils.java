package Utils;
import java.nio.file.StandardOpenOption;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.io.IOException;
public class OutputUtils {
    public static String parserOutputPath = "parser.txt";
    public static String errorPath = "error.txt";
    public static void parserOutput(String output) throws IOException {
        if(!Files.exists(Paths.get(parserOutputPath))){
            Files.createFile(Paths.get(parserOutputPath));
        }
        Files.write(Paths.get(parserOutputPath), output.getBytes(), StandardOpenOption.CREATE, StandardOpenOption.APPEND);
    }
}
