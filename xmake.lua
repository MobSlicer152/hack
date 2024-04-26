add_rules("mode.debug", "mode.release", "plugin.vsxmake.autoupdate")
set_policy("check.auto_ignore_flags", false)

if is_mode("debug") then
    add_defines("HACK_DEBUG")
elseif is_mode("release") then
    add_defines("HACK_RELEASE")
end

add_includedirs(
    "$(scriptdir)",
    "deps/phnt/include"
)

target("common")
    set_kind("static")
    add_headerfiles("hack.h", "common/**.h")
    add_files("common/**.c")
target_end()

target("hack")
    set_kind("binary")
    add_headerfiles("hack/**.h")
    add_files("hack/**.c")

    add_deps("common")

    add_ldflags("-subsystem:console", { tools = "link" })
    add_ldflags("-nodefaultlib", { tools = "link" })
target_end()
