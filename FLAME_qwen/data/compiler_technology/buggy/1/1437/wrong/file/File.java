package file;

import java.io.*;

public class File {
    public static String readPath = "testfile.txt";
    public static String lexerPath = "lexer.txt";
    public static String parserPath = "parser.txt";
    public static String symbolPath = "symbol.txt";
    public static String errorPath = "error.txt";

    public static String readFileToString(String path) {
        StringBuilder text = new StringBuilder();
        try (BufferedReader br = new BufferedReader(new FileReader(path))) {
            String line;
            while ((line = br.readLine()) != null) {
                text.append(line);
                text.append("\n");
            }
        } catch (IOException e) {
            System.out.println("=====read exception=====");
            System.out.println(e.getMessage());
        }
        return text.toString();
    }

    public static void writeStringToFile(String path, String str){
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(path))) {
            writer.write(str);
        } catch (IOException e) {
            System.out.println("=====write exception=====");
            System.out.println(e.getMessage());
        }
    }

}
