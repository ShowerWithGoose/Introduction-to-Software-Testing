package CompileErrors;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

/**
 * @author
 * @Description:
 * @date 2024/9/29 13:35
 */
public class CompileErrorHandler {
    public static CompileErrorHandler instance;

    public static CompileErrorHandler getInstance() {
        if (instance == null) {
            instance = new CompileErrorHandler();
        }return instance;
    }

    public ArrayList<CompileError> errors = new ArrayList<>();


    public void addErrorMessage(int errorLine, char errorCode) {
        errors.add(new CompileError(errorLine, errorCode));
    }

    public void outputErrorMessage(FileWriter writer) throws IOException {
//        System.out.println("hello?");
        errors.sort((e1, e2) -> (e1.errorLine -  e2.errorLine == 0 ? e1.errorCode -  e2.errorCode : e1.errorLine - e2.errorLine));
        for (CompileError error : errors) {
            writer.write(error.errorLine + " " + error.errorCode + "\n");
        }
    }
}
