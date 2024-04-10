import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class AccountWithoutSync {
    private static final Account account = new Account();
    public static void main(String[] args) {
        ExecutorService executor = Executors.newCachedThreadPool();

        // create and launch 100 threads
        for (int i = 0; i < 100; i++) {
            executor.execute(new AddAPennyTask());
        }
        executor.shutdown();
        // wait until all tasks are finished
        while (!executor.isTerminated()) {

        }
        System.out.println("What is balance? " + account.getBalance());
        /**
         * The synchronized keyword
         * Synchronizing statements
         */
    }

    // A thread for adding a penny to the account
    private static class AddAPennyTask implements Runnable {
        @Override
        public void run() {
            account.deposit(1);
        }
    }

    private static class Account {
        private int balance = 0;

        public int getBalance() {
            return balance;
        }

        public void deposit(int amount) {
            int newBalance = balance + amount;
            // this delay is deliberately added to magnify the data-corruption problem
            try {
                Thread.sleep(5);
            } catch (InterruptedException ex) {
                ex.printStackTrace();
            }
            balance = newBalance;
        }
    }
}
