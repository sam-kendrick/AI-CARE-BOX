#pragma once
#include <string>

// VoiceAssistant simulates a friendly AI voice assistant using rule-based keyword matching
class VoiceAssistant {
private:
    std::string assistantName;
    std::string lastInput;

    // Internal helper methods for case-insensitive matching
    std::string toLower(const std::string& text) const;
    bool hasWord(const std::string& text, const std::string& word) const;

public:
    // Default constructor
    VoiceAssistant();

    // Parameterized constructor
    VoiceAssistant(std::string name);

    // Getters and setters
    std::string getAssistantName() const;
    void setAssistantName(std::string name);

    std::string getLastInput() const;

    // Listen to user input typed in the console
    std::string listen();

    // Respond based on the last listened input
    void respond();

    // Overloaded respond for direct string input
    void respond(std::string query);
};
