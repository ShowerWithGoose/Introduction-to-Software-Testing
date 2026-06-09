package IOcontrol;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;

import Token.*;

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
        /*try {
            System.setOut(new PrintStream(filename));
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }*/
        for (int i = 0;i < tokenList.size();i++) {
            System.out.println(String.valueOf(i) + ' ' + tokenList.get(i).getWordType().toString()
                    + ' ' + tokenList.get(i).getContent());
        }
    }

    public static void ParserOutput(Token token) {
        File outputFile = new File("parser.txt");
        try (FileWriter writer = new FileWriter(outputFile, true)) {
            writer.write(token.getWordType().toString() + ' ' + token.getContent() + '\n');
        } catch (Exception e) {
            e.printStackTrace();
        }
        System.out.println(token.getWordType().toString() + ' ' + token.getContent());
    }

    public static void ParserOutput(String content) {
        File outputFile = new File("parser.txt");
        try (FileWriter writer = new FileWriter(outputFile, true)) {
            writer.write(content + '\n');
        } catch (Exception e) {
            e.printStackTrace();
        }
        System.out.println(content);
    }

    public static void errorOutput(HashMap<Integer,Character> errors, String filename) {
        try {
            System.setOut(new PrintStream(filename));
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
        List<Map.Entry<Integer,Character>> list = new ArrayList<>(errors.entrySet());
        list.sort(new Comparator<Map.Entry<Integer, Character>>() {
            @Override
            public int compare(Map.Entry<Integer, Character> o1, Map.Entry<Integer, Character> o2) {
                return o1.getKey().compareTo(o2.getKey());
            }
        });
        for (int i = 0;i < list.size();i++) {
            System.out.println(String.valueOf(list.get(i).getKey()) + ' ' + String.valueOf(list.get(i).getValue()));
        }
    }


}
