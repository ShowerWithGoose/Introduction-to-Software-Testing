public class Token {
    TokenType type;
    String content;
    int lineno;

    public Token(TokenType type, String content, int lineno) {
        this.type = type;
        this.content = content;
        this.lineno = lineno;
    }

    public enum TokenType{
        // 标识符（例如变量名、函数名等）
        Ident("IDENFR"),
        // 整型常量
        IntConst("INTCON"),
        // 字符串常量
        StringConst("STRCON"),
        // 字符常量
        CharConst("CHRCON"),
        // main函数的关键字
        Main("MAINTK"),
        // const关键字，用于声明常量
        Const("CONSTTK"),
        // int关键字，用于声明整型变量或函数返回类型
        Int("INTTK"),
        // char关键字，用于声明字符型变量或函数返回类型
        Char("CHARTK"),
        // break关键字，用于中断循环或switch语句
        Break("BREAKTK"),
        // continue关键字，用于跳过当前循环的剩余部分并开始下一次迭代
        Continue("CONTINUETK"),
        // if关键字，用于条件判断
        If("IFTK"),
        // else关键字，与if一起使用，表示if条件不满足时执行的代码块
        Else("ELSETK"),
        // for关键字，用于循环结构
        For("FORTK"),
        // getint函数
        Getint("GETINTTK"),
        // getchar函数
        Getchar("GETCHARTK"),
        // printf函数，用于格式化输出
        Printf("PRINTFTK"),
        // return关键字，用于从函数中返回值
        Return("RETURNTK"),
        // void关键字，表示函数没有返回值或声明一个void类型的变量（尽管这很少见）
        Void("VOIDTK"),
        // 逻辑非操作符
        Not("NOT"),
        // 逻辑与操作符
        And("AND"),
        // 逻辑或操作符
        Or("OR"),
        // 加法操作符
        Plus("PLUS"),
        // 减法操作符
        Minu("MINU"),
        // 乘法操作符
        Mult("MULT"),
        // 除法操作符
        Div("DIV"),
        // 取模操作符
        Mod("MOD"),
        // 小于比较操作符
        Lss("LSS"),
        // 小于等于比较操作符
        Leq("LEQ"),
        // 大于比较操作符
        Gre("GRE"),
        // 大于等于比较操作符
        Geq("GEQ"),
        // 等于比较操作符
        Eql("EQL"),
        // 不等于比较操作符
        Neq("NEQ"),
        // 赋值操作符
        Assign("ASSIGN"),
        // 分号，语句的结束符
        Semicn("SEMICN"),
        // 逗号，用于分隔参数或列表中的元素
        Comma("COMMA"),
        // 左圆括号，用于函数调用、控制结构或定义优先级
        Lparent("LPARENT"),
        // 右圆括号，与左圆括号匹配
        Rparent("RPARENT"),
        // 左方括号，可能用于数组索引或定义优先级（在某些上下文中）
        Lbrack("LBRACK"),
        // 右方括号，与左方括号匹配
        Rbrack("RBRACK"),
        // 左大括号，用于定义代码块或复合结构
        Lbrace("LBRACE"),
        // 右大括号，与左大括号匹配
        Rbrace("RBRACE");
        private final String value;

        private TokenType(String value) {
            this.value = value;
        }

        public String getValue() {
            return value;
        }

        public static TokenType fromValue(String value) {
            for (TokenType type : TokenType.values()) {
                if (type.value.equals(value)) {
                    return type;
                }
            }
            return null;
        }
    }

    public String toString(int lineno) {
        return String.valueOf(lineno);
    }

    public String toString(TokenType type) {
        return String.valueOf(type);
    }
}
