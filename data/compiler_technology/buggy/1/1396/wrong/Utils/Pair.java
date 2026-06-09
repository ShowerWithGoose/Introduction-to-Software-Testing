package Utils;

public class Pair<T1, T2> {
    private T1 first;
    private T2 second;

    public Pair(T1 first, T2 second) {
        this.first = first;
        this.second = second;
    }

    public T1 first() {
        return first;
    }

    public void first(T1 first) {
        this.first = first;
    }

    public T2 second() {
        return second;
    }

    public void second(T2 second) {
        this.second = second;
    }

    @Override
    public String toString() {
        return "(" + first.toString() + ", " + second.toString() + ")";
    }
}
