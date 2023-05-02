import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class ExecutorDemo {
    public static void main(String[] args) {
        /*
        * Creates a thread pool with a fixed number of threads executing concurrently.
        * A thread may be reused to execute another task after its current task is finished
        * */
        ExecutorService executor = Executors.newFixedThreadPool(3);
        // Submit runnable tasks to the executor
        executor.execute(new PrintChar('a', 1000));
        executor.execute(new PrintChar('b', 1000));
        executor.execute(new PrintNum(100));

        /*
        * Shuts down the executor, but allows the tasks in the executor to complete.
        * Once shut down, it cannot accept new tasks
        * */
        executor.shutdown();

        /*
         * What if: ExecutorService executor = Executors.newFixedThreadPool(1);
         * What if: ExecutorService executor = Executors.newCachedThreadPool();
         */
    }
}
