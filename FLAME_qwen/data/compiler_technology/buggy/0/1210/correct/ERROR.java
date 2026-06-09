import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class ERROR {
    private int num;
    private char type;

    public ERROR(int num, char type) {
        this.num = num;
        this.type = type;
    }

    public void print() {
        //System.out.println(num + " " + type);

        FileWriter fileWriter = null;
        try {
            fileWriter = new FileWriter("error.txt", true);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
        try {
            bufferedWriter.write(num + " " + type+ '\n');
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        try {
            bufferedWriter.flush();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        try {
            bufferedWriter.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
