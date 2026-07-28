# <a href="#"><img src="assets/banner.svg" width="240"></a>
![Release](https://img.shields.io/github/v/release/bsagarzazu/vs-tc-itk-template)
![Downloads](https://img.shields.io/github/downloads/bsagarzazu/vs-tc-itk-template/total)
![License](https://img.shields.io/github/license/bsagarzazu/vs-tc-itk-template)

A straightforward Visual Studio project template for Teamcenter ITK projects.

No more copy-pasting, renaming and fixing paths from old projects. Setup a clean, ready-to-go ITK project in seconds.

## Features

- **OOTB helpers**: Ready-to-use macros for error handling, RAII memory management using official `scoped_smptr`, and `std::map` based handler argument parsing.
- **Table-driven registration**: Easily manage workflow handlers and extensions via clean, centralized static tables.
- **Seamless version migration**: Change Teamcenter version dependencies in a single place within the Property Sheet.
- **Hybrid path resolution**: Automatic dependency detection for local development or server environments.
- **Dynamic headers**: Automated license and project information headers using Visual Studio template variables.
- **Code quality**: Pre-configured `Clang-Format` and `Clang-Tidy` configured to ignore third-party headers.

> **Note**: Analysis is set to manual mode in the Property Sheet to maintain build performance. Run it on-demand via _Analyze -> Run Code Analysis_.

## Project Structure

- `include/`: Helper macros, memory management, and utility headers.
- `src/`: Registration logic, implementations, and DLL entry point (`Main.cpp`).
- `Teamcenter.props`: Centralized configuration for paths, libraries, and compiler flags.

## Project Configuration

1. Edit `Teamcenter.props` to set your `CLIENT_PREFIX` and `TC_VERSION`.
2. The template relies on environment variables to resolve Teamcenter paths:
   - **Server**: Uses `TC_ROOT`.
   - **Local**: Uses `DEV_DEPENDENCIES`, expecting `$(DEV_DEPENDENCIES)\Teamcenter\TC$(TC_VERSION)` containing `include`, `include_cpp`, and `lib` directories.

## Usage

1. Download `vs-tc-itk-template` from [the latest Release](releases/latest).
2. Place the ZIP file in your Visual Studio project templates folder:
   `%USERPROFILE%\Documents\Visual Studio 2022\Templates\ProjectTemplates`
3. Open Visual Studio, create a _New Project_, and search for _Teamcenter ITK Project_.
4. Set your `CLIENT_PREFIX` and `TC_VERSION` in `Teamcenter.props` and replace all the occurrences of `[AUTHOR]` and `[COMPANY]` in the license headers with your data.

## License

Distributed under the [Boost Software License 1.0](LICENSE). No attribution is required in binary distributions.
