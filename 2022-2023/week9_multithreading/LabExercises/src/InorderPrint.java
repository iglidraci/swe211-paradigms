public class InorderPrint {

    static Bar bar = new Bar();
    public static void main(String[] args) {
        Thread t1 = new Thread(() -> bar.third());
        Thread t2 = new Thread(() -> {
            bar.second();
        });
        Thread t3 = new Thread(() -> {
            try {
                Thread.sleep(100);
                bar.first();
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        });
        t1.start();
        t2.start();
        t3.start();
    }
}

class Bar {
    /**
     * It seems correct but there is a problem with this solution
     * Find out the problem and solve it.
     */
    boolean waitFirst = true;
    boolean waitSecond = true;
    public void first() {
        System.out.println("First");
        waitFirst = false;
    }

    public void second() {
        while (waitFirst) {
        }
        System.out.println("Second");
        waitSecond = false;
    }

    public void third() {
        while (waitSecond) {
        }
        System.out.println("Third");
    }
}