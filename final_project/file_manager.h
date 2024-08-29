#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH_LENGTH 1024

// Structure to represent a file
typedef struct {
    char name[MAX_PATH_LENGTH];
    char path[MAX_PATH_LENGTH];
} File;

// Functions for file categorization
void categorize_files(const char *directory, const char *category);

// Functions for file search
void search_files(const char *directory, const char *query);

// Functions for batch operations
void batch_move_files(const char *source_directory, const char *destination_directory);
void batch_copy_files(const char *source_directory, const char *destination_directory);
void batch_delete_files(const char *directory);

#endif // FILE_MANAGER_H
