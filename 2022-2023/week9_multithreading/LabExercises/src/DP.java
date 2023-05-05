import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

abstract class DiningPhilosophers {
    protected String[] philosophers = {"Descartes", "Plato", "Socrates", "Spinoza", "Leibniz"};
    protected Lock[] chopsticks = new Lock[5];

    public DiningPhilosophers() {
        for (int i = 0; i < 5; i++) {
            chopsticks[i] = new ReentrantLock();
        }
    }
    public abstract void eat(int philosopher);
}

/**
 * This solution causes deadlock.
 * Suppose that all five philosophers become hungry at the same time and each grabs her left chopstick.
 * When each philosopher tries to grab her right chopstick, she will be delayed forever.
 */
class BadDiningPhilosophers extends DiningPhilosophers {

    @Override
    public void eat(int philosopher) {
        int left = philosopher;
        int right = (left + 1) % 5;
        chopsticks[left].lock();
        System.out.println(philosophers[philosopher] + " picked the left chopstick");
        chopsticks[right].lock();
        System.out.println(philosophers[philosopher] + " picked the right chopstick");
        System.out.println(philosophers[philosopher] + " finished eating");
        chopsticks[left].unlock();
        System.out.println(philosophers[philosopher] + " released the left chopstick");
        chopsticks[right].unlock();
        System.out.println(philosophers[philosopher] + " released the right chopstick");
    }
}

/**
 * An odd-numbered philosopher picks up first her left chopstick and then her right chopstick,
 * whereas an even-numbered philosopher picks up her right chopstick and then her left chopstick.
 */
class AsymmetricDiningPhilosophers extends DiningPhilosophers {

    @Override
    public void eat(int philosopher) {
        int left = philosopher;
        int right;
        if(left == 0) right = 4;
        else right = left - 1;
        int firstChopstick, secondChopstick;
        if((philosopher + 1) % 2 == 1) {
            firstChopstick = left;
            secondChopstick = right;
        } else {
            firstChopstick = right;
            secondChopstick = left;
        }
        chopsticks[firstChopstick].lock();
        System.out.println(philosophers[philosopher] + " picked the first chopstick");
        chopsticks[secondChopstick].lock();
        System.out.println(philosophers[philosopher] + " picked the second chopstick");
        System.out.println(philosophers[philosopher] + " finished eating");
        chopsticks[firstChopstick].unlock();
        System.out.println(philosophers[philosopher] + " released the first chopstick");
        chopsticks[secondChopstick].unlock();
        System.out.println(philosophers[philosopher] + " released the second chopstick");
        Thread.yield();
    }
}

public class DP {
    static DiningPhilosophers dp = new AsymmetricDiningPhilosophers();

    static class EatTask implements Runnable {

        private final int philosopherEating;
        public EatTask(int philosopherEating) {
            this.philosopherEating = philosopherEating;
        }

        @Override
        public void run() {
            while (true){
                dp.eat(philosopherEating);
            }
        }
    }
    public static void main(String[] args) {
        ExecutorService pool = Executors.newCachedThreadPool();
        for (int i = 0; i < 5; i++) {
            pool.execute(new EatTask(i%5));
        }
        pool.shutdown();
        while(!pool.isTerminated()) {
        }
        System.out.println("End of program");
    }
}
