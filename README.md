# Traffic Flow Analysis (Stack)

## Table of Contents
- [Project Overview](#project-overview)
- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Technologies Used](#technologies-used)
- [Author](#author)

## Project Overview
The **Traffic Flow Analysis (Stack)** project simulates and analyzes vehicle flow on a road using a stack data structure. It allows for real-time tracking of vehicles entering and leaving the road, traffic level monitoring, and predictive analytics for future traffic patterns.

## Features
- **User Authentication**: Secure login with a username and password.
- **Real-Time Vehicle Management**: Add vehicles to the stack and remove them as they leave the road.
- **Traffic Level Monitoring**: Assess and display current traffic levels (Low, Medium, High, or Congestion).
- **Dynamic Capacity Management**: Adjust the maximum road capacity during runtime.
- **Priority Handling**: Vehicles can be prioritized for entry based on their importance (e.g., emergency vehicles).
- **Traffic Prediction**: Basic traffic predictions based on current traffic data.
- **Vehicle Type Statistics**: Analyze and display statistics about different types of vehicles on the road.
- **Time-Based Analytics**: Calculate average time spent by vehicles on the road.
- **Data Persistence**: Log vehicle entries and exits to a text file for historical analysis.

## Getting Started
To get started with the project, follow these instructions to set up your development environment.

### Prerequisites
- **C Compiler**: Ensure you have a C compiler installed (e.g., GCC).
- **Terminal/Command Line Interface**: You will need to use a terminal or command prompt to compile and run the program.

### Installation
1. **Clone the Repository** (or download the source code):
   ```bash
   git clone https://github.com/yourusername/TrafficFlowAnalysis.git
   cd TrafficFlowAnalysis

2. **Compile the Program**: In your terminal, navigate to the directory containing the traffic_flow_analysis.c file and run:
```bash
gcc traffic_flow_analysis.c -o traffic_flow_analysis
```
**Usage**

1. **Run the Program: After successful compilation, run the program using**:
```bash

./traffic_flow_analysis
```
2. **Login**:
```bash
Enter the username: yashh
Enter the password: 0001
```
Menu Options: Follow the on-screen menu to:

1. **Vehicle enters the road**
2. **Vehicle leaves the road**
3. **View top vehicle on road**
4. **Display all vehicles on road**
5. **Display current traffic level**
6. **Change road capacity**
7. **Display average time on road**
8. **View traffic statistics**
9. **Predict future traffic level**
10. **Exit**
**Enter your choice:** 

Technologies Used**
C Programming Language
Standard Libraries (stdio.h, stdlib.h, string.h, time.h).
