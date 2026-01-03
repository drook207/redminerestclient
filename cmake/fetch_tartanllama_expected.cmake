include(FetchContent)
cmake_policy(PUSH)
cmake_policy(SET CMP0135 NEW)
cmake_policy(POP)
message(STATUS "Setting cmake policiy CMP0135 to behaviour new.")
FetchContent_Declare(expected GIT_REPOSITORY https://github.com/TartanLlama/expected.git GIT_TAG v1.3.1 DOWNLOAD_EXTRACT_TIMESTAMP TRUE)
FetchContent_MakeAvailable(expected)


