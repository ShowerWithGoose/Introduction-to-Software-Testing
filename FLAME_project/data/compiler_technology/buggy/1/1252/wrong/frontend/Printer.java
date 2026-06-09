package frontend;

import frontend.AST.SyntaxVarType;
import frontend.lexer.Token;

import java.io.IOException;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class Printer {
    private static Printer instance = null;  // 懒汉式单例
    private static OutputStream outputStream_Correct;
    private static OutputStream outputStream_Error;
    private static HashMap<Integer, List<ErrorType>> errorMap = new HashMap<>();

    private boolean on_off = true;
    private boolean hasError = false;

    // 私有化构造函数，防止外部直接实例化
    private Printer() {}

    // 提供获取单例实例的方法，并确保线程安全
    public static synchronized Printer getInstance() {
        if (instance == null) {
            instance = new Printer();
        }
        return instance;
    }

    // 提供设置输出流的方法
    public void setOutputStreams(OutputStream outputStream_Correct,
                                 OutputStream outputStream_Error) {
        this.outputStream_Correct = outputStream_Correct;
        this.outputStream_Error = outputStream_Error;
    }

    public void printSyntaxVarType(SyntaxVarType type) throws IOException {
        if (on_off) {
            StringBuilder sb = new StringBuilder();
            sb.append('<');
            sb.append(type.toString());
            sb.append(">\n");
            try {
                outputStream_Correct.write(sb.toString().getBytes());
            } catch (IOException e) {
                System.err.println("Can not write the correct file");
            }
        }
    }

    public void printToken(Token token) throws IOException {
        if (on_off) {
            try {
                outputStream_Correct.write(token.toString().getBytes());
            } catch (IOException e) {
                System.err.println("Can not write the correct file");
            }
        }
    }

    public void addError(int lineNum, ErrorType type) {
        errorMap.computeIfAbsent(lineNum, k -> new ArrayList<>()).add(type);
    }

    public void printError() throws IOException {
        try {
            StringBuilder sb = new StringBuilder();
            sb.append(3);
            sb.append(" ");
            sb.append(ErrorType.a.toString());
            sb.append("\n");
            outputStream_Error.write(sb.toString().getBytes());
            for (Integer lineNum : errorMap.keySet()) {
                for (ErrorType type: errorMap.get(lineNum)) {

                        sb = new StringBuilder();
                        sb.append(lineNum);
                        sb.append(" ");
                        sb.append(type.toString());
                        sb.append("\n");
                        outputStream_Error.write(sb.toString().getBytes());
                }
            }
        } catch (IOException e) {
            System.err.println("Can not write the error file");
        }
    }

    public void turnOn() {
        this.on_off = true;
    }

    public void turnOff() {
        this.on_off = false;
    }

    public void setHasError () {
        this.hasError = true;
    }

    public boolean isHasError() {
        return this.hasError;
    }
}
