#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

enum Priority {
    NORMAL = 1,
    MEDIUM = 2,
    CRITICAL = 3
};

struct Patient {
    int id;
    std::string name;
    Priority priority;
    int arrivalOrder;
};

class EmergencyQueue {
private:
    std::vector<Patient> heap;
    int arrivalCounter = 0;

    bool hasHigherPriority(const Patient& a, const Patient& b) const {
        if (a.priority != b.priority) {
            return a.priority > b.priority;
        }
        return a.arrivalOrder < b.arrivalOrder;
    }

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (hasHigherPriority(heap[index], heap[parent])) {
                std::swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int n = static_cast<int>(heap.size());
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int best = index;

            if (left < n && hasHigherPriority(heap[left], heap[best])) {
                best = left;
            }
            if (right < n && hasHigherPriority(heap[right], heap[best])) {
                best = right;
            }

            if (best != index) {
                std::swap(heap[index], heap[best]);
                index = best;
            } else {
                break;
            }
        }
    }

    static std::string priorityToString(Priority p) {
        switch (p) {
            case CRITICAL: return "Critical";
            case MEDIUM:   return "Medium";
            case NORMAL:   return "Normal";
            default:       return "Unknown";
        }
    }

public:
    void addPatient(int id, const std::string& name, Priority priority) {
        Patient p{id, name, priority, ++arrivalCounter};
        heap.push_back(p);
        heapifyUp(static_cast<int>(heap.size()) - 1);
        std::cout << "\n[SUCCESS] Patient Added: " << name 
                  << " | ID: " << id 
                  << " | Level: " << priorityToString(priority) << "\n";
    }

    void callNextPatient() {
        if (heap.empty()) {
            std::cout << "\n[CALL] No patients currently waiting.\n";
            return;
        }

        Patient next = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty()) {
            heapifyDown(0);
        }

        std::cout << "\n[CALL] Now treating: " << next.name 
                  << " | ID: " << next.id 
                  << " | Level: " << priorityToString(next.priority) << "\n";
    }

    void searchPatient(int id) const {
        for (const auto& p : heap) {
            if (p.id == id) {
                std::cout << "\n[SEARCH] Found ID " << id 
                          << ": " << p.name 
                          << " (" << priorityToString(p.priority) 
                          << ", Arrival #" << p.arrivalOrder << ")\n";
                return;
            }
        }
        std::cout << "\n[SEARCH] Patient with ID " << id << " not found.\n";
    }
};

int main() {
    EmergencyQueue eq;
    int choice;

    // લૂપ ચાલશે જ્યાં સુધી યુઝર બહાર નીકળવાનું નક્કી ન કરે
    do {
        std::cout << "\n========== EMERGENCY ROOM SYSTEM ==========\n";
        std::cout << "1. Add New Patient\n";
        std::cout << "2. Call/Treat Next Patient\n";
        std::cout << "3. Search Patient by ID\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice (1-4): ";
        std::cin >> choice;

        if (choice == 1) {
            int id, pChoice;
            std::string name;
            Priority priority;

            std::cout << "Enter Patient ID: ";
            std::cin >> id;
            std::cout << "Enter Patient Name: ";
            std::cin.ignore(); // બફર સાફ કરવા માટે
            std::getline(std::cin, name);
            
            std::cout << "Select Priority Level (1: Normal, 2: Medium, 3: Critical): ";
            std::cin >> pChoice;

            // યુઝરની ચોઇસ મુજબ પ્રાયોરિટી સેટ કરો
            if (pChoice == 3) priority = CRITICAL;
            else if (pChoice == 2) priority = MEDIUM;
            else priority = NORMAL;

            // પેશન્ટ ઉમેરો
            eq.addPatient(id, name, priority);

        } else if (choice == 2) {
            eq.callNextPatient();

        } else if (choice == 3) {
            int searchId;
            std::cout << "Enter Patient ID to search: ";
            std::cin >> searchId;
            eq.searchPatient(searchId);

        } else if (choice == 4) {
            std::cout << "Exiting System. Thank you!\n";
        } else {
            std::cout << "Invalid choice! Please enter a number between 1 and 4.\n";
        }

    } while (choice != 4);

    return 0;
}
