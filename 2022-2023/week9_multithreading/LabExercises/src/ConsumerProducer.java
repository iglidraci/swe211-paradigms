import java.util.LinkedList;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class ConsumerProducer {
    private static final Buffer buffer = new Buffer();

    public static void main(String[] args) {
        ExecutorService executor = Executors.newFixedThreadPool(2);
        executor.execute(new ProducerTask());
        executor.execute(new ConsumerTask());
        executor.shutdown();
    }

    private static class ProducerTask implements Runnable {
        @Override
        public void run() {
            try {
                int i = 1;
                while (true) {
                    buffer.write(i++); // add a value to the buffer
                    Thread.sleep((int)(Math.random() * 3000));
                }
            } catch (InterruptedException ex) {
                ex.printStackTrace();
            }
        }
    }

    private static class ConsumerTask implements Runnable {
        @Override
        public void run() {
            try {
                while (true) {
                    buffer.read();
                    Thread.sleep((int)(Math.random() * 3000));
                }
            } catch (InterruptedException ex) {
                ex.printStackTrace();
            }
        }
    }
    private static class Buffer {
        private static final int CAPACITY = 1; // buffer size
        private final LinkedList<Integer> queue = new LinkedList<>();
        // create a new lock
        private static Lock lock = new ReentrantLock();
        // create two conditions
        private static Condition notEmpty = lock.newCondition();
        private static Condition notFull = lock.newCondition();

        public void write (int value) {
            lock.lock(); // acquire the lock
            try {
                while (queue.size() == CAPACITY) {
                    System.out.println("Wait for notFull condition");
                    notFull.await();
                }
                queue.addLast(value);
                System.out.println("Producer writes " + value);
                notEmpty.signal();
            } catch (InterruptedException ex) {
                ex.printStackTrace();
            } finally {
                lock.unlock();
            }
        }

        public void read() {
            lock.lock(); // acquire lock
            try {
                while (queue.isEmpty()) {
                    System.out.println("\t\tWait for notEmpty condition");
                    notEmpty.await();
                }
                int value = queue.remove();
                System.out.println("\t\t\tConsumer reads " + value);
                notFull.signal();
            } catch (InterruptedException e) {
                e.printStackTrace();
            } finally {
                lock.unlock(); // release lock
            }
        }
    }
}
