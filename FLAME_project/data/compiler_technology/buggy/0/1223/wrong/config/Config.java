package config;

public class Config {

    // I/O Settings
    private static String inputFilePath;  // 输入文件路径
    private static String outputFilePath; // 输出文件路径
    private static String errorFilePath; // 错误输出文件路径
    private static boolean lexOption;       // 是否输出词法分析阶段语言

    // Compilation Settings
//    private boolean optimize;      // 是否进行优化
//    private boolean generateAssembly; // 是否生成汇编代码

    // 获取输入文件路径
    public static String getInputFilePath() {
        return inputFilePath;
    }

    // 设置输入文件路径
    public static void setInputFilePath(String inputFilePath) {
        Config.inputFilePath = inputFilePath;
    }

    // 获取输出文件路径
    public static String getOutputFilePath() {
        return outputFilePath;
    }

    // 设置输出文件路径
    public static void setOutputFilePath(String outputFilePath) {
        Config.outputFilePath = outputFilePath;
    }

    public static boolean isLexOption() {
        return lexOption;
    }

    public static void setLexOption(boolean lexOption) {
        Config.lexOption = lexOption;
    }

    public static String getErrorFilePath() {
        return errorFilePath;
    }

    public static void setErrorFilePath(String errorFilePath) {
        Config.errorFilePath = errorFilePath;
    }

//    // 获取优化选项
//    public boolean isOptimize() {
//        return optimize;
//    }
//
//    // 设置优化选项
//    public void setOptimize(boolean optimize) {
//        this.optimize = optimize;
//    }
//
//    // 是否生成汇编代码
//    public boolean isGenerateAssembly() {
//        return generateAssembly;
//    }
//
//    // 设置是否生成汇编代码
//    public void setGenerateAssembly(boolean generateAssembly) {
//        this.generateAssembly = generateAssembly;
//    }

    // 显示当前配置信息
    public static void showConfig() {
        System.out.println("Input File: " + inputFilePath);
        System.out.println("Output File: " + outputFilePath);
        System.out.println("Error Output File: " + errorFilePath);
        System.out.println("LexOption Mode: " + (lexOption ? "Enabled" : "Disabled"));
//        System.out.println("Optimize: " + (optimize ? "Enabled" : "Disabled"));
//        System.out.println("Generate Assembly: " + (generateAssembly ? "Yes" : "No"));
    }
}
