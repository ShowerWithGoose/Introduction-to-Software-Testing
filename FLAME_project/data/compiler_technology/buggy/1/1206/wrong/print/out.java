package print;

import java.io.*;

/**
 * @author
 * @Description:
 * @date 2024/10/12 15:33
 */
public class out {
    public static PrintWriter outwrong;
    public static void write(String content) throws IOException{
        File outputFile = new File("parser.txt");
        try (FileWriter writer = new FileWriter(outputFile, true)) {
            writer.write(content+"\n");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public static void wWrong(String content)throws IOException{
        File outputFile = new File("error.txt");
        try (FileWriter writer = new FileWriter(outputFile, true)) {
            writer.write(content+"\n");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
