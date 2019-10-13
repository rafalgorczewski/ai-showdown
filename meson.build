project('ai-showdown', 'cpp')

cpp_common_flags = [
    '-std=c++2a',
    '-fconcepts',
    '-Wall',
    '-Wextra',
    '-pedantic'
]
cpp_debug_flags = [
    '-O0',
    '-g',
]
cpp_release_flags = [
    '-O2'
]

add_global_arguments(cpp_common_flags, language : 'cpp')

if get_option('buildtype') == 'debug'
    link_arguments = ['-lprotobuf']
    add_global_arguments(cpp_debug_flags, language : 'cpp')
elif get_option('buildtype') == 'release'
    link_arguments = ['-lprotobuf']
    add_global_arguments(cpp_release_flags, language : 'cpp')
endif

protos_src = ['protos-cpp/common.pb.cc', 'protos-cpp/state.pb.cc', 'protos-cpp/result.pb.cc']
engine_src = [
'src/window.cpp',
'src/animation.cpp',
'src/spritecontroller.cpp',
'src/engine.cpp',
'src/map.cpp',
'src/unit.cpp',
'src/mapparser.cpp',
'src/knight.cpp',
'src/archer.cpp',
'src/bomberman.cpp',
'src/texturesmanager.cpp',
]

sources = [ protos_src, engine_src ]

include_dir = include_directories(['include', 'protos-cpp'])

sfml_dep = dependency('sfml-all')

executable('ai-showdown', ['main.cpp'] + sources, include_directories : include_dir, link_args: link_arguments, dependencies : sfml_dep)
