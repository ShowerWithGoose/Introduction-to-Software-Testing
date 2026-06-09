import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class OutputWork1 {
    public void outputNormal(SyntaxTreeNode father) throws IOException {
        FileWriter writer = new FileWriter("parser.txt");
        father.output(writer);
        writer.close();
    }

    public void outputError(ArrayList<SyntaxError> errors) throws IOException {
        FileWriter writer = new FileWriter("error.txt");
        for (SyntaxError value : errors) {
            writer.write(value.getLine() + " " + value.getType() + "\n");
        }
        writer.close();
    }
}
