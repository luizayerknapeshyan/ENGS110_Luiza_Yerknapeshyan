#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define XOR_KEY 0x8F

GtkWidget *window;
GtkWidget *auth_entry_username;
GtkWidget *auth_entry_password;
GtkWidget *auth_label_result;
GtkWidget *auth_button;
GtkWidget *auth_box;
GtkWidget *register_button;
GtkWidget *password_box;
GtkWidget *main_notebook;
GtkWidget *password_list;
GtkWidget *new_pass_entry_service;
GtkWidget *new_pass_entry_username;
GtkWidget *new_pass_entry_password;

// Structure to store password information
typedef struct {
    GtkWidget *label;
    char service[256];
    char username[256];
    char password[256];
} PasswordInfo;

// List to keep track of allocated PasswordInfo structures
GList *password_info_list = NULL;

void display_passwords();

void encrypt_decrypt(char *text) {
    size_t len = strlen(text);
    for (size_t i = 0; i < len; ++i) {
        text[i] ^= XOR_KEY;
    }
}

void save_credentials(const char *username, const char *password) {
    FILE *file = fopen("credentials.txt", "w");
    if (file) {
        char mutable_username[100];
        char mutable_password[100];
        
	strncpy(mutable_username, username, sizeof(mutable_username));
	strncpy(mutable_password, password, sizeof(mutable_password));
	mutable_username[sizeof(mutable_username) - 1] = '\0'; // Null-terminate the string
	mutable_password[sizeof(mutable_password) - 1] = '\0';
	encrypt_decrypt(mutable_username);
        encrypt_decrypt(mutable_password);
        fprintf(file, "%s:%s\n", mutable_username, mutable_password); // Add '\n' at the end
	fclose(file);
    }
}

gboolean authenticate_user(const char *input_username, const char *input_password) {
    FILE *file = fopen("credentials.txt", "r");
    if (!file) {
        perror("Error opening credentials file");
        return FALSE;
    }

    char stored_username[100], stored_password[100];
    int result = fscanf(file, "%99[^:]:%99[^\n]", stored_username, stored_password);
    fclose(file);

    if (result == 2) {
        // Decrypt stored credentials before comparison
        encrypt_decrypt(stored_username);
        encrypt_decrypt(stored_password);

        if (strcmp(input_username, stored_username) == 0 && strcmp(input_password, stored_password) == 0) {
	    return TRUE;
        } else {
            printf("Authentication failed. Input credentials do not match.\n");
        }
    } else {
        perror("Error reading credentials from file");
    }

    return FALSE;
}

void show_authentication_result() {
    const char *username = gtk_entry_get_text(GTK_ENTRY(auth_entry_username));
    const char *password = gtk_entry_get_text(GTK_ENTRY(auth_entry_password));

    if (authenticate_user(username, password)) {
        // Display the password manager form widgets
        gtk_box_pack_start(GTK_BOX(auth_box), password_box, TRUE, TRUE, 0);
        gtk_widget_show_all(window);
	   
	// Hide the authentication form widgets
        gtk_widget_hide(auth_entry_username);
        gtk_widget_hide(auth_entry_password);
        gtk_widget_hide(auth_label_result);
        gtk_widget_hide(auth_button);
        gtk_widget_hide(register_button);

        // Display saved passwords when authentication succeeds
        // Clear the existing labels and update them with new data
        display_passwords();
    } else {
        gtk_label_set_text(GTK_LABEL(auth_label_result), "Authentication failed, please try again");
    }
}


void register_new_user() {
    const char *username = gtk_entry_get_text(GTK_ENTRY(auth_entry_username));
    const char *password = gtk_entry_get_text(GTK_ENTRY(auth_entry_password));

    save_credentials(username, password);

    //Clear the entries after registration
    gtk_entry_set_text(GTK_ENTRY(auth_entry_username), "");
    gtk_entry_set_text(GTK_ENTRY(auth_entry_password), "");

    // Show a message indicating successful registration
    gtk_label_set_text(GTK_LABEL(auth_label_result), "Registration successful");
}

void free_password_info(gpointer data) {
    PasswordInfo *passwordInfo = (PasswordInfo *)data;
    g_free(passwordInfo);
}

void clear_password_info_list() {
    g_list_free_full(password_info_list, free_password_info);
    password_info_list = NULL;
}


void display_passwords() {
    FILE *file = fopen("passwords.txt", "r");
    if (file) {
        // Clear existing labels in password_list
        gtk_container_foreach(GTK_CONTAINER(password_list), (GtkCallback)gtk_widget_destroy, NULL);

        // Clear the password_info_list
        clear_password_info_list();

        char line[256];
        while (fgets(line, sizeof(line), file)) {
            char service[100], username[100], password[100];
            sscanf(line, "%99[^:]:%99[^:]:%99s", service, username, password);
            encrypt_decrypt(service);
            encrypt_decrypt(username);
            encrypt_decrypt(password);
            char display_text[512];
            sprintf(display_text, "Service: %s\nUsername: %s\nPassword: %s\n\n", service, username, password);

            // Create a label for each password entry
            GtkWidget *label = gtk_label_new(display_text);
            gtk_box_pack_start(GTK_BOX(password_list), label, FALSE, FALSE, 0);

            // Allocate memory for PasswordInfo structure and store the label
            PasswordInfo *passwordInfo = g_new(PasswordInfo, 1);
            passwordInfo->label = label;
            g_strlcpy(passwordInfo->service, service, sizeof(passwordInfo->service));
            g_strlcpy(passwordInfo->username, username, sizeof(passwordInfo->username));
            g_strlcpy(passwordInfo->password, password, sizeof(passwordInfo->password));

            // Add the PasswordInfo to the list
            password_info_list = g_list_prepend(password_info_list, passwordInfo);
        }
        fclose(file);
    }

    // Ensure the changes are displayed
    gtk_widget_show_all(password_list);
}

