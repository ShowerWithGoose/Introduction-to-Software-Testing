package frontend;

import java.math.BigInteger;

public record Token(LexType lexType, int lineNum, BigInteger number, String value) {

    @Override
    public String toString() {
        return this.lexType + " " + this.value;
    }
}
