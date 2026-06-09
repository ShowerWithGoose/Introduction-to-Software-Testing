import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;

public class Compiler {
    public static void main(String[] args) throws IOException {
        ArrayList<Token> tokens;
        ArrayList<SyntaxError> errors1 = new ArrayList<>();
        FileInfo fileInfo = new FileInfo(errors1);
        tokens = fileInfo.read();

        ArrayList<SyntaxError> errors2 = new ArrayList<>();
        SyntaxAnalyzer syntaxAnalyzer = new SyntaxAnalyzer(tokens, errors2);
        SyntaxTreeNode father = syntaxAnalyzer.parse();

        ArrayList<SyntaxError> errors = new ArrayList<>();
        int i = 0,j = 0;
        while (i < errors1.size() || j < errors2.size()) {
            if (i == errors1.size()) {
                errors.add(errors2.get(j));
                j++;
                continue;
            }

            if (j == errors2.size()) {
                errors.add(errors1.get(i));
                i++;
                continue;
            }


            if (errors1.get(i).getLine() <= errors2.get(j).getLine()) {
                errors.add(errors1.get(i));
                i++;
            } else {
                errors.add(errors2.get(j));
                j++;
            }
        }

        //检查错误
        boolean isCorret = errors.isEmpty();

        //输出
        OutputWork1 outputWork1 = new OutputWork1();
        if (isCorret) {
            outputWork1.outputNormal(father);
        } else {
            outputWork1.outputError(errors);
        }

    }

}
