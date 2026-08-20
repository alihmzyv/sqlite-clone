#include <cstdio>
#include <cstdlib>
#include <cstring>


int main (int argc, char* arg[]) {
    //why accepts pointer to pointer to char?
    //we need to pass the buffer (because otherwise getline would have to allocate memory itself each time and it is not efficient in terms of memory)
    //you cannot just pass a pointer and try to read from it - cause when it is null (first time) or when
    // the buffer size is not enough, it needs to allocate new memory and make the pointer to point to new memory.
    // as pointer is a copy of the pointer in memory passed to the method, it would only change what copy points to. So,
    //outside of getline, you don't have access to the new mem allocated and filled with some data
    char* buffer = nullptr;
    size_t buffer_length;

    ssize_t input_length = getline(&buffer, &buffer_length, stdin);
    if (input_length <= 0) {
        printf("ERROR");
        exit(EXIT_FAILURE);
    } else {
        buffer[input_length - 1] = 0; //replacing \n which is the last thing read with 0, so, when used (below in string comparison) as a string (char array having 0 to show the end), it works
        if (strcmp(buffer, ".exit") == 0) {
            free(buffer);
            exit(EXIT_SUCCESS);
        } else {
            printf("Unrecognized command '%s'.\n", buffer);
        }
    }
}
