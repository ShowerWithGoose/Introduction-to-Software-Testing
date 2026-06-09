package exception;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.HashMap;

public class ErrorTackle {
    private static ArrayList<CompilerError> errors = new ArrayList<>();
    private static HashMap<Integer, Integer> tokenPosToLine = new HashMap<>();

    public static void addError(CompilerError error) {
        errors.add(error);
    }
    public static void printErrors(String errPath) {
        // write to Config.err_path
        errors.sort((o1, o2) -> {
            if (o1.getIndex() == o2.getIndex()) {
                return 0;
            }
            return o1.getIndex() < o2.getIndex() ? -1 : 1;
        });
        StringBuilder content = new StringBuilder();
        for (CompilerError error : errors) {
            content.append(error.toString()).append("\n");
        }
        try {
            Files.write(Paths.get(errPath), content.toString().getBytes());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void setTokenPosToLine(HashMap<Integer, Integer> tokenPosToLine) {
        ErrorTackle.tokenPosToLine = tokenPosToLine;
    }

    public static int transTokenPosToLine(int pos) {
        if (tokenPosToLine.containsKey(pos)) {
            return tokenPosToLine.get(pos);
        }
        return -1;
    }
}
