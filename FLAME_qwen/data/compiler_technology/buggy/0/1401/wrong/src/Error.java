package src;

import java.io.BufferedWriter;
import java.io.IOException;

public class Error {
    private int line;
    private Error_Enum error_enum;

    public Error(Integer line, Error_Enum error_enum1) {
        this.line = line;
        error_enum = error_enum1;
    }

    public void word(BufferedWriter out) throws IOException {
        out.write(line + " " + error_enum.toString());
    }
}
