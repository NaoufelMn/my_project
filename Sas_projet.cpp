#include <stdio.h>

// Define the structure for a note
struct Note {
    int id;
    char title[50];
    char description[200];
    char deadline[20];
};
// Function to validate the date format (YYYY-MM-DD)
bool isValidDate(const char *date) {
    int year, month, day;
    if (sscanf(date, "%d-%d-%d", &year, &month, &day) == 3){
    	if(year >=2024){
    		return true ;
		}
	}
	return false;
}

// Function to add a note
void addNote(struct Note *notes, int *count) {
    if (*count < 100) {  // Assuming a maximum of 10 notes for simplicity
        struct Note newNote;

        // Get input from the user
        printf("Enter Note Title: ");
        scanf(" %[^\n]s", newNote.title);

        printf("Enter Note Description: ");
        scanf(" %[^\n]s", newNote.description);

        // Get and validate Deadline Time
        do {
            printf("Enter Deadline Time (YYYY-MM-DD): ");
            scanf(" %[^\n]s", newNote.deadline);
        } while (!isValidDate(newNote.deadline));

        // Assign an ID (just a simple increment for now)
        newNote.id = *count + 1;

        // Add the new note to the array
        notes[*count] = newNote;

        // Increment the count
        (*count)++;

        printf("Note added successfully!\n");
    } else {
        printf("Maximum number of notes reached!\n");
    }
}
// Function to display all notes
void displayNotes(const struct Note *notes, int count) {
    if (count == 0) {
        printf("No notes available.\n");
    } else {
        printf("\nID\tTitle\t\tDescription\t\tDeadline \n");
        printf("-------------------------------------------------------------------------------------------------------\n");
        for (int i = 0; i < count; i++) {
            printf("%d\t%s\t\t%s\t\t%s\t\n  ", notes[i].id, notes[i].title, notes[i].description, notes[i].deadline);
        }
        printf("--------------------------------------------------------------------------------------------------------\n");
    }
}


int main() {
    struct Note notes[100];  // Assuming a maximum of 100 notes for simplicity
    int noteCount = 0;
    int choice;

    do {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Add a Note\n");
        printf("2. Display Notes\n");
        printf("3. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addNote(notes, &noteCount);
                break;
                case 2:
                displayNotes(notes, noteCount);
                break;
                case 3:
                printf("Exiting program.\n");
                break;
                
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}

