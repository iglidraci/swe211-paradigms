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
    }
}

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

class PrintNum implements Runnable {
    private final int lastNum;
    public PrintNum(int n) {
        lastNum = n; // Construct a task for printing 1, 2, ..., n
    }

    @Override
    public void run() {
        Thread thread4 = new Thread(new PrintChar('c', 1000));
        thread4.start();
        for (int i = 1; i <= lastNum; i++) {
            System.out.print(" " + i);
            if(i == 50) {
                try {
                    thread4.join();
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
            }
        }
    }
}