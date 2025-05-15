import "../solid/solid.qbs" as solid

solid {
    Application {
//        cpp.cxxLanguageVersion: "c++23"
        name: "App"

        files: [
            "data/bg.frag",
            "data/bg.vert",
            "data/block.frag",
            "data/block.vert",
            "data/cubemap.frag",
            "data/cubemap.vert",
            "data/app.rc",
            "data/app.res",
            "data/gui.frag",
            "data/gui.vert",
            "data/icon.png",
            "data/phong.frag",
            "data/phong.vert",
            "data/project.json",
            "data/sheet.png",
            "data/simple.frag",
            "data/simple.vert",
            "data/solid.ico",
            "data/vertexanimation.frag",
            "data/vertexanimation.vert",
            "source/dictionary.cpp",
            "source/dictionary.h",
            "source/dictionarymenu.cpp",
            "source/dictionarymenu.h",
            "source/gamemenu.cpp",
            "source/gamemenu.h",
            "source/gameover.cpp",
            "source/gameover.h",
            "source/intro.cpp",
            "source/intro.h",
            "source/japanesekana.h",
            "source/level.cpp",
            "source/level.h",
            "source/levelselectmenu.cpp",
            "source/levelselectmenu.h",
            "source/main.cpp",
            "source/main.h",
            "source/mousecursor.cpp",
            "source/mousecursor.h",
            "source/pausemenu.cpp",
            "source/pausemenu.h",
            "source/playtetrismenu.cpp",
            "source/playtetrismenu.h",
            "source/quiz.cpp",
            "source/quiz.h",
            "source/settingsmenu.cpp",
            "source/settingsmenu.h",
            "source/speechbubble.cpp",
            "source/speechbubble.h",
            "source/startmenu.cpp",
            "source/startmenu.h",
            "source/tetris.cpp",
            "source/tetris.h",
        ]

        Depends { name: "core"  }
        Depends { name: "nullrenderer"  }
        Depends { name: "nullphysics"  }
        Depends { name: "nullaudio"  }
        Depends { name: "nullphysics"  }
        Depends { name: "nullfilesystem"  }
        Depends { name: "gles2renderer"  }
        Depends { name: "stdfilesystem"  }
        Depends { name: "portaudioaudio"  }

        property stringList includePaths: "../solid/source"

        Properties {
            condition: qbs.targetOS.contains("macos")

            cpp.frameworks: {
                if (qbs.architecture.includes("arm64"))
                    return macosFrameworks.concat(
                           "CoreHaptics",
                           "MediaPlayer",
                           "GameController",
                           "QuartzCore",
                           "IOSurface")
                return macorFrameworks
            }

            cpp.dynamicLibraries: macosSharedLibs

            cpp.staticLibraries: staticLibs.concat("SDL2", "MoltenVK")

            cpp.libraryPaths: [project.buildDirectory, "../solid/lib/debug/darwin/"+qbs.architecture]
            cpp.includePaths: includePaths.concat("../solid/include/darwin")
            cpp.defines: project.defines.concat(project.sdlDefines)
        }

        Properties {
            condition: qbs.targetOS.contains("linux")

            //cpp.dynamicLibraries: linuxSharedLibs
            cpp.staticLibraries: staticLibs.concat("SDL2")

            cpp.libraryPaths: [project.buildDirectory, "../solid/lib/debug/linux/x86_64"]
            cpp.includePaths: includePaths.concat("../solid/include/linux")
            cpp.defines: project.defines.concat(project.sdlDefines)
        }

        Properties {
            condition: qbs.targetOS.contains("windows")

            cpp.dynamicLibraries: windowsSharedLibs
            cpp.staticLibraries: staticLibs

            cpp.libraryPaths: [project.buildDirectory, "../solid/lib/debug/mingw32/x86_64"]
            cpp.includePaths: includePaths.concat("../solid/include/mingw32")
            cpp.defines: project.defines.concat(project.windowsDefines)
        }

        Depends { name: "cpp" }
        Depends { name: "core" }
        Depends { name: "nullphysics" }
        Depends { name: "bulletphysics" }
    }
}
