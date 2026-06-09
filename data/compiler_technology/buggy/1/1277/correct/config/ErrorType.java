package config;

public enum ErrorType {
    a,  // 非法符号 &,|
    i,  // 缺少分号 报错行号为分号前一个非络结符所在行号。
    j,  // 缺少右小括号)
    k   // 缺少右中括号]
}
