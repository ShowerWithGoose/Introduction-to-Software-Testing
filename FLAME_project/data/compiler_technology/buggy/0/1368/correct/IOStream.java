import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.Scanner;
import java.io.FileReader;
import java.io.IOException;

public class IOStream {
    private static LinkedHashMap<Integer, String> inputStrings = new LinkedHashMap<>();
    private static int lineNum;
    private static ArrayList<LexType> lexTypes = new ArrayList<>();
    private static ArrayList<String> lexStrings = new ArrayList<>();
    public static ErrorType errorType = null;
    public static int errorLineNum;
    public static void readFile() {
        String fileName = "testfile.txt";
        lineNum = 0;
        try (Scanner sc = new Scanner(new FileReader(fileName))) {
            while (sc.hasNextLine()) {  //按行读取字符串
                String line = sc.nextLine();
                inputStrings.put(lineNum, line);
                lineNum++;
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static ArrayList<String> toInputStrings() {
        ArrayList<String> strings = new ArrayList<>();
        for (Integer i : inputStrings.keySet()) {
            strings.add(inputStrings.get(i));
        }
        return strings;
    }

    public static void createOutput() {
        Lexer lexer = Lexer.getInstance();
        while (true) {
            int next = lexer.next();
            if (next == 0) {
                lexTypes.add(lexer.getLexType());
                lexStrings.add(lexer.getToken());
            } else if (next == 1) { // 词法分析出口
                break;
            }
        }
    }

    public static Boolean outOfLineNum(int num) {
        return num >= lineNum;
    }

    public static void output() throws FileNotFoundException {
        String filePath1 = "lexer.txt";
        String filePath2 = "error.txt";
        FileOutputStream fileOutputStream1 = new FileOutputStream(filePath1);
        FileOutputStream fileOutputStream2 = new FileOutputStream(filePath2);
        if (errorType == ErrorType.a) {
            String errorOutput = errorLineNum + " " + errorType;
            byte[] buff = errorOutput.getBytes();
            try {
                fileOutputStream2.write(buff);
            } catch (Exception e) {
                e.printStackTrace();
            }
        } else {
            for (int i = 0; i < lexTypes.size(); i++) {
                String s = lexTypes.get(i) + " " + lexStrings.get(i) + '\n';
                byte[] buff = s.getBytes();
                try {
                    fileOutputStream1.write(buff);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }
    }

    public static void setErrorHappened(ErrorType type, int num) {
        errorType = type;
        errorLineNum = num + 1;
    }

    public static void debug38() {
        for (Integer i : inputStrings.keySet()) {
            if (inputStrings.get(i).length() == 38) {
                System.out.println(i);
            }
        }
    }

}
