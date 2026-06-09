package frontend.parser;

import frontend.parser.declaration.Decl;
import frontend.parser.function.*;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

/**
 * CompUnit 类表示编译单元（通常是程序的根结构），包括全局声明、函数定义以及主函数定义。
 * 它实现了 SyntaxOutput 接口，负责将语法树输出为字符串形式，并将其写入文件。
 */
public class CompUnit implements SyntaxOutput {

    // 常量，表示当前语法结构的名称，用于生成语法树字符串
    private static final String SYNTAX_NAME = "<CompUnit>";

    // 存储全局声明的列表（Decl）
    private ArrayList<Decl> globalDeclarations;

    // 主函数定义（MainFuncDef）
    private MainFuncDef mainFunctionDefinition;

    // 存储函数定义的列表（FuncDef）
    private ArrayList<FuncDef> functionDefinitions;

    /**
     * 构造函数，用于初始化 CompUnit 对象。
     * @param globalDeclarations 全局声明列表（Decl）
     * @param functionDefinitions 函数定义列表（FuncDef）
     * @param mainFunctionDefinition 主函数定义（MainFuncDef）
     */
    public CompUnit(ArrayList<Decl> globalDeclarations, ArrayList<FuncDef> functionDefinitions, MainFuncDef mainFunctionDefinition) {
        // 如果传入的列表为 null，则初始化为空列表，避免空指针异常
        this.globalDeclarations = globalDeclarations != null ? globalDeclarations : new ArrayList<>();
        this.functionDefinitions = functionDefinitions != null ? functionDefinitions : new ArrayList<>();
        this.mainFunctionDefinition = mainFunctionDefinition;
    }

    /**
     * 将语法树结构输出为字符串，并将其写入文件。
     * @return 生成的语法树字符串
     */
    @Override
    public String toSyntaxString() {
        // 使用 StringBuilder 以提高字符串拼接的性能
        StringBuilder syntaxStringBuilder = new StringBuilder();

        // 遍历并拼接全局声明的语法字符串
        if (globalDeclarations != null && !globalDeclarations.isEmpty()) {
            globalDeclarations.forEach(declaration -> syntaxStringBuilder.append(declaration.toSyntaxString()));
        }

        // 遍历并拼接函数定义的语法字符串
        if (functionDefinitions != null && !functionDefinitions.isEmpty()) {
            functionDefinitions.forEach(function -> syntaxStringBuilder.append(function.toSyntaxString()));
        }

        // 拼接主函数的语法字符串
        if (mainFunctionDefinition != null) {
            syntaxStringBuilder.append(mainFunctionDefinition.toSyntaxString());
        }

        // 添加当前语法结构的名称
        syntaxStringBuilder.append(SYNTAX_NAME).append("\n");

        // 将拼接好的字符串写入文件
        writeSyntaxToFile(syntaxStringBuilder.toString());

        return syntaxStringBuilder.toString();
    }

    /**
     * 将生成的语法树字符串写入文件 "parser.txt"。
     * @param syntaxContent 要写入文件的内容
     */
    private void writeSyntaxToFile(String syntaxContent) {
        // 使用 try-with-resources 以确保文件流正确关闭
        try (FileWriter fileWriter = new FileWriter("parser.txt")) {
            // 将内容写入文件
            fileWriter.write(syntaxContent);
        } catch (IOException e) {
            // 如果发生 IO 异常，打印堆栈跟踪信息
            e.printStackTrace();
        }
    }
}
