# CPU_Process_Scheduling in C

Scheduling of CPU processes is done to finish tasks on time. <br/>
There are different process scheduling algorithms based on which process you want to execute first.<br/>
They are categorized into 2 categories - Non-Preemptive and Preemptive.<br/>

# Non-Preemptive Scheduling Algorithms:
- It is used when process switches from running state to waiting state, or when a process terminates. Basically one entire process executes completely before another starts.<br/>
- The non-pre-emptive algorithms coded here are - First Come First Serve, Shortest Job First, Non-Preemptive Priority Scheduling.<br/>

1. First Come First Serve (FCFS)<br/>
    - the process which arrives first executes first followed by the ones arriving next.<br/>
    - if multiple processes arrive while a particular process is running, then the process with the least            arrival time exexutes first.<br/>
    - Pseudocode:<br/>
         &nbsp;  &nbsp; sort the processes in ascending order of arrival time<br/>
         &nbsp;  &nbsp; loop through the arrival time (the counter is the time)<br/>
         &nbsp;  &nbsp; if a particular time is the arrival time of a process<br/>
         &nbsp;  &nbsp;  &nbsp;  &nbsp; print the process' pid, arrival time and time+burst time<br/>
         &nbsp;  &nbsp;  &nbsp;  &nbsp; update time to be time+burst time<br/>
          
2. Shortest Job First (SJF)<br/>
    - process with the least burst time executes first<br/>
    - Pseudocode:<br/>
        &nbsp;  &nbsp; sort the processes in ascending order of burst time<br/>
        &nbsp;  &nbsp; flag all processes as -1<br/>
        &nbsp;  &nbsp; first print the process arriving first (burst time need not be the least) and flag it as 1<br/>
        &nbsp;  &nbsp; then loop through all the processes (processes are sorted based on burst time)<br/>
        &nbsp;  &nbsp;  &nbsp;  &nbsp; if a process has arrived and it has not been flagged yet<br/>
        &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp; print the process. pid, current time and time+burst<br/>
        &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp; update time to be time+burst<br/>
   
3. Non-Preemeptive Priority Scheduling <br/>
    - process with the highest priority executes first till its completion without interruption<br/>
    - Pseudocode:<br/>
         &nbsp;  &nbsp; sort all the processes in ascending order of priority (smaller the number -> higher the priority)<br/>
         &nbsp;  &nbsp; flag all the processes as -1<br/>
         &nbsp;  &nbsp; first print the process arriving first and flag it as 1<br/>
         &nbsp;  &nbsp; then loop through all the processes (processes are sorted based on priority)<br/>
         &nbsp;  &nbsp;  &nbsp;  &nbsp; if a process has arrived and it has not been flagged yet<br/>
         &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp; print the process' pid, current time, time+burst<br/>
         &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp; update time to be time+burst<br/>
        
# Preemptive Scheduling Algorithms :<br/>
- It is used when a process switched from running to ready state or waiting to rady state. Basically the execution of one process is interupted for another one to execute.<br/>
- The pre-emptive algorithms coded here are -  Shortest Remaining Time First, Preemptive Priority Scheduling.<br/>

1. Shortest Remaining Time First (SRTF)<br/>
  - it is the pre-emptive version of SJF<br/>
  - Pseudocode:<br/>
      &nbsp; &nbsp; sort the processes in ascending order of arrival time<br/>
      &nbsp; &nbsp; initialise a variable min_b (minimum burst=9999)<br/>
      &nbsp; &nbsp; initialise a variable id=0<br/>
      
      &nbsp; &nbsp; until( process has ended, execute for 1 sec)<br/>
      &nbsp; &nbsp; { <br/>
      &nbsp; &nbsp; &nbsp; &nbsp; if (current process has ended)<br/>
      &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; do necessary calculations to update total_waiting_Time, total_response_time, turn_Around_time<br/>
      &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;if (all processes have ended)<br/>
      &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp; break out of the loop<br/>
      &nbsp; &nbsp; &nbsp; &nbsp; check (if a new process arrived at this instant or already arrived but not finished execution)<br/>
      &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp; if its burst time is the least burst time<br/>
      &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp; change process id<br/>
      &nbsp; &nbsp; &nbsp; &nbsp; if (process has started for the first time)<br/>
      &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp; mark its "first arrival time"<br/>
      &nbsp; &nbsp; }<br/>
      
2. Preemptive Priority Scheduling<br/>
  - it is the pre-emptive version of FCFS<br/>
  - Pseudocode:<br/>
       &nbsp;  &nbsp; sort the processes in ascending order of arrival time<br/>
       &nbsp;  &nbsp; initialise a varible min_p (minimum priority=9999)<br/>
       &nbsp;  &nbsp; initialise a variable id=0<br/>
      
       &nbsp;  &nbsp; until( process has ended, execute for 1 sec)<br/>
       &nbsp;  &nbsp; {<br/>
       &nbsp;  &nbsp;  &nbsp;  &nbsp; if (current process has ended)<br/>
       &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp; do necessary calculations to update total_waiting_Time, total_response_time, turn_Around_time<br/>
       &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp; if (all processes have ended)<br/>
       &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp; &nbsp;  &nbsp; break out of the loop<br/>
       &nbsp;  &nbsp;  &nbsp;  &nbsp; check (if a new process arrived at this instant or already arrived but not finished execution)<br/>
       &nbsp;  &nbsp;  &nbsp;  &nbsp; &nbsp;  &nbsp; if its priority is the least priority (smaller the number-> higher the priority)<br/>
       &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp; change process id<br/>
       &nbsp;  &nbsp;  &nbsp;  &nbsp; if (process has started for the first time)<br/>
       &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp; mark its "first arrival time"<br/>
       &nbsp;  &nbsp; }
