package frontend;

import frontend.declaration.Decl;
import frontend.declaration.DeclParser;
import frontend.function.FuncDef;
import frontend.function.FuncDefParser;
import frontend.function.MainFuncDef;
import frontend.function.MainFuncDefParser;

import java.util.ArrayList;

/**
 * 解析器: CompUnitParser (编译单元)
 * 对应文法: CompUnit -> Decl* FuncDef* MainFuncDef
 *
 * 解析程序的编译单元，包含全局声明、函数定义和主函数定义。
 */
public class CompUnitParser {
    private final TokenListIterator iterator;

    private final ArrayList<Decl> decls;
    private final ArrayList<FuncDef> funcDefs;
    private MainFuncDef mainFuncDef;

    public CompUnitParser(TokenList tokens) {
        this.iterator = new TokenListIterator(tokens);
        this.decls = new ArrayList<>();
        this.funcDefs = new ArrayList<>();
        this.mainFuncDef = null;
    }

    /**
     * 解析编译单元。
     * @return 解析后的 CompUnit 对象
     */
    public CompUnit parseCompUnit() {
        parseDecls();
        parseFuncDefs();
        parseMainFuncDef();
        return new CompUnit(this.decls, this.funcDefs, this.mainFuncDef);
    }

    private void parseDecls() {
        while (this.iterator.hasNext()) {
            Token first = this.iterator.readNextToken();
            Token second = this.iterator.readNextToken();

            // 检查函数定义
            Token third = this.iterator.readNextToken(); // 读取第三个 token
            if (third.getType().equals(TokenType.LPARENT)) {
                // 如果下一个 token 是 '(', 说明是函数定义，回退3个 token，跳过声明解析
                this.iterator.unReadToken(3); // 回退3个 token，保持解析位置在函数定义起始
                return;
            } else {
                this.iterator.unReadToken(1); // 如果第三个 token 不是 '(', 只回退一个 token
            }

            // 处理声明
            if (isDeclStart(first, second)) {
                this.iterator.unReadToken(2);
                DeclParser declParser = new DeclParser(this.iterator);
                this.decls.add(declParser.parseDecl());
            } else {
                this.iterator.unReadToken(2);
                break;
            }
        }
    }


    /**
     * 判断两个 Token 是否是声明的起始部分。
     * @param first 第一个 Token
     * @param second 第二个 Token
     * @return 是否为声明起始
     */
    private boolean isDeclStart(Token first, Token second) {
        // 处理常量声明 (const int, const char 等)
        if (first.getType().equals(TokenType.CONSTTK) &&
                (second.getType().equals(TokenType.INTTK) || second.getType().equals(TokenType.CHARTK))) {
            return true;
        }

        // 处理普通变量声明 (int, char)
        return (first.getType().equals(TokenType.INTTK) || first.getType().equals(TokenType.CHARTK)) &&
                second.getType().equals(TokenType.IDENFR);
    }


    /**
     * 解析函数定义 (FuncDef)。
     */
    private void parseFuncDefs() {
        while (this.iterator.hasNext()) {
            Token first = this.iterator.readNextToken();
            Token second = this.iterator.readNextToken();

            if (isFuncDefStart(first, second)) {
                this.iterator.unReadToken(2);
                FuncDefParser funcDefParser = new FuncDefParser(this.iterator);
                this.funcDefs.add(funcDefParser.parseFuncDef());
            } else {
                this.iterator.unReadToken(2);
                break;
            }
        }
    }

    /**
     * 判断两个 Token 是否是函数定义的起始部分。
     * @param first 第一个 Token
     * @param second 第二个 Token
     * @return 是否为函数定义起始
     */
    private boolean isFuncDefStart(Token first, Token second) {
        return (first.getType().equals(TokenType.INTTK) ||
                first.getType().equals(TokenType.VOIDTK) ||
                first.getType().equals(TokenType.CHARTK)) && // 新增对 char 的支持
                second.getType().equals(TokenType.IDENFR);
    }


    /**
     * 解析主函数定义 (MainFuncDef)。
     */
    private void parseMainFuncDef() {
        MainFuncDefParser mainFuncDefParser = new MainFuncDefParser(this.iterator);
        this.mainFuncDef = mainFuncDefParser.parseMainFuncDef();
    }
}
