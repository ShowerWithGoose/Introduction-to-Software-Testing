import FrontEnd.*;
import java.io.*;

public class Compiler {

    private static final String inputFilePath = "testfile.txt";
    private static String readFile() throws IOException {
        InputStream is = new FileInputStream(inputFilePath);
        BufferedReader reader = new BufferedReader(new InputStreamReader(is));
        StringBuilder buffer = new StringBuilder();
        String line = reader.readLine();

        while (line != null) {
            buffer.append(line).append("\n");
            line = reader.readLine();
        }

        reader.close();
        is.close();
        return buffer.toString();
    }

    public static void main(String[] args) throws IOException {
        LexicalAnalyzer analyser = new LexicalAnalyzer();
        analyser.AnalizeProgramWord(readFile());
    }
    }
