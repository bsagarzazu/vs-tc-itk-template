# vs-tc-itk-template

A straightforward Visual Studio project template for Teamcenter ITK projects.

## Features

- **OOTB helpers**: Simplified error handling, RAII memory management, and `std::map` based handler argument parsing.
- **Table-driven registration**: Easily manage workflow handlers and extensions via static tables.
- **Seamless version migration**: Seamlessly change Teamcenter version dependencies in one place.
- **Dependencies path resolution**: Automatic dependency detection for local development or server environments.
- **Code quality**: Pre-configured `Clang-Format` and `Clang-Tidy`.
- **Dynamic headers**: Automated license and project information headers using VS template variables. 

## Project Structure

- `include/`: Helper macros, memory management, and utility headers.
- `src/`: Registration logic, implementations, and DLL entry point.
- `Teamcenter.props`: Centralized configuration for paths, libraries, and compiler flags.

## Project Configuration

Edit `Teamcenter.props` to set your `CLIENT_PREFIX` and `TC_VERSION`.

The template relies on environment variables to resolve Teamcenter paths:
- **Server**: Uses `TC_ROOT`.
- **Local**: Uses `DEV_DEPENDENCIES`, expecting `$(DEV_DEPENDENCIES)\Teamcenter\TC$(TC_VERSION)` containing the `include`, `include_cpp`, and `lib` directories.

## Usage

1. Download `vs-tc-itk-template` from [the latest Release](releases/latest).
2. Place the ZIP file in your Visual Studio project templates folder:
   `%USERPROFILE%\Documents\Visual Studio 2022\Templates\ProjectTemplates`
3. Open Visual Studio, create a **New Project**, and search for "Teamcenter ITK Project".

## License

Distributed under the [Boost Software License 1.0](LICENSE). No attribution is required in binary distributions.