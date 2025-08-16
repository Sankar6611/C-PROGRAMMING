c
#include <stdio.h>

enum Weekday {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

enum Status {
    PENDING = 100,
    APPROVED = 200,
    REJECTED = 300
};

const char* getWeekdayName(enum Weekday day) {
    switch (day) {
        case MONDAY: return "Monday";
        case TUESDAY: return "Tuesday";
        case WEDNESDAY: return "Wednesday";
        case THURSDAY: return "Thursday";
        case FRIDAY: return "Friday";
        case SATURDAY: return "Saturday";
        case SUNDAY: return "Sunday";
        default: return "Unknown";
    }
}

int main() {
    enum Weekday today = FRIDAY;
    enum Status applicationStatus = PENDING;
    
    printf("Weekday enumeration values:\n");
    printf("MONDAY = %d\n", MONDAY);
    printf("TUESDAY = %d\n", TUESDAY);
    printf("WEDNESDAY = %d\n", WEDNESDAY);
    printf("THURSDAY = %d\n", THURSDAY);
    printf("FRIDAY = %d\n", FRIDAY);
    printf("SATURDAY = %d\n", SATURDAY);
    printf("SUNDAY = %d\n", SUNDAY);
    
    printf("\nStatus enumeration values:\n");
    printf("PENDING = %d\n", PENDING);
    printf("APPROVED = %d\n", APPROVED);
    printf("REJECTED = %d\n", REJECTED);
    
    printf("\nUsing enumerations:\n");
    printf("Today is %s (value: %d)\n", getWeekdayName(today), today);
    
    switch (applicationStatus) {
        case PENDING:
            printf("Application status: Pending review\n");
            break;
        case APPROVED:
            printf("Application status: Approved\n");
            break;
        case REJECTED:
            printf("Application status: Rejected\n");
            break;
    }
    
    return 0;
}
