struct semaphore { 
    enum value(0, 1); 
  
    // q contains all Process Control Blocks (PCBs) 
    // corresponding to processes got blocked 
    // while performing down operation. 
    Queue<process> q; 
  
} P(semaphore s) 
{ 
    if (s.value == 1) { 
        s.value = 0; 
    } 
    else { 
        // add the process to the waiting queue 
        q.push(P) 
            sleep(); 
    } 
} 
V(Semaphore s) 
{ 
    if (s.q is empty) { 
        s.value = 1; 
    } 
    else { 
  
        // select a process from waiting queue 
        q.pop(); 
        wakeup(); 
    } 
} 













struct Semaphore { 
    int value; 
  
    // q contains all Process Control Blocks(PCBs) 
    // corresponding to processes got blocked 
    // while performing down operation. 
    Queue<process> q; 
  
} P(Semaphore s) 
{ 
    s.value = s.value - 1; 
    if (s.value < 0) { 
  
        // add process to queue 
        // here p is a process which is currently executing 
        q.push(p); 
        block(); 
    } 
    else
        return; 
} 
  
V(Semaphore s) 
{ 
    s.value = s.value + 1; 
    if (s.value <= 0) { 
  
        // remove process p from queue 
        q.pop(); 
        wakeup(p); 
    } 
    else
        return; 
} 
