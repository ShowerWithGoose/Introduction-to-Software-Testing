import java.io.IOException;
import java.util.ArrayList;
import java.util.Map;
import java.util.TreeMap;
import Node.*;
import Tools.ReadFile;
import Tools.Token;
import Tools.WriteFile;
import Tools.myError;

public class Compiler {
    public static void main(String[] args) throws IOException {
        String input = ReadFile.GetFile();
        //词法分析
        Lexer.tokenize(input);
        ArrayList<Token> tokens = Lexer.getTokens();

        //语法分析
        Parser parser = new Parser(tokens);
        CompUnit compUnit = parser.getCompUnit();
        compUnit.checkOut();


        TreeMap<Integer, myError> errors = myError.getErrorTreeMap();
        StringBuilder stringBuilder1 = new StringBuilder();
        for (Map.Entry<Integer, myError> entry : errors.entrySet()) {
            stringBuilder1.append(entry.getKey()).append(" ").append(entry.getValue().toString()).append("\n");
        }
        WriteFile.MakeFile_error(stringBuilder1.toString());

    }
}
