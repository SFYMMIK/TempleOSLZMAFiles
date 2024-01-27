#include "libc.h"

void play_startup_sound() {
    Sound(440, 1000); // Play A note for 1 second
    Sleep(1000);      // Wait for 1 second
    Sound(554, 1000); // Play C# note for 1 second
    Sleep(1000);      // Wait for 1 second
    Sound(659, 1000); // Play E note for 1 second
}

void display_startup_image() {
    int img = Jpeg("startup_image.jpg"); // Load the startup image
    SetVideoMode(640, 480); // Set video mode
    Clear(0x000000);        // Clear screen to black
    BlitSprite(img, 0, 0); // Display image at (0, 0)
    Sleep(3000);            // Wait for 3 seconds
    SetVideoMode(0, 0);     // Restore original video mode
}

void compress_folder() {
    char folder_path[256];
    FileRequester(folder_path, "Select folder to compress");
    char output_path[256];
    FileRequester(output_path, "Save compressed file as");
    // Implement compression logic
    // ...
    Alert("Compression complete.");
}

void decompress_file() {
    char input_path[256];
    FileRequester(input_path, "Select file to decompress");
    char output_folder[256];
    FileRequester(output_folder, "Select output folder");
    // Implement decompression logic
    // ...
    Alert("Decompression complete.");
}

void encrypt_file() {
    char input_path[256];
    FileRequester(input_path, "Select file to encrypt");
    char output_path[256];
    FileRequester(output_path, "Save encrypted file as");
    // Implement encryption logic
    // ...
    Alert("Encryption complete.");
}

void decrypt_file() {
    char input_path[256];
    FileRequester(input_path, "Select file to decrypt");
    char output_path[256];
    FileRequester(output_path, "Save decrypted file as");
    // Implement decryption logic
    // ...
    Alert("Decryption complete.");
}

void main() {
    // Play startup sound
    play_startup_sound();
    // Display startup image
    display_startup_image();

    int choice;
    do {
        Cls();
        choice = Menu("File Compression and Encryption Tool",
                      "Compress Folder",
                      "Decompress File",
                      "Encrypt File",
                      "Decrypt File",
                      "Exit");
        switch (choice) {
            case 1: compress_folder(); break;
            case 2: decompress_file(); break;
            case 3: encrypt_file(); break;
            case 4: decrypt_file(); break;
        }
    } while (choice != 5);
}