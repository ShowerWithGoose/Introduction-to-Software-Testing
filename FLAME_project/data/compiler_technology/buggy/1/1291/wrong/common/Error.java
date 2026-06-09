package common;

public class Error implements Comparable<Error>{

    // 错误类别码
    public static final String LEXICAL_ERROR = "a";   // 词法分析错误
    public static final String NAME_REDEFINED = "b";   // 名字重定义
    public static final String UNDEFINED_NAME = "c";   // 未定义的名字
    public static final String PARAM_COUNT_MISMATCH = "d"; // 函数参数个数不匹配
    public static final String PARAM_TYPE_MISMATCH = "e";   // 函数参数类型不匹配
    public static final String RETURN_MISMATCH = "f";        // 无返回值的函数存在不匹配的 return 语句
    public static final String RETURN_STATEMENT_MISSING = "g"; // 有返回值的函数缺少 return 语句
    public static final String CONST_MODIFICATION = "h";     // 不能改变常量的值
    public static final String MISSING_SEMICOLON = "i";      // 缺少分号
    public static final String MISSING_RIGHT_PAREN = "j";    // 缺少右小括号
    public static final String MISSING_RIGHT_BRACKET = "k";   // 缺少右中括号
    public static final String PRINTF_FORMAT_MISMATCH = "l";  // printf中格式字符与表达式个数不匹配
    public static final String BREAK_CONTINUE_OUTSIDE_LOOP = "m"; // 在非循环块中使用 break 和 continue 语句

    private final int line;
    private final String type;

    public Error(int line, String Type) {
        this.line = line;
        this.type = Type;
    }

    @Override
    public String toString() {
        return line + " " + type;
    }

    @Override
    public int compareTo(Error o) {
        int cmp = Integer.compare(this.line, o.line);
        if (cmp != 0) {
            return cmp;
        }
        return String.CASE_INSENSITIVE_ORDER.compare(this.type, o.type);
    }
}
