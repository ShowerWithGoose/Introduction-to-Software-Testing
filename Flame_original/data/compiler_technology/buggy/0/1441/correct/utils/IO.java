package utils;
import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Scanner;
import java.util.StringJoiner;


public class IO {

    public static String read() throws IOException {
        InputStream in = new BufferedInputStream(Files.newInputStream(Paths.get("testfile.txt")));
        Scanner scanner = new Scanner(in);
        StringJoiner stringJoiner = new StringJoiner("\n");
        while (scanner.hasNextLine()) {
            stringJoiner.add(scanner.nextLine());
        }
        scanner.close();
        in.close();
        return stringJoiner.toString();
    }

    public static void write(String value, String filename){
        File outputFile = new File(filename);
        try (FileWriter writer = new FileWriter(outputFile, true)) {
            writer.write(value);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
