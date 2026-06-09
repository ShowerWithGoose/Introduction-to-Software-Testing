package frontend.symbol.symbolType;

import frontend.parser.TreeNode;
import frontend.symbol.Type;

public class Symbol {
    public int id;		// 当前单词对应的id。
    public int tableId; 	// 当前单词所在的符号表编号。
    public String token; 	// 当前单词所对应的字符串。
    public Type type;
    public int declLine;
    public TreeNode treeNode;
    // 数组的维数：a[dim1] dim1
    // 变量的值：val，寄存器：reg
    // func：
    // 	retype		// 0 -> void, 1 -> int, 2 -> char
    //	paramNum	// 参数数量
    // 	paramTypeList	// 参数类型
}

