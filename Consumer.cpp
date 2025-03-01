//Created by: Alex Thomas
//Date: 2/27/2025
//Assignment: Project 1 Multi-Threading Programming

#include <iostream>
#include <fcntl.h>
#include <unistd.h>

int main() {

  //need to use mkfifo my_pipe in the terminal
  const char* pipe_name = "my_pipe";

  //Buffer
  char buffer[1024];

  // Open the named pipe
  int pipe_fd = open(pipe_name, O_RDONLY);

  //Checks to see if the pipe opened
  if (pipe_fd == -1) {
    std::cerr << "Failed to open pipe for reading" << std::endl;
    return 1;
  }

  // Read data from the pipe
  ssize_t bytes_read = read(pipe_fd, buffer, sizeof(buffer));

  //Checks to see if anything was read from the pipe
  if (bytes_read == -1) {
    std::cerr << "Read failed" << std::endl;
    close(pipe_fd);
    return 1;
  }

  //tells cout where the string ends
  buffer[bytes_read] = '\0';

  //print the recieved message
  std::cout << "Consumer received: " << buffer << std::endl;

  // Close the pipe
  close(pipe_fd);
  return 0;
}