# Sleep Better App by Justin Lai

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [System Architecture](#system-architecture)
- [Usage](#usage)


---

## Overview
**Sleep Better App** is a Qt-based application designed to help users track and analyze their sleep patterns, manage daily habits, and optimize their wake-up times with a smart alarm system. The app provides a user-friendly interface for entering sleep data, analyzing sleep quality, and making personalized recommendations based on sleep scores and habits.

---

## Features
- **Sleep Tracking:**
  - Add sleep sessions with start/end times, sleep quality, and notes.
  - View detailed sleep logs in a table.

- **Sleep Analysis:**
  - Compute an "Adjusted Sleep Score" based on habits and sleep quality.

- **Habit Management:**
  - Add, edit, and delete daily habits.
  - Track common habits like drinking water, eating healthy, and exercising.

- **Smart Alarm:**
  - Suggests an optimal bedtime based on user-selected wake time and sleep score.
  - Ensures at least 7 hours of sleep regardless of user inputs.

---

## System Architecture
The application uses a modular, object-oriented design with the following key components:

### Classes:
1. **SleepLog:** Manages sleep session data.
2. **SleepAnalyzer:** Analyzes sleep quality and computes adjusted sleep scores.
3. **HabitManager:** Handles user-defined habits and their frequencies.
4. **SmartAlarm:** Recommends bedtimes based on wake-up time and sleep scores.

### Dialogs:
- **AddSleepSessionDialog:** Interface for adding sleep sessions.
- **ManageHabitsDialog:** Interface for managing habits.
- **SleepAnalysisDialog:** Displays sleep analysis results.
- **SmartAlarmDialog:** Provides bedtime recommendations based on user inputs.

### Design Patterns:
- **Model-View-Controller (MVC):** Separation of UI and business logic.
- **Singleton Pattern:** Used for centralized management of certain components.
- **Observer Pattern:** Ensures UI updates dynamically when underlying data changes.

---

## Usage
1. **Track Sleep Sessions:**
   - Add sleep sessions with timestamps, quality, and notes using the "Add Sleep Session" button.
2. **Analyze Sleep:**
   - Click the "Analyze Sleep" button to compute your sleep score.
3. **Manage Habits:**
   - Use "Manage Habits" to add or modify daily habits that influence sleep.
4. **Set Smart Alarm:**
   - Use the "Smart Alarm" button to get recommendations for your ideal bedtime.
5. **Save and Load Data:**
   - Use the "Save Data" and "Load Data" buttons to persist or retrieve your data.

---
## Running the program
Navigate to ...\code\build\Desktop_Qt_6_8_0_MinGW_64_bit-Release\release folder. There should be an exe file you can run. If it does not work you may have to run it through QT Creator.

## Troubleshooting and Packaging Instructions

If the exe file doesn't work after moving it to a different folder or computer, follow these steps to resolve the issue.

### Problem: Missing Dependencies
The application requires additional libraries (DLLs) from Qt to run. These dependencies are not automatically included with the `.exe` file. 

### Solution: Package the Application
1. **Locate the `windeployqt` Tool:**
   - The `windeployqt` tool is included with Qt. Make sure Qt is installed on your system and its `bin` folder is added to your system’s PATH.
   - Example path for Qt:
     ```
     C:\Qt\6.8.0\mingw_64\bin
     ```

2. **Run `windeployqt`:**
   - Open a terminal or command prompt.
   - Navigate to the folder containing the `Sleep Better App.exe` file.
   - Run the following command:
     ```cmd
     windeployqt "Sleep Better App.exe"
     ```
   - This command will copy all the required Qt libraries (DLLs) into the same directory as the executable.

3. **Check for Missing Files:**
   - After running `windeployqt`, ensure that the following types of files are present in the same folder as your `.exe`:
     - Qt DLLs, e.g., `Qt6Core.dll`, `Qt6Gui.dll`, `Qt6Widgets.dll`.
     - Any plugins or additional files required by the app (e.g., `platforms/qwindows.dll` for Windows).
     - Any configuration or resource files (e.g., `.json`, `.ini`, or image files) that your app uses.

4. **Package Everything:**
   - Create a ZIP archive of the folder containing:
     - `Sleep Better App.exe`.
     - All the DLLs and additional files generated by `windeployqt`.
   - Distribute this ZIP file to others.


## Dependencies
- **Qt Framework 6.8.0**
- **C++ Standard Library**

---
