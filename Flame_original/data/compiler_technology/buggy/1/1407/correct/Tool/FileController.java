package Tool;

import java.io.*;

public class FileController {
    static FileWriter fileWriter;

    static {
        try {
            fileWriter = new FileWriter("parser.txt");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    static PrintWriter printWriter = new PrintWriter(fileWriter);

    public static String readFileToString(String filePath) {
        StringBuilder content = new StringBuilder();

        try (BufferedReader bufferedReader = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = bufferedReader.readLine()) != null) {
                content.append(line).append("\n");  // 每行读取后追加换行符
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        return content.toString();
    }

    public static void printlnParser(String string){
        printWriter.println(string);
    }
    public static void closeAllFile(){
        printWriter.close();
    }
}
