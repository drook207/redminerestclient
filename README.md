# Redmine REST Client

A C++ REST client library for Redmine project management system, built with Qt.

## Description

This library provides a modern C++ interface for interacting with the Redmine REST API. It leverages Qt's networking capabilities to communicate with Redmine servers, allowing you to manage issues, projects, and time entries programmatically.

## Features

- REST API client for Redmine
- Qt-based asynchronous networking
- Support for issue management
- API key authentication
- Type-safe error handling using `tl::expected`

## Requirements

- CMake 3.24 or higher
- Qt 6 (Core, Network, LinguistTools)
- C++17 compatible compiler

## Dependencies

- Qt6::Core
- Qt6::Network
- [TartanLlama's expected](https://github.com/TartanLlama/expected) - for error handling

## Building

```bash
cmake -B build
cmake --build build
```

## Usage

```cpp
#include "restclient.hpp"

// Create a client instance
redmine::RestClient client;

// Configure connection
client.setBaseUrl(QUrl("https://your-redmine-instance.com"));
client.setApiKey("your-api-key");

// Connect to the server
if (client.connect()) {
    // Fetch an issue
    client.getIssue(123);
}
```

## API Resources

Currently supported resources:

- Issues (`/issues.json`, `/issues/{id}.json`)
- Projects (`/projects.json`, `/projects/{id}.json`)
- Time Entries (`/time_entries.json`, `/time_entries/{id}.json`)

## Project Structure

```
redminerestclient/
├── src/
│   ├── restclient.hpp       # Main REST client class
│   ├── restclient.cpp
│   ├── apiresources.hpp     # API endpoint definitions
│   └── issues/
│       ├── issue.hpp        # Issue data structures
│       └── issue.cpp
├── CMakeLists.txt
└── README.md
```

## License

See [LICENSE](LICENSE) file for details.

## Author

Pascal Berndt (drook207@gmail.com)
