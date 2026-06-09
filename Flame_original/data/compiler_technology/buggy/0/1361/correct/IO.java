import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringJoiner;

public class IO {
    public static String read(String filename) throws IOException {
        InputStream input = new BufferedInputStream(Files.newInputStream(Paths.get(filename)));
        Scanner scanner = new Scanner(input);
        StringJoiner stringJoiner = new StringJoiner("\n");
        while (scanner.hasNextLine()) {
            stringJoiner.add(scanner.nextLine());
        }
        return stringJoiner.toString();
    }

    public static void LexerOutput(ArrayList<Token> tokenList, String filename) {
        try {
            System.setOut(new PrintStream(filename));
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
        for (int i = 0;i < tokenList.size();i++) {
            System.out.println(tokenList.get(i).getWordType().toString()
                    + ' ' + tokenList.get(i).getContent());
        }
    }

    public static void errorOutput(String content,String filename) {
        try {
            System.setOut(new PrintStream(filename));
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
        System.out.println(content);
    }


}
