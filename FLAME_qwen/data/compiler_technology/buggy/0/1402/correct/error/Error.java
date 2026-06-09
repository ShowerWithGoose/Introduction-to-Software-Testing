package error;

import java.io.IOException;

import static utils.IO.writeError;

public class Error {
    public static void error(int lineNumber, ErrorType type) throws IOException {
        writeError("error.txt",lineNumber, type);
    }
}
