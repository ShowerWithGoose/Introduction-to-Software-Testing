package frontend;

import java.util.regex.Pattern;

public class Match {
    private boolean ifGreedy;
    private String string;
    private Pattern pattern;

    public Match(Type type) {
        this.string = type.getName();
        this.ifGreedy = type.getWhether();
        if (ifGreedy) {
            this.pattern = Pattern.compile("^" + this.string);
        } else {
            this.pattern = Pattern.compile("^" + this.string + "(?![_A-Za-z0-9])");
        }
    }

    public Pattern getPattern() {
        return pattern;
    }




}
