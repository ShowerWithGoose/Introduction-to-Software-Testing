package Tools;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class ReadFile {
    public static String GetFile() {
        StringBuilder fileContent = new StringBuilder();
        String line;

        try (BufferedReader reader = new BufferedReader(new FileReader("testfile.txt"))) {
            while ((line = reader.readLine()) != null) {
                fileContent.append(line).append(System.lineSeparator());
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        // fileContent now contains the contents of the file
        return fileContent.toString();
    }
}