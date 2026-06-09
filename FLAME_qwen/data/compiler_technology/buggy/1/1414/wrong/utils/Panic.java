package utils;

public class Panic {
    public static void panic(String message) {
        throw new RuntimeException(message);
    }

    public static void panicIfFalse(boolean condition, String message) {
        if (!condition) {
            throw new RuntimeException(message);
        }
    }
}
