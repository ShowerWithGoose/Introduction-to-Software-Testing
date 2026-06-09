import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class OutputWork1 {
    public void outputNormal(ArrayList<Token> tokens) throws IOException {
        FileWriter writer = new FileWriter("lexer.txt");
        for (Token value : tokens) {
            writer.write(value.getType() + " " + value.getValue() + "\n");
        }
        writer.close();
    }

    public void outputError(ArrayList<Token> tokens) throws IOException {
        FileWriter writer = new FileWriter("error.txt");
        for (Token value : tokens) {
            if (value.getType().equals("UNKNOWN")) {
                writer.write(value.getValue() + " a\n");
            }
        }
        writer.close();
    }
}
