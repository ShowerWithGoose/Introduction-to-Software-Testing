import FrontEnd.*;
import java.io.*;
import java.util.ArrayList;

public class Compiler {
    private static final String inputFilePath = "testfile.txt";
    public static final String outputFilePath="outpufile";
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
        /*这个超出数字范围了还是咋的*/
        ArrayList<Token> tokenArrayList=analyser.AnalizeProgramWord(readFile());
        SytaxParser sytaxParser=new SytaxParser(tokenArrayList);
        sytaxParser.sytaxAnalyze();
    }
    }
