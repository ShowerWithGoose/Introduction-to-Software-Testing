import frontend.TokenLexer;

import java.io.*;
import java.util.ArrayList;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Compiler {
    public static void main(String[] args) {
        try {
            ArrayList<String> arr = new ArrayList<>();
            String line = null;
            InputStream inStr = new FileInputStream("testfile.txt");
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(inStr));
            while (true) {
                line = bufferedReader.readLine();
                if (line == null) {
                    break;
                }
                arr.add(line);
            }
            TokenLexer tokenLexer = new TokenLexer(arr);
            tokenLexer.tokenScan();
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}