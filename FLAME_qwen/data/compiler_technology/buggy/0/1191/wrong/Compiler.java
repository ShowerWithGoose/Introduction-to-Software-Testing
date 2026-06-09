import frontend.Lexer;

import java.io.*;
import java.util.HashMap;
import java.util.Objects;

public class Compiler {
    private static Lexer lexer;
    private static String curToken;
    private static String curType;
    private static HashMap<Integer, Character> error;

    public static void main(String[] args) {

        String testfilePath = "testfile.txt";
        String lexerPath = "lexer.txt";
        String errorPath = "error.txt";
        StringBuilder sb = new StringBuilder();

        try (BufferedReader br = new BufferedReader(new FileReader(testfilePath))) {
            String line;
            while ((line = br.readLine()) != null) {
                sb.append(line).append('\n');
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        try {
            FileOutputStream fileOutputStream = new FileOutputStream(lexerPath);
            fileOutputStream.write(new byte[0]);
            fileOutputStream.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

        String fileContent = sb.toString();
        lexer = new Lexer(fileContent);

        while (lexer.getSymbol() == 0) {
            curToken = lexer.getCurToken();
            curType = lexer.getCurType();
            if (!Objects.equals(curToken, "")) {
                try (BufferedWriter writer = new BufferedWriter(new FileWriter(lexerPath, true))) {
                    writer.write(curType + " " + curToken + "\n");
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }

        error = lexer.getError();

        try {
            FileOutputStream fileOutputStream = new FileOutputStream(errorPath);
            fileOutputStream.write(new byte[0]);
            fileOutputStream.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

        for (Integer key : error.keySet()) {
            try (BufferedWriter writer = new BufferedWriter(new FileWriter(errorPath, true))) {
                writer.write(key + " " + error.get(key) + "\n");
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

    }
}
