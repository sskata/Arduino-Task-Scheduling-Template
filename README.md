# Arduino-Task-Scheduling-Template

Simple task scheduling template to use with various ATmega328 based Arduinos.

## Features
- Supports 10 ms, 20 ms, 50 ms, 100 ms, 200 ms, 500 ms, and 1000 ms task execution periods.

## Getting Started

This code is only a template to start from when task scheduling is needed. Simply add functions to the template code and add a function call inside the appropriate task scheduling period inside loop(). Different task periods need to be enabled/disabled according to need in the beginning of the code (the #define statements).

### Prerequisites

- An ATmega328 based Arduino
- The Arduino IDE

## Known issues/risks

- If tasks (functions) take longer to execute (return) than the execution period, the scheduler will skip one or more iterations of the task (function).
- The micros() rollover handling is currently very inaccurate, the execution period will be a bit shorter/longer during rollover (about every 70 minutes).
- This template code will not work 100% properly with interrupts since micros() don't increment while executing ISR:s.
- The micros() funciton has a resolution of 4 µs, thus affectig the execution period accuracy accordingly.
