#include "VoiceAssistant.h"
#include <iostream>

// Helper to convert string to lowercase without external libraries
std::string VoiceAssistant::toLower(const std::string& text) const {
    std::string result = "";
    for (size_t i = 0; i < text.length(); i++) {
        char c = text[i];
        if (c >= 'A' && c <= 'Z') {
            c = c + ('a' - 'A');
        }
        result += c;
    }
    return result;
}

// Helper to check if text contains a specific keyword
bool VoiceAssistant::hasWord(const std::string& text, const std::string& word) const {
    std::string lowerText = toLower(text);
    std::string lowerWord = toLower(word);
    return lowerText.find(lowerWord) != std::string::npos;
}

// Default constructor
VoiceAssistant::VoiceAssistant() {
    assistantName = "Aura";
    lastInput = "";
}

// Parameterized constructor
VoiceAssistant::VoiceAssistant(std::string name) {
    assistantName = name;
    lastInput = "";
}

// Getter for assistant name
std::string VoiceAssistant::getAssistantName() const {
    return assistantName;
}

// Setter for assistant name
void VoiceAssistant::setAssistantName(std::string name) {
    assistantName = name;
}

// Getter for last input
std::string VoiceAssistant::getLastInput() const {
    return lastInput;
}

// Listen to user input from console
std::string VoiceAssistant::listen() {
    std::cout << "\n============================================\n";
    std::cout << "         AI VOICE ASSISTANT (" << assistantName << ")\n";
    std::cout << "============================================\n";
    std::cout << "  Speak (type) your query, or type 'bye' to return.\n";
    std::cout << "  (Try asking about: medicine, task, help, family, reminder)\n\n";
    std::cout << "  >>> You: ";

    std::getline(std::cin, lastInput);

    // If input is empty (e.g. leftover newline), try once more
    if (lastInput.empty()) {
        std::getline(std::cin, lastInput);
    }

    return lastInput;
}

// Respond to the last listened input
void VoiceAssistant::respond() {
    respond(lastInput);
}

// Respond to a specific string query using rule-based keywords
void VoiceAssistant::respond(std::string query) {
    std::cout << "\n  [" << assistantName << " AI]: ";

    if (query.empty()) {
        std::cout << "I didn't quite catch that. Please speak again!\n";
        return;
    }

    if (hasWord(query, "help") || hasWord(query, "emergency") || hasWord(query, "doctor") || hasWord(query, "pain")) {
        std::cout << "\n  *** HEALTH & SAFETY ADVISORY ***\n";
        std::cout << "  If you are experiencing severe discomfort, please sit down and rest.\n";
        std::cout << "  You can perform a 'Daily Check-In' (Option 5) or 'Call Family' (Option 7)\n";
        std::cout << "  to trigger an immediate alert to your caregiver or loved one!\n";
    }
    else if (hasWord(query, "medicine") || hasWord(query, "pill") || hasWord(query, "dose")) {
        std::cout << "\n  *** MEDICINE ADVICE ***\n";
        std::cout << "  Remember to take your prescribed doses on time with a full glass of water.\n";
        std::cout << "  You can review your full medicine schedule in the Daily Briefing (Option 6).\n";
        std::cout << "  Never skip doses without consulting your healthcare provider.\n";
    }
    else if (hasWord(query, "task") || hasWord(query, "work") || hasWord(query, "project") || hasWord(query, "deadline")) {
        std::cout << "\n  *** PRODUCTIVITY COACH ***\n";
        std::cout << "  Break your workload into manageable 25-minute focus intervals.\n";
        std::cout << "  Check your pending work tasks in the Daily Briefing (Option 6) to stay ahead!\n";
        std::cout << "  Remember to take brief eye and stretch breaks.\n";
    }
    else if (hasWord(query, "family") || hasWord(query, "contact") || hasWord(query, "call") || hasWord(query, "daughter") || hasWord(query, "son")) {
        std::cout << "\n  *** FAMILY CONNECTION ***\n";
        std::cout << "  Staying connected with loved ones brings comfort and peace of mind.\n";
        std::cout << "  Use Option 7 from the main menu to place a simulated call or check-in alert!\n";
    }
    else if (hasWord(query, "reminder") || hasWord(query, "alarm") || hasWord(query, "schedule")) {
        std::cout << "\n  *** REMINDER SYSTEM ***\n";
        std::cout << "  I can keep track of all your appointments, medications, and meetings.\n";
        std::cout << "  Use Option 2 to add a new reminder, or Option 3 to view all reminders.\n";
    }
    else if (hasWord(query, "hello") || hasWord(query, "hi") || hasWord(query, "hey")) {
        std::cout << "Hello there! It is wonderful to speak with you today. How can I assist you?\n";
    }
    else if (hasWord(query, "how are you")) {
        std::cout << "I am functioning smoothly and happy to help you stay healthy and organized!\n";
    }
    else if (hasWord(query, "bye") || hasWord(query, "goodbye") || hasWord(query, "exit")) {
        std::cout << "Goodbye for now! Take care of yourself, and call on me anytime.\n";
    }
    else {
        std::cout << "I heard your words, but I am trained specifically on your daily care.\n";
        std::cout << "  You can ask me about:\n";
        std::cout << "  - 'medicine' for health & dosage tips\n";
        std::cout << "  - 'task' or 'work' for productivity tips\n";
        std::cout << "  - 'help' or 'emergency' for safety assistance\n";
        std::cout << "  - 'family' to connect with emergency contacts\n";
        std::cout << "  - 'reminder' to organize your day\n";
    }
    std::cout << "============================================\n";
}
