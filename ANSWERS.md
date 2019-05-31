**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

-> When a process executes, it passes through different states. Below are the five states.

1. start: This is the initial state when a process is first started/created.
2. Ready: The process is waiting to be assigned to a processor. Ready processes are waiting to have the processor allocated to them by the operating system so that they can run. Process may come into this state after Start state or while running it by but interrupted by the scheduler to assign CPU to some other process.
3. Running: Once the process has been assigned to a processor by the OS scheduler, the process state is set to running and the processor executes its instructions.
4. Waiting: Process moves into the waiting state if it needs to wait for a resource, such as waiting for user input, or waiting for a file to become available.
5. Terminated or Exit: Once the process finishes its execution, or it is terminated by the operating system, it is moved to the terminated state where it waits to be removed from main memory.

**2. What is a zombie process?**

-> A zombie process is a process whose execution is completed but it still has an entry in the process table. It usually occur for child processes, as the parent process still needs to read its child's exit status.

**3. How does a zombie process get created? How does one get destroyed?**

-> A zombie process get created when the leftover bits of dead processes that haven’t been cleaned up properly. When a process dies on Linux, it isn’t all removed from memory immediately — its process descriptor stays in memory. The process’s status becomes exit_zombie and the process’s parent is notified that its child process has died with the SIGCHLD signal. The parent process is then supposed to execute the wait() system call to read the dead process’s exit status and other information. This allows the parent process to get information from the dead process. After wait() is called, the zombie process is completely removed from memory. However, if a parent process isn’t programmed properly and never calls wait(), its zombie children will stick around in memory until they’re cleaned up.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

-> The benefit of working in a complied language is faster performance. Whereas, the benefits of working in a non-complied language are easier to implement, more convenient for dynamic languages, and faster code execution.
