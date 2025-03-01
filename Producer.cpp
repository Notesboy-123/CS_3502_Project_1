//Created by: Alex Thomas
//Date: 2/27/2025
//Assignment: Project 1 Multi-Threading Programming

#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>

int main() {

  //need to use mkfifo my_pipe in the terminal
  const char* pipe_name = "my_pipe";

  //Message to be sent to the consumer
  const char* data = "Producer says hello";

  // Open the named pipe for writing
  int pipe = open(pipe_name, O_WRONLY);

  //if pipe is not opened
  if (pipe == -1) {
    std::cerr << "Failed to open pipe for writing" << std::endl;
    return 1;
  }

  // Write data to the pipe
  ssize_t bytes_written = write(pipe, data, strlen(data));

  //Checks to see if anything is written to the pipe
  if (bytes_written == -1) {
    std::cerr << "Write failed" << std::endl;
    close(pipe);
    return 1;
  }

  std::cout << "Producer sent: " << data << std::endl;

  // Close the pipe
  close(pipe);
  return 0;
}