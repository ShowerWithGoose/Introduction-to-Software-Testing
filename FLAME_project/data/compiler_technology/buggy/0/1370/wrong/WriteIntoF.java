import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class WriteIntoF {
    private static WriteIntoF instance;
    private String filePathn = "lexer.txt";
    private String filePathe = "error.txt";
    private WriteIntoF() {
    }

    public static synchronized WriteIntoF getInstance() {
        if (instance == null) {
            instance = new WriteIntoF();
        }
        return instance;
    }

    public void writeToFile(boolean ifnormal, String content) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(ifnormal ? filePathn : filePathe, true))) {
            // 第二个参数为true，表示追加模式
            writer.write(content);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}