void generate_password() {
    // Seed the rand() function with current time to always generate different numbers
    srand((unsigned int)(time(NULL))); 

    // Add the arrays from which the characters will be randomly pulled
    char number[] = "0123456789";
    char letter[] = "abcdefghijklmnopqrstuvwxyz";
    char LETTER[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char symbol[] = "!@#$%^&*()_+={|}:;'<>?,./-";

    char password[17];


    for(int i = 0; i < 16; i++) {
        // Generate a random number from 0 to 4 and pull a character from the corresponding array
	int randomizer = rand() % 4;
	

    	switch(randomizer) {
	    case 0:
		password[i] = number[rand() % 10];
		break;
	    case 1:
		password[i] = LETTER[rand() % 26];
		break;
	    case 2:
		password[i] = symbol[rand() % 26];
	        break;
	    case 3:
		password[i] = letter[rand() % 26];
	        break;	
	}
    }

    password[17] = '\0';

    // Display the generated password in the application
    gtk_entry_set_text(GTK_ENTRY(new_pass_entry_password), password);
}

void save_password() {
    const char *service = gtk_entry_get_text(GTK_ENTRY(new_pass_entry_service));
    const char *username = gtk_entry_get_text(GTK_ENTRY(new_pass_entry_username));
    const char *password = gtk_entry_get_text(GTK_ENTRY(new_pass_entry_password));

    FILE *file = fopen("passwords.txt", "a");
    if (file) {
        char mutable_service[100];
        char mutable_username[100];
        char mutable_password[100];
        strcpy(mutable_service, service);
        strcpy(mutable_username, username);
        strcpy(mutable_password, password);

        encrypt_decrypt(mutable_service);
        encrypt_decrypt(mutable_username);
        encrypt_decrypt(mutable_password);

        fprintf(file, "%s:%s:%s\n", mutable_service, mutable_username, mutable_password);
        fclose(file);

        // Update the display
        display_passwords();
    }

    // Clear the form entry fields after the button is clicked
    gtk_entry_set_text(GTK_ENTRY(new_pass_entry_service), "");
    gtk_entry_set_text(GTK_ENTRY(new_pass_entry_username), "");
    gtk_entry_set_text(GTK_ENTRY(new_pass_entry_password), "");

}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Password Manager");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Authentication Window
    auth_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    auth_entry_username = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(auth_entry_username), "Username");
    auth_entry_password = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(auth_entry_password), "Password");
    gtk_entry_set_visibility(GTK_ENTRY(auth_entry_password), FALSE);
    auth_button = gtk_button_new_with_label("Authenticate");
    register_button = gtk_button_new_with_label("Register");
    g_signal_connect(auth_button, "clicked", G_CALLBACK(show_authentication_result), NULL);
    g_signal_connect(register_button, "clicked", G_CALLBACK(register_new_user), NULL);
    auth_label_result = gtk_label_new("");
    gtk_box_pack_start(GTK_BOX(auth_box), auth_entry_username, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(auth_box), auth_entry_password, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(auth_box), auth_button, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(auth_box), register_button, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(auth_box), auth_label_result, FALSE, FALSE, 0);

    // Passwords Window
    password_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    
    main_notebook = gtk_notebook_new();
    gtk_notebook_set_tab_pos(GTK_NOTEBOOK(main_notebook), GTK_POS_TOP);
    password_list = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    GtkWidget *new_pass_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    new_pass_entry_service = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(new_pass_entry_service), "Service");
    new_pass_entry_username = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(new_pass_entry_username), "Username");
    new_pass_entry_password = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(new_pass_entry_password), "Password");
    GtkWidget *generate_pass_button = gtk_button_new_with_label("Generate password");
    g_signal_connect(generate_pass_button, "clicked", G_CALLBACK(generate_password), NULL);
    GtkWidget *new_pass_button = gtk_button_new_with_label("Add Password");
    g_signal_connect(new_pass_button, "clicked", G_CALLBACK(save_password), NULL);
    gtk_box_pack_start(GTK_BOX(new_pass_box), new_pass_entry_service, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(new_pass_box), new_pass_entry_username, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(new_pass_box), new_pass_entry_password, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(new_pass_box), generate_pass_button, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(new_pass_box), new_pass_button, FALSE, FALSE, 0);

    GtkWidget *password_label = gtk_label_new("Saved Passwords");
    GtkWidget *new_pass_label = gtk_label_new("Add a New Password");
    GtkWidget *scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(scrolled_window), password_list);
    gtk_notebook_append_page(GTK_NOTEBOOK(main_notebook), scrolled_window, password_label);
    gtk_notebook_append_page(GTK_NOTEBOOK(main_notebook), new_pass_box, new_pass_label);

    gtk_box_pack_start(GTK_BOX(password_box), main_notebook, TRUE, TRUE, 0);

    // Packing everything together
    gtk_container_add(GTK_CONTAINER(window), auth_box);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

