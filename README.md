# CPU_Process_Scheduling in C

Scheduling of CPU processes is done to finish tasks on time. <br/>
There are different process scheduling algorithms based on which process you want to execute first.<br/>
They are categorized into 2 categories - Non-Preemptive and Preemptive.<br/>

# Non-Preemptive Scheduling Algorithms:
- It is used when process switches from running state to waiting state, or when a process terminates. Basically one entire process executes completely before another starts.<br/>
- The non-pre-emptive algorithms coded here are - First Come First Serve, Shortest Job First, Non-Preemptive Priority Scheduling.<br/>

1. First Come First Serve (FCFS)<br/>
    a. the process which arrives first executes first followed by the ones arriving next.<br/>
    b. if multiple processes arrive while a particular process is running, then the process with the least            arrival time exexutes first.<br/>
    c. Pseudocode:<br/>
        sort the processes in ascending order of arrival time<br/>
        loop through the arrival time (the counter is the time)<br/>
        if a particular time is the arrival time of a process<br/>
          &nbsp; print the process' pid, arrival time and time+burst time<br/>
          &nbsp; update time to be time+burst time<br/>
          
2. Shortest Job First (SJF)<br/>
    a.process with the least burst time executes first<br/>
    b. Pseudocode:<br/>
        sort the processes in ascending order of burst time<br/>
        flag all processes as -1<br/>
        first print the process arriving first (burst time need not be the least) and flag it as 1<br/>
        then loop through all the processes (processes are sorted based on burst time)<br/>
          if a process has arrived and it has not been flagged yet<br/>
            print the process. pid, current time and time+burst<br/>
            update time to be time+burst<br/>
   
3. Non-Preemeptive Priority Scheduling <br/>
    a.process with the highest priority executes first till its completion without interruption<br/>
    b. Pseudocode:<br/>
        sort all the processes in ascending order of priority (smaller the number -> higher the priority)<br/>
        flag all the processes as -1<br/>
        first print the process arriving first and flag it as 1<br/>
        then loop through all the processes (processes are sorted based on priority)<br/>
          if a process has arrived and it has not been flagged yet<br/>
            print the process' pid, current time, time+burst<br/>
            update time to be time+burst<br/>
        
# Preemptive Scheduling Algorithms :<br/>
- It is used when a process switched from running to ready state or waiting to rady state. Basically the execution of one process is interupted for another one to execute.<br/>
- The pre-emptive algorithms coded here are -  Shortest Remaining Time First, Preemptive Priority Scheduling.<br/>

1. Shortest Remaining Time First (SRTF)<br/>
  a. it is the pre-emptive version of SJF<br/>
  b. Pseudocode:<br/>
      sort the processes in ascending order of arrival time<br/>
      initialise a variable min_b (minimum burst=9999)<br/>
      initialise a variable id=0<br/>
      
      until( process has ended, execute for 1 sec)<br/>
      { <br/>
        if (current process has ended)<br/>
          do necessary calculations to update total_waiting_Time, total_response_time, turn_Around_time<br/>
          if (all processes have ended)<br/>
            break out of the loop<br/>
        check (if a new process arrived at this instant or already arrived but not finished execution)<br/>
          if its burst time is the least burst time<br/>
            change process id<br/>
        if (process has started for the first time)<br/>
          mark its "first arrival time"<br/>
      }<br/>
      
2. Preemptive Priority Scheduling<br/>
  a. it is the pre-emptive version of FCFS<br/>
  b. Pseudocode:<br/>
      sort the processes in ascending order of arrival time<br/>
      initialise a varible min_p (minimum priority=9999)<br/>
      initialise a variable id=0<br/>
      
      until( process has ended, execute for 1 sec)<br/>
      {<br/>
        if (current process has ended)<br/>
          do necessary calculations to update total_waiting_Time, total_response_time, turn_Around_time<br/>
          if (all processes have ended)<br/>
            break out of the loop<br/>
        check (if a new process arrived at this instant or already arrived but not finished execution)<br/>
          if its priority is the least priority (smaller the number-> higher the priority)<br/>
            change process id<br/>
        if (process has started for the first time)<br/>
          mark its "first arrival time"<br/>
      }
