# FILEMASTER
#### Video Demo:  <(https://youtu.be/frCiBpnsmKA)>
#### Description:
Is a robust command-line tool designed to efficiently organize and manage files within large projects. It addresses the common problem of disorganized files in extensive projects by providing a suite of functionalities for file categorization, advanced search, and batch operations. Developed in C, FileMaster is intended to simplify file management tasks, making it easier for users to maintain an orderly workspace and streamline their workflows.

FileMaster project is organized into several components, each serving a specific purpose:


1. 'file_manager.h':

    Purpose: This header file defines the core structures and function prototypes used throughout the project. It includes the definition of the 'File' structure, which represents a file with its name and path. It also declares the functions for file categorization, searching, and batch operations.

    Content:
    '#include' directives for necessary libraries.
    Definition of the 'File' structure.
    Declarations of functions for categorizing files, searching files, and performing batch operations.

2.  'file_manager.c':

    Purpose: This source file implements the functions declared in 'file_manager.h'. It contains the logic for file categorization, searching, and batch operations. The implementation ensures that files can be efficiently managed according to user commands.

    Content:
    Implementation of 'categorize_files()': Moves files into user-defined categories.
    Implementation of 'search_files()': Searches for files within a directory based on a query string.
    Implementation of 'batch_move_files()', 'batch_copy_files()', and 'batch_delete_files()': Performs batch operations to move, copy, or delete files across directories.

3. 'main.c':

    Purpose: The main source file serves as the entry point of the application. It parses command-line arguments and invokes the appropriate functions based on user input.

    Content:
    Command-line argument parsing.
    Calls to functions from 'file_manager.c' based on the user command ('categorize', 'search', 'move', 'copy', 'delete').

4. 'Makefile':

    Purpose: The Makefile is used to automate the build process of the project. It specifies how to compile the source files into an executable and how to clean up build artifacts.

    Content:
    Compilation rules for each source file.
    Linking rules to create the final executable 'FileMaster'.
    Clean-up rules to remove object files and the executable.

5. 'README.md':

    Purpose: The README.md file provides comprehensive documentation for the project. It explains the purpose of the project, how to use it, and details about the implementation.

    Content:
    Overview of the project's purpose and features.
    Detailed instructions on how to compile and run the tool.
    Examples of usage for each command.
    Information on how to contribute to the project.

During the development of FileMaster, design choices were debated and considered:


1. Command-Line Interface (CLI) vs. Graphical User Interface (GUI)

   Choice: A CLI was chosen over a GUI due to its simplicity and effectiveness for file management tasks, especially for users familiar with command-line operations. A CLI is also more suitable for scripting and automation.

2. File Management Operations

   Batch Operations: The decision to include batch operations (move, copy, delete) was made to enhance efficiency when dealing with multiple files simultaneously. This choice was driven by the need to support large-scale file management tasks.

3. Error Handling

   Implementation: Error handling was carefully implemented to provide meaningful feedback to users. For instance, if a directory cannot be opened or a file operation fails, appropriate error messages are displayed to help users diagnose issues.

4. Modularity

   Structure: The project is divided into separate files ('file_manager.h', 'file_manager.c', 'main.c') to enhance modularity and maintainability. This separation allows for easier updates and debugging, as well as clear delineation of responsibilities.

5. Performance Considerations

   Efficiency: The functions were optimized for performance, especially for operations like searching and batch processing, to handle large numbers of files efficiently.


Conclusion

FileMaster is a powerful command-line tool designed to address the challenges of managing files in large projects. Its modular design, comprehensive functionality, and thoughtful implementation make it a valuable asset for users who need to organize and manage their files efficiently. The README.md file provides detailed documentation to guide users through the installation, usage, and contribution process, ensuring that FileMaster is accessible and useful for a wide range of file management tasks.
