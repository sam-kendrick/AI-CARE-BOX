# AI Care Box - Software-Only Personal Assistant

**AI Care Box** is a software-only personal assistant designed in pure Object-Oriented C++ to support elderly citizens and busy working professionals. It combines daily wellbeing check-ins, medication schedules, work task tracking, appointment reminders, automated emergency family alerts, and an interactive voice assistant simulator.

---

## Strict Architectural Rules Followed

1. **Pure Object-Oriented Design**:
   - Only C++ classes and objects are used.
   - `main()` is the only global function in the entire project, and its only task is instantiating `CareBox` and invoking `.run()`.
   - **Zero global variables**, **zero macros**, **zero templates**, **zero lambdas**, and **zero external libraries/APIs**.
2. **Encapsulation & Safety**:
   - Every data member is `private`.
   - Access is mediated strictly via public constructors, getters, setters, and member methods.
   - Fixed-size arrays (no `std::vector`) are used inside classes for predictable memory usage.
3. **Standard Library Constraints**:
   - Only `<iostream>`, `<string>`, and fixed-size native arrays are utilized.
4. **Senior-Friendly Display**:
   - Output uses high-contrast, large-text banner formatting (`===`, `***`, `###`) for optimal visibility and readability.

---

## Class Architecture Overview

| # | Class | File Pair | Description |
|---|---|---|---|
| 1 | **User** | `User.h` / `User.cpp` | Base class storing user identity (`name`, `age`, `language`). Provides `showProfile()` and polymorphic virtual methods. |
| 2 | **ElderlyUser** | `ElderlyUser.h` / `ElderlyUser.cpp` | Derived from `User`. Adds `emergencyContact` and fixed-size `medicineList` with `addMedicine()` and `showMedicines()`. |
| 3 | **ProfessionalUser** | `ProfessionalUser.h` / `ProfessionalUser.cpp` | Derived from `User`. Adds `jobTitle`, `workHours`, and fixed-size `taskList` with `addTask()` and `showTasks()`. |
| 4 | **Reminder** | `Reminder.h` / `Reminder.cpp` | Models an individual reminder item with `title`, `time`, and `isDone` status. |
| 5 | **ReminderManager** | `ReminderManager.h` / `ReminderManager.cpp` | Encapsulates a fixed array of `Reminder` objects with methods to add, view, complete, and filter pending reminders. |
| 6 | **FamilyContact** | `FamilyContact.h` / `FamilyContact.cpp` | Stores caregiver/family contact details (`name`, `phone`, `relation`). Features `sendAlert(message)` for emergency notification simulation. |
| 7 | **DailyCheckIn** | `DailyCheckIn.h` / `DailyCheckIn.cpp` | Prompts daily wellbeing status ("Are you feeling okay today?"). If answered negatively, it immediately triggers `FamilyContact::sendAlert()`. |
| 8 | **DailyBriefing** | `DailyBriefing.h` / `DailyBriefing.cpp` | Aggregates daily greeting, pending reminders from `ReminderManager`, and polymorphic schedule (medicines for seniors, tasks for professionals). |
| 9 | **VoiceAssistant** | `VoiceAssistant.h` / `VoiceAssistant.cpp` | Rule-based AI assistant engine. Implements `listen()` and `respond()` with keyword recognition (`medicine`, `task`, `help`, `family`, `reminder`). |
| 10 | **CareBox** | `CareBox.h` / `CareBox.cpp` | Main controller class owning and coordinating all components. Houses the 8-option interactive menu loop in `run()`. |

---

## File Structure

```text
e:/oops med proejct/
│
├── main.cpp                  # Application entry point (instantiates CareBox)
├── CareBox.h / .cpp          # Central application coordinator & menu loop
├── User.h / .cpp             # Base User class
├── ElderlyUser.h / .cpp      # Senior profile with medicine tracking
├── ProfessionalUser.h / .cpp # Working professional profile with task tracking
├── Reminder.h / .cpp         # Single reminder entity
├── ReminderManager.h / .cpp  # Fixed-size array reminder collection manager
├── FamilyContact.h / .cpp    # Emergency family member contact & alert dispatcher
├── DailyCheckIn.h / .cpp     # Wellbeing check-in & automated safety trigger
├── DailyBriefing.h / .cpp    # Unified daily summary presentation
├── VoiceAssistant.h / .cpp   # Rule-based natural language assistant
└── README.md                 # System documentation & build guide
```

---

## Build Command (g++)

Compile all translation units together using `g++`:

```bash
g++ -std=c++11 -Wall -Wextra main.cpp CareBox.cpp User.cpp ElderlyUser.cpp ProfessionalUser.cpp Reminder.cpp ReminderManager.cpp FamilyContact.cpp DailyCheckIn.cpp DailyBriefing.cpp VoiceAssistant.cpp -o AICareBox.exe
```

---

## Running the Program

Run the generated executable:

```powershell
.\AICareBox.exe
```

---

## Menu Options

When launched, the program guides the user through profile selection (Senior Citizen or Busy Professional), then presents the main menu:

```text
============================================
                 MAIN MENU
============================================
  [1] Talk to assistant
  [2] Add reminder
  [3] View reminders
  [4] Mark reminder done
  [5] Daily check-in
  [6] Daily briefing
  [7] Call family (simulated)
  [0] Exit
============================================
```

### Feature Details:
- **Option 1 (Talk to assistant)**: Type any question or phrase. The assistant matches keywords such as `medicine`, `task`, `help`, `family`, or `reminder` and returns customized care guidance.
- **Option 2 (Add reminder)**: Enter a title and time to schedule a new item.
- **Option 3 (View reminders)**: Displays all pending and completed reminders in a clean numbered list.
- **Option 4 (Mark reminder done)**: Enter the reminder number to check it off.
- **Option 5 (Daily check-in)**: Enter `yes` to confirm wellness or `no` to automatically dispatch an alert message to the emergency family contact.
- **Option 6 (Daily briefing)**: Displays a complete morning briefing showing role, pending reminders, and scheduled medicines or work tasks.
- **Option 7 (Call family)**: Initiates a simulated two-way voice call connection to the registered caregiver/family contact.
- **Option 0 (Exit)**: Closes the session with a friendly farewell.
