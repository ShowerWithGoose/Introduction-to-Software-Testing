import java.util.ArrayList;
import java.util.List;

public class ParserOutput {
    private List<String> output;
    private boolean outputEnabled;

    public ParserOutput() {
        this.output = new ArrayList<>();
        this.outputEnabled = false;
    }

    public void setOutputEnabled(boolean enabled) {
        this.outputEnabled = enabled;
    }

    public void write(String line) {
        if (outputEnabled) {
            output.add(line);
        }
    }

    public List<String> getOutput() {
        return output;
    }
}
