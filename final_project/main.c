#include "file_manager.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <command> <directory> [options]\n", argv[0]);
        return 1;
    }

    const char *command = argv[1];
    const char *directory = argv[2];

    if (strcmp(command, "categorize") == 0) {
        if (argc != 4) {
            fprintf(stderr, "Usage: %s categorize <directory> <category>\n", argv[0]);
            return 1;
        }
        const char *category = argv[3];
        categorize_files(directory, category);
    } else if (strcmp(command, "search") == 0) {
        if (argc != 4) {
            fprintf(stderr, "Usage: %s search <directory> <query>\n", argv[0]);
            return 1;
        }
        const char *query = argv[3];
        search_files(directory, query);
    } else if (strcmp(command, "move") == 0) {
        if (argc != 4) {
            fprintf(stderr, "Usage: %s move <source_directory> <destination_directory>\n", argv[0]);
            return 1;
        }
        const char *destination_directory = argv[3];
        batch_move_files(directory, destination_directory);
    } else if (strcmp(command, "copy") == 0) {
        if (argc != 4) {
            fprintf(stderr, "Usage: %s copy <source_directory> <destination_directory>\n", argv[0]);
            return 1;
        }
        const char *destination_directory = argv[3];
        batch_copy_files(directory, destination_directory);
    } else if (strcmp(command, "delete") == 0) {
        batch_delete_files(directory);
    } else {
        fprintf(stderr, "Unknown command: %s\n", command);
        return 1;
    }

    return 0;
}
