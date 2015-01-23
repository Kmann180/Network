# AIEFramework

The AIE C++ OpenGL Framework, used by Advanced Diploma and Degree students. This repo is in constant flux and improvement. Differences may exist between this code-base and class tutorials.

## Purpose

  - An *eventually* cross-platform (Windows, OSX, Linux) wrapper for a real-time OpenGL game loop.
  - OpenGL functionality should remain bare for students to learn as much as possible.
  - The ability to load textures and 3D models will be provided, but loaded model data will
    not automatically create OpenGL resources.
  - A helper class for easily drawing debug 2D/3D "widgets" will be provided so that basic
    math ideas can be demonstrated, along with A.I. entities and physics, without the need to
    load a model.

## Dependencies

  This project depends on the following 3rd-party libraries:

  - GLEW (for managing OpenGL extensions)
  - GLFW (for managing basic OpenGL window and controls)
  - GLM (for mathematics)
  - STB (for simple image loading)
  - FBX SDK 2015.1 (for the optional FBXLoader library for loading FBX models)

## Quick Setup

For more in-depth directions, check the repository wiki.

1. Clone the repository to your workstation.
2. Initialize and clone the submodules. Build the GLEW and GLFW solutions.
3. Configure the FBXLoader project's Environment Variables property sheet to point to the location of the FBX SDK on your workstation.
4. Build the AIEFramework solution.
5. If using Visual Studio, copy the templates to your Visual Studio templates directory. 

## Contributions

Please fork, commit, rebase, and then make a pull request!
