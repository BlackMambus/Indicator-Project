#include <iostream>
#include <thread>
#include <chrono>

class HazardIndicator {
public:
    HazardIndicator() : isActive(false) {}

    // Function to turn on the hazard lights
    void turnOn() {
        isActive = true;
        displayIndicator();
    }

    // Function to turn off the hazard lights
    void turnOff() {
        isActive = false;
        displayIndicator();
    }

    // Function to toggle the hazard lights (if they are on, turn them off, and vice versa)
    void toggle() {
        isActive = !isActive;
        displayIndicator();
    }

    // Function to display the hazard indicator status
    void displayIndicator() {
        if (isActive) {
            std::cout << "Hazard lights are ON. Blinking...\n";
            blinkLights();
        } else {
            std::cout << "Hazard lights are OFF.\n";
        }
    }

private:
    bool isActive;

    // Simulate blinking lights (flashes every second)
    void blinkLights() {
        int blinkCount = 5; // For example, blink 5 times
        for (int i = 0; i < blinkCount; i++) {
            std::cout << (i % 2 == 0 ? "LEFT BLINKER ON  | RIGHT BLINKER ON" : "LEFT BLINKER OFF | RIGHT BLINKER OFF") << std::endl;
        }
    }
};

int main() {
    HazardIndicator hazard;
    int choice;
    
    while (true) {
        std::cout << "\nHazard Indicator System\n";
        std::cout << "1. Turn ON Hazard Lights\n";
        std::cout << "2. Turn OFF Hazard Lights\n";
        std::cout << "3. Toggle Hazard Lights\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                hazard.turnOn();
                break;
            case 2:
                hazard.turnOff();
                break;
            case 3:
                hazard.toggle();
                break;
            case 4:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice, please try again.\n";
        }
    }

    return 0;
}
