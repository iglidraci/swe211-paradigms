public class TaskThreadDemo {
    public static void main(String[] args) {
        // create tasks
        Runnable printA = new PrintChar('a', 1000);
        Runnable printB = new PrintChar('b', 1000);
        Runnable print1000 = new PrintNum(1000);
        // creat threads
        Thread thread1 = new Thread(printA);
        Thread thread2 = new Thread(printB);
        Thread thread3 = new Thread(print1000);
        // start threads
        thread1.start();
        thread2.start();
        thread3.start();
        // Invoking run() directly merely executes this method in the same thread
        // no new thread is started
    }
}
/**This class provides a framework for printing any single character a given number of times.*/
class PrintChar implements Runnable {

    private final char charToPrint; // the character to print
    private final int times; // the number of times to repeat

    public PrintChar(char c, int t) {
        charToPrint = c;
        times = t;
    }

    @Override
    public void run() {
        for (int i = 0; i < times; i++) {
            System.out.print(charToPrint);
        }
    }
}

/**This class provides a framework for printing numbers from 1 to n, for any integer n.*/
class PrintNum implements Runnable {
    private final int lastNum;
    public PrintNum(int n) {
        lastNum = n; // Construct a task for printing 1, 2, ..., n
    }

    @Override
    public void run() {
        for (int i = 1; i <= lastNum; i++) {
            System.out.print(" " + i);
        }
    }
}