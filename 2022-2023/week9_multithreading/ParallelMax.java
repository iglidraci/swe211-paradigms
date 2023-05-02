import java.util.concurrent.ForkJoinPool;
import java.util.concurrent.RecursiveTask;

public class ParallelMax {
    public static void main(String[] args) {
        final int N = 9_000_000;
        int[] list = new int[N];
        for (int i = 0; i < N; i++) {
            list[i] = i;
        }
        long startTime = System.currentTimeMillis();
        System.out.println("The max number is " + max(list));
        long endTime = System.currentTimeMillis();
        System.out.println("The number of processors is " + Runtime.getRuntime().availableProcessors());
        System.out.println("Time is " + (endTime - startTime) + " milliseconds");
    }

    public static int max(int[] list) {
        RecursiveTask<Integer> task = new MaxTask(list, 0, list.length);
        ForkJoinPool pool = new ForkJoinPool();
        return pool.invoke(task);
    }

    private static class MaxTask extends RecursiveTask<Integer> {
        private static final int THRESHOLD = 1000;
        private final int[] list;
        private final int low;
        private final int high;

        public MaxTask(int[] list, int low, int high) {
            this.list = list;
            this.low = low;
            this.high = high;
        }

        @Override
        protected Integer compute() {
            if (high - low < THRESHOLD) {
                // solve it sequentially
                int m = list[0];
                for (int i = low; i < high; i++) {
                    if(list[i] > m)
                        m = list[i];
                }
                return m;
            } else {
                int mid = (low + high) / 2;
                RecursiveTask<Integer> left = new MaxTask(list, low, mid);
                RecursiveTask<Integer> right = new MaxTask(list, mid, high);
                left.fork(); // Invoking fork() on the task causes the task to be executed
                right.fork();
                // The join() method awaits for the task to complete and then returns the result
                return Math.max(left.join(), right.join());
            }
        }
    }
}
