package frontend.function;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;
import frontend.function.FuncFParam;
import frontend.function.FuncFParamParser;
import frontend.function.FuncFParams;

import java.util.ArrayList;

/**
 * 解析器: FuncFParams (函数形参列表)
 * 对应文法: FuncFParams → FuncFParam { ',' FuncFParam }
 *
 * 解析函数形参列表，支持一个或多个函数形参。
 */
public class FuncFParamsParser {
    private final TokenListIterator iterator;

    public FuncFParamsParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    /**
     * 解析函数形参列表，返回包含解析后的 FuncFParams 对象。
     *
     * @return 解析后的 FuncFParams 对象
     */
    public FuncFParams parseFuncFParams() {
        ArrayList<Token> commas = new ArrayList<>();
        ArrayList<FuncFParam> funcFParams = new ArrayList<>();

        // 解析第一个参数
        FuncFParamParser funcFParamParser = new FuncFParamParser(this.iterator);
        FuncFParam first = funcFParamParser.parseFuncFParam();

        // 解析后续逗号和参数
        Token token = this.iterator.readNextToken();
        while (token.getType().equals(TokenType.COMMA)) {
            commas.add(token);
            funcFParams.add(funcFParamParser.parseFuncFParam());
            token = this.iterator.readNextToken();
        }

        // 回退最后一个非逗号的 Token
        this.iterator.unReadToken(1);

        // 创建并返回 FuncFParams 对象
        return new FuncFParams(first, commas, funcFParams);
    }
}
