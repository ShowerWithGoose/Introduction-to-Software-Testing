import Start.Config;
import Start.Driver;

public class Compiler {
    public static void main(String[] args) {
        for (int i = 0; i < args.length; i++) {
            String arg = args[i];
            if (arg.equals("-i") || arg.equals("-I")) {
                Config.in_path = args[i + 1];
            }
            if (arg.equals("-o") || arg.equals("-O")) {
                Config.out_path = args[i + 1];
            }
            if (arg.equals("-e") || arg.equals("-E")) {
                Config.err_path = args[i + 1];
            }
        }
        Driver driver = Driver.getInstance();
        driver.run();
    }
}
