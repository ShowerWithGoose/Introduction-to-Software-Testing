import java.io.*;

public class Compiler {
    public static void main(String[] args) throws IOException {
        Lexer lexer = new Lexer();

        BufferedReader reader = new BufferedReader(new FileReader("testfile.txt"));
        PrintWriter fpResult = new PrintWriter(new FileWriter("lexer.txt"));
        PrintWriter fpError = new PrintWriter(new FileWriter("error.txt"));

        String source; // 源程序字符串
        int curPos; // 当前字符串位置
        int lineNum = 0; // 当前行号

        while ((source = reader.readLine()) != null) {
            curPos = 0;
            lineNum++;
            while (curPos < source.length() && (source.charAt(curPos) == ' ' || source.charAt(curPos) == '\t')) curPos++;
            if (curPos >= source.length()) continue;
            if (lexer.getFlagForCrossAnno()) {
                while (curPos < source.length() - 1 && !(source.charAt(curPos) == '*' && source.charAt(curPos + 1) == '/')) {
                    curPos++;
                }
                if (curPos < source.length() - 1) lexer.setFlagForCrossAnno(false);
            } else {
                while (curPos < source.length()) {
                    curPos = lexer.next(source, curPos);
                    if (lexer.getFlagForError()) {
                        lexer.setFlagForError(false);
                        fpError.printf("%d %c\n", lineNum, lexer.getErrorType());
                    } else if (lexer.getFlagForSingleAnno()) {
                        lexer.setFlagForSingleAnno(false);
                    } else if(lexer.getFlagForCrossAnno()){
                        while (curPos < source.length() - 1 && !(source.charAt(curPos) == '*' && source.charAt(curPos + 1) == '/')) {
                            curPos++;
                        }
                        if (curPos < source.length() - 1) {
                            lexer.setFlagForCrossAnno(false);
                            curPos += 2;
                        }
                    } else {
                        fpResult.printf("%s %s\n", lexer.getLexType(), lexer.getToken());
                    }
                }
            }
        }

        reader.close();
        fpResult.close();
        fpError.close();
    }
}