import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.NoSuchFileException;
import java.nio.file.Path;
import java.nio.file.Paths;

public class Readfile {
    private String filePath;
    private String srccode;

    public Readfile(String filePath) {
        this.filePath = filePath;
        this.srccode = "";
    }

    public String read() {
        try {
            Path path = Paths.get(filePath);
            srccode = Files.readString(path);
        } catch (NoSuchFileException e) {
            System.err.println("文件不存在: " + filePath);
        } catch (IOException e) {
            System.err.println("无法读取文件: " + filePath);
            e.printStackTrace();
        }
        return srccode;
    }
}
