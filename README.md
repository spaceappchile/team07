ArduSat Pi:
======================================
A redundancy-enabled satellite computer based on Arduino and Raspberry Pi
--------------------------------------------

This project aims to define a cubesat payload architecture based on ArduSat and using a Raspberry Pi to extend processing capabilities. In order to arrive at a reliable, flight-capable solution, we have attempted to produce a redundant system where each processor is replicated three times and an FPGA works as an arbiter and voting mechanism.
The FPGA is responsible for interfacing modules in a transparent manner, so that a single failure will be corrected. It also resets the system if a processor fails permanently for a certain period of time.

Flight hardware should not use the Arduino or Raspberry Pi development boards but its' processors, stripped-down of unnecessary connectors and peripherals.
However, in order to test the idea and provide a proof of concept we have worked on out-of-the-box boards (with no redundancy, obviously) alongside our conceptual architectural description.

The file architecture.pdf provides an in-depth description of the hardware architecture, backed up with the files in the Hardware folder. The folders named Arduino and Raspberry Pi provide the code we used for the development boards.

Block diagrams have been created using Dia (http://dia-installer.de/).
