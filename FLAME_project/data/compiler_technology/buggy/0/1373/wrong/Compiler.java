import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;

public class Compiler {
    public static void main(String[] args) throws IOException {
        ArrayList<Token> tokens = new ArrayList<>();
        FileInfo fileInfo = new FileInfo();
        tokens = fileInfo.read();

        //检查错误
        boolean isFault = false;
        for (Token value : tokens) {
            if (value.getType().equals("UNKNOWN")) {
                isFault = true;
                break;
            }
        }

        //输出
        OutputWork1 outputWork1 = new OutputWork1();
        if (isFault) {
            outputWork1.outputError(tokens);
        } else {
            outputWork1.outputNormal(tokens);
        }

    }

}
