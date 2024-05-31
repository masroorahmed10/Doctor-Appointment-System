#include <iostream>
#include <string>

using namespace std;

// Define maximum size for arrays
const int MAX_PATIENTS = 30;
const int MAX_APPOINTMENTS = 30;

// Global arrays to store data
string patientNames[MAX_PATIENTS];
int patientAges[MAX_PATIENTS];
string patientContacts[MAX_PATIENTS];
string appointmentDates[MAX_APPOINTMENTS];
string appointmentTimes[MAX_APPOINTMENTS];
bool appointmentBooked[MAX_APPOINTMENTS];

// Global counters to keep track of data count
int patientCount = 0;
int appointmentCount = 0;

// Define doctor's available time
const string doctorAvailableFrom = "14:00"; // 2:00 PM
const string doctorAvailableTo = "16:00";   // 4:00 PM

// Function prototypes
void addPatient();
void displayPatients();
void cancelAppointment();
void displayAppointments();
void displayBookingSlots();
void totalEarning();
bool isDoctorAvailable(string time);

int main() {
    int choice;
    do {
        cout << "\nMain Menu\n";
        cout << "1. Book Appointment\n";
        cout << "2. Display Patients\n";
        cout << "3. Cancel Appointment\n";
        cout << "4. Display Available Appointments\n";
        cout << "5. Total earning of doctor\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                displayPatients();
                break;
            case 3:
                cancelAppointment();
                break;
            case 4:
                displayAppointments();
                break;
            case 5:
                totalEarning();
                break;
            case 6:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}

// Function to add a new patient
void addPatient() {
    if (patientCount < MAX_PATIENTS) {
        cout << "Enter patient name: ";
        cin >> patientNames[patientCount];
        cout << "Enter patient age: ";
        cin >> patientAges[patientCount];
        cout << "Enter contact information: ";
        cin >> patientContacts[patientCount];
        patientCount++;
    } else {
        cout << "Patient database is full. Cannot add more patients." << endl;
    }

    if (appointmentCount < MAX_APPOINTMENTS) {
        string date, time;
        cout << "Enter appointment date (YYYY-MM-DD): ";
        cin >> date;
        cout << "Enter appointment time (HH:MM): ";
        cin >> time;

        if (isDoctorAvailable(time)) {
            appointmentDates[appointmentCount] = date;
            appointmentTimes[appointmentCount] = time;
            appointmentBooked[appointmentCount] = true;
            appointmentCount++;
            cout << "Appointment booked successfully!" << endl;
        } else {
            cout << "Doctor is not available at that time. Please choose another time." << endl;
        }
    } else {
        cout << "Appointment slots are full. Cannot book more appointments." << endl;
    }
}

// Function to display all patients
void displayPatients() {
    cout << "List of Patients:" << endl;
    for (int i = 0; i < patientCount; ++i) {
        cout << "Name: " << patientNames[i] << ", Age: " << patientAges[i] << ", Contact: " << patientContacts[i] << endl;
    }
}

// Function to cancel an appointment
void cancelAppointment() {
    string date, time;
    cout << "Enter appointment date to cancel (YYYY-MM-DD): ";
    cin >> date;
    cout << "Enter appointment time to cancel (HH:MM): ";
    cin >> time;

    for (int i = 0; i < appointmentCount; ++i) {
        if (appointmentDates[i] == date && appointmentTimes[i] == time) {
            appointmentBooked[i] = false;
            cout << "Appointment canceled successfully!" << endl;
            return;
        }
    }
    cout << "Appointment not found." << endl;
}

// Function to display available appointments
void displayAppointments() {
    cout << "Available Appointments:" << endl;
    displayBookingSlots();
    for (int i = 0; i < appointmentCount; ++i) {
        if (!appointmentBooked[i]) {
            cout << "Date: " << appointmentDates[i] << ", Time: " << appointmentTimes[i] << endl;
        }
    }
}

// Function to display booking slots
void displayBookingSlots() {
    cout << "Booking Slots:" << endl;
    for (int i = 0; i < appointmentCount; ++i) {
        if (appointmentBooked[i]) {
            cout << "Date: " << appointmentDates[i] << ", Time: " << appointmentTimes[i] << " (Booked)" << endl;
        } else {
            cout << "Date: " << appointmentDates[i] << ", Time: " << appointmentTimes[i] << " (Available)" << endl;
        }
    }
}

// Function to check if the doctor is available at the specified time
bool isDoctorAvailable(string time) {
    if (time >= doctorAvailableFrom && time <= doctorAvailableTo) {
        for (int i = 0; i < appointmentCount; ++i) {
            if (appointmentBooked[i] && appointmentTimes[i] == time) {
                return false; // Doctor is already booked at this time
            }
        }
        return true; // Doctor is available at this time and no overlapping appointments
    } else {
        return false; // Doctor is not available at this time
    }
}

// Total earning of the doctor 
void totalEarning() {
    int bookings, fee, total_earning;
    cout << "Bookings in a month: ";
    cin >> bookings;
    cout << "Fee per visit: ";
    cin >> fee;
    total_earning = bookings * fee;
    cout << "Total earnings = $" << total_earning << endl;
}
