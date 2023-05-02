import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class ThreadCooperation {
    private static final Account account = new Account();

    public static void main(String[] args) {
        ExecutorService executor = Executors.newFixedThreadPool(2);
        executor.execute(new DepositTask());
        executor.execute(new WithdrawTask());
        executor.shutdown();
        System.out.println("Thread 1\t\tThread 2\t\tBalance");
    }
    private static class DepositTask implements Runnable {
        @Override
        public void run() {
            try {
                while (true) {
                    account.deposit((int)(Math.random() * 10) + 1);
                    Thread.sleep(1000); // purposely delay to let the withdraw method proceed
                }
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }
    private static class WithdrawTask implements Runnable {
        @Override
        public void run() {
            while (true) {
                account.withdraw((int)(Math.random() * 10)  + 1);
            }
        }
    }
    private static class Account {
        private static final Lock lock = new ReentrantLock();
        private static final Condition newDeposit = lock.newCondition();
        private int balance = 0;

        public int getBalance() {
            return balance;
        }

        public void withdraw(int amount) {
            lock.lock(); // acquire lock
            try {
                while (balance < amount) {
                    System.out.println("\t".repeat(3) + "Wait for a deposit");
                    newDeposit.await();
                }
                balance -= amount;
                System.out.println("\t".repeat(3) + "Withdraw " + amount + "\t\t" + getBalance());
            } catch (InterruptedException ex) {
                ex.printStackTrace();
            } finally {
                lock.unlock(); // release the lock
            }
            /*
            What would happen if the while loop was changed to an if statement?
             */
        }

        public void deposit(int amount) {
            lock.lock(); // acquire the lock
            try {
                balance += amount;
                System.out.println("Deposit " + amount + "\t".repeat(5) + getBalance());
                // signal threads waiting on the condition
                newDeposit.signalAll();
            } finally {
                lock.unlock(); // Release the lock
            }
        }
    }
}
