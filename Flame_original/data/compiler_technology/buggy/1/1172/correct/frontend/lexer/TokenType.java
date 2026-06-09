package frontend.lexer;

import java.util.regex.Pattern;
import java.util.EnumMap;
import java.util.Map;

/**
 * TokenType 枚举，定义了所有可能的 Token 类型。
 * 每个枚举值表示不同的词法单元类型，包含保留字、标识符、常量、运算符、分隔符以及错误词法等。
 * 通过正则表达式匹配相应的输入内容。
 */
public enum TokenType {
    // 保留字（关键词）
    MAINTK(true, "main"),          // main 关键字
    CONSTTK(true, "const"),        // const 关键字
    INTTK(true, "int"),            // int 关键字
    CHARTK(true, "char"),          // char 关键字
    BREAKTK(true, "break"),        // break 关键字
    CONTINUETK(true, "continue"),  // continue 关键字
    IFTK(true, "if"),              // if 关键字
    ELSETK(true, "else"),          // else 关键字
    FORTK(true, "for"),            // for 关键字
    GETINTTK(true, "getint"),      // getint 关键字
    GETCHARTK(true, "getchar"),    // getchar 关键字
    PRINTFTK(true, "printf"),      // printf 关键字
    RETURNTK(true, "return"),      // return 关键字
    VOIDTK(true, "void"),          // void 关键字

    // 标识符和常量
    IDENFR(false, "[a-zA-Z_][a-zA-Z0-9_]*"),  // 标识符 (以字母或下划线开头，后接字母、数字或下划线)
    INTCON(false, "[0-9]+"),                 // 整数常量 (由数字组成)
    CHRCON(false, "'([^'\\\\]|\\\\.)'"),      // 字符常量 (单个字符或转义字符)
    STRCON(false, "\"([^\"\\\\]|\\\\.)*\""),  // 字符串常量 (由双引号包裹的字符序列)

    // 运算符和分隔符
    PLUS(false, "\\+"),        // 加号 "+"
    MINU(false, "-"),          // 减号 "-"
    MULT(false, "\\*"),        // 乘号 "*"
    DIV(false, "/"),           // 除号 "/"
    LEQ(false, "<="),          // 小于等于 "<="
    LSS(false, "<"),           // 小于 "<"
    GEQ(false, ">="),          // 大于等于 ">="
    GRE(false, ">"),           // 大于 ">"
    EQL(false, "=="),          // 等于 "=="
    NEQ(false, "!="),          // 不等于 "!="
    NOT(false, "!"),           // 逻辑非 "!"
    AND(false, "&&"),          // 逻辑与 "&&"
    OR(false, "\\|\\|"),       // 逻辑或 "||"
    ASSIGN(false, "="),        // 赋值 "="
    SEMICN(false, ";"),        // 分号 ";"
    COMMA(false, ","),         // 逗号 ","
    LPARENT(false, "\\("),     // 左括号 "("
    RPARENT(false, "\\)"),     // 右括号 ")"
    MOD(false, "%"),           // 取模 "%"
    LBRACK(false, "\\["),      // 左方括号 "["
    RBRACK(false, "\\]"),      // 右方括号 "]"
    LBRACE(false, "\\{"),      // 左花括号 "{"
    RBRACE(false, "\\}"),      // 右花括号 "}"

    // 错误词法
    ERROR_AND(false, "&"),     // 错误的逻辑与 "&" (应为 "&&")
    ERROR_OR(false, "\\|");    // 错误的逻辑或 "|" (应为 "||")

    private final boolean isReserved;  // 表示该词法单元是否为保留字
    private final String patternStr;   // 正则表达式，用于匹配该词法单元
    private final boolean isError;     // 表示该词法单元是否为错误类型

    // 延迟初始化的模式缓存，用于存储每个 TokenType 对应的编译后的正则表达式 Pattern。
    private static final Map<TokenType, Pattern> patternCache = new EnumMap<>(TokenType.class);

    /**
     * 构造函数，初始化 TokenType 枚举项。
     * @param isReserved 该 Token 是否为保留字
     * @param patternStr 匹配该 Token 的正则表达式字符串
     */
    TokenType(boolean isReserved, String patternStr) {
        this.isReserved = isReserved; // 初始化是否为保留字的标志
        this.patternStr = patternStr; // 初始化正则表达式字符串
        this.isError = patternStr.equals("&") || patternStr.equals("\\|");  // 如果是错误的运算符，则标记为错误类型
    }

    /**
     * 获取对应的正则表达式模式，使用延迟初始化方式缓存每个 TokenType 对应的 Pattern。
     * 其中保留字要求后面不能跟随字母或数字，以防止匹配类似 "ifelse" 的情况。
     * @return 编译后的正则表达式 Pattern 对象
     */
    public Pattern getPattern() {
        // 如果缓存中不存在该 TokenType 的 Pattern，则根据规则生成并存入缓存
        return patternCache.computeIfAbsent(this, key -> {
            // 如果是保留字，后面不能接字母或数字；否则按照普通正则表达式匹配
            String fullPatternStr = isReserved
                    ? "^" + patternStr + "(?![a-zA-Z0-9_])"  // 保留字匹配规则
                    : "^" + patternStr;                      // 非保留字的匹配规则
            return Pattern.compile(fullPatternStr);          // 编译为 Pattern 并返回
        });
    }

    /**
     * 判断该 Token 是否为错误类型。
     * @return 如果是错误 Token 返回 true，否则返回 false
     */
    public boolean isError() {
        return isError;  // 返回是否为错误类型
    }

    /**
     * 判断该 Token 是否为保留字。
     * @return 如果是保留字返回 true，否则返回 false
     */
    public boolean isReserved() {
        return isReserved;  // 返回是否为保留字
    }
}
