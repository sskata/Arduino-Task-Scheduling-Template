/******************** Task scheduling template ********************
*  
* Author: Sebastian Skata
*   
* This is a simple task scheduling template to make tasks execute
* with various periods. The template contains examples, modify 
* accordig to need.
*   
* Features/Usage:
* - Make tasks as functions (not in loop()) and list function calls
*   in appropriate task execution period group in loop() under the 
*   tasklist comment.
* - Supports 10 ms, 20 ms, 50 ms, 100 ms, 200 ms, 500 ms, and 
*   1000 ms task execution periods.
* - Handles micros() counter rollover.
* 
* Known issues/risks:
* - If tasks (functions) take longer to execute (return) than the 
*   execution period, the scheduler will skip one or more iterations 
*   of the task (function).
* - The micros() rollover handling is currently very inaccurate,
*   the execution period will be a bit shorter/longer during
*   rollover (about every 70 minutes).
* - This template code will not work 100% properly with interrupts 
*   since micros() don't increment while executing ISR:s.
* - The micros() funciton has a resolution of 4 µs, thus affectig
*   the execution period accuracy accordingly.
*******************************************************************/

//Set to 1 if tasks with respective period is used, otherwise set to 0 to save memory and CPU
#define TASK_10MS 0
#define TASK_20MS 0
#define TASK_50MS 0
#define TASK_100MS 0
#define TASK_200MS 0
#define TASK_500MS 1
#define TASK_1000MS 1

void setup(){
  Serial.begin(9600); //Only used for the examples
}

void firstTask(){ //Example task 1
  Serial.println("Task 1 is executing");
}

void secondTask(){ //Example task 2
  Serial.println("Task 2 is executing");
}

void loop(){ //Task scheduler, schedules and executes tasks
#if TASK_10MS  
  static long unsigned int a = micros();
  if(micros() >= (a + 10000)){ //10 ms tasks
    a = micros();
    /* Tasklist: 10 ms */
  }
  else if(micros() < a) a = 0;
#endif
#if TASK_20MS
  static long unsigned int b = micros();
  if(micros() >= (b + 20000)){ //20 ms tasks
    b = micros();
    /* Tasklist: 20 ms */
  }
  else if(micros() < b) b = 0;
#endif
#if TASK_50MS
  static long unsigned int c = micros();
  if(micros() >= (c + 50000)){ //50 ms tasks
    c = micros();
    /* Tasklist: 50 ms */
  }
  else if(micros() < c) c = 0;
#endif
#if TASK_100MS
  static long unsigned int d = micros();
  if(micros() >= (d + 100000)){ //100 ms tasks
    d = micros();
    /* Tasklist: 100 ms */
  }
  else if(micros() < d) d = 0;
#endif
#if TASK_200MS
  static long unsigned int e = micros();
  if(micros() >= (e + 200000)){ //200 ms tasks
    e = micros();
    /* Tasklist: 200 ms */
  }
  else if(micros() < e) e = 0;
#endif
#if TASK_500MS
  static long unsigned int f = micros();
  if(micros() >= (f + 500000)){ //500 ms tasks
    f = micros();
    /* Tasklist: 500 ms */
    firstTask();
  }
  else if(micros() < f) f = 0;
#endif
#if TASK_1000MS
  static long unsigned int g = micros();
  if(micros() >= (g + 1000000)){ //1000 ms tasks
    g = micros();
    /* Tasklist: 1000 ms */
    secondTask();
  }
  else if(micros() < g) g = 0;
#endif
}
