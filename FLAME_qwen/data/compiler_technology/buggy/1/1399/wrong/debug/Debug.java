/********************************************************************************
 * @FileName     : Debug.java
 * @Author       :
 * @Description  : Debug类
 * @Notice       : None
 * @Time         : 2024-10-04 04:35
 * @Version      : 0.0
 ********************************************************************************/

package debug;

import config.Config;

public class Debug {
    public static final boolean is_debugging = Config.is_debugging; // 是否为debug模式
    public static final boolean use_panic = Config.use_panic; // 是否在遇到错误时直接退出程序
    public static final boolean use_parser_info_print = Config.use_parser_info_print;

    public static void printDebug(String info) {
        if (is_debugging) {
            System.out.println("============== Debug ==============\n" + info);
        }
    }

    public static void panic(String info) {
        if (is_debugging) {
            Debug.printDebug(info);
            if (Config.is_throws_exception)
                throw new RuntimeException("Panic!");
            if (use_panic) {
                System.out.println("Panic!");
                System.exit(1);
            }
        }
    }

}
