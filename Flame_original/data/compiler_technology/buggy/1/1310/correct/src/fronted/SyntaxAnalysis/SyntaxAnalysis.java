package src.fronted.SyntaxAnalysis;

import src.AST.*;
import src.ErrorHandle.BaseError;
import src.fronted.SyntaxAnalysis.Utils.Utils;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.stream.Collectors;

import static src.ErrorHandle.ErrorController.ErrorList;

public class SyntaxAnalysis {
    //接收词法分析的结果
    public static ArrayList<String> syntaxList;
    //最终要输出的列表
    public static int Syntaxcur = -1;
    //当前读到的词法分析的位置。
    //因为这个量已知在变化，所以如果写一个工具类的话，
    // 就需要每次都传入这个变量，所以就把工具类放到这个文件里面吧。
    //而且就算写在内部类里面，感觉反而是更麻烦了，只是结构清晰了一点。
    //最终解决办法就是写成一个静态的全局变量
    private Root root;
    public static Utils utils;

    //根节点
    public SyntaxAnalysis() {
        //别忘了初始化
        utils = new Utils();
        syntaxList = new ArrayList<>();
        root = new Root();
    }

    public void analyse() {
        this.root.compUnit = new CompUnit().analyse();
    }

    public void output() throws IOException {
        if (!ErrorList.isEmpty()) {
            ErrorList = (ArrayList<BaseError>) ErrorList.stream().sorted(Comparator.comparingInt(BaseError::getRow)).collect(Collectors.toList());
            BufferedWriter errorWriter = new BufferedWriter(new FileWriter("error.txt"));
            for (BaseError baseError : ErrorList) {
                errorWriter.write(baseError.getRow() + " " + baseError.getErrortype());
                errorWriter.newLine();
            }
            errorWriter.flush();
            errorWriter.close();
        } else {
            BufferedWriter lexerWriter = new BufferedWriter(new FileWriter("parser.txt"));
            for (String s : syntaxList) {
                lexerWriter.write(s);
                lexerWriter.newLine();
            }
            lexerWriter.flush();
            lexerWriter.close();
        }
    }
}
