import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class Output {

    private static final Output output = new Output();

    public void output(String file, String content) {
        try {
            BufferedWriter writer = new BufferedWriter(new FileWriter(file));
            writer.write(content);
            writer.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static Output getOutput() {
        return output;
    }
}
