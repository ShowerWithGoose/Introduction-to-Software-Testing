import frontend.SyntaxError.*;
import frontend.lexer.*;
import frontend.parser.CompUnit;
import frontend.parser.CompUnitParser;
import java.util.ArrayList;
import java.util.List;

// 观察者模式接口，定义了观察者收到通知时的行为
interface CompilationObserver {
    // 当编译器有更新时，通知观察者的方法
    void notifyObserver(String notification);
}

// 具体的观察者实现类，负责记录编译过程中的日志
class CompilationLogger implements CompilationObserver {
    @Override
    public void notifyObserver(String notification) {
        // 当接收到通知时，在控制台打印日志信息
        System.out.println("日志： " + notification);
    }
}

// 策略模式接口，定义了输出编译结果的策略
interface OutputStrategy {
    // 用于输出编译单元（抽象语法树）的方法
    void export(CompUnit unit);
}

// 具体的输出策略实现类，默认使用将编译单元转换为语法字符串的方法输出
class DefaultOutputStrategy implements OutputStrategy {
    @Override
    public void export(CompUnit unit) {
        // 将编译单元转换为语法树字符串表示，并输出
        unit.toSyntaxString();
    }
}

// 编译器主类，继承自 BaseCompiler，包含编译流程的具体实现
public class Compiler extends BaseCompiler {
    // 存储观察者对象的列表，用于观察者模式
    private List<CompilationObserver> observerList = new ArrayList<>();
    // 输出策略的引用，使用策略模式实现不同的输出方式
    private OutputStrategy outputPlan;

    // 编译器构造函数，初始化观察者和输出策略
    public Compiler() {
        // 添加一个日志观察者，用于记录编译过程
        observerList.add(new CompilationLogger());
        // 设置默认的输出策略为 DefaultOutputStrategy
        this.outputPlan = new DefaultOutputStrategy();
    }

    // 编译器主入口方法，接收文件路径作为参数
    public static void main(String[] args) {
        // 创建编译器实例并调用 compile 方法开始编译流程
        Compiler compilerInstance = new Compiler();
        compilerInstance.compile("testfile.txt", "parser.txt", "error.txt");
    }

    // 实现 BaseCompiler 抽象类中的 compile 方法
    @Override
    public void compile(String inputFilePath, String outputFilePath, String errorLogFile) {
        // 通知观察者编译开始
        notifyObservers("编译启动");

        // 初始化编译环境，成功则继续进行后续步骤
        if (initializeCompiler()) {
            // 进行词法分析，生成 token 序列
            TokenList tokenSequence = executeLexicalAnalysis(inputFilePath);
            // 进行语法分析，生成编译单元（抽象语法树）
            CompUnit compilationUnit = executeSyntaxAnalysis(tokenSequence);
            // 输出编译结果
            presentOutput(compilationUnit);
            // 完成编译流程，清理环境
            finalizeCompilation();
        }

        // 通知观察者编译结束
        notifyObservers("编译结束");
    }

    // 初始化编译器环境，比如清理错误文件
    private boolean initializeCompiler() {
        // 获取单例的错误处理器实例
        SyntaxErrorHandler errorHandler = SyntaxErrorHandler.getInstance();
        if (errorHandler != null) {
            // 清空 error.txt 文件中的内容
            errorHandler.ClearError_txt();
            // 通知观察者错误文件已清空
            notifyObservers("错误文件已清空");
            return true;
        }
        return false;
    }

    // 进行词法分析，将源文件转换为 token 列表
    private TokenList executeLexicalAnalysis(String sourceFile) {
        // 添加异常处理，防止词法分析失败
        try {
            // 创建源文件对象
            SourceFile srcFile = new SourceFile(sourceFile);
            // 创建词法分析器对象
            Lexer lexer = new Lexer(srcFile);
            // 创建空的 token 列表，用于存储词法分析结果
            TokenList tokenList = new TokenList();
            // 将词法分析的 token 结果添加到列表中
            lexer.TokenToList(tokenList);
            // 通知观察者词法分析完成
            notifyObservers("词法分析完成");
            return tokenList;
        } catch (Exception e) {
            // 词法分析失败时通知观察者
            notifyObservers("词法分析失败");
            return null;
        }
    }

    // 进行语法分析，将 token 列表转换为抽象语法树
    private CompUnit executeSyntaxAnalysis(TokenList tokenSequence) {
        // 添加异常处理，防止语法分析失败
        try {
            // 创建语法分析器对象，并传入 token 列表
            CompUnitParser parser = new CompUnitParser(tokenSequence);
            // 解析生成编译单元（抽象语法树）
            CompUnit unit = parser.parseCompUnit();
            // 通知观察者语法分析完成
            notifyObservers("语法分析完成");
            return unit;
        } catch (Exception e) {
            // 语法分析失败时通知观察者
            notifyObservers("语法分析失败");
            return null;
        }
    }

    // 使用策略模式输出编译结果
    private void presentOutput(CompUnit unit) {
        // 如果语法分析结果不为空，则使用当前的输出策略进行输出
        if (unit != null) {
            outputPlan.export(unit);
            notifyObservers("结果输出完成");
        } else {
            // 如果语法分析结果为空，通知观察者输出为空
            notifyObservers("输出结果为空");
        }
    }

    // 完成编译过程，处理错误文件并进行收尾工作
    private void finalizeCompilation() {
        // 启动一个线程对错误文件进行排序
        Thread errorThread = new Thread(() -> {
            SyntaxErrorHandler.getInstance().SortError_txt();
            notifyObservers("错误文件已排序");
        });
        errorThread.start();

        // 等待错误排序线程完成
        try {
            errorThread.join();
        } catch (InterruptedException e) {
            // 如果线程中断，通知观察者
            notifyObservers("错误文件排序中断");
        }
    }

    // 观察者模式的通知方法，遍历所有观察者并发送通知
    private void notifyObservers(String message) {
        for (CompilationObserver observer : observerList) {
            observer.notifyObserver(message);
        }
    }

    // 冗余方法，不影响功能，用于演示额外的检查
    private void runAdditionalChecks() {
        // 模拟执行额外的检查
        notifyObservers("执行额外的检查");
    }

    // 设置输出策略的方法，允许更换输出方式
    public void setOutputStrategy(OutputStrategy strategy) {
        this.outputPlan = strategy;
        notifyObservers("输出策略已更改");
    }
}

// 抽象基类，定义了编译器必须实现的基本方法
abstract class BaseCompiler {
    // 抽象方法，所有子类必须实现具体的编译逻辑
    public abstract void compile(String inputFilePath, String outputFilePath, String errorLogFile);
}
