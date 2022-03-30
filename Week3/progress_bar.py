from random import randint
from time import sleep


def update_progress_bar(processes, nr_processes, scale=10):
    work_to_do = sum(processes.values())
    work_done = nr_processes*100 - work_to_do
    percentage = work_done / nr_processes
    print(f'| {"|"*(work_done//scale)}{" "*(work_to_do//scale)} | {work_done}/{nr_processes*100} ({percentage}%)',
          end='\r')


def main():
    nr_processes = 10
    processes = {i: 100 for i in range(nr_processes)}
    while len(processes.keys()) > 0:
        process_id = randint(0, nr_processes - 1)
        if process_id in processes:
            work_done = randint(0, 50)
            sleep(.1)
            if processes[process_id] <= work_done:
                # finished with one process
                processes.pop(process_id)
            else:
                # reduce process work to do
                processes[process_id] -= work_done
            update_progress_bar(processes, nr_processes, 15)


if __name__ == '__main__':
    main()
