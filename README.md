# CPU_Process_Scheduling in C

Scheduling of CPU processes is done to finish tasks on time.
There are different process scheduling algorithms based on which process you want to execute first.
They are categorized into 2 categories - Non-Preemptive and Preemptive.

# Non-Preemptive Scheduling Algorithms:
- It is used when process switches from running state to waiting state, or when a process terminates. Basically one entire process executes completely before another starts.
- The non-pre-emptive algorithms coded here are - First Come First Serve, Shortest Job First, Non-Preemptive Priority Scheduling.

1. First Come First Serve (FCFS)
    a. the process which arrives first executes first followed by the ones arriving next.
    b. if multiple processes arrive while a particular process is running, then the process with the least            arrival time exexutes first.
    c. Pseudocode:
        sort the processes in ascending order of arrival time
        loop through the arrival time (the counter is the time)
        if a particular time is the arrival time of a process
          print the process' pid, arrival time and time+burst time
          update time to be time+burst time
          
2. Shortest Job First (SJF)
    a.process with the least burst time executes first
    b. Pseudocode:
        sort the processes in ascending order of burst time
        flag all processes as -1
        first print the process arriving first (burst time need not be the least) and flag it as 1
        then loop through all the processes (processes are sorted based on burst time)
          if a process has arrived and it has not been flagged yet
            print the process. pid, current time and time+burst
            update time to be time+burst
   
3. Non-Preemeptive Priority Scheduling 
    a.process with the highest priority executes first till its completion without interruption
    b. Pseudocode:
        sort all the processes in ascending order of priority (smaller the number -> higher the priority)
        flag all the processes as -1
        first print the process arriving first and flag it as 1
        then loop through all the processes (processes are sorted based on priority)
          if a process has arrived and it has not been flagged yet
            print the process' pid, current time, time+burst
            update time to be time+burst
        
# Preemptive Scheduling Algorithms :
- It is used when a process switched from running to ready state or waiting to rady state. Basically the execution of one process is interupted for another one to execute.
- The pre-emptive algorithms coded here are -  Shortest Remaining Time First, Preemptive Priority Scheduling.

1. Shortest Remaining Time First (SRTF)
  a. it is the pre-emptive version of SJF
  b. Pseudocode:
      sort the processes in ascending order of arrival time
      initialise a variable min_b (minimum burst=9999)
      initialise a variable id=0
      
      until( process has ended, execute for 1 sec)
      { 
        if (current process has ended)
          do necessary calculations to update total_waiting_Time, total_response_time, turn_Around_time
          if (all processes have ended)
            break out of the loop
        check (if a new process arrived at this instant or already arrived but not finished execution)
          if its burst time is the least burst time
            change process id
        if (process has started for the first time)
          mark its "first arrival time"
      }
      
2. Preemptive Priority Scheduling
  a. it is the pre-emptive version of FCFS
  b. Pseudocode:
      sort the processes in ascending order of arrival time
      initialise a varible min_p (minimum priority=9999)
      initialise a variable id=0
      
      until( process has ended, execute for 1 sec)
      {
        if (current process has ended)
          do necessary calculations to update total_waiting_Time, total_response_time, turn_Around_time
          if (all processes have ended)
            break out of the loop
        check (if a new process arrived at this instant or already arrived but not finished execution)
          if its priority is the least priority (smaller the number-> higher the priority)
            change process id
        if (process has started for the first time)
          mark its "first arrival time"
      }
