package util;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

/**
 * ClassName: IOUtil
 * Package: util
 * Description:
 *
 * @Author
 * @Create 2024/9/23 19:39
 * @Version 1.0
 */
public class IOUtil {
    public static String read(String path) throws IOException {
        StringBuilder contentBuilder = new StringBuilder();

        try (BufferedReader br = new BufferedReader(new FileReader(path))) {
            String line;
            while ((line = br.readLine()) != null) {
                contentBuilder.append(line).append("\n");
            }
        }

        return contentBuilder.toString();
    }

    public static void write(String path, String content) {
        try (FileWriter fw = new FileWriter(path)) {
            fw.write(content);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
