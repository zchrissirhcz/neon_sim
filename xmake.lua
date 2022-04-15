target("test_ex7")
    set_kind("binary")
    add_files("test_ex7.cpp")

target("test_ex4")
    set_kind("binary")
    add_files("test_ex4.cpp")

target("test_ex8")
    set_kind("binary")
    add_files("test_ex8.cpp")

target("test_threshold")
    set_kind("binary")
    add_files("test_threshold.cpp")

target("test_ex9")
    set_kind("binary")
    add_files("test_ex9.cpp")

target("test_ex10")
    set_kind("binary")
    add_files("test_ex10.cpp")

target("test_ex5")
    set_kind("binary")
    add_files("test_ex5.cpp")

target("test_ex3")
    set_kind("binary")
    add_files("test_ex3.cpp")

target("test_ex1")
    set_kind("binary")
    add_files("test_ex1.cpp")

target("test_rgb2bgr")
    set_kind("binary")
    add_files("test_rgb2bgr.cpp")

target("test_ex2")
    set_kind("binary")
    add_files("test_ex2.cpp")

target("test_rgb2gray")
    set_kind("binary")
    add_files("test_rgb2gray.cpp")

target("test_ex11")
    set_kind("binary")
    add_files("test_ex11.cpp")

target("test_ex6")
    set_kind("binary")
    add_files("test_ex6.cpp")

--
-- If you want to known more usage about xmake, please see https://xmake.io
--
-- ## FAQ
--
-- You can enter the project directory firstly before building project.
--
--   $ cd projectdir
--
-- 1. How to build project?
--
--   $ xmake
--
-- 2. How to configure project?
--
--   $ xmake f -p [macosx|linux|iphoneos ..] -a [x86_64|i386|arm64 ..] -m [debug|release]
--
-- 3. Where is the build output directory?
--
--   The default output directory is `./build` and you can configure the output directory.
--
--   $ xmake f -o outputdir
--   $ xmake
--
-- 4. How to run and debug target after building project?
--
--   $ xmake run [targetname]
--   $ xmake run -d [targetname]
--
-- 5. How to install target to the system directory or other output directory?
--
--   $ xmake install
--   $ xmake install -o installdir
--
-- 6. Add some frequently-used compilation flags in xmake.lua
--
-- @code
--    -- add debug and release modes
--    add_rules("mode.debug", "mode.release")
--
--    -- add macro defination
--    add_defines("NDEBUG", "_GNU_SOURCE=1")
--
--    -- set warning all as error
--    set_warnings("all", "error")
--
--    -- set language: c99, c++11
--    set_languages("c99", "c++11")
--
--    -- set optimization: none, faster, fastest, smallest
--    set_optimize("fastest")
--
--    -- add include search directories
--    add_includedirs("/usr/include", "/usr/local/include")
--
--    -- add link libraries and search directories
--    add_links("tbox")
--    add_linkdirs("/usr/local/lib", "/usr/lib")
--
--    -- add system link libraries
--    add_syslinks("z", "pthread")
--
--    -- add compilation and link flags
--    add_cxflags("-stdnolib", "-fno-strict-aliasing")
--    add_ldflags("-L/usr/local/lib", "-lpthread", {force = true})
--
-- @endcode
--

