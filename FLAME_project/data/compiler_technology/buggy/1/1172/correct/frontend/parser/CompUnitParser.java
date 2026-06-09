package frontend.parser;

import frontend.parser.declaration.*;
import frontend.parser.function.*;
import frontend.lexer.*;

import java.util.ArrayList;

/**
 * CompUnitParser 类负责解析整个编译单元（通常是程序的顶层结构）。
 * 它解析全局声明、函数定义以及主函数，并将解析结果封装为 CompUnit 对象。
 */
public class CompUnitParser {
    // 负责遍历和访问 Token 的迭代器
    private TokenListIterator tokenIterator;

    // 存储全局声明的列表
    private ArrayList<Decl> globalDeclarations = new ArrayList<>();

    // 存储函数定义的列表
    private ArrayList<FuncDef> functionDefinitions = new ArrayList<>();

    // 主函数定义
    private MainFuncDef mainFunctionDefinition;

    /**
     * 构造函数，初始化 CompUnitParser。
     * @param tokenList 词法分析生成的 TokenList，用于构建 TokenListIterator
     */
    public CompUnitParser(TokenList tokenList) {
        // 使用 TokenList 初始化迭代器
        this.tokenIterator = new TokenListIterator(tokenList);
    }

    /**
     * 解析整个编译单元。
     * 包括全局声明、函数定义和主函数定义，最终返回一个 CompUnit 对象。
     * @return 解析后的 CompUnit 对象
     */
    public CompUnit parseCompUnit() {
        parseGlobalDeclarations();
        parseFunctionDefinitions();
        parseMainFunctionDefinition();
        // 将解析结果封装为 CompUnit 并返回
        return new CompUnit(this.globalDeclarations, this.functionDefinitions, this.mainFunctionDefinition);
    }

    /**
     * 解析全局声明（Decl）。
     * 通过读取多个 Token 判断是否为全局声明，遇到函数定义时停止解析。
     */
    private void parseGlobalDeclarations() {
        // 初始化全局声明解析器
        DeclParser declParser = new DeclParser(this.tokenIterator);

        // 遍历 Token，尝试解析每个全局声明
        while (this.tokenIterator.hasNext()) {
            int tokensRead = 0;  // 记录读取的 Token 数量，便于回退
            Token firstToken = tokenIterator.readNextToken();
            tokensRead++;

            // 如果没有下一个 Token，回退并退出
            if (!tokenIterator.hasNext()) {
                tokenIterator.unReadTokens(tokensRead);
                break;
            }

            Token secondToken = tokenIterator.readNextToken();
            tokensRead++;

            // 如果没有下一个 Token，回退并退出
            if (!tokenIterator.hasNext()) {
                tokenIterator.unReadTokens(tokensRead);
                break;
            }

            Token thirdToken = tokenIterator.readNextToken();
            tokensRead++;

            // 如果第三个 Token 是左括号 "(", 表示遇到函数定义，退出解析
            if (thirdToken.getType() == TokenType.LPARENT) {
                tokenIterator.unReadTokens(tokensRead);  // 回退读取的 Token
                break;
            } else {
                // 如果不是函数定义，解析为全局声明
                tokenIterator.unReadTokens(tokensRead);  // 回退读取的 Token
                Decl globalDecl = declParser.parseDecl();
                if (globalDecl != null) {
                    this.globalDeclarations.add(globalDecl);  // 添加解析后的全局声明
                }
            }
        }
    }

    /**
     * 解析函数定义（FuncDef）。
     * 通过读取 Token 判断是否为函数定义，遇到主函数定义时停止解析。
     */
    private void parseFunctionDefinitions() {
        // 初始化函数定义解析器
        FuncDefParser funcDefParser = new FuncDefParser(this.tokenIterator);

        // 遍历 Token，尝试解析每个函数定义
        while (this.tokenIterator.hasNext()) {
            int tokensRead = 0;  // 记录读取的 Token 数量，便于回退
            Token firstToken = tokenIterator.readNextToken();
            tokensRead++;

            // 如果没有下一个 Token，回退并退出
            if (!tokenIterator.hasNext()) {
                tokenIterator.unReadTokens(tokensRead);
                break;
            }

            Token secondToken = tokenIterator.readNextToken();
            tokensRead++;

            // 如果第二个 Token 是主函数的标识 "main"，表示遇到主函数定义，退出
            if (secondToken.getType() == TokenType.MAINTK) {
                tokenIterator.unReadTokens(tokensRead);  // 回退读取的 Token
                break;
            } else {
                // 如果不是主函数，解析为普通函数定义
                tokenIterator.unReadTokens(tokensRead);  // 回退读取的 Token
                FuncDef funcDef = funcDefParser.parseFuncDef();
                if (funcDef != null) {
                    this.functionDefinitions.add(funcDef);  // 添加解析后的函数定义
                }
            }
        }
    }

    /**
     * 解析主函数定义（MainFuncDef）。
     * 通过 MainFuncDefParser 来解析主函数定义。
     */
    private void parseMainFunctionDefinition() {
        // 初始化主函数定义解析器
        MainFuncDefParser mainFuncDefParser = new MainFuncDefParser(this.tokenIterator);
        // 解析并存储主函数定义
        this.mainFunctionDefinition = mainFuncDefParser.parseMainFuncDef();
    }
}
