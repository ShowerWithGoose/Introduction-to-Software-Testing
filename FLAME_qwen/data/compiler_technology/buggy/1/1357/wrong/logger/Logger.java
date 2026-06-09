package logger;

import java.util.ArrayList;

public class Logger {
    private static ArrayList<String> good = new ArrayList<>();
    private static ArrayList<String> bad = new ArrayList<>();

    public static void logGood(String s) {
        good.add(s);
    }

    public static void logBad(String s) {
        bad.add(s);
    }

    public static String getLastGood() {
        return good.get(good.size() - 1);
    }

    public static String removeLastGood() {
        return good.remove(good.size() - 1);
    }

    public static String getGood() {
        StringBuilder stringBuilder = new StringBuilder();
        for (String s : good) {
            stringBuilder.append(s);
        }
        return stringBuilder.toString();
    }

    public static String getBad() {
        StringBuilder stringBuilder = new StringBuilder();
        for (String s : bad) {
            stringBuilder.append(s);
        }
        return stringBuilder.toString();
    }
}
